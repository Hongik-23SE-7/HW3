//
// Created by dongho on 2023/05/24.
//

#ifndef Authenticator_hpp
#define Authenticator_hpp

#include <iostream>
#include <vector>

using namespace std;

class Authenticator {
private:
    static Authenticator *authenticator;
    string session;
public:
    static Authenticator *getAuthenticator();
    void addSession(string loginId);
    string clearSession();
};

#endif
