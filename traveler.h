#pragma once
#include <vector>
#include "city.h"

class Traveler {
    public:
        void add_city(City city);
        City get_city(int i);
        int cities();
    private:
        std::vector<City> destinations;
};