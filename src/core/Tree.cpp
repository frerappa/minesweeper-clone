#include "Tree.hpp"

Tree::Tree(){
  root = nullptr;
}

bool Tree::search_insert(int v){
  Node **walk = &root;
  while (*walk) { 
    int curkey = (*walk)->data;
    if (curkey == v) {
      return true;
    }
    if (v > curkey) 
      walk = &(*walk)->right;
    else 
      walk = &(*walk)->left;
  }
  *walk = new Node{v, nullptr, nullptr};
  return false;
}
