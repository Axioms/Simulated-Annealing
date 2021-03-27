#include <iostream>
#include <math.h> 
#include "slidingPuzzle.h"
#include "slidingPuzzleState.h"

slidingPuzzle::slidingPuzzle() {

}

bool slidingPuzzle::simulated_annealing(spState current_state) {
    int iters = 0;
    double init_temp = 2500;
    double final_temp = 0.001;
    double alpha = 0.9999;

    double current_temp = init_temp;
    //spState current_state;
    current_state.randomize_sate(100);
    spState solution;
    //solution.print_state();
    //std::cout << "Cost: " << current_state.get_cost() << std::endl;

    while (current_temp > final_temp && false == (solution.get_state() == current_state.get_state())) {
        spState neigbor = current_state.get_neighbor();

        int cost_diff =  neigbor.get_cost() - current_state.get_cost();

        double K = exp(-cost_diff / current_temp);
        double l = ((double) rand() / (RAND_MAX));
        //std::cout << std::endl << "l: " << l << std::endl << "K: " << K << std::endl << (l<K?"state was accepted":"state was regected") << std::endl;

        if (cost_diff < 0) {
            current_state = neigbor;
            //neigbor.print_state();
            //std::cout << "Cost: " << current_state.get_cost() << std::endl;
            //std::cout << std::endl << "l: " << l << std::endl << "K: " << K << std::endl << (l<K?"state was accepted":"state was regected") << std::endl;
        }
        else if (l < K) {
            current_state = neigbor;
            //neigbor.print_state();
            //std::cout << "Cost: " << current_state.get_cost() << std::endl;
            //std::cout << std::endl << "l: " << l << std::endl << "K: " << K << std::endl << (l<K?"state was accepted":"state was regected") << std::endl;
        }
        //std::cout << "cost diff: " << cost_diff << std::endl;
        iters++;
        current_temp *= alpha;
    }
    //std::cout << iters << std::endl;
    if (current_state.get_cost() == 0) {
        current_state.print_state();
    }
    return current_state.get_cost() == 0;
}