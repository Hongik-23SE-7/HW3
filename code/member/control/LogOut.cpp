#include "LogOut.hpp"

string LogOut::logOut() {
    authenticator = Authenticator::getAuthenticator();
    return authenticator->clearSession();
}
