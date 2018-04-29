#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <exception>
#include <thread>
#include "bee.h"

namespace bees {
    class Drone: public Bee{
    public:
        Drone(const unsigned int id, const std::string& role, BeeHive& hive);
        void run();
        bool is_dead;
    };
}
#endif