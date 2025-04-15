#include "vehicle.h"
#include "warehouse.h"

Warehouse _warehouse;
Car _car;
Truck _truck;

void push() {
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        int rand_num = rand() % 2;

        if (rand_num == 0) {
            _warehouse.push(&_car);
        } else {
            _warehouse.push(&_truck);
        }
    }
}

void pop(int consumer_number) {
    for (int i = 0; i < 10; i++) {
        std::cout << "========== Consumer " << consumer_number << " ==========" << std::endl;
        _warehouse.pop();
    }
}

int main(void) {
    std::thread vehicle_thread_pop(pop, 1);
    std::thread vehicle_thread_push(push);

    vehicle_thread_push.join();
    vehicle_thread_pop.join();
    return 0;
}
