#include <algorithm>
#include <iostream>
#include "routePlanner.h"

RoutePlanner::RoutePlanner(Traveler traveler_init) {
    traveler = traveler_init;
    route.resize(traveler.cities());
    distance = 0;
}

RoutePlanner::RoutePlanner(route_type route_init, Traveler traveler_init) {
    route = route_init;
    traveler = traveler_init;
    route.resize(traveler.cities());
    distance = 0;
}

RoutePlanner::route_type RoutePlanner::get_route() {
    return route;
}

Traveler RoutePlanner::get_traveler() {
    return traveler;
}

void RoutePlanner::generate_route() {
    for (int city_index = 0; city_index < traveler.cities(); city_index++) {
        set_city(city_index, traveler.get_city(city_index));
    }
    std::random_shuffle(route.begin(), route.end());
}

City RoutePlanner::get_city(int i) {
    return route[i];
}

void RoutePlanner::set_city(int i, City city) {
    route[i] = city;
    distance = 0;
}

int RoutePlanner::get_distance() {
    if (true) {
        int route_distance = 0;
        for (int i = 0; i < get_route_length(); i++) {
            City from = get_city(i);
            City destination;
            if(i+1 < get_route_length()) {
                destination = get_city(i+1);
            }
            else {
                destination = get_city(0);
            }

            route_distance += from.distance(destination);
        }
        distance = route_distance;
    }
    return distance;
}

int RoutePlanner::get_route_length() {
    return route.size();
}

std::string RoutePlanner::route_to_string() {
    std::string route_string = "start -> ";
    for (int i=0; i<get_route_length()-1; i++) {
        route_string += get_city(i).city_cords_to_string() + " -> ";
    }

    route_string += get_city(get_route_length()-1).city_cords_to_string() + " -> end";
    return route_string;
}