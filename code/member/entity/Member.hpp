#ifndef Member_hpp
#define Member_hpp

#include <iostream>
#include <vector>
using namespace std;

class Member {
private:
    string id;
    string password;
    string name;
public:
    Member() {};
    Member(string id, string password, string name) {
        this->id = id;
        this->password = password;
        this->name = name;
    }
    string getId();
    bool matchPassword(string password);
};

#endif