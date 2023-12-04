#include <iostream>
#include <memory>
#include "SpreadsheetCell.h"

using namespace std;

int main()
{ 
    auto smartCell {make_unique<SpreadsheetCell>()};
    SpreadsheetCell* myCellp {new SpreadsheetCell{}};
    
    return 0;
}