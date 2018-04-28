#ifndef BEEHIVE_H
#define BEEHIVE_H
#include "../util/random.h"
#include "../bees/bee.h"
#include "flower_field.h"
#include "queens_chamber.h"
#include "../util/logger.h"
#include <deque>
#include "memory"

using std::deque;
using std::string;
using world::Flower_field;
using world::Queens_chamber;
using util::logger;
using util::random;
using bees::Bee;
using std::vector;
using std::shared_ptr;
using std::cout;
using bees::Resource;
namespace world{
    class BeeHive{
    public:
        BeeHive(int seed, int drones, int nector_workers, int pollen_workers);
        ~BeeHive();
        BeeHive(const BeeHive&)= delete;
        BeeHive& operator=(const world::BeeHive&)=delete;
        void start();
        void end();
        //void display(string& msg);
        friend std::ostream& operator<<(std::ostream& os, const BeeHive& other);
        logger lg_;
        vector <shared_ptr<my_thread> > bee_vec {};
        bool active_;
        Flower_field field_;
        Resource bag;

    private:
        int seed_;
        int drones_;
        int nector_workers_;
        int pollen_workers_;
        //deque<bees::Bee*> beeq_;
        //Queens_chamber* chamber_;
        //std::ostream& os;
        util::random rng_;

        //std::ostream &os;

    };
}
#endif