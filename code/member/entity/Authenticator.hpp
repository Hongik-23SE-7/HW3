//
// Created by dongho on 2023/05/24.
//

#ifndef Authenticator_hpp
#define Authenticator_hpp

#include <iostream>
#include <vector>
#include "Session.hpp"

using namespace std;

class Authenticator {
private:
    static Authenticator *authenticator;
    vector<Session> sessionList;
public:
    static Authenticator *getAuthenticator();
    void addSession(string loginId);
    void removeSession(string loginId);
};

#endif
