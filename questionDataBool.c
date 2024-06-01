#include "questionDataBool.h"
#include <stdio.h>
#include "traningHooks.h"

enum {START ,ADD, CHECK, ADVICE};

void questionData(){
    int questionDataBool; // Переменная, имитирующая логику выбора
    printf("\n Выберите нужный функционал:\n");
    printf("\n 1: Добавить тренировку \n 2: Просмотреть тренировку \n 3: Советы по тренировкам\n");
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
