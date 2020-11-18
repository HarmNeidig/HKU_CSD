#include"Dog.h"
#include<iostream>

Dog::Dog(int NewDogAge)
{
  if (NewDogAge <= 5){
    std::cout << "I love little puppies <3" << std::endl;
  }
    else if (NewDogAge == 49){
        std::cout << "Snoop Doggy Dog 8)" << std::endl;
      }
      else{
          std::cout << "Your Dog is probably dead :'(" << std::endl;
        }
};

//destrutor
Dog::~Dog(){
  std::cout << "Bye Dawg" << std::endl;
};
