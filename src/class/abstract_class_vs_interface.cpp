/*
Interface: you mean a C++ class with only pure virtual methods (i.e. without any code).
Abstract class you mean a C++ class with virtual methods  and some code, but at least one pure virtual method that makes the class not instantiable.
*/

class MyInterface
{
public:
  // Empty virtual destructor for proper cleanup
  virtual ~MyInterface() {}

  virtual void Method1() = 0;
  virtual void Method2() = 0;
};


class MyAbstractClass
{
public:
  virtual ~MyAbstractClass();

  virtual void Method1()
{
//some code here
}
  virtual void Method2();
  void Method3();

  virtual void Method4() = 0; // make MyAbstractClass not instantiable
};

int main()
{
}
