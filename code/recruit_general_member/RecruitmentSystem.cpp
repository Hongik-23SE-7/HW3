#include "RecruitmentSystem.h"
#include <fstream>
using namespace std;


/*
    Entity
*/ 

// GeneralMember
string GeneralMember::getId() {
    return id;
}

void GeneralMember::setId(string id) {
    this->id = id;
}

void GeneralMember::addNewApplication(Application application) {
    applicationList.push_back(application);
}

// GeneralMemberRepository
GeneralMemberRepository* GeneralMemberRepository::generalMemberRepository = nullptr;

GeneralMemberRepository* GeneralMemberRepository::getGeneralMemberRepository() {
    if (generalMemberRepository == nullptr)
        generalMemberRepository = new GeneralMemberRepository();

    return generalMemberRepository;
}

GeneralMember GeneralMemberRepository::getGeneralMember(string id) {

    for (auto generalMember : generalMemberList) {
        if (generalMember.getId() == id)
            return generalMember;
    }

    return GeneralMember();
}

void GeneralMemberRepository::join(string memberId) {
    GeneralMember newMember;
    newMember.setId(memberId);
    generalMemberList.push_back(newMember);
}

// Recruitment
string Recruitment::getCompanyName() {
    return companyName;
}

string Recruitment::getBusinessNumber() {
    return businessNumber;
}

string Recruitment::getDuty() {
    return duty;
}

string Recruitment::getIntake() {
    return intake;
}

string Recruitment::getDeadline() {
    return deadline;
}

void Recruitment::setCompanyName(string companyName) {
    this->companyName = companyName;
}

void Recruitment::setBusinessNumber(string businessNumber) {
    this->businessNumber = businessNumber;
}

void Recruitment::setDuty(string duty) {
    this->duty = duty;
}

void Recruitment::setIntake(string intake) {
    this->intake = intake;
}

void Recruitment::setDeadline(string deadline) {
    this->deadline = deadline;
}

void Recruitment::addNewApplication(Application application) {
    applicationList.push_back(application);
}

// RecruitmentRepository
RecruitmentRepository* RecruitmentRepository::recruitmentRepository = nullptr;

RecruitmentRepository* RecruitmentRepository::getRecruitmentRepository() {
    if (recruitmentRepository == nullptr)
        recruitmentRepository = new RecruitmentRepository();

    return recruitmentRepository;
}

Recruitment RecruitmentRepository::getRecruitmentByCompanyName(string companyName) {
    for (auto recruitment : recruitmentList)
        if (recruitment.getCompanyName() == companyName) {
            return recruitment;
        }

    return Recruitment();
}

Recruitment RecruitmentRepository::getRecruitmentByBusinessNumber(string businessNumber) {
    for (auto recruitment : recruitmentList) {
        if (recruitment.getBusinessNumber() == businessNumber)
            return recruitment;
    }

    return Recruitment();
}

void RecruitmentRepository::addRecruitment(string companyName, string businessNumber, string duty, string intake, string deadline) {
    Recruitment newRecruitment;
    newRecruitment.setCompanyName(companyName);
    newRecruitment.setBusinessNumber(businessNumber);
    newRecruitment.setDuty(duty);
    newRecruitment.setIntake(intake);
    newRecruitment.setDeadline(deadline);

    recruitmentList.push_back(newRecruitment);
}


// Application
Application::Application(Recruitment recruitment, GeneralMember member) : recruitment(recruitment), member(member) {};

Recruitment Application::getRecruitment() {
    return recruitment;
}

GeneralMember Application::getGeneralMember() {
    return member;
}

// ApplicationRepository
ApplicationRepository* ApplicationRepository::applicationRepository = nullptr;

ApplicationRepository* ApplicationRepository::getApplicationRepository() {
    if (applicationRepository == nullptr)
        applicationRepository = new ApplicationRepository();

    return applicationRepository;
}

vector<Application> ApplicationRepository::getApplicationList(string memberId) {
    vector<Application> memberApplicationList;

    for (auto application : applicationList) {
        if (application.getGeneralMember().getId() == memberId)
            memberApplicationList.push_back(application);
    }

    return memberApplicationList;
}

Application ApplicationRepository::createApplication(Recruitment recruitment, GeneralMember member) {

    Application application(recruitment, member);

    recruitment.addNewApplication(application);
    member.addNewApplication(application);

    applicationList.push_back(application);

    return application;

}

/*
    Control
*/
// SearchRecruitment
string SearchRecruitment::showRecruitment(string companyName) {
    repository = RecruitmentRepository::getRecruitmentRepository();

    Recruitment recruitment = repository->getRecruitmentByCompanyName(companyName);

    string result = "";

    if (recruitment.getCompanyName().empty())
        result = "일치하는 회사명이 존재하지 않습니다.";
    else {
        result.append(recruitment.getCompanyName());
        result.append(" ");
        result.append(recruitment.getBusinessNumber());
        result.append(" ");
        result.append(recruitment.getDuty());
        result.append(" ");
        result.append(recruitment.getIntake());
        result.append(" ");
        result.append(recruitment.getDeadline());
    }

    return result;
}

// ApplyRecruitment
string ApplyRecruitment::applyRecruitment(string businessNumber, string memberId) {
    applicationRepository = ApplicationRepository::getApplicationRepository();
    recruitmentRepository = RecruitmentRepository::getRecruitmentRepository();
    generalMemberRepository = GeneralMemberRepository::getGeneralMemberRepository();

    Recruitment recruitment = recruitmentRepository->getRecruitmentByBusinessNumber(businessNumber);
    GeneralMember member = generalMemberRepository->getGeneralMember(memberId);

    Application newApplication = applicationRepository->createApplication(recruitment, member);

    string result = newApplication.getRecruitment().getCompanyName();
    result.append(" ");
    result.append(newApplication.getRecruitment().getBusinessNumber());
    result.append(" ");
    result.append(newApplication.getRecruitment().getDuty());

    return result;
}

// GetApplicationInfo
string GetApplicationInfo::getApplicationList(string memberId) {
    repository = ApplicationRepository::getApplicationRepository();

    vector<Application> applicationList = repository->getApplicationList(memberId);

    string result = "";

    if (applicationList.size() == 0)
        result = "지원 정보가 없습니다.\n";
    else
        for (auto application : applicationList) {
            result.append(application.getRecruitment().getCompanyName());
            result.append(" ");
            result.append(application.getRecruitment().getBusinessNumber());
            result.append(" ");
            result.append(application.getRecruitment().getDuty());
            result.append(" ");
            result.append(application.getRecruitment().getIntake());
            result.append(" ");
            result.append(application.getRecruitment().getDeadline());
            result.append("\n");
        }

    return result;
}

/*
    Boundary
*/
// SearchRecruitmentUI
void SearchRecruitmentUI::searchRecruitment(ifstream& input, ofstream& output) {
    input >> companyName;
    control = new SearchRecruitment();

    string result = control->showRecruitment(companyName);
    output << "4.1. 채용 정보 검색 \n> " << result << endl;
}

// ApplyRecruitmentUI
void ApplyRecruitmentUI::applyRecruitment(ifstream& input, ofstream& output, string memberId) {
    input >> businessNumber;
    control = new ApplyRecruitment();

    string result = control->applyRecruitment(businessNumber, memberId);

    output << "4.2. 채용 지원\n> " << result << endl;

}

// ApplicationInfoUI
void ApplicationInfoUI::showApplicationInfo(ifstream& input, ofstream& output, string memberId) {
    control = new GetApplicationInfo();

    string result = control->getApplicationList(memberId);

    output << "4.3. 지원 정보 조회\n> " << result;
}