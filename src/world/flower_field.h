#ifndef FLOWER_FIELD_H
#define FLOWER_FIELD_H

#include "../bees/worker.h"
#include <mutex>
#include <condition_variable>

using bees::Worker;
using std::mutex;
using std::condition_variable;

namespace world{
class Flower_field{
    public:
        Flower_field();
        int current_running;
        mutex worker_mutex;
        condition_variable worker_cond;
        void enter(Worker* worker);
        void exit(Worker* worker);

    };
}
#endif
