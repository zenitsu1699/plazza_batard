/*
** EPITECH PROJECT, 2021
** The_Plazza.hpp
** File description:
** The plazza name function ....
*/

#ifndef THE_PLAZZA_HPP
#define THE_PLAZZA_HPP

#include "Librairie.hpp"

int bad_arg(int ac, char **av);
void usage(void);
int check_digit(char **av);
char *prompt(void);
std::vector<std::string> my_str_to_word_tab(char *str, char c);
std::vector<std::string> my_string_to_word_tab(std::string str, char c);
int check_pizzatype(std::string str);
int check_pizzasize(std::string str);
int check_number(std::string str);
int bad_command(std::vector<std::string> mystr);
std::string perfect_prompt(void);
the_commands find_all_command(std::string mystr);
int ManageKitchen(the_commands pizza_command, int nb_cooks);
int CreateKitchen(std::string mystr);

#endif /* !THE_PLAZZA_HPP */
