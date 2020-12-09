#include<iostream>
#include<string>

class person{
public:
  //constructor
  person();
  //destructor
  ~person();
  //setter for age
  void setAge(int age);
  //getter for age
  int getAge();
  //setter for name
  void setName(std::string name);
  //getter for name
  std::string getName();
private:
  int age;
  std::string name;
};
