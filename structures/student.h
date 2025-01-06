#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"

/// @brief Структура студента
typedef struct Student
{
    user_t user;
} student_t;

/// @brief Инифиализация студента
/// @param id Идентификатор
/// @param fullname ФИО
/// @param email Почта
/// @param phone Телефон
/// @return Студент
student_t StudentInit(int id, char* fullname, char* email, char* phone)
{
    student_t student;
    student.user = UserInit(id, fullname, email, phone);

    return student;
}

/// @brief Вывод студента
/// @param student Студент
void PrintStudent(student_t student)
{
    PrintUser(student.user);
    printf(" (студент):\n\tФИО:\t\t%s\n\tТелефон:\t%s\n", student.user.fullname, student.user.phone);
}
#endif