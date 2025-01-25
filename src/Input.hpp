
#pragma once
/********************************************/
//
//              CopyRight Moatasem
//
/********************************************/
/*
author : Moatasem
date :Sat Jan 25 08:15:21 PM CET 2025
brief:
*/
namespace sp {
template <typename T> class Input {

public:
  virtual ~Input() = default;
  virtual T get() = 0;
  virtual void terminate() = 0;

protected:
  virtual void listen() = 0;
};
} // namespace sp
