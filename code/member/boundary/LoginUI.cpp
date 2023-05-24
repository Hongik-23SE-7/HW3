#include "LoginUI.hpp"

void LoginUI::login(ifstream &input, ofstream &output) {
    string id;
    string password;

    input >> id >> password;
    control = new Login();

    if (control->login(id, password)) {
        string result = "";
        result.append(id);
        result.append(" ");
        result.append(password);
        output << "2.1. 로그인 \n> " << result << endl;
        return;
    } else {
        return;
    }
}
