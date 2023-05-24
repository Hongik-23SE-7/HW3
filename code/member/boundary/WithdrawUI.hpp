#ifndef WithdrawUI_h
#define WithdrawUI_h

#include <iostream>
#include <fstream>
#include "../control/Withdraw.hpp"

class WithdrawUI {
private:
    Withdraw *control;
public:
    void withdraw(ofstream& output);
};


#endif
