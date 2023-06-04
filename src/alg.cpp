// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
std::vector<char> getPerm(const Tree& tree, int n) {
std::vector<char> getPerm(const Tree& tree, int i) {
  std::vector<std::vector<char>> perms = tree.getPermutations();
    if (perms.size() >= i) {
      return perms[i - 1];
    } else {
        return {};
    }
}
