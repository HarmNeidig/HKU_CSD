#include<iostream>

class square
{
public:
  square();
  ~square();
  //setter
  void setNumValue(int x);
  void setNumRefrence(int &x);
  void setNumPointer(int *x);
  //getter
  int getNum();
  int calculate();
private:
  int x;
};
