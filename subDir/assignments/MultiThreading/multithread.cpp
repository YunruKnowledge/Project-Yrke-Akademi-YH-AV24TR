

#include <exception>
#include <iostream>
#include <stdint.h>
#include <string>

#include <condition_variable>
#include <mutex>
#include <thread>

#define MINIMUN_CAPACITY 8

// Set CAPACITY TO 8 or above, with inline command '-DCAPACITY=[INSERT_NUMBER]'
#ifdef CAPACITY
#if CAPACITY < MINIMUN_CAPACITY
#error Warehouse capacity below minimum! (Set 'CAPACITY' above 7.)
#endif
#else
#error No capacity set, please set 'CAPACITY' to 8 or above.
#endif

static uint64_t MINIMUM_ID{1001};
static constexpr uint32_t CONSUMER_INTERVAL_MS{1000};
static uint16_t CSMR_COUNT{1};
static uint8_t MINIMUM_CONSUMERS{2};

static std::mutex MTX;
static std::condition_variable CONDITION_VAR;

/**
 * @brief Vehicle, main class for cars and trucks.
 * Automatically generates ID.
 * Vitual Print() function.
 *
 */
class Vehicle {
  uint64_t id{0};
  std::string model;
  std::string type;

public:
  Vehicle() {
    id = MINIMUM_ID;
    MINIMUM_ID++;
  };

  void setProperties(const std::string &_model, const std::string &_type) {
    model = _model;
    type = _type;
  }

  uint64_t getId(void) { return id; }
  std::string getModel(void) { return model; }
  std::string getType(void) { return type; }

  virtual void print(void) {}
};

/**
 * @brief Truck, has property max (weight load). Inherits Vehicle.
 * overrides print().
 *
 */
class Truck : public Vehicle {
  uint32_t max;

public:
  Truck(uint32_t _max_load, const std::string &_model) : max{_max_load} {
    setProperties(_model, "Truck");
  }

  void print(void) override {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Model: " << getModel() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Max. load weight: " << max << std::endl;
  }
};

/**
 * @brief Car, has property max (passengers). Inherits Vehicle.
 * overrides print().
 *
 */
class Car : public Vehicle {
  uint16_t max;

public:
  Car(uint8_t _max_passengers, const std::string &_model)
      : max{_max_passengers} {
    setProperties(_model, "Car");
  }

  void print(void) override {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Model: " << getModel() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Max. passengers: " << max << std::endl;
  }
};

/**
 * @brief Warehouse uncopyable circular buffer class.
 * But forces push/producers & pop/consumers to wait when full or empty.
 * array CAPACITY is a macro.
 *
 */
class Warehouse {
  std::shared_ptr<Vehicle> array[CAPACITY];
  uint32_t size{CAPACITY};
  uint32_t head{0};
  uint32_t tail{0};
  uint32_t count{0};

public:
  Warehouse(const Warehouse &) = delete;
  Warehouse &operator=(const Warehouse &) = delete;
  Warehouse() = default;

  bool pop(std::shared_ptr<Vehicle> &_var) {
    std::unique_lock<std::mutex> lock{MTX};

    while (count <= 0) {
      CONDITION_VAR.wait(lock);
    }

    bool status{false};
    if (count > 0) {
      _var = array[tail];

      // increments tail, loops if reaches end.
      if (tail >= size - 1) {
        tail = 0;
      } else {
        tail++;
      }

      count--;
      status = true;
    } else {
      ;
    }

    lock.unlock();
    CONDITION_VAR.notify_all();
    return status;
  }

  bool push(std::shared_ptr<Vehicle> _value) {
    std::unique_lock<std::mutex> lock{MTX};

    // if head catches tail. (Sleeps when full.)
    while (head == tail && count > 0) {
      CONDITION_VAR.wait(lock);
    }

    bool status{true};
    array[head] = _value;

    // increments tail if head catches tail. (Theoretically never happens?)
    if (head == tail && count > 0) {
      if (tail >= size - 1) {
        tail = 0;
      } else {
        tail++;
      }
      status = false;
    }

    // increments head loops if reaches end.
    if (head >= size - 1) {
      head = 0;
    } else {
      if (head == tail && count > 0) {
        tail++;
      }
      head++;
    }

    // increments count, not if more than size.
    if (count < size) {
      count++;
    }

    lock.unlock();
    CONDITION_VAR.notify_all();
    return status;
  }

  void clear(void) {
    std::unique_lock<std::mutex> lock{MTX};

    head = 0;
    tail = 0;
    count = 0;

    lock.unlock();
    CONDITION_VAR.notify_one();
  }
};

/**
 * @brief Producer, randomly pushes Truck or Car.
 *
 * @param _warehouse
 */
static void producer(std::shared_ptr<Warehouse> _warehouse) {
  while (1) {

    if ((rand() % 10) >=
        5) { // randomly truck or car, [0-10] if > 4 then truck.
      std::shared_ptr<Truck> temp = NULL;
      temp = std::make_shared<Truck>((rand() % 16000 + 2000),
                                     "Ford Viola FF5. Trunk");
      _warehouse->push(temp);
    } else {
      std::shared_ptr<Car> temp = NULL;
      temp = std::make_shared<Car>(static_cast<uint8_t>(rand() % 8),
                                   "Revolt G6. 2660x Driver");
      _warehouse->push(temp);
    }

    // "randomly" - assuming random timing as well.
    std::this_thread::sleep_for(std::chrono::milliseconds(
        (rand() % CONSUMER_INTERVAL_MS) ));
  }
}

/**
 * @brief Consumer thread. Pops and print.
 *
 * @param _warehouse
 */
static void consumer(std::shared_ptr<Warehouse> _warehouse) {
  static std::mutex csmr_mtx;
  csmr_mtx.lock();
  uint16_t index = CSMR_COUNT;
  CSMR_COUNT++;
  csmr_mtx.unlock();

  while (1) {
    std::shared_ptr<Vehicle> test = NULL;
    _warehouse->pop(test);
    csmr_mtx.lock();
    std::cout << "======== Consumer " << index << " ========" << std::endl;
    test->print();
    std::cout << std::endl;
    csmr_mtx.unlock();

    // "at a time" - assuming no random timing like the producer.
    std::this_thread::sleep_for(
        std::chrono::milliseconds(CONSUMER_INTERVAL_MS));
  }
}

/**
 * @brief Allows setting for consumer amount of threads.
 *
 * @param _amount_csmr
 * @param _warehouse
 */
static void setConsumers(const uint8_t _amount_csmr,
                         std::shared_ptr<Warehouse> _warehouse) {
  if (_amount_csmr < MINIMUM_CONSUMERS) {
    throw std::range_error("Below minimum consumer amount.");
  } else {
    for (uint8_t i = 0; i < _amount_csmr; i++) {
      std::thread thread{consumer, _warehouse};
      thread.detach();
    }
  }
}

int main(void) {
  srand(time(NULL));

  // Warehouse buffer
  std::shared_ptr<Warehouse> buffer = NULL;
  buffer = std::make_shared<Warehouse>();

  // Producer
  std::thread thread{producer, buffer};
  thread.detach();

  // Consumer, first arg for amount, minimum 2.
  setConsumers(5, buffer);

  // sleep main thread for terminal output.
  while (1) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
  }

  return 0;
}
