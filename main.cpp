#include <iostream>
#include "source/Table.h"
using namespace std;

#define PLAYER1 1
#define PLAYER2 2

int main() {
  Table table = Table();

  table.place_turn(PLAYER1, 1, 0);

  table.print();

  return 0;
}