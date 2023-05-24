#ifndef Member_hpp
#define Member_hpp

#include <iostream>
#include <vector>
using namespace std;

class Member {
private:
    string id;
    string password;
public:
    Member() {};
    Member(string id, string password) {
        this->id = id;
        this->password = password;
    }
    string getId();

    bool matchPassword(string password);
};

#endif