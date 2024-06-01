#ifndef TRAINING_DIARY_CREATETRANING_H
#define TRAINING_DIARY_CREATETRANING_H
void write_training();

typedef struct {
    char date[11]; // Дата тренировки в формате "YYYY-MM-DD"
    int duration;  // Продолжительность тренировки в минутах (опционально)
    char exercise[50]; // Название упражнения
    int repetitions; // Количество повторений
    float weight; // Вес, который использовался
} Training;


#endif