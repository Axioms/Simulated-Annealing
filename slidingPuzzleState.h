#pragma once
#include <vector>

class spState
{
    public:
        typedef std::vector<std::vector<int>> puzzle_state;
        spState();
        spState(puzzle_state state);
        ~spState();
        void print_state();
        void randomize_sate(int iter);
        puzzle_state get_state();
        int get_number_of_neighbors();
        std::vector<spState> get_neighbors();
        spState get_neighbor();
        void swap(int row, int col);
        int get_cost();
        friend bool operator==(const spState &stateOne, const spState &stateTwo);

    private:
        puzzle_state current_sate;
        struct Cur
        {
            int row;
            int col;
        };
        Cur cur;
};