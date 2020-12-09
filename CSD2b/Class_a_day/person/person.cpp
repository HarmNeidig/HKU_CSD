#include<iostream>
#include<string>
#include"person.h"

//constructor
person::person(){
  std::cout << "Hi" << std::endl;
}

//destrutor
person::~person(){
  std::cout << "Houdoe" << std::endl;
}

//setter for age
void person::setAge(int age){
  this->age = age;
  std::cout << "This person is now " << age << " years old" << std::endl;
}

//getter for age
int person::getAge(){
  return age;
}

//setter for name
void person::setName(std::string name){
  this->name = name;
  std::cout << "This persons name is now " << name << std::endl;
}

//getter for name
std::string person::getName(){
  return name;
}
