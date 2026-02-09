#pragma once

#include <iostream>
#include <vector>
#include <cstring>
#include <random>
#include <chrono>
using namespace std;

class Table {
public:
  int height, width;  
  
  vector<string> posible_places;
  vector<vector<int>> table;

  Table() {
    height = 3;
    width = 3;

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        string temp_position = { _convert_char(i), _convert_char(j) };
        posible_places.push_back(temp_position);
      }
    }

    table = vector<vector<int>>(height, vector<int>(width, 0));

  }

  vector<int> get_random_position() {
    int random_choice = rand() % posible_places.size();
    vector<int> ret_temp;
    ret_temp = {
      _convert_int(posible_places[random_choice][0]),
      _convert_int(posible_places[random_choice][1])
    };
    posible_places.erase(posible_places.begin() + random_choice);
    return ret_temp;
  }

  char _convert_char(int &number) {
    return (char)(number + '0');
  }
  int _convert_int(char &letter) {
    return (int)(letter - '0');
  }
  bool check_place_available(int &row, int &column) {
    return table[row][column] == 0;
  }
  bool place_turn(int row, int column, int player) {
    if (!check_place_available(row, column)) return false;
    
    table[row][column] = player;

    return true;
  }

  bool check_placement_winner(int row, int column) {
    //? Just remember the x is the columns and the y is the rows
    int player = table[row][column];
    bool checker = false;

    //? Check the colums
    if ((table[row][0] == table[row][1]) && (table[row][1] == table[row][2])) {
      cout << "row" << endl;
      return true;
    }

    //? Check the rows
    if ((table[0][column] == table[1][column]) && (table[1][column] == table[2][column])) {
      cout << "column" << endl;
      return true;
    }

    //? Check the diagonals
    //TODO Check the big o times to not always check the diagonals
    if (
      table[0][0] == player &&
      table[1][1] == player &&
      table[2][2] == player
    ) {
      cout << "diagonal" << endl;
      return true;
    }

    return false;
  }

  void print() {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        std::cout << table[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};