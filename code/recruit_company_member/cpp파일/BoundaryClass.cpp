#include "BoundaryClass.hpp"

void RegisterRecruitmentUI::registerRecruitment(ifstream& input, ofstream& output) {
    input >> duty >> deadline >> intake;
    control = new RegisterRecruitment();

    string result = control->addNewRecruitment(duty, deadline, intake);
    output << "3.1 채용 정보 등록\n> " << result << endl;
}

void SearchRegisteredRecruitmentUI::searchRegisteredRecruitment(ifstream& input, ofstream& output) {
    control = new SearchRegisteredRecruitment();

    string result = control->showRegisteredRecruitment();
    output << "3.2 등록 채용 정보 조회\n> " << result << endl;
}

void SearchRecruitmentUI::searchRecruitment(ifstream& input, ofstream& output) {
    input >> companyName;
    control = new SearchRecruitment();

    string result = control->showRecruitment(companyName);
    output << "4.1. 채용 정보 검색 \n> " << result << endl;
}


void ApplyRecruitmentUI::applyRecruitment(ifstream& input, ofstream& output, string memberId) {
    input >> businessNumber;
    control = new ApplyRecruitment();
    
    string result = control->applyRecruitment(businessNumber, memberId);
    
    output << "4.2. 채용 지원\n> " << result << endl;
    
}
