#include "slidingPuzzleState.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>

spState::spState()
{
    //current_sate = new int*[3];
    //current_sate[0] = new int[3];
    //current_sate[1] = new int[3];
    //current_sate[2] = new int[3];
    current_sate.resize(3);
    current_sate[0].resize(3);
    current_sate[1].resize(3);
    current_sate[2].resize(3);
    current_sate[0][0] = 1;
    current_sate[0][1] = 2;
    current_sate[0][2] = 3;
    current_sate[1][0] = 8;
    current_sate[1][1] = 0;
    current_sate[1][2] = 4;
    current_sate[2][0] = 7;
    current_sate[2][1] = 6;
    current_sate[2][2] = 5;
    cur.row = 1;
    cur.col = 1;
    /*     for (int i=1; i < 4; i++) {
        current_sate[i-1] = new int[3];
        for (int j =1; j<4 ; j++) {
            if(((3*(i-1)) + j)%9 == 0) {
                cur.row = i-1;
                cur.col = j-1;
            }
            current_sate[i-1][j-1] = ((3*(i-1)) + j)%9;
        }
    }
 */
}

spState::spState(puzzle_state state)
{

    current_sate = state;
    for (int i = 0; i < 3; i++)
    {
        //current_sate[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            if (current_sate[i][j] == 0)
            {
                cur.row = i;
                cur.col = j;
            }
        }
    }
    //current_sate = state;
}

spState::~spState()
{
    //free(current_sate);
}

void spState::print_state()
{
    puzzle_state state = current_sate;

    std::cout << "+----------+" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "|[";

        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] != 0)
            {
                std::cout << state[i][j];
            }
            else
            {
                std::cout << " ";
            }

            if (j != 2)
            {
                std::cout << ", ";
            }
            else if (j == 2)
            {
                std::cout << " ]|" << std::endl;
            }
        }
    }
    std::cout << "+----------+" << std::endl;
    std::cout << std::endl;
}

void spState::randomize_sate(int iter)
{
    int initial_state[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    for (int i = 0; i < iter; i++)
    {
        std::random_shuffle(std::begin(initial_state), std::end(initial_state));
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (initial_state[(3 * i) + j] == 0)
            {
                cur.row = i;
                cur.col = j;
            }

            current_sate[i][j] = initial_state[(3 * i) + j];
        }
    }
}

spState::puzzle_state spState::get_state()
{
    return current_sate;
}

int spState::get_number_of_neighbors()
{
    if ((cur.row == 0 || cur.row == 2) && (cur.col == 0 || cur.col == 2))
    {
        return 2;
    }
    else if (cur.row == 1 && cur.col == 1)
    {
        return 4;
    }
    else
    {
        return 3;
    }
}

std::vector<spState> spState::get_neighbors()
{
    int number_of_neighbors = get_number_of_neighbors();
    int created_neighbors = 0;
    std::vector<spState> neighbors;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((created_neighbors < number_of_neighbors) && (i == cur.row || j == cur.col) && (abs(i - cur.row) < 2 && abs(j - cur.col) < 2) && (i != cur.row || j != cur.col))
            {
                spState temp_sp = spState(current_sate);
                temp_sp.swap(i, j);
                neighbors.push_back(temp_sp);
                //std::cout << created_neighbors << " " << number_of_neighbors << std::endl;
                created_neighbors++;
            }
        }
    }
    return neighbors;
}

spState spState::get_neighbor()
{
    std::vector<spState> neighbors = get_neighbors();
    /* int best = 0;
    int best_cost = neighbors[0].get_cost();
    for (int i=0; i< neighbors.size(); i++) {
        if(neighbors[i].get_cost() <= best_cost) {
            best = i;
            best_cost = neighbors[i].get_cost();
        }
    }

    return neighbors[best]; */
    return neighbors[rand() % neighbors.size()];
}

void spState::swap(int row, int col)
{
    //swaped_state = current_sate;
    /* std::memcpy(next_state,current_sate, sizeof(current_sate)); */
    current_sate[cur.row][cur.col] = current_sate[row][col];
    current_sate[row][col] = 0;
    cur.row = row;
    cur.col = col;

    //free(swaped_state);
}

int spState::get_cost()
{
    int cost = 0;
    spState goal_obj;
    puzzle_state goal_state = goal_obj.get_state();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (goal_state[i][j] != current_sate[i][j])
            {
                cost++;
            }
        }
    }

    return cost;
}