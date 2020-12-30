#include<iostream>

class square
{
public:
  square();
  ~square();
  //setter
  void setNum(int x);
  //getter
  int getNum();
  int calculate();
private:
  int x;
};
