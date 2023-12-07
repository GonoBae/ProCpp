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
    Spreadsheet sheet1 {2, 2};
    SpreadsheetCell& cell1 { sheet1.getCellAt(1, 1) };
    const Spreadsheet sheet2 {2, 2};
    const SpreadsheetCell& cell2 { sheet2.getCellAt(1, 1) };
    
    return 0;
}