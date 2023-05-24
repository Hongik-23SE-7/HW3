#include "SignUpUI.hpp"

void SignUpUI::companyMemberSignUp(std::ifstream &input, std::ofstream &output) {
    string companyName;
    string businessNumber;
    string id;
    string password;

    input >> companyName >> businessNumber >> id >> password;
    control = new SignUp();
    control->companyMemberSignUp(id, password, companyName, businessNumber);

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

void SignUpUI::generalMemberSignUp(std::ifstream &input, std::ofstream &output) {
    string name;
    string residentRegistrationNumber;
    string id;
    string password;

    input >> name >> residentRegistrationNumber >> id >> password;
    control = new SignUp();
    control->generalMemberSignUp(id, password, name, residentRegistrationNumber);

    string result = "";
    result.append(name);
    result.append(" ");
    result.append(residentRegistrationNumber);
    result.append(" ");
    result.append(id);
    result.append(" ");
    result.append(password);
    result.append(" ");

    output << "1.1. 회원가입 \n> " << result << endl;
}

