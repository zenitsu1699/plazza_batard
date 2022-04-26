/*
** EPITECH PROJECT, 2021
** BadCommand.cpp
** File description:
** The bad comment of shell
*/

#include "../include/The_Plazza.hpp"

int check_pizzatype(std::string str)
{
    std::vector<std::string> PizzaType = { "regina" , "margarita" , "americana" , "fantasia" ,
                                            "Regina" , "Margarita" , "Americana" , "Fantasia" };

    for (int l = 0; l < PizzaType.size(); l++)
            if (str == PizzaType[l]) return 0;
    std::cout << str << ": It's not a pizza!\n";
    return 84;
}

int check_pizzasize(std::string str)
{
    std::vector<std::string> PizzaSize = { "S" , "M" , "L" , "XL" , "XXL" };

    for (int l = 0; l < PizzaSize.size(); l++)
            if (str == PizzaSize[l]) return 0;
    std::cout << "It's a bad size of pizza!\n";
    return 84;
}

int check_number(std::string str)
{
    int findMe = 10;

    findMe = str.find("x");
    if (findMe != 0) {
        std::cout << "Please check your number of pizza!\n";
        return 84; }
    return 0;
}

int bad_command(std::vector<std::string> mystr)
{
    int length = mystr.size();

    if (length == 1 && mystr[0] != "status") {
        std::cout << "Please tape " << '"' << "status" << '"' << std::endl;
        return 84; }
    else if (length == 1 && mystr[0] == "status")
        return 0;
    else
        for (int k = 0; k < mystr.size(); ) {
            if (check_pizzatype(mystr[k])) return 84;
            k++;
            if (check_pizzasize(mystr[k])) return 84;
            k++;
            if (check_number(mystr[k])) return 84;
            k++;
            if (k < mystr.size()) {
            if ((mystr[k] == ";") && (k + 1 == mystr.size())) {
                std::cout << "; at the end of command\n";
                return 84; }
            else if ((mystr[k] == ";") && (k + 1 < mystr.size())) k++; } }
    return 0;
}