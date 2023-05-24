#include "Authenticator.hpp"

Authenticator* Authenticator::authenticator = nullptr;

Authenticator* Authenticator::getAuthenticator() {
    if (authenticator == nullptr) {
        authenticator = new Authenticator();
    }
    return authenticator;
}

void Authenticator::addSession(string loginId) {
    this->session = loginId;
}

string Authenticator::clearSession() {
    string retId = this->session;
    this->session.clear();
    return retId;
}
