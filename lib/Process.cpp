/*
** EPITECH PROJECT, 2021
** Process.cpp
** File description:
** Encapsulation du process....
*/

#include "../include/The_Plazza.hpp"

MYProc::MYProc()
{
    M_pid = getpid();
    m_pid = fork();
}

MYProc::~MYProc()
{
    kill(m_pid, SIGKILL);
}

pid_t MYProc::get_my_pid_father(void)
{
  return M_pid;
}

pid_t MYProc::get_my_pid_son(void)
{
  return m_pid;
}
