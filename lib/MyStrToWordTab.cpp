/*
** EPITECH PROJECT, 2021
** MyStrToWordTab.cpp
** File description:
** my str to word tab
*/

#include "../include/The_Plazza.hpp"

std::vector<std::string> my_str_to_word_tab(char *str, char c)
{
    std::vector<std::string> mystr;
    std::string S = str;
    std::stringstream X(S);
    std::string T;

    while (std::getline(X, T, c))
        if (T != "")
            mystr.push_back(T);
    return mystr;
}

std::vector<std::string> my_string_to_word_tab(std::string str, char c)
{
    std::vector<std::string> mystr;
    std::stringstream X(str);
    std::string T;

    while (std::getline(X, T, c))
        if (T != "")
            mystr.push_back(T);
    return mystr;
}
