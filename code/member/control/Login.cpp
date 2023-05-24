#include "Login.hpp"
#include "../entity/Authenticator.hpp"

bool Login::login(string id, string password) {
    repository = MemberRepository::getMemberRepository();

    if (repository->existMemberById(id)) {
        Member member = repository->getMemberById(id);
        if (member.matchPassword(password)) {
            Authenticator *authenticator = Authenticator::getAuthenticator();
            authenticator->addSession(member.getId());
            return true;
        }
    }
    return false;
}
