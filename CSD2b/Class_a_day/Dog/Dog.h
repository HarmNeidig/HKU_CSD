class Dog
{
public:
//constructor
  Dog();
//destructor
  ~Dog();
// setter
  void setAge(int age);
// getter
  int getAge();
// methods
  void inputAge();
  void checkAge();

private:
  int age;
};
