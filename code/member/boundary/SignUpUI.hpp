#ifndef SignUpUI_hpp
#define SignUpUI_hpp

#include <iostream>
#include <fstream>
#include "../control/SignUp.hpp"

class SignUpUI {
private:
    SignUp *control;

public:
    void companyMemberSignUp(ifstream& input, ofstream& output);
    void generalMemberSignUp(ifstream& input, ofstream& output);
};

#endif