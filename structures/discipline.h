#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"

/// @brief Структура дисциплины
typedef struct Discipline
{
    int id;
    char name[64];
} discipline_t;

/// @brief Инициализация дисциплины
/// @param id Идентификатор
/// @param name Имя дисциплины
/// @return Дисциплина
discipline_t DisciplineInit(int id, char* name)
{
    discipline_t discipline;
    discipline.id = id;

    for (int i = 0; name[i] != '\0'; i++)
    {
        discipline.name[i] = name[i];
    }

    return discipline;
}

/// @brief Ввод дисциплины
/// @param id Ижентификатор
/// @return Дисциплина
discipline_t InputDiscipline(int id)
{
    char* name = malloc(64);

    printf("Дисциплина:\t");
    scanf("%s", name);
    ClearBuffer();

    discipline_t discipline = DisciplineInit(id, name);

    return discipline;
}

/// @brief Вывод дисциплины
/// @param discipline Дисциплина
void DisciplinePrint(discipline_t discipline)
{
    printf("%s", discipline.name);
}

#endif