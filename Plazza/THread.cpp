/*
** EPITECH PROJECT, 2021
** Thread.cpp
** File description:
** Thread.cpp
*/

#include "../include/The_Plazza.hpp"

MYthread::MYthread(void (*myfunction)(int *ref), int *dest)
{
  thr = std::thread(myfunction, dest);
}

void MYthread::join(void)
{
  thr.join();
}

MYthread::~MYthread()
{

}
