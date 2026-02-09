#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Table {
public:
  int height, width;  
  vector<vector<int>> table;

  Table() {
    height = 3;
    width = 3;

    table = vector<vector<int>>(height, vector<int>(width, 0));
  }

  void place_turn(int player, int x, int y) {
    //TODO Check this to more reayaility
    table[y][x] = player;
  }

  void check_placement_winner(int x, int y) {
    int player = table[y][x];

    // Check column
    
    // Check row
    // Check diagonal

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