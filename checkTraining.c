#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 15
#define GROUPS 3
#define EXERCISES_PER_GROUP (MAX_EXERCISES / GROUPS)

void read_all_trainings() {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\training-diary\\training.txt", "r");
    if (!file) {
        perror("Не удалось открыть файл");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void read_trainings_by_date(const char *date) {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\training-diary\\training.txt", "r");
    if (!file) {
        perror("Не удалось открыть файл");
        return;
    }

    char line[256];
    int match = 0; // Флаг для вывода тренировки

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Дата: ", 6) == 0) {
            if (strstr(line, date)) {
                match = 1;
            } else {
                match = 0;
            }
        }
        if (match) {
            printf("%s", line);
        }
    }

    fclose(file);
}

void read_trainings_by_exercise(const char *exercise) {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\training-diary\\training.txt", "r");
    if (!file) {
        perror("Не удалось открыть файл");
        return;
    }

    char line[256];
    int match = 0; // Флаг для вывода тренировки

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Упражнение: ", 12) == 0) {
            if (strstr(line, exercise)) {
                match = 1;
            } else {
                match = 0;
            }
        }
        if (match) {
            printf("%s", line);
        }
    }

    fclose(file);
}

void checkTraining() {
    int choice;
    printf("Выберите тип вывода тренировок:\n1-Вывод всех тренировок\n2-Вывод тренировок по дате\n3-Вывод тренировок по упражнению\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            read_all_trainings();
            break;
        case 2: {
            printf("Введите дату тренировки (YYYY-MM-DD): ");
            char date[11];
            scanf("%10s", date);
            read_trainings_by_date(date);
            break;
        }
        case 3: {
            int group_choice, exercise_choice;
            char *exercises[GROUPS][EXERCISES_PER_GROUP] = {
                    {"Приседания",         "Жим лежа",        "Тяга становой", "", ""},
                    {"Бицепс с гантелями", "Французский жим", "Жим ногами",    "", ""},
                    {"Подтягивания",       "Отжимания",       "Планка",        "", ""}
            };

            printf("Выберите группу упражнений (1-3):\n1. Ноги\n2. Руки\n3. Спина\n");
            scanf("%d", &group_choice);

            if (group_choice < 1 || group_choice > GROUPS) {
                printf("Неверный выбор группы упражнений.\n");
                return;
            }

            printf("Выберите упражнение (1-%d):\n", EXERCISES_PER_GROUP);
            for (int i = 0; i < EXERCISES_PER_GROUP; i++) {
                if (strlen(exercises[group_choice - 1][i]) > 0) {
                    printf("%d. %s\n", i + 1, exercises[group_choice - 1][i]);
                }
            }
            scanf("%d", &exercise_choice);

            if (exercise_choice < 1 || exercise_choice > EXERCISES_PER_GROUP ||
                strlen(exercises[group_choice - 1][exercise_choice - 1]) == 0) {
                printf("Неверный выбор упражнения.\n");
                return;
            }

            char *selected_exercise = exercises[group_choice - 1][exercise_choice - 1];
            read_trainings_by_exercise(selected_exercise);
            break;
        }
        default:
            printf("Неверный выбор.\n");
            break;
    }
}