#ifndef QUEENS_CHAMBER_H
#define QUEENS_CHAMBER_H

#include <deque>
#include "../util/my_thread.h"
#include <mutex>
#include <condition_variable>
#include "../bees/drone.h"
#include "../bees/queen.h"

using std::shared_ptr;
using util::my_thread;
using std::deque;
using std::mutex;
using std::condition_variable;
using bees::Drone;
using bees::Queen;
namespace world{
    class Queens_chamber{
    public:
        Queens_chamber();
        deque <Drone*> drone_vec;
        mutex drone_mutex;
        mutex drone_mutex2;
        condition_variable drone_cond;
        void enter(Drone* drone);
        void exit(Drone* drone);
        void queen_try();
        bool queen_ready;
        bool drone_there();
    };
}
#endif
