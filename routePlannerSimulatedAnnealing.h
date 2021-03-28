#pragma once
#include "routePlanner.h"
#include "traveler.h"
#include "city.h"

class RPSA {
    public:
        RPSA(int num_of_cities);
        void generate_new_city_list(int num_of_cities);
        void run_sa();

    private:
        double accept_chance(int e, int new_e, double temp);
        Traveler traveler;

};