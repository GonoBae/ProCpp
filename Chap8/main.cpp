#include <iostream>
#include <memory>
#include "SpreadsheetCell.h"

using namespace std;

int main()
{ 
    auto Cellp { make_unique<SpreadsheetCell>() };
    Cellp->SetValue(3.7);
    cout << "cell 1 : " << Cellp->getValue() << " " << Cellp->getString() << endl;
    return 0;
}