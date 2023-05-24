#include "MemberRepository.hpp"

MemberRepository* MemberRepository::memberRepository = nullptr;

MemberRepository* MemberRepository::getMemberRepository() {
    if(memberRepository == nullptr)
        memberRepository = new MemberRepository();

    return memberRepository;
}

bool MemberRepository::existMemberById(string id) {
    for(Member member : memberList) {
        if(member.getId() == id)
            return true;
    }
    return false;
}

Member MemberRepository::getMemberById(string id) {
    for(Member member : memberList) {
        if(member.getId() == id)
            return member;
    }
    return CompanyMember();
}

void MemberRepository::addNewMember(Member member) {
    memberList.push_back(member);
}

void MemberRepository::deleteMember(string id) {
    for (int i = 0; i < memberList.size(); i++) {
        if (memberList[i].getId().compare(id) == 0) {
            memberList.erase(memberList.begin() + i);
            return;
        }
    }
}