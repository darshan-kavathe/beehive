
#include <iostream>
#include <chrono>
#include <thread>
#include "world/beehive.h"

using std::chrono::milliseconds;
using std::this_thread::sleep_for;

int main(int argc, char* argv[]) {
    // check number of arguments
    if (argc<6){
        std::cerr<<"Usage: bee_main seed seconds drones nectar_workers pollen_workers"<<std::endl;
        return 0;
    }
    else {
        //Parse input to int
        int seed = std::atoi(argv[1]);
        int seconds = std::atoi(argv[2]);
        int drones = std::atoi(argv[3]);
        int nector_workers = std::atoi(argv[4]);
        int pollen_workers = std::atoi(argv[5]);
        std::cout<<seed<<seconds<<drones<<nector_workers<<pollen_workers;
        world::BeeHive hive_(seed, drones, nector_workers, pollen_workers);
        hive_.start();
        sleep_for(milliseconds(seconds*1000));
        hive_.end();
        // start  instance
        //new world::Beehive(seed, seconds, drones, nectar_workers, pollen_workers);
        // do you need to join or delete this instance??
    }
    return 0;
}

