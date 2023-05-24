#ifndef RecruitmentSystem_h
#define RecruitmentSystem_h
#include <iostream>
#include <vector>
using namespace std;


// Entity

class Application;


class GeneralMember {
private:
    string id;
    vector<Application> applicationList;
public:
    void setId(string id);
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
    void join(string memberId);
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
    void addRecruitment(string companyName, string businessNumber, string duty, string intake, string deadline);
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


class SearchRecruitment {
private:
    RecruitmentRepository* repository;

public:
    string showRecruitment(string companyName);
};


class ApplyRecruitment {
private:
    ApplicationRepository* applicationRepository;
    RecruitmentRepository* recruitmentRepository;
    GeneralMemberRepository* generalMemberRepository;
public:
    string applyRecruitment(string businessNumber, string memberId);
};


class GetApplicationInfo {
private:
    ApplicationRepository* repository;

public:
    string getApplicationList(string memberId);
};


// Boundary

class SearchRecruitmentUI {
private:
    SearchRecruitment* control;
    string companyName;

public:
    void searchRecruitment(ifstream& input, ofstream& output);
};


class ApplyRecruitmentUI {
private:
    ApplyRecruitment* control;
    string businessNumber;

public:
    void applyRecruitment(ifstream& input, ofstream& output, string memberId);
};


class ApplicationInfoUI {
private:
    GetApplicationInfo* control;
public:
    void showApplicationInfo(ifstream& input, ofstream& output, string memberId);
};

#endif

