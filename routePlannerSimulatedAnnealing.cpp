#include <iostream>
#include <math.h>
#include "routePlannerSimulatedAnnealing.h"

RPSA::RPSA(int num_of_cities) {
    generate_new_city_list(num_of_cities);
}

void RPSA::generate_new_city_list(int num_of_cities) {
    Traveler temp;


    for (int i=0; i< num_of_cities; i++) {
        temp.add_city(City());
    }
    traveler = temp;
}

void RPSA::run_sa() {
    // Set initial temp
    double temp = 10000;

    // Cooling rate
    double coolingRate = 0.0003;

    RoutePlanner current_solution = RoutePlanner(traveler);
    

    current_solution.generate_route();

    std::cout << "Inital route distance is: " + std::to_string(current_solution.get_distance()) << std::endl;
    std::cout << "Inital Route: " << current_solution.route_to_string() << std::endl;

    RoutePlanner best = RoutePlanner(current_solution.get_route(), traveler);

    while (temp > 1) {
        RoutePlanner neighbor = RoutePlanner(current_solution.get_traveler());
        int rand_pos_one = (int) rand() % neighbor.get_route_length();
        int rand_pos_two = (int) rand() % neighbor.get_route_length();

        City city_swap_one = neighbor.get_city(rand_pos_one);
        City city_swap_two = neighbor.get_city(rand_pos_two);

        neighbor.set_city(rand_pos_two, city_swap_one);
        neighbor.set_city(rand_pos_one, city_swap_two);

        int e = current_solution.get_distance();
        int new_e = neighbor.get_distance();

        
/*         if (new_e < e) {
            std::cout << (new_e < e? "Better":"Worse") << " " << std::to_string(e) << " " << std::to_string(new_e) << std::endl;
        } */

        double ran = (double) rand() / (RAND_MAX);

        if (accept_chance(e, new_e, temp) > ran) {
            current_solution = neighbor;//RoutePlanner(neighbor.get_route(), neighbor.get_traveler());
        }

/*         if (current_solution.get_distance() < best.get_distance()) {
            std::cout << (current_solution.get_distance() < best.get_distance() ? "NEW BEST":"NOT BETTER") << " " << std::to_string(current_solution.get_distance()) << " " << std::to_string(best.get_distance()) << std::endl;
        } */
        if(current_solution.get_distance() < best.get_distance()) {
            best = current_solution; //RoutePlanner(current_solution.get_route(), current_solution.get_traveler());
        }

        temp *= 1-coolingRate;
    }

    std::cout << "Final route distance is: " + std::to_string(best.get_distance()) << std::endl;
    std::cout << "Final Route: " << best.route_to_string() << std::endl;

}

double RPSA::accept_chance(int e, int new_e, double temp) {
    if (new_e < e) {
        return 1.0;
    }

    else {
        return exp((e - new_e) / temp);
    }
}
