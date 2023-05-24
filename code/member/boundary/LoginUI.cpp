#include "LoginUI.hpp"

void LoginUI::login(ifstream &input, ofstream &output) {
    string id;
    string password;

    input >> id >> password;
    control = new Login();

    cout << "loginUI 진입" << endl;
    if (control->login(id, password)) {
        cout << "로그인 성공" << endl;
        string result = "";
        result.append(id);
        result.append(" ");
        result.append(password);
        output << "2.1. 로그인 \n> " << result << endl;
        return;
    } else {
        output << "로그인 실패" << endl;
        return;
    }
}
