#ifndef RESOURCE_H
#define RESOURCE_H

#include <mutex>

namespace bees{
    class Resource{
    public:
        Resource(int nector_, int pollen);
        int nector_;
        int pollen_;
        std::mutex lock;
        void deposit_nector(int amt);
        void deposit_pollen(int amt);
        int fetch_resource();
    };
}
#endif