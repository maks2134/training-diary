#include "questionDataBool.h"
#include <stdlib.h>
#include <stdio.h>
#include "systemTech.h"

enum {START ,ADD, REMOVE, CHANGE, CHECK, END};

void questionData(){
    int questionDataBool; // Переменная, имитирующая логику выбора
    printf("\n Выберите нужный функционал:\n");
    printf("\n 1: Добавить новую запись \n 2: Удалить запись \n 3: Изменить запись \n 4: Проверить запись (доступно только для Админа) \n ");
    scanf("%d", &questionDataBool); // Считываем переменную, имитирующую логику выбора
    switch (questionDataBool) {
        case ADD:
            addData(); // Функция добавления данных
            break;
        case REMOVE:
            removeData(); // Функция удаления данных
            break;
        case CHANGE:
            changeData(); // Функция изменения данных
            break;
        case CHECK:
            checkData(); // Функция проверки данных
            break;
        case END:
            GenerateReport(); // Функция для генерации отчета
            break;
        default:
            printf("Неверный ввод"); // Обработка некорректного ввода
            break;
    }
}
