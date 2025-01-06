#ifndef STUDENT_MARK_H
#define STUDENT_MARK_H

#include "student.h"
#include "teacher.h"
#include "discipline.h"

/// @brief Структура успеваемости студента
typedef struct StudentMark
{
    int id;
    student_t student;
    teacher_t teacher;
    discipline_t discipline;
    int mark;

} student_mark_t;

/// @brief Инициализация успеваемости студента
/// @param id Идентификатор
/// @param student Студент
/// @param teacher Преподаватель
/// @param discipline Дисциплина
/// @param mark Оценка
/// @return Успеваемость
student_mark_t StudentMarkInit(int id, student_t student, teacher_t teacher, discipline_t discipline, int mark)
{
    student_mark_t student_mark;
    student_mark.id = id;
    student_mark.student = student;
    student_mark.teacher = teacher;
    student_mark.discipline = discipline;
    student_mark.mark = mark;

    return student_mark;
}

/// @brief Вывод успеваемости студента
/// @param student_mark 
void PrintStudentMark(student_mark_t student_mark)
{
    printf("Студент:\t%s\nДисциплина:\t%s\nОценка:\t\t%i\n\n", student_mark.student.user.fullname, student_mark.discipline.name, student_mark.mark);
}

#endif