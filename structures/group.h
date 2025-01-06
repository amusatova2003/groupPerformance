#ifndef GROUP_H
#define GROUP_H
#include <stdio.h>
#include "student.h"

/// @brief Максимальное число студентов в группе
#define MAX_STUDENT_COUNT 30

/// @brief Структура группы
typedef struct Group
{
    unsigned id;
    char name[128];
    student_t students[MAX_STUDENT_COUNT];

    unsigned student_count;
} group_t;

/// @brief Инициализация группы
/// @param id Идентификатор
/// @param name Имя группы
/// @return Группа
group_t GroupInit(unsigned id, char* name)
{
    group_t group;
    group.id = id;
    group.student_count = 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        group.name[i] = name[i];
    }

    return group;
}

/// @brief Добавление студента в группу
/// @param group Группа
/// @param student Студент
void AddStudent(group_t *group, student_t student)
{
    if (group->student_count < MAX_STUDENT_COUNT)
    {
        group->students[group->student_count] = student;
        group->student_count++;
    }
}

/// @brief Вывод группы
/// @param group Группа
void PrintGroup(group_t group)
{
    printf("Группа: %s\n", group.name);

    for (int i = 0; i < group.student_count; i++)
    {
        PrintStudent(group.students[i]);
    }
}
#endif