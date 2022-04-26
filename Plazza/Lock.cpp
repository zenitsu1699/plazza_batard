/*
** EPITECH PROJECT, 2021
** Lock.cpp
** File description:
** Lock.cpp
*/

#include "../include/The_Plazza.hpp"

MYmutex::~MYmutex()
{

}

MYmutex::MYmutex()
{

}
void MYmutex::lock(void)
{
  mtx.lock();
}

void MYmutex::unlock(void)
{
  mtx.unlock();
}

void MYmutex::trylock(void)
{
  mtx.try_lock();
}
