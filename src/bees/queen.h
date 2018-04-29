#ifndef QUEEN_H
#define QUEEN_H

#include "bee.h"
#include <iostream>
#include <exception>
#include <thread>

namespace bees {
    class Queen: public Bee{
    public:
        Queen(const unsigned int id, const std::string& role, BeeHive& hive);

        void run();
    };
}
#endif