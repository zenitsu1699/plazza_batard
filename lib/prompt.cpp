/*
** EPITECH PROJECT, 2021
** prompt.cpp
** File description:
** The prompt of project ....
*/

#include "../include/The_Plazza.hpp"

char *prompt(void)
{
    char *buf;
    size_t bufsize = 900000;
    size_t characters;

    buf = (char *)malloc(bufsize * sizeof(char));
    if (buf == NULL) return NULL;
    std::cout << "PLazza chez Salifou> ";
    characters = getline(&buf, &bufsize, stdin);
    if (characters == -1) {
        std::cout << " (CTRL+D)" << std::endl;
        exit(0); }
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '\n' && buf[i + 1] == '\0') {
            buf[i] = '\0';
            return buf; }
        else if (buf[i] == '\t')
            buf[i] = ' ';
    return buf;
}

std::string perfect_prompt(void)
{
    char *str = prompt();
    std::string string;
    std::vector<std::string> mystr =  my_str_to_word_tab(str, ' ');

    while (mystr.size() == 0) {
        str = prompt();
        mystr = my_str_to_word_tab(str, ' '); }
    while (bad_command(mystr) == 84) {
        str = prompt();
        mystr = my_str_to_word_tab(str, ' ');
        while (mystr.size() == 0) {
            str = prompt();
            mystr = my_str_to_word_tab(str, ' '); }
    }
    string = str;
    return string;
}