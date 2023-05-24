//
// Created by dongho on 2023/05/24.
//

#ifndef GeneralMember_hpp
#define GeneralMember_hpp
#include "Member.hpp"


class GeneralMember : public Member{
private:
    string name;
    string residentRegistrationNumber;
public:
    GeneralMember() {};
    GeneralMember(string id,
                  string password,
                  string name,
                  string residentRegistrationNumber) :  Member(id, password) {
        this->name = name;
        this->residentRegistrationNumber = residentRegistrationNumber;
    }
};


#endif
