#include "MemberRepository.hpp"

MemberRepository* MemberRepository::memberRepository = nullptr;

MemberRepository* MemberRepository::getMemberRepository() {
    if(memberRepository == nullptr)
        memberRepository = new MemberRepository();

    return memberRepository;
}

bool MemberRepository::existMemberById(string id) {
    for(CompanyMember member : memberList) {
        if(member.getId() == id)
            return true;
    }
    return false;
}

CompanyMember MemberRepository::getMemberById(string id) {
    for(CompanyMember member : memberList) {
        if(member.getId() == id)
            return member;
    }
    return CompanyMember();
}

void MemberRepository::addNewMember(CompanyMember companyMember) {
    memberList.push_back(companyMember);
}

void MemberRepository::deleteMember(string id) {
    for (int i = 0; i < memberList.size(); i++) {
        if (memberList[i].getId().compare(id) == 0) {
            memberList.erase(memberList.begin() + i);
            return;
        }
    }
}