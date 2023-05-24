#ifndef LogOut_h
#define LogOut_h

#include <iostream>
#include "../entity/Authenticator.hpp"
using namespace std;

class LogOut {
private:
    Authenticator *authenticator;
public:
    string logOut();
};

#endif
