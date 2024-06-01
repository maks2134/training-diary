#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 15
#define GROUPS 3
#define EXERCISES_PER_GROUP (MAX_EXERCISES / GROUPS)

typedef struct {
    char date[11];    // Дата тренировки в формате "YYYY-MM-DD"
    int duration;     // Продолжительность тренировки в минутах (опционально)
    char exercise[50]; // Название упражнения
    int repetitions;  // Количество повторений
    float weight;     // Вес, который использовался
} Training;

typedef struct Node {
    Training data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Функции для работы с очередью
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Training data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Не удалось выделить память для нового узла");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear) {
        q->rear->next = newNode;
    }
    q->rear = newNode;

    if (!q->front) {
        q->front = newNode;
    }
}

Training dequeue(Queue *q) {
    if (isEmpty(q)) {
        perror("Очередь пуста");
        exit(EXIT_FAILURE);
    }
    Node *temp = q->front;
    Training data = temp->data;
    q->front = q->front->next;

    if (!q->front) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void printTraining(Training training) {
    printf("Дата: %s\n", training.date);
    if (training.duration > 0) {
        printf("Продолжительность: %d минут\n", training.duration);
    }
    printf("Упражнение: %s\n", training.exercise);
    printf("Количество повторений: %d\n", training.repetitions);
    printf("Вес: %.2f кг\n", training.weight);
    printf("--------------------------\n");
}

void write_training() {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\training-diary\\training.txt", "a");
    if (!file) {
        perror("Не удалось открыть файл");
        return;
    }

    Queue trainingQueue;
    initQueue(&trainingQueue);

    Training training;
    char duration_input[10];
    char *exercises[GROUPS][EXERCISES_PER_GROUP] = {
            {"Приседания", "Жим лежа", "Тяга становой", "", ""},
            {"Бицепс с гантелями", "Французский жим", "Жим ногами", "", ""},
            {"Подтягивания", "Отжимания", "Планка", "", ""}
    };

    printf("Введите дату тренировки (YYYY-MM-DD): ");
    scanf("%10s", training.date);

    printf("Введите продолжительность тренировки (в минутах, или оставьте пустым): ");
    fgets(duration_input, sizeof(duration_input), stdin); // Очистка буфера
    fgets(duration_input, sizeof(duration_input), stdin);
    if (strcmp(duration_input, "\n") == 0) {
        training.duration = 0; // Если введено пустое значение, продолжительность равна 0
    } else {
        training.duration = atoi(duration_input);
    }

    int group_choice, exercise_choice;
    printf("Выберите группу упражнений (1-3):\n1. Ноги\n2. Руки\n3. Спина\n");
    scanf("%d", &group_choice);

    if (group_choice < 1 || group_choice > GROUPS) {
        printf("Неверный выбор группы упражнений.\n");
        fclose(file);
        return;
    }

    printf("Выберите упражнение (1-%d):\n", EXERCISES_PER_GROUP);
    for (int i = 0; i < EXERCISES_PER_GROUP; i++) {
        if (strlen(exercises[group_choice - 1][i]) > 0) {
            printf("%d. %s\n", i + 1, exercises[group_choice - 1][i]);
        }
    }
    scanf("%d", &exercise_choice);

    if (exercise_choice < 1 || exercise_choice > EXERCISES_PER_GROUP || strlen(exercises[group_choice - 1][exercise_choice - 1]) == 0) {
        printf("Неверный выбор упражнения.\n");
        fclose(file);
        return;
    }

    strcpy(training.exercise, exercises[group_choice - 1][exercise_choice - 1]);

    printf("Введите количество повторений: ");
    scanf("%d", &training.repetitions);

    printf("Введите вес, который использовался: ");
    scanf("%f", &training.weight);

    // Добавляем тренировку в очередь
    enqueue(&trainingQueue, training);

    // Записываем все тренировки из очереди в файл
    while (!isEmpty(&trainingQueue)) {
        Training t = dequeue(&trainingQueue);
        fprintf(file, "Дата: %s\n", t.date);
        if (t.duration > 0) {
            fprintf(file, "Продолжительность: %d минут\n", t.duration);
        }
        fprintf(file, "Упражнение: %s\n", t.exercise);
        fprintf(file, "Количество повторений: %d\n", t.repetitions);
        fprintf(file, "Вес: %.2f кг\n", t.weight);
        fprintf(file, "--------------------------\n");
    }

    fclose(file);
    printf("Тренировка успешно записана в файл.\n");
}