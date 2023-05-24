#include "SignUpUI.hpp"

void SignUpUI::signUp(ifstream &input, ofstream &output) {
    string companyName;
    string businessNumber;
    string id;
    string password;

    input >> companyName >> businessNumber >> id >> password;
    control = new SignUp();
    control->signUp(id, password, companyName, businessNumber);

    string result = "";
    result.append(companyName);
    result.append(" ");
    result.append(businessNumber);
    result.append(" ");
    result.append(id);
    result.append(" ");
    result.append(password);
    result.append(" ");

    output << "1.1. 회원가입 \n> " << result << endl;
}
