#include <iostream>

using namespace std;

class Simple
{
    public:
        Simple() { cout << "Constructor" << endl; }
        ~Simple() { cout << "Destructor" << endl; }
};

int main()
{
    Simple* mySimple = new Simple[4];
    delete[] mySimple;
    mySimple = nullptr;
    return 0;
}