#pragma once
#include <vector>
#include <string>
#include "city.h"
#include "traveler.h"

class RoutePlanner {
    public:
        typedef std::vector<City> route_type;
        RoutePlanner(Traveler traveler_init);
        RoutePlanner(route_type route_init, Traveler traveler_init);
        route_type get_route();
        Traveler get_traveler();
        void generate_route();
        City get_city(int i);
        void set_city(int i, City city);
        int get_distance();
        int get_route_length();
        std::string route_to_string();
    private:
        route_type route;
        int distance;
        Traveler traveler;
};