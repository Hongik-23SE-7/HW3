#include "Withdraw.hpp"

string Withdraw::withdraw(string loginId) {
    memberRepository = MemberRepository::getMemberRepository();
    memberRepository->deleteMember(loginId);
    return loginId;
}
