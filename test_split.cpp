/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  Node* in = nullptr;
  for (int i = 10; i >= 1; --i) {
    in = new Node(i,in);
  }
  Node* odd = nullptr;
  Node* even = nullptr;
  split(in,odd,even);

  cout << "odds ";
  for(Node* print = odd; print != nullptr; print = print->next){
    cout << print->value << " ";
  }

  cout << "evens ";
  for(Node* print = even; print != nullptr; print = print->next){
    cout << print->value << " ";
  }
}
