#include "LogOutUI.hpp"
#include "WithdrawUI.hpp"

void WithdrawUI::withdraw(std::ofstream &output) {
    LogOut *logOut = new LogOut;
    string logOutId = logOut->logOut();

    Withdraw *withdraw = new Withdraw();
    string withdrawId = withdraw->withdraw(logOutId);

    output << "1.2. 회원탈퇴 \n> " << withdrawId << endl;
}
