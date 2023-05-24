#ifndef Login_h
#define Login_h

#include <iostream>
#include "../entity/MemberRepository.hpp"
using namespace std;

class Login {
private:
    MemberRepository *repository;
public:
    bool login(string id, string password);
};

#endif
