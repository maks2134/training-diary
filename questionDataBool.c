#include "questionDataBool.h"
#include <stdio.h>
#include "traningHooks.h"

enum {START ,ADD, CHECK, ADVICE};

void questionData(){
    int questionDataBool; // Переменная, имитирующая логику выбора
    printf("\n Выберите нужный функционал:\n");
    printf("\n 1: Добавить новую запись \n 2: Удалить запись \n 3: Изменить запись\n");
    scanf("%d", &questionDataBool); // Считываем переменную, имитирующую логику выбора
    switch (questionDataBool) {
        case ADD:
            createTraning(); // Функция добавления тренировок
            break;
        case CHECK:
            reportTraining(); // Функция просмотра тренировки
            break;
        case ADVICE:
            adviceTraning(); // Функция выдачи советов
            break;
        default:
            printf("Неверный ввод"); // Обработка некорректного ввода
            break;
    }
}
