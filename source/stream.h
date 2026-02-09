#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class WinnerTree {
private:
  struct Node {
    string move;
    vector<Node*> children;
    
    Node(string m) : move(m) {}
  };

public:
  string filename;
  Node* head;

  WinnerTree(const string& filename) {
    this->filename = filename;
  }

  void save_game(Node* root) {
    ofstream ofs(filename, ios::binary);
    if (root) {
      _save_recursive(root, ofs); //! Here put root in the init of the class as the first movement
    }
  }

  void load_game() {
    ifstream ifs(filename, ios::binary);

    if (!ifs.is_open()) {
      cerr << "> Error in opening the file <" << filename << endl;
      return;
    }

    head = _load_game_recursive(ifs);
  }

  Node* _load_game_recursive(ifstream& ifs) {
    size_t move_len;
    if (!ifs.read(reinterpret_cast<char*>(&move_len), sizeof(move_len))) {
      cout << "> Error in reading the data <" << endl;
      return;
    }

    string move(move_len, '\0');
    ifs.read(&move[0], move_len);

    Node* node = new Node(move);

    //? read the children
    size_t num_children;
    ifs.read(reinterpret_cast<char*>(&num_children), sizeof(num_children));

    //? recursive method
    node->children.reserve(num_children);
    for (size_t i = 0; i < num_children; ++i) {
      node->children.push_back(_load_game_recursive(ifs));
    }
  }

  void _save_recursive(Node* node, ofstream& ofs) {
    if (!node) return;

    //? save the path
    size_t move_len = node->move.size();
    ofs.write(reinterpret_cast<const char*>(&move_len), sizeof(move_len));
    ofs.write(node->move.data(), move_len);

    //? save the children of the node
    size_t num_children = node->children.size();
    ofs.write(reinterpret_cast<const char*>(&num_children), sizeof(num_children));

    //? call recursively
    for (Node* child : node->children) {
      _save_recursive(child, ofs);
    }
  }
};