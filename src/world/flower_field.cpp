#include "flower_field.h"
#include "beehive.h"


using world::Flower_field;
using std::unique_lock;
using std::lock_guard;

constexpr int MAX_RUNNING = 1;
Flower_field::Flower_field():worker_cond{},worker_mutex{}{
    //constexpr int MAX_RUNNING = 10;
int current_running =0;
}

void Flower_field::enter(Worker* worker) {
    unique_lock<mutex> ul{worker_mutex};
    worker_cond.wait(ul,[this](){return current_running<MAX_RUNNING;});
    ++current_running;
    worker->hive_->lg_.log("*FF* "+ worker->get_type()
                           +"("+std::to_string(worker->get_amt())+")"
                           +" WORKER #"
                           +std::to_string(worker->getId())
                           +" enters field");
}
void Flower_field::exit(Worker *worker) {
    {
    lock_guard<mutex> lguard{worker_mutex};
    --current_running;}
    //lock_guard.unlock();
    worker_cond.notify_one();
    worker->hive_->lg_.log("*FF* "+ worker->get_type()
                           +"("+std::to_string(worker->get_amt())+")"
                           +" WORKER #"
                           +std::to_string(worker->getId())
                           +" leaves field");
}