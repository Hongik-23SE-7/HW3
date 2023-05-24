#include "SignUpUI.hpp"

void SignUpUI::signUp(ifstream &input, ofstream &output) {
    string id;
    string password;
    string name;

    input >> id >> password >> name;
    control = new SignUp();
    control->signUp(id, password, name);

    string result = "";
    result.append(id);
    result.append(" ");
    result.append(password);
    result.append(" ");
    result.append(name);

    output << "1.1. 회원가입 \n> " << result << endl;
}
