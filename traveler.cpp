#include "traveler.h"

void Traveler::add_city(City city) {
    destinations.push_back(city);
} 

City Traveler::get_city(int i) {
    return destinations[i];
}

int Traveler::cities() {
    return destinations.size();
}