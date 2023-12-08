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
SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    cout << lhs.getValue() - rhs.getValue() << endl;
    return SpreadsheetCell { lhs.getValue() - rhs.getValue() };
}
SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    cout << lhs.getValue() * rhs.getValue() << endl;
    return SpreadsheetCell { lhs.getValue() * rhs.getValue() };
}
SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    if(rhs.getValue() == 0)
    {
        throw invalid_argument { "Divide by zero." };
    }
    cout << lhs.getValue() / rhs.getValue() << endl;
    return SpreadsheetCell { lhs.getValue() / rhs.getValue() };
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return (lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return (lhs.getValue() < rhs.getValue());
}

bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return (lhs.getValue() > rhs.getValue());
}

bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return (lhs.getValue() != rhs.getValue());
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return !(lhs < rhs);
}

int main()
{
    SpreadsheetCell myCell { 4 }, aThirdCell;
    string str { "hello" };
    aThirdCell = myCell - 5.6;
    aThirdCell = myCell * 4;
    aThirdCell = 5.6 / myCell;
    aThirdCell = 4 + myCell;
    aThirdCell += 4;
    
    return 0;
}