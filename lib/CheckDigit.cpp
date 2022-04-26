/*
** EPITECH PROJECT, 2021
** CheckDigit.cpp
** File description:
** Check the number .....
*/

#include "../include/The_Plazza.hpp"

int check_digit(char **av)
{
    for (int i = 2; i <= 3; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (!std::isdigit(av[i][j]))
                return (84);
    if (av[1][0] < '0' || av[1][0] > '9') return 84;
    for (int j = 1; av[1][j] != '\0'; j++)
            if ((av[1][j] < '0' || av[1][j] > '9') && (av[1][j] != '.'))
                return (84);
    if (atoi(av[2]) == 0) return 84;
    return (0);
}