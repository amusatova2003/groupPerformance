#ifndef USER_H
#define USER_H
#include "../utils.c"
/// @brief Структура пользователя
typedef struct User
{
    int id;
    /// @brief ФИО
    char fullname[64];
    /// @brief Электронная почта
    char email[64];
    /// @brief Телефон
    char phone[19];
} user_t;

/// @brief Инициализация пользователя
/// @param id Идентификатор
/// @param fullname ФИО
/// @param email Почта
/// @param phone Телефон
/// @return Пользователь
user_t UserInit(int id, char* fullname, char* email, char* phone)
{
    user_t user;
    user.id = id;

    for (int i = 0; fullname[i] != '\0'; i++)
    {
        user.fullname[i] = fullname[i];
    }

    for (int i = 0; email[i] != '\0'; i++)
    {
        user.email[i] = email[i];
    }

    for (int i = 0; phone[i] != '\0'; i++)
    {
        user.phone[i] = phone[i];
    }

    return user;
}

/// @brief Ввод пользователя
/// @param id Идентификатор
/// @return Пользователь
user_t InputUser(int id)
{
    char* fullname = malloc(64);
    char* email = malloc(64);
    char* phone = malloc(19);

    printf("ФИО:\t");
    scanf("%s", fullname);
    ClearBuffer();
    printf("Почта:\t");
    scanf("%s", email);
    ClearBuffer();
    printf("Телефон:\t");
    scanf("%s", phone);
    ClearBuffer();

    user_t user = UserInit(id, fullname, email, phone);

    return user;
}

/// @brief Вывод пользователя
/// @param user Пользователь
void PrintUser(user_t user)
{
    printf("Пользователь №%i", user.id);
}
#endif