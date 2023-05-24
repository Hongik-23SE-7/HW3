#include "LogOutUI.hpp"
#include "../entity/Authenticator.hpp"

void LogOutUI::logOut(std::ofstream &output) {
    control = new LogOut();
    string logOutId = control->logOut();
    cout << logOutId << endl;

    output << "2.2. 로그아웃 \n> " << logOutId << endl;
}
