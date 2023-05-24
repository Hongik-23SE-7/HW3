#ifndef RecruitmentRepository_hpp
#define RecruitmentRepository_hpp

#include <iostream>
#include <vector>
#include "Recruitment.hpp"
using namespace std;

class RecruitmentRepository {
private:
    static RecruitmentRepository* recruitmentRepository;
    vector<Recruitment> recruitmentList;
    
public:
    static RecruitmentRepository* getRecruitmentRepository();
    Recruitment getRecruitmentByCompanyName(string companyName);
    Recruitment getRecruitmentByBusinessNumber(string businessNumber);
    Recruitment addNewRecruitment(string duty, string intake, string deadline);
    vector<Recruitment> getRecruitmentData();
};

#endif
