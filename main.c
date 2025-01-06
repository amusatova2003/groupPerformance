#include <stdio.h>
#include <stdlib.h>
#include "structures/student_mark.h"
#include "structures/group.h"

/// @brief Получение группы студента
/// @param groups Список групп
/// @param student Студент
/// @param group_counte Число групп
/// @return Группа студента
group_t GetGroup(group_t *groups, student_t student, int group_count)
{
    // Проходимся по группам
    for (int i = 0; i < group_count; i++)
    {
        group_t group = groups[i];
        // Проходимся по студентам
        for (int j = 0; j < group.student_count; j++)
        {
            // Если нашли студента в группе, выводим группу
            if (group.students[j].user.id == student.user.id)
            {
                return group;
            }
        }
    }
}

/// @brief Средняя оценка студента
/// @param marks Оценки
/// @param student Студент
/// @param mark_count Число оценок
/// @return Средняя оценка
double AvgStudentMark(student_mark_t *marks, student_t student, int mark_count)
{
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < mark_count; i++)
    {
        student_mark_t mark = marks[i];
        
        if (mark.student.user.id == student.user.id)
        {
            sum += mark.mark;
            count++;
        }
    }

    return sum / count;
}

/// @brief Средняя оценка группы
/// @param marks Оценки
/// @param groups Список групп
/// @param group Группа
/// @param mark_count Число оценок
/// @param groups_count Число групп
/// @return Средняя оценка
double AvgGroupMark(student_mark_t *marks, group_t *groups, group_t group, int mark_count, int groups_count)
{
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < mark_count; i++)
    {
        student_mark_t mark = marks[i];
        group_t _group = GetGroup(groups, mark.student, groups_count);

        if (group.id == _group.id)
        {
            sum += mark.mark;
            count++;
        }

    }

    return sum / count;
}

/// @brief Средняя оценка группы по дисциплине
/// @param marks Оценки
/// @param groups Список групп
/// @param group Группа
/// @param discipline Дисциплина
/// @param mark_count Число оценок
/// @param groups_count Число групп
/// @return Средняя оценка
double AvgGroupMarkByDiscipline(student_mark_t *marks, group_t *groups, group_t group, discipline_t discipline, int mark_count, int groups_count)
{
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < mark_count; i++)
    {
        student_mark_t mark = marks[i];
        group_t _group = GetGroup(groups, mark.student, groups_count);

        if (group.id == _group.id && mark.discipline.id == discipline.id)
        {
            sum += mark.mark;
            count++;
        }

    }

    return sum / count;
}

