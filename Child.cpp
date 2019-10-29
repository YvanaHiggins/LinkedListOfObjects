#include <iostream>
#include <string>
using namespace std;

#include "Child.h"

//Constructors
Child::Child()
{
}

Child::Child(string firstN, string lastN, int age)
{
  this->firstName = firstN;
  this->lastName = lastN;
  this->id = age;
}

//Destructors
Child::~Child()
{
}

//Gets the first name
string& Child::getFirstName()
{
  return this->firstName;
}

//Gets the last name
string& Child::getLastName()
{
  return this->lastName;
}

//Gets the age
int& Child::getId()
{
  return this->id;
}

//overloading the cout operator
ostream& operator<<(ostream &out, const Child &other)
{
  out << other.firstName << other.lastName << other.id;
  return out;
}

//overloadting the "less than" operator
bool Child::operator<(const Child &other) const
{
  //Checks if child are equal
  if(*(this)==other)
  {
    return false;
  }

  //Checks lastName
  if(this->lastName.compare(other.lastName) <= -1)
  {
    return true;
  }
  else
  {
    return false;
  }

  //Checks firstName
  if (this->firstName.compare(other.firstName) <= -1 )
  {
    return true;
  }
  else
  {
    return false;
  }

  //Checks age
  if (this->id < other.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//OVERLOADED OPERATORS
//overloaded <= operator
bool Child::operator<=(const Child &other) const
{
  if(*(this) < other || *(this) == other)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Overloaded > operator
bool Child::operator>(const Child &other) const
{
  //Checks if child are equal
  if(*(this)==other)
  {
    return false;
  }

  //Checks last name
  if(this->lastName.compare(other.lastName) >= 1)
  {
    return true;
  }
  else
  {
    return false;
  }


  //Checks first name
  if (this->firstName.compare(other.firstName) >= 1 )
  {
    return true;
  }
  else
  {
    return false;
  }


  //Checks age
  if (this->id > other.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Overloaded >= operator
bool Child::operator>=(const Child &other) const
{
  if(*(this) > other || *(this) == other)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Overloaded == operator
bool Child::operator==(const Child &other) const
{
  return (this->firstName == other.firstName) && (this->lastName == other.lastName) && (this->id == other.id);
}

//Overloaded != operator
bool Child::operator!=(const Child &other) const
{
  return (this->firstName != other.firstName) || (this->lastName != other.lastName) || (this->id != other.id);
}
