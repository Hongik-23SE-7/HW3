#ifndef Session_hpp
#define Session_hpp

#include <iostream>
using namespace std;

class Session {
private:
    string loginId;
public:
    Session(string loginId) {
        this->loginId = loginId;
    }
};

#endif
