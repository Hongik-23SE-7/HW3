#ifndef SignUp_hpp
#define SignUp_hpp

#include <iostream>
#include "../entity/MemberRepository.hpp"

class MemberRepository;

class SignUp {
private:
    MemberRepository *repository;

public:
    void signUp(string id, string password, string companyName, string businessNumber);
};

#endif