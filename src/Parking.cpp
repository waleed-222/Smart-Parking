/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 08:40:00 PM CET 2025
brief:
*/
#include "Parking.hpp"
#include "Display.hpp"
#include "TCP.hpp"
#include "TcpConverter.hpp"

namespace sp {
template <typename T, typename U>
Parking<T, U>::Parking(T conv, std::unique_ptr<Input<U>> &in, Display &monitor)
    : converter(conv), input(in), updater(monitor) {
  t1_executer = std::thread([this] {
    while (!quit) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      if (converter.convert(this->input->get()) == Actions::PARK_FIRST) {
        this->park(Floors::FIRST);
      } else if (converter.convert(this->input->get()) ==
                 Actions::PARK_SECOND) {
        this->park(Floors::SECOND);
      } else if (converter.convert(this->input->get()) ==
                 Actions::UNPARK_FIRST) {
        this->unpark(Floors::FIRST);
      } else if (converter.convert(this->input->get()) ==
                 Actions::UNPARK_SECOND) {
        this->unpark(Floors::SECOND);
      } else {
      }
      this->updater.update(parkinglot_available);
    }
  });
}
template <typename T, typename U> Parking<T, U>::~Parking() {
  if (t1_executer.joinable()) {
    t1_executer.join();
  }
}

template <typename T, typename U> void Parking<T, U>::park(Floors floor) {
  if (floor < Floors::NUM_FLOORS) {
    if (parkinglot_available[floor] > 0) {
      parkinglot_available[floor]--;
    }
  }
}
template <typename T, typename U> void Parking<T, U>::unpark(Floors floor) {
  if (floor < Floors::NUM_FLOORS) {
    if (parkinglot_available[floor] < PARKING_LOT_SIZE) {
      parkinglot_available[floor]++;
    }
  }
}

template class Parking<TcpConverter, Key>; // move to client

} // namespace sp