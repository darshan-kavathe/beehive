#include "queen.h"
#include "../world/beehive.h"

using bees::Queen;

Queen::Queen(const unsigned int id, const std::string& role, BeeHive& hive):
        Bee(id,role,hive){
        hive_.lg_.log("*B* QUEEN #"
                      +std::to_string(this->getId())
                      +" is born");

}
void Queen::run() {/*
    while (hive_.active_) {
        if (hive_.chamber_.drone_there()) {
            if (hive_.bag.fetch_resource()) {
                hive_.chamber_.queen_try();
                hive_.give_birth();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }*/
}