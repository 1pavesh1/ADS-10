// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>
struct Node {
  bool helper = false;
  char value;
  std::vector<Node*> point;
};
class Tree {
 private:
  Node* root;
  std::vector<std::vector<char>> perms;
  void insert(Node* root, const std::vector<char>& vec) {
    for (char ch : vec) {
      Node* temp = new Node;
      temp->value = ch;
      root->point.push_back(temp);
      std::vector<char> remainingChars(vec);
      remainingChars.erase(std::find(remainingChars.begin(), \
                                     remainingChars.end(), ch));
      insert(temp, remainingChars);
    }
  }
  void findPerms(Node* root, std::vector<char> vec) {
    if (!root->helper)
      vec.push_back(root->value);
    if (root->point.empty()) {
      perms.push_back(vec);
    } else {
        for (Node* child : root->point) {
          findPerms(child, vec);
        }
    }
}

 public:
  explicit Tree(const std::vector<char>& vec) {
    root = new Node;
    root->helper = true;
    insert(root, vec);
    std::vector<char> curr;
    findPerms(root, curr);
  }
  std::vector<std::vector<char>> getPermutations() const {
    return perms;
  }
};
#endif  // INCLUDE_TREE_H_
