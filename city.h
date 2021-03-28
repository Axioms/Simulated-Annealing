#pragma once
#include <string>

class City {
    public:
        City();
        City(int x_val, int y_val);
        int get_x();
        int get_y();
        double distance(City neighbor);
        std::string city_cords_to_string();
    private:
        int x;
        int y;
};