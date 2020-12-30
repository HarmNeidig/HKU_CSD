#include <iostream>

int main()
{
  char letter = 'a'; 
  char *letterpointer;
  letterpointer = &letter;

  std::cout << "Contents of the variable letter: ";
  std::cout << letter << std::endl;

  std::cout << "Contents of letterpointer: ";
  std::cout << letterpointer << std::endl;


  std::cout << "Contents of what letterpointer points to: ";
  std::cout << *letterpointer << std::endl;

  *letterpointer = 'b';
  std::cout << "The variabele letter has gotten a new value through letterpointer." << std::endl;
  std::cout << "Contents of what letterpointer points to: ";
  std::cout << *letterpointer << std::endl;

  std::cout << "Contents of the variable letter: ";
  std::cout << letter << std::endl;



  /*
   * Create the necessary pointer(s) and use them
   */

  unsigned short year = 2019;
  std::cout << "Contents of the variabele year: ";
  std::cout << year << std::endl;
  unsigned short *yearpointer = &year;
  std::cout << "Contents of yearpointer: ";
  std::cout << yearpointer << std::endl;

  std::cout << "Contents of what yearpointer points to: ";
  std::cout << *yearpointer << std::endl;
  *yearpointer = 2077;

  std::cout << "Contents of the variabele year: ";
  std::cout << year << std::endl;

  unsigned short *anotheryearpointer = &year;

  std::cout << "Contents of anotheryearpointer: ";
  std::cout << anotheryearpointer << std::endl;


  std::cout << "Contents of what anotheryearpointer points to: ";
  std::cout << *anotheryearpointer << std::endl;

  *anotheryearpointer += 1;


  std::cout << "Contents of year: ";
  std::cout << year << std::endl;


  std::cout << "Contents of what anotheryearpointer points to: ";
  std::cout << *anotheryearpointer << std::endl;

  anotheryearpointer++;

  std::cout << "Contents of anotheryearpointer after ++: ";
  std::cout << *anotheryearpointer << std::endl;


}
