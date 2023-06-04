// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>
#include <algorithm>
struct Node {
    bool isRoot = false;
    char value;
    std::vector<Node*> ptrs;
};
class Tree {
 private:
    Node* root;
    std::vector<std::vector<char>> permutations;
    void findPermutations(Node* root, std::vector<char> vect) {
         if (!root->isRoot)
            vect.push_back(root->value);
         if (root->ptrs.empty()) {
           permutations.push_back(vect);
         } else {
             for (Node* child : root->ptrs) {
                 findPermutations(child, vect);
             }
         }
    }
    void insert(Node* root, const std::vector<char>& vect) {
        for (char c : vect) {
            Node*temp = new Node;
            temp->value = c;
            root->ptrs.push_back(temp);
            std::vector<char> otherChars(vect);
            otherChars.erase(std::find(otherChars.begin(), \
                otherChars.end(), c));
            insert(temp, otherChars);
        }
    }

 public:
    explicit Tree(const std::vector<char>& vect) {
        root = new Node;
        root->isRoot = true;
        insert(root, vect);
        std::vector<char> actual;
        findPermutations(root, actual);
    }
    std::vector<std::vector<char>> getPermutations() const {
        return permutations;
    }
};

#endif  // INCLUDE_TREE_H_
