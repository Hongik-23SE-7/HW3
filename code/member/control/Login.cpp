#include "Login.hpp"
#include "../entity/MemberRepository.hpp"

bool Login::login(string id, string password) {
    MemberRepository *repository = MemberRepository::getMemberRepository();

    if (repository->existMemberById(id)) {
        Member member = repository->getMemberById(id);
        if (member.matchPassword(password)) {
            return true;
        }
    }
    return false;
}
