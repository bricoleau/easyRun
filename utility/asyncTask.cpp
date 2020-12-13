#include "asyncTask.h"

void asyncTask::execute()
{
  callbackVoid target = _target;
  _target.unset();
  target.execute();
}

void asyncTaskGen::execute()
{
  void (asyncTaskGen::*target)() = _target;
  unset();
  (this->*target)();
}

