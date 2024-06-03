#include "clearTraning.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void clearTraning() {
    char date_to_delete[11]; // Формат даты YYYY-MM-DD
    int confirmation; // Для подтверждения "да" или "нет"
    char line[MAX_LINE_LENGTH];
    int line_found = 0;

    // Получение даты от пользователя
    printf("Введите дату тренировки для удаления (YYYY-MM-DD): ");
    scanf("%s", &date_to_delete);
    date_to_delete[strcspn(date_to_delete, "\n")] = '\0'; // Удаление символа новой строки

    // Открытие исходного файла для чтения
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\training-diary\\test", "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    // Открытие временного файла для записи
    FILE *temp_file = fopen("C:\\Users\\maks2\\CLionProjects\\training-diary\\temp.txt", "w");
    if (temp_file == NULL) {
        perror("Ошибка создания временного файла");
        fclose(file);
        return;
    }

    // Чтение строк из исходного файла и запись их во временный файл, исключая строку с указанной датой
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, date_to_delete, strlen(date_to_delete)) == 0) {
            line_found = 1;
            printf("Найдена строка для удаления");
            printf("Вы уверены, что хотите удалить эту запись? (да(1)/нет(2)): ");
            scanf("%d", &confirmation);

            if (confirmation) {
                // Если не подтверждено, копируем строку во временный файл
                fputs(line, temp_file);
            } else {
                printf("Запись с датой %s успешно удалена.\n", date_to_delete);
            }
        } else {
            // Копирование всех остальных строк во временный файл
            fputs(line, temp_file);
        }
    }

    // Закрытие файлов
    fclose(file);
    fclose(temp_file);

    // Замена исходного файла временным
    if (line_found) {
        if (remove("C:\\Users\\maks2\\CLionProjects\\training-diary\\test") != 0) {
            perror("Ошибка удаления исходного файла");
        } else if (rename("C:\\Users\\maks2\\CLionProjects\\training-diary\\test", "C:\\Users\\maks2\\CLionProjects\\training-diary\\test") != 0) {
            perror("Ошибка переименования временного файла");
        }
    } else {
        printf("Запись с датой %s не найдена.\n", date_to_delete);
        remove("C:\\Users\\maks2\\CLionProjects\\training-diary\\temp.txt"); // Удаление временного файла, если запись не найдена
    }
}