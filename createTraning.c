#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 15
#define GROUPS 3
#define EXERCISES_PER_GROUP (MAX_EXERCISES / GROUPS)

typedef struct {
    char date[11]; // Дата тренировки в формате "YYYY-MM-DD"
    int duration;  // Продолжительность тренировки в минутах (опционально)
    char exercise[50]; // Название упражнения
    int repetitions; // Количество повторений
    float weight; // Вес, который использовался
} Training;

void write_training() {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\training-diary\\traning.txt", "a");
    if (!file) {
        perror("Не удалось открыть файл");
        return;
    }

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

    fprintf(file, "Дата: %s\n", training.date);
    if (training.duration > 0) {
        fprintf(file, "Продолжительность: %d минут\n", training.duration);
    }
    fprintf(file, "Упражнение: %s\n", training.exercise);
    fprintf(file, "Количество повторений: %d\n", training.repetitions);
    fprintf(file, "Вес: %.2f кг\n", training.weight);
    fprintf(file, "--------------------------\n");

    fclose(file);
    printf("Тренировка успешно записана в файл.\n");
}