/*
** EPITECH PROJECT, 2021
** BadArgs.cpp
** File description:
** Bad the args.....
*/

#include "../include/The_Plazza.hpp"

void usage(void)
{
    std::cout << "USAGE:\n\t./plazza a b c" << std::endl;
    std::cout << "\ta Multiplier for the cooking time of the pizzas." << std::endl;
    std::cout << "\tb Number of cooks per kitchen." << std::endl;
    std::cout << "\tc Time in milliseconds, used by the kitchen stock to replace ingredients." << std::endl;
}

int bad_arg(int ac, char **av)
{
    if (ac != 4) {
        usage();
        return 84; }
    else if (check_digit(av)) {
        usage();
        return 84; }
    return 0;
}