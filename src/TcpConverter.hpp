
#pragma once
/********************************************/
//
//              CopyRight Waleed Ebrahem
//
/********************************************/
/*
author : Waleed Ebrahem
date :Sun Mar 16 07:06:15 PM CET 2025
brief:
*/
#include "TCP.hpp"
#include "Types.hpp"
#include "converter.hpp"
namespace sp {
class TcpConverter : public Converter<Key> {
public:
  Actions convert(Key data) override {
    Actions action = Actions::NONE;
    if (data == Key::CarEnter1) {
      action = Actions::PARK_FIRST;
    } else if (data == Key::CarEnter2) {
      action = Actions::PARK_SECOND;
    } else if (data == Key::CarExit1) {
      action = Actions::UNPARK_FIRST;
    } else if (data == Key::CarExit2) {
      action = Actions::UNPARK_SECOND;
    } else {
    }
    return action;
  }
};
} // namespace sp
