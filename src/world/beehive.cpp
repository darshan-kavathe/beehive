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
using std::unique_lock;

BeeHive::BeeHive(int seed, int drones, int nector_workers, int pollen_workers):
        seed_(seed), drones_(drones), nector_workers_(nector_workers),
        pollen_workers_(pollen_workers),lg_(std::cout),rng_(seed),active_(false),field_(),
        bag(0,0),temp_id(1)
        //,chamber_()
//
{
    // TODO how to make sure queen is born first
    /*
    bee_vec. push_back (make_shared<Queen>(temp_id, "Queen",*this));
    for ( int i =0; i <drones_; ++ i ) {
        bee_vec. push_back (std::make_shared<Drone>(temp_id, "Drone",*this));
        temp_id++;
    }*/
    for ( int i =0; i <nector_workers_; ++ i ) {
        bee_vec. push_back (make_shared<Worker>("NECTOR", rng_.roll_dice(0,6),temp_id, "Worker",*this));
        temp_id++;
    }
    for ( int j =0; j <pollen_workers_; ++ j ) {
        bee_vec. push_back (make_shared<Worker>("POLLEN", rng_.roll_dice(0,6),temp_id, "Worker",*this));
        temp_id++;
    }
}

void BeeHive::dead(Bee* b){
    //std::unique_lock<std::mutex> l(lock);
    //dead_pool.push_back(b);
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

void BeeHive::give_birth(){
    int tmp_children = rng_.roll_dice(1,5);
    for (int i=0; i<tmp_children; i++){
        int tmp_role = rng_.roll_dice(1,10);
        if (tmp_role<=6){
            bee_vec. push_back (make_shared<Drone>(temp_id, "Drone",*this));
        }
        else if(tmp_role<=8){
            bee_vec. push_back (make_shared<Worker>("NECTOR", rng_.roll_dice(0,6),temp_id, "Worker",*this));
        }
        else{
            bee_vec. push_back (make_shared<Worker>("POLLEN", rng_.roll_dice(0,6),temp_id, "Worker",*this));
        }
        temp_id++;
    }
}