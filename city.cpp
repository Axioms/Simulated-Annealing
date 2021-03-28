#include <iostream>
#include <math.h>
#include "city.h"

City::City() {
    x = rand() % 201;
    y = rand() % 201;
}

City::City(int x_val, int y_val) {
    x = x_val;
    y = y_val;
}

int City::get_x() {
    return x;
}

int City::get_y() {
    return y;
}

double City::distance(City city) {
    int x_distance = abs(get_x() - city.get_x());
    int y_distance = abs(get_y() - city.get_y());

    return sqrt((x_distance * x_distance) + (y_distance * y_distance));
}

std::string City::city_cords_to_string() {
    std::string cords = "( " + std::to_string(get_x()) + ", " + std::to_string(get_y()) + " )"; 
    return cords;
}