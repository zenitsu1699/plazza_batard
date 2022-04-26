/*
** EPITECH PROJECT, 2021
** Ipc.cpp
** File description:
** The name of lib...
*/

#include "../include/The_Plazza.hpp"

IPC::IPC()
{
  this->nbQueues = 0;
}


IPC::~IPC()
{
  for (int i = 0; i < this->ins.size(); i++) {
    mq_close(this->ins[i].second);
  }
  for (int j = 0; j < this->outs.size(); j++) {
    mq_close(this->outs[j].second);
  }
}

void IPC::addQueue(int idKitchen)
{
  mqd_t mqfd;
  struct mq_attr attr;
  std::string name("/plazza" + std::to_string(this->nbQueues + 1) + "IN");

  attr.mq_maxmsg = 10;
  attr.mq_msgsize = 20;
  mq_unlink(name.c_str());
  mqfd = mq_open(name.c_str(), O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), &attr);
  if (mqfd == -1) {
    exit(84);
  }
  std::pair<int, mqd_t> queueIn {idKitchen, mqfd};
  this->ins.push_back(queueIn);
  name.clear();
  name = "/plazza" + std::to_string(this->nbQueues + 1) + "OUT";
  mq_unlink(name.c_str());
  mqfd = mq_open(name.c_str(), O_RDWR | O_CREAT | O_NONBLOCK, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), &attr);
  if (mqfd == -1) {
    exit(84);
  }
  std::pair<int, mqd_t> queueOut {idKitchen, mqfd};
  this->outs.push_back(queueOut);
  this->nbQueues++;
}

void IPC::sendMessageToKitchen(int idKitchen, const std::string message)
{
  int idQueue = this->getQueueId(idKitchen, 1);
  int ret = 0;

  ret = mq_send(this->ins[idQueue].second, message.c_str(), message.length() + 1, 0);
  if (ret == -1) {
    exit(84);
  }
}

int IPC::receiveMessageFromKitchen(int idKitchen, std::string &buffer)
{
  int idQueue = this->getQueueId(idKitchen, 2);
  int ret = 0;
  char buff[20];

  ret = mq_receive(this->outs[idQueue].second, buff, 20, 0);
  if (ret == -1 && errno != EAGAIN) {
    exit(84);
  }
  if (ret > 0)
    buffer.assign(buff);
  return (ret);
}

void IPC::sendMessageToReception(mqd_t descriptor, const std::string message)
{
  int ret = 0;

  ret = mq_send(descriptor, message.c_str(), message.length() + 1, 0);
  if (ret == -1) {
    exit(84);
  }
}

void IPC::receiveMessageFromReception(mqd_t descriptor, std::string &buffer)
{
  int ret = 0;
  char buff[20];

  ret = mq_receive(descriptor, buff, 20, 0);
  if (ret == -1) {
    exit(84);
  }
  if (ret > 0)
    buffer.assign(buff);
}

int IPC::getQueueId(int idKitchen, int mode)
{
  if (mode == 1) {
    for (int i = 0; i < this->ins.size(); i++) {
      if (this->ins[i].first == idKitchen)
	return (i);
    }
  } else if (mode == 2) {
    for (int j = 0; j < this->outs.size(); j++) {
      if (this->outs[j].first == idKitchen)
	return (j);
    }
  }
  exit(84);
}
