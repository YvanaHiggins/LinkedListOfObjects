#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>
using namespace std;

class Child {

friend ostream& operator<<(ostream &out, const Child &other);

public:

  //Constructors
  Child();
  Child(string firstN, string lastN, int age);

  //destructors
  ~Child();

  //getters
  string& getFirstName();
  string& getLastName();
  int& getId();

  //Operator Overloads
  bool operator>(const Child &other) const;
  bool operator>=(const Child &other) const;
  bool operator<(const Child &other) const;
  bool operator<=(const Child &other) const;
  bool operator==(const Child &other) const;
  bool operator!=(const Child &other) const;

private:
  //Private variables
  string firstName;
  string lastName;
  int id;
};

#include "Child.cpp"

#endif
