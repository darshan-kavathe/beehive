#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <exception>
#include <thread>
#include "bee.h"


namespace bees {
    class Worker: public Bee{
    public:
        Worker(const std::string& type, const unsigned int amt, const unsigned int id, const std::string& role, BeeHive& hive);
        void run();
        const std::string get_type();
        const unsigned int get_amt();
        friend std::ostream& operator<<(std::ostream& os, const Worker& other);
        bool is_dead;

    private:
        const std::string type_;
        const unsigned int amt_;
    }
    ;
}
#endif