#include "worker.h"
#include "../world/beehive.h"

using bees::Worker;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

Worker::Worker(const std::string &type, const unsigned int amt, const unsigned int id, const std::string &role,
               BeeHive* hive):
        type_(type), amt_(amt), Bee(id,role,hive){
        hive_->lg_.log("*B* "+ this->get_type()
                       +"("+std::to_string(this->get_amt())+")"
                       +" WORKER #"
                       +std::to_string(this->getId())
                       +" is born\n");
}

void Worker::run() {
    while(hive_->active_){
        ((*hive_).field_).enter(this);
        sleep_for(milliseconds(amt_*1000));
        ((*hive_).field_).exit(this);
    }
}

const std::string Worker::get_type() {
    return type_;
}
const unsigned int Worker::get_amt() {
    return amt_;
}

std::ostream& operator<<(std::ostream& os, const Worker& other){
    //os<<other.type_<<" worker ("<<other.amt_<<") #"<<other.getId();
    return os;
}