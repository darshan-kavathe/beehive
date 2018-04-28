#include "beehive.h"
#include "sstream"
#include "../bees/drone.h"
#include "../bees/worker.h"
#include "../bees/queen.h"
#include "memory.h"

using std::ostream;
using world::BeeHive;
using util::logger;
using std::vector;
using bees::Bee;
using util::my_thread;
using bees::Drone;
using bees::Worker;
using bees::Queen;
using std::shared_ptr;
using std::make_shared;


BeeHive::BeeHive(int seed, int drones, int nector_workers, int pollen_workers):
        seed_(seed), drones_(drones), nector_workers_(nector_workers),
        pollen_workers_(pollen_workers),lg_(std::cout),rng_(seed),active_(false),field_(),
        bag(0,0)
//
{
    // TODO how to make sure queen is born first

    int temp_id =1;
    for ( int i =0; i <nector_workers_; ++ i ) {
        bee_vec. push_back (make_shared<Worker>("NECTOR", rng_.roll_dice(0,6),temp_id, "Worker",*this));
        temp_id++;
    }
    for ( int j =0; j <pollen_workers_; ++ j ) {
        bee_vec. push_back (make_shared<Worker>("POLLEN", rng_.roll_dice(0,6),temp_id, "Worker",*this));
        temp_id++;
    }
}

void BeeHive::start() {
    lg_.log("*BH* Beehive begins buzzing!");
    active_= true;
    for (auto & bee : bee_vec) {
        bee->start();
    }
}
void BeeHive::end() {

    active_=false;
    for (auto & bee : bee_vec) {
        bee->join();
    }
    lg_.log("*BH* Beehive stops buzzing!");
}

//void BeeHive::display(string &msg) {

//}
BeeHive::~BeeHive() {}
std::ostream& operator<<(std::ostream& os, const BeeHive& other){
    return os;
}

