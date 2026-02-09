#include <iostream>
#include <ctime>
#include "source/Table.h"
using namespace std;

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));
  
  Table table = Table();

  int player1 = 1;
  int player2 = 2;
  int player_turn = player1;

  cout << "> Starting test <" << endl;

  while (true) {
    if (table.posible_places.size() == 0) {
      cout << "There is no winner in this run" << endl;
      break;
    }
    vector<int> next_position = table.get_random_position();
    bool response = table.place_turn(next_position[0], next_position[1], player_turn);

    table.print();
    cout << "Row: " << next_position[0] << " Column: " << next_position[1] << endl;
    cout << "Response place in the table: " << response << endl << endl;

    bool winner_checker = table.check_placement_winner(next_position[0], next_position[1]);
    if (winner_checker) {
      cout << "The winner is: " << player_turn << endl;
      break;
    }

    if (player_turn == player1)
      player_turn = player2;
    else player_turn = player1;
  }

  cout << "> Ending test <" << endl;

  return 0;
}