//
// Created by roki on 2025-04-09.
//

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <condition_variable>
#include <string>
#include <iostream>
#include <array>
#include <thread>
#include <mutex>

#include "vehicle.h"

#define SIZE 8

class Warehouse {
  static constexpr size_t MIN_SIZE = 7;
  int head{0};
  int tail{0};

  size_t capacity{0};
  size_t max_capacity{SIZE};

  std::array<Vehicle *, SIZE> vehicles;

  std::mutex mutex;
  std::condition_variable cv;

public:
  explicit Warehouse() {
    static_assert(SIZE > MIN_SIZE, "Minimum size is too small");
  }

  void push(Vehicle *vehicle) {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [&] {
      return capacity != max_capacity;
    });

    if (capacity == max_capacity) {
      head = (head + 1) % max_capacity;
    } else {
      capacity++;
    }

    vehicles[tail] = vehicle;
    vehicles[tail]->increase_id();
    tail = (tail + 1) % max_capacity;

    cv.notify_one();
  }

  void pop(void) {
    std::unique_lock<std::mutex> lock(mutex);

    cv.wait(lock, [&] {
      return capacity != 0;
    });

    Vehicle *vehicle = std::move(vehicles[head]);
    std::cout << "ID: " << vehicle->get_id() << std::endl;
    std::cout << "Type: " << vehicle->get_vehicle_type() << std::endl;
    std::cout << "Model: " << vehicle->get_vehicle_model() << std::endl;
    std::cout << "Max.: " << ((vehicle->get_vehicle_type() == "Car") ? "Passenger " : "Weight ") << vehicle->
        get_vehicle_capacity() << std::endl;


    head = (head + 1) % max_capacity;
    capacity--;

    cv.notify_one();
  }
};

#endif //WAREHOUSE_H
