#include "resource.h"

bees::Resource::Resource(int nector, int pollen):nector_(nector),pollen_(pollen){
}
void bees::Resource::deposit_nector(int amt) {
    std::unique_lock<std::mutex> l(lock);
    nector_+=amt;
}
void bees::Resource::deposit_pollen(int amt) {
    std::unique_lock<std::mutex> l(lock);
    pollen_+=amt;
}
int bees::Resource::fetch_resource() {
    std::unique_lock<std::mutex> l(lock);
    if(nector_<1 or pollen_<1){
        return 0;
    }
    else{
        nector_--;
        pollen_--;
        return 1;
    }
}