#include"Dog.h"
#include<iostream>

Dog::Dog()
{
  std::cout << "hello dog" << std::endl;
};

//destrutor
Dog::~Dog(){
  std::cout << "Bye Dawg" << std::endl;
};

// setter
void Dog::setAge(int age){
  this->age = age;
}
//getter
int Dog::getAge(){
  return age;
}

// input function
void Dog::inputAge(){
  int x;
  std::cout << "how old is your dog? " << std::endl;
  std::cin >> x;
  setAge(x);
}

// output function
void Dog::checkAge(){
  if (age <= 5){
    std::cout << "I love little puppies <3" << std::endl;
  }
    else if (age == 49){
        std::cout << "Snoop Doggy Dog 8)" << std::endl;
      }
      else{
          std::cout << "Your Dog is probably dead :'(" << std::endl;
        }
}
