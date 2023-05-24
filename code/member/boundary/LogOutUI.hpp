#ifndef LogOutUI_hpp
#define LogOutUI_hpp

#include <iostream>
#include <fstream>
#include "../control/LogOut.hpp"

using namespace std;

class LogOutUI {
private:
    LogOut *control;
public:
    void logOut(ifstream& input, ofstream& output);
};

#endif