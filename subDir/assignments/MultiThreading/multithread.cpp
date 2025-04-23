#include <condition_variable>
#include <iostream>
#include <mutex>
#include <stdint.h>
#include <string>
#include <thread>

#define MINIMUN_CAPACITY 8
#define MINIMUN_CONSUMERS 2

// Set CAPACITY TO 8 or above, with inline command '-DCAPACITY=[INSERT_NUMBER]'
#ifdef CAPACITY
#if CAPACITY < MINIMUN_CAPACITY
#error Warehouse capacity below minimum! (Set 'CAPACITY' above 7.)
#endif
#else
#error No capacity set, please set 'CAPACITY' to 8 or above.
#endif

static uint64_t GLOBAL_ID_INDEX{1001};
static constexpr uint32_t RANDOM_MODULUS_VALUE{1000};
static uint16_t CONSUMER_COUNT{1};

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
  Vehicle(const std::string &_model, const std::string &_type)
      : model{_model}, type{_type} {
    id = GLOBAL_ID_INDEX;
    GLOBAL_ID_INDEX++;
  };

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
  Truck(uint32_t _max_load, const std::string &_model)
      : max{_max_load}, Vehicle(_model, "Truck") {}

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
      : max{_max_passengers}, Vehicle(_model, "Car") {}

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

  std::mutex MTX;
  std::condition_variable CONDITION_VAR;

public:
  Warehouse(const Warehouse &) = delete;
  Warehouse &operator=(const Warehouse &) = delete;
  Warehouse() = default;

  void pop(std::shared_ptr<Vehicle> &_var) {
    std::unique_lock<std::mutex> lock{MTX};

    while (count == 0) {
      CONDITION_VAR.wait(lock);
    }

    if (count > 0) {
      _var = array[tail];

      // increments tail, loops if reaches end.
      tail = (tail + 1) % size;

      count--;
    } else {
      ;
    }

    lock.unlock();
    CONDITION_VAR.notify_all();
  }

  void push(std::shared_ptr<Vehicle> _value) {
    std::unique_lock<std::mutex> lock{MTX};

    // if head catches tail. (Sleeps when full.)
    while (head == tail && count > 0) {
      CONDITION_VAR.wait(lock);
    }

    array[head] = _value;

    // increments tail if head catches tail. (Theoretically never happens?)
    if (head == tail && count > 0) {
      if (tail >= size - 1) {
        tail = 0;
      } else {
        tail++;
      }
    }

    // increments head, loops if reaches end.
    head = (head + 1) % size;

    // increments count, not if more than size.
    if (count < size) {
      count++;
    }

    lock.unlock();
    CONDITION_VAR.notify_all();
  }
};

/**
 * @brief Producer thread, randomly pushes Truck or Car.
 *
 * @param _warehouse
 */
static void producer(std::shared_ptr<Warehouse> _warehouse) {
  while (1) {
    if ((rand() % 2 == 0)) {
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

    // faster than single consumer.
    std::this_thread::sleep_for(
        std::chrono::milliseconds((rand() % RANDOM_MODULUS_VALUE / 2)));
  }
}

/**
 * @brief Consumer thread. Randomly pops and print.
 *
 * @param _warehouse
 */
static void consumer(std::shared_ptr<Warehouse> _warehouse) {
  static std::mutex csmr_mtx;
  csmr_mtx.lock();
  uint16_t index = CONSUMER_COUNT;
  CONSUMER_COUNT++;
  csmr_mtx.unlock();

  while (1) {
    std::shared_ptr<Vehicle> test = NULL;
    _warehouse->pop(test);
    csmr_mtx.lock();
    std::cout << "======== Consumer " << index << " ========" << std::endl;
    test->print();
    std::cout << std::endl;
    csmr_mtx.unlock();

    std::this_thread::sleep_for(
        std::chrono::milliseconds(rand() % RANDOM_MODULUS_VALUE));
  }
}

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cout
        << "No argument or too many arguments found for amount of comsumers."
        << std::endl
        << "Set amount of consumers by adding a argument to the program. ('"
        << MINIMUN_CONSUMERS << "' or above)" << std::endl
        << "Exiting..." << std::endl;

    exit(1);
  } else if (atoi(argv[1]) < MINIMUN_CONSUMERS) {
    std::cout << "Argument value incorrect." << std::endl
              << "Provide number '" << MINIMUN_CONSUMERS << "' or above."
              << std::endl
              << "Exiting..." << std::endl;

    exit(1);
  } else {
    srand(time(NULL));

    // Warehouse buffer
    std::shared_ptr<Warehouse> buffer = NULL;
    buffer = std::make_shared<Warehouse>();

    // Consumer
    for (uint8_t i = 0; i < atoi(argv[1]); i++) {
      std::thread thread{consumer, buffer};
      thread.detach();
    }

    // Producer
    std::thread thread{producer, buffer};
    thread.join();
  }

  return 0;
}
