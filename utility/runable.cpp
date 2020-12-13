#include "runable.h"

//linked list init
runable* runable::rootRunable = NULL;

//run all runable instances from all derived classes
//that is the main idea of this library
void runable::runAll()
{
  runable* item = rootRunable;
  while (item != NULL)
  {
    item->run();
    item = item->nextRunable;
  }
}

//count runable objects
uint16_t runable::nbRunable()
{
  uint16_t nb = 0;
  runable* item = rootRunable;
  while (item != NULL)
  {
    nb++;
    item = item->nextRunable;
  } 
  return nb;
}

//constructor
runable::runable()
{
  addLastRunable();
}

//destructor
runable::~runable()
{
  removeRunable();
}

//add runable object to the head of linked list
void runable::addFirstRunable()
{
  this->nextRunable = rootRunable;
  rootRunable = this;
}

//add runable object to the linked list
void runable::addBeforeRunable(runable &next)
{
  if (rootRunable == NULL)
  {
    addFirstRunable();
  }
  else if (rootRunable == &next)
  {
    this->nextRunable = rootRunable;
    rootRunable = this;
  }
  else
  {
    runable* item = rootRunable;
    while (item->nextRunable != NULL && item->nextRunable != &next) item = item->nextRunable;
    this->nextRunable = item->nextRunable;
    item->nextRunable = this;
  }
}

//add runable object to the linked list
void runable::addAfterRunable(runable &previous)
{
  if (rootRunable == NULL)
  {
    addFirstRunable();
  }
  else if (rootRunable == &previous)
  {
    this->nextRunable = rootRunable->nextRunable;
    rootRunable->nextRunable = this;
  }
  else
  {
    runable* item = rootRunable;
    while (item->nextRunable != NULL && item->nextRunable != &previous) item = item->nextRunable;
    if (item->nextRunable != NULL) item = item->nextRunable;
    this->nextRunable = item->nextRunable;
    item->nextRunable = this;
  }
}

//add runable object to the tail of linked list
void runable::addLastRunable()
{
  addAfterRunable(*this); // (*this) wont be found
}

//remove runable object from linked list
void runable::removeRunable()
{
  if (rootRunable != NULL)
  {
    if (rootRunable == this)
    {
      rootRunable = this->nextRunable;
    }
    else
    {
      runable* item = rootRunable;
      while (item->nextRunable != NULL && item->nextRunable != this) item = item->nextRunable;
      if (item->nextRunable == this) item->nextRunable = this->nextRunable; 
    }
  }
}

void runable::setFirstRunable()
{
  removeRunable();
  addFirstRunable();
}

void runable::setAfterRunable(runable &previous)
{
  removeRunable();
  addAfterRunable(previous);
}

void runable::setBeforeRunable(runable &next)
{
  removeRunable();
  addBeforeRunable(next);
}

void runable::setLastRunable()
{
  removeRunable();
  addLastRunable();
}
