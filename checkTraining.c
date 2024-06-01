#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_all_trainings() {
    FILE *file = fopen("training.txt", "r");
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
    FILE *file = fopen("training.txt", "r");
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
    FILE *file = fopen("training.txt", "r");
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


void checkTraining(){
    int choise;
    printf("Выберите тип вывода тренировок:\n1-Вывод всех тренировок\n2-Вывод тренировок по дате\n3-Вывод тренировок по упражнению\n");
    switch (choise){
        case 1:
    }
}