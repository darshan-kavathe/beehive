#ifndef BEEHIVE_H
#define BEEHIVE_H
#include "../util/random.h"
#include "../bees/bee.h"
#include "flower_field.h"
#include "queens_chamber.h"
#include "../util/logger.h"
#include <deque>
#include "memory"
#include <mutex>
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
using std::mutex;
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
        //vector <shared_ptr<my_thread> > dead_pool {};
        void dead(Bee* b);
        std::mutex lock;
        int temp_id;
        //Queens_chamber chamber_;
        util::random rng_;
        void give_birth();

    private:
        int seed_;
        int drones_;
        int nector_workers_;
        int pollen_workers_;


    };
}
#endif