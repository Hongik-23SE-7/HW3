#include "RecruitmentSystem.h"
#include <fstream>
using namespace std;


/*
    Entity
*/ 

// Authenticator
Authenticator* Authenticator::authenticator = nullptr;

Authenticator* Authenticator::getAuthenticator() {
    if (authenticator == nullptr) {
        authenticator = new Authenticator();
    }
    return authenticator;
}

string Authenticator::clearSession() {
    string tmp = loginId;
    this->loginId = "\0";

    return tmp;
}

void Authenticator::setLoginId(string loginId) {
    this->loginId = loginId;
}


string Authenticator::getLoginId() {
    return loginId;
}


// Member
string Member::getId() {
    return this->id;
}

bool Member::matchPassword(string password) {
    if (this->password.compare(password) == 0) {
        return true;
    }
    else {
        return false;
    }
}



// MemberRepository
MemberRepository* MemberRepository::memberRepository = nullptr;

MemberRepository* MemberRepository::getMemberRepository() {
    if (memberRepository == nullptr)
        memberRepository = new MemberRepository();

    return memberRepository;
}

bool MemberRepository::existMemberById(string id) {
    for (Member member : memberList) {
        if (member.getId() == id)
            return true;
    }
    return false;
}

Member MemberRepository::getMemberById(string id) {
    for (Member member : memberList) {
        if (member.getId() == id)
            return member;
    }
    return Member();
}

void MemberRepository::addNewMember(Member member) {
    memberList.push_back(member);
}

void MemberRepository::deleteMember(string id) {
    for (int i = 0; i < memberList.size(); i++) {
        if (memberList[i].getId().compare(id) == 0) {
            memberList.erase(memberList.begin() + i);
            return;
        }
    }
}

// CompanyMember
CompanyMember::CompanyMember(string id, string password, string companyName, string businessNumber) : Member(id, password) {
    this->companyName = companyName;
    this->businessNumber = businessNumber;
}

string CompanyMember::getBusinessNumber() {
    return businessNumber;
}

string CompanyMember::getComapnyName() {
    return companyName;
}

// GeneralMember
GeneralMember::GeneralMember(string id, string password, string name, string residentRegistrationNumber) : Member(id, password) {
    this->name = name;
    this->residentRegistrationNumber = residentRegistrationNumber;
}

string GeneralMember::getId() {
    return id;
}

void GeneralMember::addNewApplication(Application application) {
    applicationList.push_back(application);
}


// CompanyMemberRepository
CompanyMemberRepository* CompanyMemberRepository::companyMemberRepository = nullptr;

CompanyMemberRepository* CompanyMemberRepository::getCompanyMemberRepository() {
    if (companyMemberRepository == nullptr)
        companyMemberRepository = new CompanyMemberRepository();

    return companyMemberRepository;
}

CompanyMember CompanyMemberRepository::getCompanyMember(string id) {

    for (auto companyMember : companyMemberList) {
        if (companyMember.getId() == id)
            return companyMember;
    }

    return CompanyMember();
}

bool CompanyMemberRepository::existMember(string id) {
    for (CompanyMember member : companyMemberList) {
        if (member.getId() == id)
            return true;
    }
    return false;
}

void CompanyMemberRepository::addNewMember(CompanyMember member) {
    companyMemberList.push_back(member);
}

