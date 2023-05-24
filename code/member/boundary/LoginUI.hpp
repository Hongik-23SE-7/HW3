#ifndef LoginUI_hpp
#define LoginUI_hpp

#include <iostream>
#include <fstream>
#include "../control/Login.hpp"

using namespace std;

class LoginUI {
private:
    Login *control;
public:
    void login(ifstream& input, ofstream& output);
};

#endif
