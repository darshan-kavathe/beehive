#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <exception>
#include <thread>
#include "bee.h"

namespace bees {
    class Drone: bees::Bee{
    public:
        Drone();
        void run();
    };
}
#endif