//
// Created by roki on 2025-04-09.
//

#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Vehicle {
    static constexpr int MIN_RAND = 1000;
    uint32_t unique_id;

protected:
    Vehicle() {
        srand(time(nullptr));
        unique_id = (rand() % (MIN_RAND + 1)) + MIN_RAND;
    }

    virtual ~Vehicle(void) = default;

public:
    [[nodiscard]] virtual std::string get_vehicle_type(void) const {
        return "";
    }

    [[nodiscard]] virtual std::string get_vehicle_model(void) const {
        return "";
    }

    [[nodiscard]] virtual int get_vehicle_capacity(void) const {
        return 0;
    };

    [[nodiscard]] uint32_t get_id(void) const {
        return unique_id;
    }

    void increase_id(void) {
        unique_id++;
    }
};

class Car : public Vehicle {
    std::string type{"Car"};
    std::string model{"V40"};
    int passengers{5};

public:
    [[nodiscard]] std::string get_vehicle_type(void) const override {
        return type;
    }

    [[nodiscard]] std::string get_vehicle_model(void) const override {
        return model;
    }

    [[nodiscard]] int get_vehicle_capacity(void) const override {
        return passengers;
    }

    ~Car() override = default;
};

class Truck : public Vehicle {
    std::string type{"Truck"};
    std::string model{"Vera"};
    int weight{500};

public:
    [[nodiscard]] std::string get_vehicle_type(void) const override {
        return type;
    }

    [[nodiscard]] std::string get_vehicle_model(void) const override {
        return model;
    }

    [[nodiscard]] int get_vehicle_capacity(void) const override {
        return weight;
    }

    ~Truck() override = default;
};


#endif //VEHICLE_H
