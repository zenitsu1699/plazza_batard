/*
** EPITECH PROJECT, 2021
** IKitchen.cpp
** File description:
** IKitchen.cpp
*/

#include "../include/The_Plazza.hpp"

IKitchen::IKitchen(int nb, int time, std::vector<the_pizza> cmd_pizza)
{
  nb_cooks = nb;
  time_update = time;
  cook_action = 0;
  mine.doe = 5;
  mine.tomato = 5;
  mine.ham = 5;
  mine.steak = 5;
  mine.eggplant = 5;
  mine.cheese = 5;
  mine.gruyere = 5;
  mine.mushrooms = 5;
  order = cmd_pizza;
}

IKitchen::~IKitchen()
{
  nb_cooks = 0;
  time_update = 0;
  cook_action = 0;
  mine.doe = 0;
  mine.tomato = 0;
  mine.ham = 0;
  mine.steak = 0;
  mine.eggplant = 0;
  mine.cheese = 0;
  mine.gruyere = 0;
  mine.mushrooms = 0;
}

int IKitchen::get_nb_cooks(void)
{
  return nb_cooks;
}

void IKitchen::set_cooks_in_work(void)
{
  cook_action++;
}

void IKitchen::get_the_pizza_done(void)
{
  std::vector<the_pizza>::iterator it;

  it = order.begin();
  order.erase(it);
}
