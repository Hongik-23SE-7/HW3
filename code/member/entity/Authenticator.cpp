#include "Authenticator.hpp"
#include "Session.hpp"

Authenticator* Authenticator::authenticator = nullptr;

Authenticator* Authenticator::getAuthenticator() {
    if (authenticator == nullptr) {
        authenticator = new Authenticator();
    }
    return authenticator;
}

void Authenticator::addSession(string loginId) {
    Session session = {loginId};
    sessionList.push_back(session);
}