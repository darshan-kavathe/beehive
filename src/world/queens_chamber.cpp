#include "queens_chamber.h"
#include "../bees/drone.h"
#include "beehive.h"

using world::Queens_chamber;
using bees::Drone;
using std::unique_lock;
using std::lock_guard;
Queens_chamber::Queens_chamber():drone_cond{},drone_mutex{}{

}

void Queens_chamber::enter(Drone* drone){
    drone->hive_.lg_.log("*QC* DRONE #"
                           +std::to_string(drone->getId())
                           +" enters chamber");
    unique_lock<mutex> ul{drone_mutex};
    drone_vec.push_back(drone);

    drone_cond.wait(ul,[this,drone]{
        return (((drone_vec.front())->getId())==(drone->getId())&& queen_ready);});
    drone_vec.pop_front();
    /*
    (drone->hive_).lg_.log("*QC* Queen mates with DRONE #"
                            +std::to_string(drone->getId())
                            );*/
}
void Queens_chamber::exit(Drone* drone) {
    (drone->hive_).lg_.log("*QC* DRONE #"
                          +std::to_string(drone->getId())
                           +" leaves chamber"
    );
}

void Queens_chamber::queen_try() {
    {
        unique_lock<mutex> ul{drone_mutex2};
        queen_ready = true;
    }
    drone_cond.notify_all();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    {
        unique_lock<mutex> ul{drone_mutex2};
        queen_ready = false;
    }
}

bool Queens_chamber::drone_there(){
    {
        unique_lock<mutex> ul{drone_mutex};
        return drone_vec.size()!=0;
    }
}
