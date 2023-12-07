#include "Spreadsheet.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    cout << lhs.getValue() + rhs.getValue() << endl;
    return SpreadsheetCell { lhs.getValue() + rhs.getValue() };
}
int main()
{
    SpreadsheetCell myCell { 4 }, aThirdCell;
    string str { "hello" };
    aThirdCell = myCell + 5.6;
    aThirdCell = myCell + 4;
    aThirdCell = 5.6 + myCell;
    aThirdCell = 4 + myCell;
    
    return 0;
}