#include "Spreadsheet.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

Spreadsheet createObject()
{
    return Spreadsheet {1, 1};
}
int main()
{
    vector<Spreadsheet> vec;
    for(size_t i { 0 }; i < 2; i++)
    {
        cout << "Iteration " << i << endl;
        vec.push_back(Spreadsheet {1, 1});
        cout << endl;
    }

    Spreadsheet s {1, 1};
    s = createObject();

    Spreadsheet s2 {1, 1};
    s2 = s;
    
    return 0;
}