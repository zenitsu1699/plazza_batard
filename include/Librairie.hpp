/*
** EPITECH PROJECT, 2021
** Librairie.hpp
** File description:
** The name of lib...
*/

#ifndef LIBRAIRIE_HPP
#define LIBRAIRIE_HPP

#include <vector>
#include <string>
#include <cstdio>
#include <mqueue.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

#define PMODE 0655
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <utility>
#include <chrono>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)


enum PizzaType
{
    Regina = 1 ,
    Margarita = 2 ,
    Americana = 4 ,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1 ,
    M = 2 ,
    L = 4 ,
    XL = 8 ,
    XXL = 16
};

enum Ingredients
{
    doe,
    tomato,
    gruyere,
    ham,
    mushrooms,
    steak,
    eggplant,
    cheese
};

typedef struct Ingredient
{
  int doe;
  int tomato;
  int gruyere;
  int ham;
  int mushrooms;
  int steak;
  int eggplant;
  int cheese;
} Ingredient;

typedef struct the_pizza
{
    int num;
    std::string name;
    std::string size;
} the_pizza;

typedef struct the_commands
{
    int nb_command;
    std::vector<the_pizza> command;
} the_commands;

class MYProc
{
public:
    MYProc();
    ~MYProc();
    pid_t get_my_pid_father(void);
    pid_t get_my_pid_son(void);

private:
    pid_t m_pid;
    pid_t M_pid;
};

class MYmutex
{
  private:
    std::mutex mtx;
  public:
    MYmutex();
    ~MYmutex();
    void lock(void);
    void unlock(void);
    void trylock(void);
    std::mutex get_my_mutex(void);
};

class MYthread
{
  public:
    MYthread(void (*myfunction)(int *ref), int *dest);
    ~MYthread();
    void join(void);
    std::thread get_my_thread(void);
  private:
    std::thread thr;
};

class IKitchen
{
  private:
      int nb_cooks;
      int cook_action;
      int time_update;
      Ingredient mine;
      std::vector<the_pizza> order;

  public:
      IKitchen(int nb, int time, std::vector<the_pizza> cmd_pizza);
      ~IKitchen();
      int get_nb_cooks(void);
      void set_cooks_in_work(void);
      void update_the_ingredients(void);
      int get_cook_in_work(void);
      int get_status_of_ingredient(void);
      void get_the_pizza_done(void);
};

class IPC {
public:
  IPC();
  ~IPC();
  void addQueue(int idKitchen);
  void sendMessageToKitchen(int idKitchen, const std::string message);
  int receiveMessageFromKitchen(int idKitchen, std::string &buffer);
  void sendMessageToReception(mqd_t descriptor, const std::string message);
  void receiveMessageFromReception(mqd_t descriptor, std::string &buffer);
private:
  int nbQueues;
  std::vector<std::pair<int, mqd_t>> ins;
  std::vector<std::pair<int, mqd_t>> outs;
  int getQueueId(int idKitchen, int mode);
};

#endif /* !LIBRAIRIE_HPP */
