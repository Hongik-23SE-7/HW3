#include "MemberRepository.hpp"

MemberRepository* MemberRepository::memberRepository = nullptr;

MemberRepository* MemberRepository::getMemberRepository() {
    if(memberRepository == nullptr)
        memberRepository = new MemberRepository();

    return memberRepository;
}

Member MemberRepository::getMemberById(string id) {
    for(Member member : memberList) {
        if(member.getId() == id)
            return member;
    }
    return Member(); // null 반환 하고
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