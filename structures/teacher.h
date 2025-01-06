#ifndef TEACHER_H
#define TEACHER_H
#include "user.h"

/// @brief Структура преподавателя
typedef struct Teacher
{
    user_t user;
    /// @brief Опыт работы
    unsigned experiense;
} teacher_t;

teacher_t TeacherInit(int id, char* fullname, char* email, char* phone, unsigned experiense)
{
    teacher_t teacher;
    teacher.experiense = experiense;
    teacher.user = UserInit(id, fullname, email, phone);

    return teacher;
}

/// @brief Вывод преподавателя
/// @param teacher Преподаватель
void PrintTeacher(teacher_t teacher)
{
    PrintUser(teacher.user);
    printf(" (преподаватель):\n\tФИО:\t\t%s\n\tТелефон:\t%s\n\tОпыт:\t\t%u\n", teacher.user.fullname, teacher.user.phone, teacher.experiense);
}
#endif