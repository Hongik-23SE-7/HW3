#ifndef RecruitmentSystem_h
#define RecruitmentSystem_h
#include <iostream>
#include <vector>
using namespace std;


// Entity

class Authenticator {
private:
    static Authenticator* authenticator;
    string loginId;

public:
    static Authenticator* getAuthenticator();
    string clearSession();
    void setLoginId(string loginId);
    string getLoginId();
};


class Member {
private:
    string id;
    string password;
public:
    Member() {};
    Member(string id, string password) {
        this->id = id;
        this->password = password;
    }
    string getId();

    bool matchPassword(string password);
};


class MemberRepository {
private:
    static MemberRepository* memberRepository;
    vector<Member> memberList;

public:
    static MemberRepository* getMemberRepository();
    Member getMemberById(string id);
    bool existMemberById(string id);
    void addNewMember(Member member);
    void deleteMember(string id);
};


class CompanyMember : public Member {
private:
    string companyName;
    string businessNumber;
public:
    CompanyMember() {};
    CompanyMember(string id, string password, string companyName, string businessNumber);
    string getComapnyName();
    string getBusinessNumber();
};


class CompanyMemberRepository {
private:
    static CompanyMemberRepository* companyMemberRepository;
    vector<CompanyMember> companyMemberList;
public:
    static CompanyMemberRepository* getCompanyMemberRepository();
    CompanyMember getCompanyMember(string id);
    void addNewMember(CompanyMember member);
    bool existMember(string id);
    void deleteMember(string id);
};


class Application;

class GeneralMember : public Member {
private:
    string id;
    string name;
    string residentRegistrationNumber;
    vector<Application> applicationList;
public:
    GeneralMember() {};
    GeneralMember(string id, string password, string name, string residentRegistrationNumber);
    string getId();
    void addNewApplication(Application application);
};


class GeneralMemberRepository {
private:
    static GeneralMemberRepository* generalMemberRepository;
    vector<GeneralMember> generalMemberList;
public:
    static GeneralMemberRepository* getGeneralMemberRepository();
    GeneralMember getGeneralMember(string id);
    void addNewMember(GeneralMember member);
    bool existMember(string id);
    void deleteMember(string id);
};


class Recruitment {
private:
    string companyName;
    string businessNumber;
    string duty;
    string intake;
    string deadline;
    vector<Application> applicationList;

public:
    string getCompanyName();
    string getBusinessNumber();
    string getDuty();
    string getIntake();
    string getDeadline();
    void setCompanyName(string companyName);
    void setBusinessNumber(string businessNumber);
    void setDuty(string duty);
    void setIntake(string intake);
    void setDeadline(string deadline);
    void addNewApplication(Application application);
};


class RecruitmentRepository {
private:
    static RecruitmentRepository* recruitmentRepository;
    vector<Recruitment> recruitmentList;

public:
    static RecruitmentRepository* getRecruitmentRepository();
    Recruitment getRecruitmentByCompanyName(string companyName);
    Recruitment getRecruitmentByBusinessNumber(string businessNumber);
    Recruitment addNewRecruitment(string companyName, string businessNumber, string duty, string intake, string deadline);
    vector<Recruitment> getRecruitmentList();
};


class Application {
private:
    Recruitment recruitment;
    GeneralMember member;
public:
    Application(Recruitment recruitment, GeneralMember member);
    Recruitment getRecruitment();
    GeneralMember getGeneralMember();
};


class ApplicationRepository {
private:
    static ApplicationRepository* applicationRepository;
    vector<Application> applicationList;
public:
    static ApplicationRepository* getApplicationRepository();
    vector<Application> getApplicationList(string memberId);
    Application createApplication(Recruitment recruitment, GeneralMember member);
};


// Control

class Login {
private:
    Authenticator* authenticator;
    GeneralMemberRepository* generalMemberRepository;
    CompanyMemberRepository* companyMemberRepository;
public:
    bool login(string id, string password);
};


class LogOut {
private:
    Authenticator* authenticator;
public:
    string logOut();
};


class SignUp {
private:
    GeneralMemberRepository* generalMemberRepository;
    CompanyMemberRepository* companyMemberRepository;

public:
    void companyMemberSignUp(string id, string password, string companyName, string businessNumber);
    void generalMemberSignUp(string id, string password, string name, string residentRegistrationNumber);
};


class Withdraw {
private:
    MemberRepository* memberRepository;
public:
    string withdraw(string loginId);
};


class RecruitmentRepository;

class RegisterRecruitment {
private:
    Authenticator* authenticator;
    CompanyMemberRepository* companyMemberRepository;
    RecruitmentRepository* recruitmentRepository;

public:
    string addNewRecruitment(string duty, string intake, string deadlline);
};


class SearchRecruitment {
private:
    RecruitmentRepository* repository;

public:
    string showRecruitment(string companyName);
};


class SearchRegisteredRecruitment {
private:
    RecruitmentRepository* repository;

public:
    string showRegisteredRecruitment();
};


class ApplyRecruitment {
private:
    Authenticator* authenticator;
    ApplicationRepository* applicationRepository;
    RecruitmentRepository* recruitmentRepository;
    GeneralMemberRepository* generalMemberRepository;
public:
    string applyRecruitment(string businessNumber);
};


class GetApplicationInfo {
private:
    Authenticator* authenticator;
    GeneralMemberRepository* generalMemberRepository;
    ApplicationRepository* applicationRepository;

public:
    string getApplicationList();
};


// Boundary
class LoginUI {
private:
    Login* control;
public:
    void login(ifstream& input, ofstream& output);
};


class LogOutUI {
private:
    LogOut* control;
public:
    void logOut(ofstream& output);
};


class SignUpUI {
private:
    SignUp* control;

public:
    void companyMemberSignUp(ifstream& input, ofstream& output);
    void generalMemberSignUp(ifstream& input, ofstream& output);
};


class WithdrawUI {
private:
    Withdraw* control;
public:
    void withdraw(ofstream& output);
};


class RegisterRecruitmentUI {
private:
    RegisterRecruitment* control;

    string duty;
    string deadline;
    string intake;

public:
    void registerRecruitment(ifstream& input, ofstream& output);
};

class SearchRegisteredRecruitmentUI {
private:
    SearchRegisteredRecruitment* control;

public:
    void searchRegisteredRecruitment(ifstream& input, ofstream& output);
};


class ApplyRecruitmentUI {
private:
    ApplyRecruitment* control;
    string businessNumber;

public:
    void applyRecruitment(ifstream& input, ofstream& output);
};

class SearchRecruitmentUI {
private:
    SearchRecruitment* control;
    string companyName;

public:
    void searchRecruitment(ifstream& input, ofstream& output);
};


class ApplicationInfoUI {
private:
    GetApplicationInfo* control;
public:
    void showApplicationInfo(ifstream& input, ofstream& output);
};

#endif

