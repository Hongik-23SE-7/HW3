#ifndef MemberRepository_hpp
#define MemberRepository_hpp

#include <iostream>
#include <vector>
#include "CompanyMember.hpp"
#include "GeneralMember.hpp"

using namespace std;

class Member;

class MemberRepository {
private:
    static MemberRepository *memberRepository;
    vector<Member> memberList;

public:
    static MemberRepository *getMemberRepository();
    Member getMemberById(string id);
    bool existMemberById(string id);
    void addNewMember(Member member);
    void deleteMember(string id);
};

#endif
