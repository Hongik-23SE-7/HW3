#include "LogOut.hpp"
#include "../entity/Authenticator.hpp"

string LogOut::logOut() {
    Authenticator *authenticator = Authenticator::getAuthenticator();
    return authenticator->clearSession();
}
