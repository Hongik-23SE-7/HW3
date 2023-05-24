#include "Withdraw.hpp"
#include "../entity/MemberRepository.hpp"

string Withdraw::withdraw(string loginId) {
    MemberRepository *memberRepository = MemberRepository::getMemberRepository();
    memberRepository->deleteMember(loginId);
    return loginId;
}
