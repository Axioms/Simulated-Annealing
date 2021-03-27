#include <iostream>
#include "slidingPuzzle.h"
#include "slidingPuzzleState.h"

int main()
{
    // init random
    srand(time(NULL));
    slidingPuzzle a;
    spState aa;
    int trys = 0;
    aa.randomize_sate(1);
    bool is_complete = false;
    while (!is_complete) {
        is_complete = a.simulated_annealing(aa);
        //std::cout << "waiting...\n";
        //std::cin.ignore();
        trys++;
    }
    aa.print_state();
    std::cout << "times attempted: " << trys << std::endl;
/* 
    std::cout << "test" << std::endl;
    spState sp_state;

    sp_state.print_state();
    std::cout << sp_state.get_number_of_neighbors() << std::endl;
    sp_state.randomize_sate(1000);
    sp_state.print_state();
    std::cout << sp_state.get_number_of_neighbors() << std::endl;
    sp_state.randomize_sate(1000);
    sp_state.print_state();
    std::cout << sp_state.get_number_of_neighbors() << std::endl;
    sp_state.randomize_sate(1000);
    sp_state.print_state();
    std::cout << sp_state.get_number_of_neighbors() << std::endl;
    sp_state.randomize_sate(1000);
    sp_state.print_state();

    std::cout << sp_state.get_number_of_neighbors() << std::endl;
    std::vector<spState> neigbors = sp_state.get_neighbors();
    std::cout << "c==============================8" << std::endl;
    //int size_of_neigbors = (sizeof((neigbors)) / sizeof((neigbors)[0]));
    //std::cout << size_of_neigbors << std::endl;

    for (int i = 0; i < sp_state.get_number_of_neighbors(); i++)
    {
        neigbors[i].print_state();
        std::cout << "Cost: " << neigbors[i].get_cost() << std::endl;
    }
 */
    return 0;
}