#include <memory>
#include <iostream>
#include "SpreadsheetCell.h"

using namespace std;

int main()
{
    SpreadsheetCell myCell { 5 };
    if(myCell.getValue() == 5) SpreadsheetCell anotherCell { 6 };
    cout << "myCell: " << myCell.getValue() << endl;
    
    return 0;
}