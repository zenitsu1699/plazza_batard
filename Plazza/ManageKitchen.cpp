/*
** EPITECH PROJECT, 2021
** ManageKitchen.cpp
** File description:
** ManageKitchen.cpp
*/

#include "../include/The_Plazza.hpp"

the_commands find_all_command(std::string mystr)
{
    the_commands pizza_command;
    std::vector<std::string> str1 = my_string_to_word_tab(mystr, ';');
    std::vector<std::string> str2;
    the_pizza my_pizza;
    std::string ss;
    int n = 0;
    int pos = 0;

    for (int i = 0; i < str1.size(); i++) {
        str2 = my_string_to_word_tab(str1[i], ' ');
        my_pizza.name = str2[0];
        my_pizza.size = str2[1];
        pos =str2[2].find("x");
        ss = str2[2].substr(pos + 1);
        my_pizza.num = stoi(ss);
        n += my_pizza.num;
        pizza_command.command.push_back(my_pizza); }
        pizza_command.nb_command = n;
    std::cout << "The num of pizza is : " << pizza_command.nb_command << std::endl;
    return pizza_command;
}

int ManageKitchen(the_commands pizza_command, int nb_cooks)
{
    int nb_kitchen = 0;
    int sum = 0;

    for (nb_kitchen = 0; pizza_command.nb_command > sum; nb_kitchen++)
        sum = nb_kitchen * nb_cooks;
    std::cout << "The num of kitchen created is : " << nb_kitchen << std::endl;
    return nb_kitchen;
}
