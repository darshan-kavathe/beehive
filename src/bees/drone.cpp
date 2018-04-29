#include "drone.h"
#include "../world/beehive.h"

using bees::Drone;

Drone::Drone(const unsigned int id, const std::string& role, BeeHive& hive):
        Bee(id,role,hive){
    hive_.lg_.log("*B* DRONE #"
                  +std::to_string(this->getId())
                  +" is born");
}
void Drone::run(){/*
    while(hive_.active_) {
        ((hive_).chamber_).enter(this);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        ((hive_).chamber_).exit(this);
        hive_.lg_.log("*B* DRONE #"
                      +std::to_string(this->getId())
                      +" is perished!");

    }*/
}