int main()
{
    // Заполняем структуры данными //
    
    // Дисциплины
    discipline_t disciplines[] = {
        DisciplineInit(1, "Информатика"),
        DisciplineInit(2, "Линейная алгебра"),
        DisciplineInit(3, "Компьютерные сети"),
        DisciplineInit(4, "Аналитическая геометрия"),
        DisciplineInit(5, "Дифференциальные уравнения"),
        DisciplineInit(6, "Системное программирование"),
        DisciplineInit(7, "Алгоритмизация и программирования"),
    };

    // Студенты
    student_t students[] = {
        StudentInit(1, "Савкина Наталия Кирилловна", "nataliya.savkina@mail.ru", "+7 (965) 266-77-70"),
        StudentInit(2, "Лягушкина Тамара Герасимовна", "tamara64@yandex.ru", "+7 (965) 407-58-21"),
        StudentInit(3, "Левченко Григорий Герасимович", "greg1975@rambler.ru", "+7 (994) 226-24-88"),
        StudentInit(4, "Митрохова Таисия Александровна", "taisiya1962@outlook.com", "+7 (922) 681-36-73"),
        StudentInit(5, "Прокашева Вероника Александровна", "veronika20021986@ya.ru", "+7 (977) 140-22-69"),
    };

    // Преподаватели
    teacher_t teachers[] = {
        TeacherInit(1, "Ишеев Юлиан Романович", "yulian73@outlook.com", "+7 (972) 437-54-81", 16),
        TeacherInit(2, "Якушевич Венедикт Викторович", "venedikt5669@outlook.com", "+7 (961) 530-95-75", 23),
        TeacherInit(3, "Грибалева Ирина Ефимовна", "irina23101986@gmail.com", "+7 (974) 784-40-78", 7),
        TeacherInit(4, "Яндиева Александра Данииловна", "aleksandra27071965@rambler.ru", "+7 (913) 858-51-53", 4),
    };

    // Группы
    group_t groups[] = {
        GroupInit(1, "1091"),
        GroupInit(2, "1092"),
    };

    // Добавление студентов в группу
    AddStudent(&groups[0], students[0]);
    AddStudent(&groups[0], students[1]);
    AddStudent(&groups[0], students[2]);
    AddStudent(&groups[1], students[3]);
    AddStudent(&groups[1], students[4]);

    // Оценки студентов
    student_mark_t marks[5000];
    // {
    //     StudentMarkInit(1, students[0], teachers[1], disciplines[2], 4),
    //     StudentMarkInit(2, students[0], teachers[3], disciplines[0], 4),
    //     StudentMarkInit(3, students[1], teachers[1], disciplines[1], 4),
    //     StudentMarkInit(4, students[0], teachers[2], disciplines[1], 5),
    //     StudentMarkInit(5, students[1], teachers[0], disciplines[5], 5),
    //     StudentMarkInit(6, students[1], teachers[0], disciplines[0], 5),
    //     StudentMarkInit(7, students[2], teachers[2], disciplines[0], 5),
    //     StudentMarkInit(8, students[3], teachers[0], disciplines[2], 4),
    //     StudentMarkInit(9, students[2], teachers[2], disciplines[5], 2),
    //     StudentMarkInit(10, students[4], teachers[3], disciplines[6], 3),
    //     StudentMarkInit(11, students[3], teachers[3], disciplines[5], 5),
    //     StudentMarkInit(12, students[1], teachers[0], disciplines[3], 5),
    // };

    int mark_count = sizeof(marks) / sizeof(student_mark_t);
    int group_count = sizeof(groups) / sizeof(group_t);
    int discipline_count = sizeof(disciplines) / sizeof(discipline_t);
    int student_count = sizeof(students) / sizeof(student_t);
    int teacher_count = sizeof(teachers) / sizeof(teacher_t);

    for (int i = 0; i < 5000; i++)
    {
        marks[i] = StudentMarkInit(i + 1, students[rand() % student_count], teachers[rand() % teacher_count], disciplines[rand() % discipline_count], 3 + rand() % 3);
    }

    for (int i = 0; i < 10 % mark_count; i++)
    {
        PrintStudentMark(marks[i]);
    }

    printf("\nСредние оценки студентов:\n");
    for (int i = 0; i < student_count; i++)
    {
        printf("%s(группа %s):\t%.2f\n", students[i].user.fullname, GetGroup(groups, students[i], group_count).name, AvgStudentMark(marks, students[i], mark_count));
    }

    printf("\n\nСредние оценки групп:\n");
    for (int i = 0; i < group_count; i++)
    {
        printf("%s:\t%.2f\n", groups[i].name, AvgGroupMark(marks, groups, groups[i], mark_count, group_count));
    }

    printf("\n\nСредние оценки групп по дисциплинам:\n");
    for (int i = 0; i < group_count; i++)
    {
        printf(" Группа %s:\n", groups[i].name);

        for (int j = 0; j < discipline_count; j++)
        {
            double mark = AvgGroupMarkByDiscipline(marks, groups, groups[i], disciplines[j], mark_count, group_count);

            if (mark > 0)
            {
                printf("\t%s:\t%.2f\n", disciplines[j].name, mark);
            }

        }
    }
    return 0;
}
