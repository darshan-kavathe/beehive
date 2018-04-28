#include "worker.h"
#include "../world/beehive.h"

using bees::Worker;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

Worker::Worker(const std::string &type, const unsigned int amt, const unsigned int id, const std::string &role,
               BeeHive& hive):
        type_(type), amt_(amt), Bee(id,role,hive){
        hive_.lg_.log("*B* "+ this->get_type()
                       +"("+std::to_string(this->get_amt())+")"
                       +" WORKER #"
                       +std::to_string(this->getId())
                       +" is born");
}

void Worker::run() {
    while(hive_.active_){
        ((hive_).field_).enter(this);
        /*
        (hive_).lg_.log("*FF* "+ get_type()
                       +"("+std::to_string(get_amt())+")"
                       +" WORKER #"
                       +std::to_string(getId())
                       +" enters field");*/
        sleep_for(milliseconds(1000*amt_));
        /*
        (hive_).lg_.log("*FF* "+ get_type()
                         +"("+std::to_string(get_amt())+")"
                         +" WORKER #"
                         +std::to_string(getId())
                         +" leaves field");*/
        ((hive_).field_).exit(this);
        if (type_=="POLLEN"){
            (hive_).bag.deposit_pollen(amt_);
            (hive_).lg_.log("*BH* "+ get_type()
                            +"("+std::to_string(get_amt())+")"
                            +" WORKER #"
                            +std::to_string(getId())
                            +" deposits resources");
        }
        if (type_=="NECTOR"){
            (hive_).bag.deposit_nector(amt_);
            (hive_).lg_.log("*BH* "+ get_type()
                            +"("+std::to_string(get_amt())+")"
                            +" WORKER #"
                            +std::to_string(getId())
                            +" deposits resources");
        }
        if((hive_).bag.fetch_resource()){
            (hive_).lg_.log("*W* "+ get_type()
                            +"("+std::to_string(get_amt())+")"
                            +" WORKER #"
                            +std::to_string(getId())
                            +" is refueling");
        }
        else{
            (hive_).lg_.log("*BH* "+ get_type()
                            +"("+std::to_string(get_amt())+")"
                            +" WORKER #"
                            +std::to_string(getId())
                            +" Perished!");
            break;
        }

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