#include <iostream>

/*
  Assignment: complete this program by putting your code in all the locations
    that say -- your code here --

  Make sure that the program compiles and builds and check the output
    after every change.

  Tip: before you look at the output, always think ahead what you expect to
    see and then check if your assumption was correct.
 */

int main()
{
char letter = 'a'; // find this in the ASCII table (type 'man ascii')
char *letterpointer;
letterpointer = &letter;

  std::cout << "Contents of the variable letter: ";
  // -- your code here --
  std::cout << letter << std::endl;

  std::cout << "Contents of letterpointer: ";
  // -- your code here --
  std::cout << letterpointer << std::endl;


  std::cout << "Contents of what letterpointer points to: ";
  // -- your code here --
  std::cout << *letterpointer << std::endl;

  *letterpointer = 'b';
  std::cout << "The variabele letter has gotten a new value through letterpointer." << std::endl;
  std::cout << "Contents of what letterpointer points to: ";
  // -- your code here --
  std::cout << *letterpointer << std::endl;

  std::cout << "Contents of the variable letter: ";
  // -- your code here --
  std::cout << letter << std::endl;



  /*
   * Create the necessary pointer(s) and use them
   */

  unsigned short year = 2019;
  std::cout << "Contents of the variabele year: ";
  // -- your code here --
  std::cout << year << std::endl;
  // create a pointer to year
  // -- your code here --
  unsigned short *yearpointer = &year;
  std::cout << "Contents of yearpointer: ";
  // -- your code here --
  std::cout << yearpointer << std::endl;

  std::cout << "Contents of what yearpointer points to: ";
  std::cout << *yearpointer << std::endl;
  // give year a new value via yearpointer
  // -- your code here --
  *yearpointer = 2077;

  std::cout << "Contents of the variabele year: ";
  // -- your code here --
  std::cout << year << std::endl;

  // create another pointer to year, named anotheryearpointer
  // -- your code here --
  unsigned short *anotheryearpointer = &year;

  std::cout << "Contents of anotheryearpointer: ";
  // -- your code here --
  std::cout << anotheryearpointer << std::endl;


  std::cout << "Contents of what anotheryearpointer points to: ";
  // -- your code here --
  std::cout << *anotheryearpointer << std::endl;

  // give year a new value via anotheryearpointer
  // -- your code here --
  *anotheryearpointer += 1;


  std::cout << "Contents of year: ";
  // -- your code here --
  std::cout << year << std::endl;


  std::cout << "Contents of what anotheryearpointer points to: ";
  // -- your code here --
  std::cout << *anotheryearpointer << std::endl;

  anotheryearpointer++;

  std::cout << "Contents of anotheryearpointer after ++: ";
  // -- your code here --
  std::cout << *anotheryearpointer << std::endl;


} // main()
