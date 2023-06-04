// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <iostream>
#include <vector>
struct Node {
  char value;
  bool isRoot = false;

  std::vector<Node*> ptrs;
};
class Tree {
 private:
  Node* root;
  std::vector<std::vector<char>> permutations;
  void findPermutations(Node* root, std::vector<char> vect) {
    if (!root->isRoot) vect.push_back(root->value);
    if (!root->ptrs.empty()) {
      for (Node* child : root->ptrs) {
        findPermutations(child, vect);
      }
    } else {
      permutations.push_back(vect);
    }
  }
  void insert(Node* root, std::vector<char>& vect) {
    for (char c : vect) {
      Node* temp = new Node;
      temp->value = c;
      root->ptrs.push_back(temp);
      std::vector<char> otherChars(vect);
      otherChars.erase(std::find(otherChars.begin(), otherChars.end(), c));
      insert(temp, otherChars);
    }
  }

 public:
  explicit Tree(std::vector<char>& vect) {
    root = new Node;
    root->isRoot = true;
    insert(root, vect);
    std::vector<char> actual;
    findPermutations(root, actual);
  }
  std::vector<std::vector<char>> getPermutations() {
    return permutations;
  }
};
#endif  // INCLUDE_TREE_H_
