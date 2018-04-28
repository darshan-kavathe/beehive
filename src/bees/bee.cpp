#include "bee.h"

using bees::Bee;

Bee::Bee(const unsigned int id, const std::string& role, BeeHive& hive):
id_(id),role_(role),hive_(hive){
}

unsigned int bees::Bee::getId() const {
    return id_;
}

std::string bees::Bee::getRole() const {
    return role_;
}

Bee::~Bee(){}

std::ostream& operator<<(std::ostream& os, const Bee& other){
    os<<"*B* ";
    return os;
}