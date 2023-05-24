//
// Created by dongho on 2023/05/24.
//

#ifndef CompanyMember_hpp
#define CompanyMember_hpp
#include "Member.hpp"


class CompanyMember : public Member{
private:
    string companyName;
    string businessNumber;
public:
    CompanyMember() {};
    CompanyMember(string id,
                  string password,
                  string companyName,
                  string businessNumber) :  Member(id, password) {
        this->companyName = companyName;
        this->businessNumber = businessNumber;
    }
};


#endif
