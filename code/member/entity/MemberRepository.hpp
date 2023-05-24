#ifndef MemberRepository_hpp
#define MemberRepository_hpp

#include <iostream>
#include <vector>
#include "CompanyMember.hpp"
using namespace std;

class Member;

class MemberRepository {
private:
    static MemberRepository *memberRepository;
    vector<CompanyMember> memberList;

public:
    static MemberRepository *getMemberRepository();
    CompanyMember getMemberById(string id);
    bool existMemberById(string id);
    void addNewMember(CompanyMember member);
    void deleteMember(string id);
};

#endif