void CompanyMemberRepository::deleteMember(string id) {
    for (int i = 0; i < companyMemberList.size(); i++) {
        if (companyMemberList[i].getId().compare(id) == 0) {
            companyMemberList.erase(companyMemberList.begin() + i);
            return;
        }
    }
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

bool GeneralMemberRepository::existMember(string id) {
    for (GeneralMember member : generalMemberList) {
        if (member.getId() == id)
            return true;
    }
    return false;
}

void GeneralMemberRepository::addNewMember(GeneralMember member) {
    generalMemberList.push_back(member);
}

void GeneralMemberRepository::deleteMember(string id) {
    for (int i = 0; i < generalMemberList.size(); i++) {
        if (generalMemberList[i].getId().compare(id) == 0) {
            generalMemberList.erase(generalMemberList.begin() + i);
            return;
        }
    }
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

vector<Recruitment> RecruitmentRepository::getRecruitmentList()
{
    return recruitmentList;
}

Recruitment RecruitmentRepository::addNewRecruitment(string companyName, string businessNumber, string duty, string intake, string deadline) {
    Recruitment newRecruitment;
    newRecruitment.setCompanyName(companyName);
    newRecruitment.setBusinessNumber(businessNumber);
    newRecruitment.setDuty(duty);
    newRecruitment.setIntake(intake);
    newRecruitment.setDeadline(deadline);

    recruitmentList.push_back(newRecruitment);

    return newRecruitment;
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

//Login
bool Login::login(string id, string password) {
    generalMemberRepository = GeneralMemberRepository::getGeneralMemberRepository();
    companyMemberRepository = CompanyMemberRepository::getCompanyMemberRepository();
    authenticator = Authenticator::getAuthenticator();

    if (generalMemberRepository->existMember(id)) {
        Member member = generalMemberRepository->getGeneralMember(id);
        if (member.matchPassword(password)) {
            authenticator->setLoginId(member.getId());
            return true;
        }
    }
    if (companyMemberRepository->existMember(id)) {
        Member member = companyMemberRepository->getCompanyMember(id);
        if (member.matchPassword(password)) {
            authenticator->setLoginId(member.getId());
            return true;
        }
    }
    return false;
}

//LogOut
string LogOut::logOut() {
    authenticator = Authenticator::getAuthenticator();
    return authenticator->clearSession();
}

// SignUp
void SignUp::companyMemberSignUp(string id, string password, string companyName, string businessNumber) {
    companyMemberRepository = CompanyMemberRepository::getCompanyMemberRepository();
    CompanyMember member = { id, password, companyName, businessNumber };
    companyMemberRepository->addNewMember(member);
}

void SignUp::generalMemberSignUp(string id, string password, string name, string residentRegistrationNumber) {
    generalMemberRepository = GeneralMemberRepository::getGeneralMemberRepository();
    GeneralMember member = { id, password, name, residentRegistrationNumber };
    generalMemberRepository->addNewMember(member);
}

// Withdraw
string Withdraw::withdraw(string loginId) {
    memberRepository = MemberRepository::getMemberRepository();
    memberRepository->deleteMember(loginId);
    return loginId;
}

// RegisterRecruitment
string RegisterRecruitment::addNewRecruitment(string duty, string intake, string deadline) {
    authenticator = Authenticator::getAuthenticator();
    companyMemberRepository = CompanyMemberRepository::getCompanyMemberRepository();
    recruitmentRepository = RecruitmentRepository::getRecruitmentRepository();

    CompanyMember member = companyMemberRepository->getCompanyMember(authenticator->getLoginId());
    Recruitment recruitment = recruitmentRepository->addNewRecruitment(member.getBusinessNumber(), member.getBusinessNumber(), duty, intake, deadline);
    string result = "";

    result.append(recruitment.getDuty());
    result.append(" ");
    result.append(recruitment.getIntake());
    result.append(" ");
    result.append(recruitment.getDeadline());

    return result;
}

// SearchRegisteredRecruitment
string SearchRegisteredRecruitment::showRegisteredRecruitment() {
    repository = RecruitmentRepository::getRecruitmentRepository();

    vector<Recruitment> allRecruitments = repository->getRecruitmentList();

    string result = "";

    for (auto recruitment : allRecruitments) {
        result.append(recruitment.getDuty());
        result.append(" ");
        result.append(recruitment.getIntake());
        result.append(" ");
        result.append(recruitment.getDeadline());
        result.append("\n");
    }

    return result;
}

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
string ApplyRecruitment::applyRecruitment(string businessNumber) {
    applicationRepository = ApplicationRepository::getApplicationRepository();
    recruitmentRepository = RecruitmentRepository::getRecruitmentRepository();
    generalMemberRepository = GeneralMemberRepository::getGeneralMemberRepository();
    authenticator = Authenticator::getAuthenticator();

    Recruitment recruitment = recruitmentRepository->getRecruitmentByBusinessNumber(businessNumber);
    GeneralMember member = generalMemberRepository->getGeneralMember(authenticator->getLoginId());

    Application newApplication = applicationRepository->createApplication(recruitment, member);

    string result = newApplication.getRecruitment().getCompanyName();
    result.append(" ");
    result.append(newApplication.getRecruitment().getBusinessNumber());
    result.append(" ");
    result.append(newApplication.getRecruitment().getDuty());

    return result;
}

// GetApplicationInfo
string GetApplicationInfo::getApplicationList() {
    authenticator = Authenticator::getAuthenticator();
    generalMemberRepository = GeneralMemberRepository::getGeneralMemberRepository();
    applicationRepository = ApplicationRepository::getApplicationRepository();

    GeneralMember member = generalMemberRepository->getGeneralMember(authenticator->getLoginId());

    vector<Application> applicationList = applicationRepository->getApplicationList(member.getId());

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
// LogInUI
void LoginUI::login(ifstream& input, ofstream& output) {
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
    }
    else {
        return;
    }
}

// LogOutUI
void LogOutUI::logOut(std::ofstream& output) {
    control = new LogOut();
    string logOutId = control->logOut();

    output << "2.2. 로그아웃 \n> " << logOutId << endl;
}

// SignUpUI
void SignUpUI::companyMemberSignUp(std::ifstream& input, std::ofstream& output) {
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

void SignUpUI::generalMemberSignUp(std::ifstream& input, std::ofstream& output) {
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

// WithdrawUI
void WithdrawUI::withdraw(std::ofstream& output) {
    LogOut* logOut = new LogOut;
    string logOutId = logOut->logOut();

    Withdraw* withdraw = new Withdraw();
    string withdrawId = withdraw->withdraw(logOutId);

    output << "1.2. 회원탈퇴 \n> " << withdrawId << endl;
}

// RegisterRecruitmentUI
void RegisterRecruitmentUI::registerRecruitment(ifstream& input, ofstream& output) {
    input >> duty >> deadline >> intake;
    control = new RegisterRecruitment();

    string result = control->addNewRecruitment(duty, deadline, intake);
    output << "3.1 채용 정보 등록\n> " << result << endl;
}

// SearchRegisterRecruitmentUI
void SearchRegisteredRecruitmentUI::searchRegisteredRecruitment(ifstream& input, ofstream& output) {
    control = new SearchRegisteredRecruitment();

    string result = control->showRegisteredRecruitment();
    output << "3.2 등록 채용 정보 조회\n> " << result << endl;
}

// ApplyRecruitmentUI
void ApplyRecruitmentUI::applyRecruitment(ifstream& input, ofstream& output) {
    input >> businessNumber;
    control = new ApplyRecruitment();

    string result = control->applyRecruitment(businessNumber);

    output << "4.2. 채용 지원\n> " << result << endl;

}

// SearchRecruitmentUI
void SearchRecruitmentUI::searchRecruitment(ifstream& input, ofstream& output) {
    input >> companyName;
    control = new SearchRecruitment();

    string result = control->showRecruitment(companyName);
    output << "4.1. 채용 정보 검색 \n> " << result << endl;
}

// ApplicationInfoUI
void ApplicationInfoUI::showApplicationInfo(ifstream& input, ofstream& output) {
    control = new GetApplicationInfo();

    string result = control->getApplicationList();

    output << "4.3. 지원 정보 조회\n> " << result;
}