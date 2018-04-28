#ifndef BEE_H
#define BEE_H

#include <iostream>

#include "../util/my_thread.h"
#include "../util/logger.h"
#include "../bees/resource.h"

using util::my_thread;

namespace world{
class BeeHive;}

using world::BeeHive;
namespace bees {
    class Bee:public my_thread{
    public:
        //Constructor of bees
        Bee(const unsigned int id_, const std::string& role_, BeeHive* hive_);
        //Destructor of bees
        ~Bee();
        //delete copy constructor
        Bee(Bee& b)= delete;
        //assignment operator is not valid
        Bee&operator=(Bee&b)=delete;
        //return role
        std::string getRole() const;
        //return id
        unsigned int getId() const;
        // run the bee
        // beehive pointer
        // print method
        BeeHive* hive_;
        friend std::ostream& operator<<(std::ostream& out, const Bee& other);
    private:
        //role of bee
        const std::string& role_;
        //ID of bee
        const unsigned int id_;
        //pointer to its own BeeHive

    };
}
#endif