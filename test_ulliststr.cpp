#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;

int main(int argc, char* argv[])
{
  size_t loc = 8;
  
  ULListStr listB;
  for(int i = 1; i <= 20; ++i) {
    string back = "back" + to_string(i);
    listB.push_back(back);
  }

  cout << "back: " <<  listB.back() << "\n";
  cout << "at " << loc << ": " << listB.get(loc) << "\n";

  for(int j = 0; j < 6; ++j) {
    listB.pop_back();
  }

  cout << "back: " <<  listB.back() << "\n";
  cout << "at " << loc << ": " << listB.get(loc) << "\n";

  ULListStr listF;
  for (int i = 1; i <= 20; ++i) {
    string front = "front" + to_string(i);
    listF.push_front(front);
  }

  cout << "front: " <<  listF.front() << "\n";
  cout << "at " << loc << ": " << listF.get(loc) << "\n";


  for (int j = 0; j < 7; ++j) {
    listF.pop_front();
  }

  cout << "front: " <<  listF.front() << "\n";
  cout << "at " << loc << ": " << listF.get(loc) << "\n";
}
