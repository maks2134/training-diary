#include <stdio.h>
#include <systemTech.h>
#include <questionDataBool.h>

int main(){
    setRussianLanguage();
    setBackgorundColor();

    printf("------------------------------------------------ ЖУРНАЛ ТРЕНИРОВОК ------------------------------------------------");
    int choice;
    do { //зацикливаем main

        questionData(); // Переходим к выбору функционала
        printf("\nЖелаете продолжить? (1: Да, 0: Нет): ");
        scanf("%d", &choice); // Спрашиваем пользователя, хочет ли он продолжить
        ClearConsole();

        } while (choice != 0); // Продолжаем цикл до тех пор, пока пользователь не решит завершить программу
        return 0; // Завершаем программу
}
