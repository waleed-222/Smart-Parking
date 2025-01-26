
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
#include "Input.hpp"
#include "Types.hpp"
namespace sp {
template <typename T> class Converter {

public:
  virtual ~Converter() = default;
  virtual Actions convert(typename Input<T>::type data) = 0;
};
} // namespace sp
