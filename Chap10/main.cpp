#include <iostream>

using namespace std;

class Base
{
    public:
        void someMethod() { cout << "Base" << endl; }
};

class Derived : public Base
{
    public:
        void someMethod() { cout << "Derived" << endl; }
};

int main()
{
    Derived myDerived;
    Base& ref { myDerived };
    ref.someMethod();

    return 0;
}