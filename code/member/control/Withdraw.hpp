#ifndef Withdraw_h
#define Withdraw_h

#include <iostream>
#include "../entity/MemberRepository.hpp"
using namespace std;

class Withdraw {
private:
    MemberRepository *memberRepository;
public:
    string withdraw(string loginId);
};

#endif
