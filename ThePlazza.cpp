/*
** EPITECH PROJECT, 2021
** ThePlazza.cpp
** File description:
** Ah aha ha ah aha ah ah a........
*/

#include "include/The_Plazza.hpp"

int main(int ac, char **av)
{
    std::string my_str;
    the_commands pizza_command;
    int nb_cooks = 0;
    int time_cooks = 0;
    int stock_time = 0;
    int nb_kitchen = 0;
    int res = 45;

    if (bad_arg(ac, av)) return 84;
    nb_cooks = atoi(av[2]);
    time_cooks = atoi(av[1]);
    stock_time = atoi(av[3]);
    while (12) {
        my_str = perfect_prompt();
        if (my_str == "status") {
            std::cout << "The status of ktchen\n";
            if (nb_kitchen == 0)
                std::cout << "Any kitchen for the moment\n";
            else std::cout << nb_kitchen << " open for the moment\n"; }
        else {
            pizza_command = find_all_command(my_str);
            nb_kitchen = ManageKitchen(pizza_command, nb_cooks);
            CreateKitchen(my_str);
        }
    }
    return 0;
}