#include "RecruitmentRepository.hpp"

RecruitmentRepository* RecruitmentRepository::recruitmentRepository = nullptr;

RecruitmentRepository* RecruitmentRepository::getRecruitmentRepository() {
    if(recruitmentRepository == nullptr)
        recruitmentRepository = new RecruitmentRepository();
    
    return recruitmentRepository;
}

Recruitment RecruitmentRepository::getRecruitmentByCompanyName(string companyName) {
    for(auto recruitment : recruitmentList)
        if(recruitment.getCompanyName() == companyName) {
            return recruitment;
        }
            
    
    return Recruitment();
}

Recruitment RecruitmentRepository::getRecruitmentByBusinessNumber(string businessNumber) {
    for(auto recruitment : recruitmentList) {
        if(recruitment.getBusinessNumber() == businessNumber)
            return recruitment;
    }
    
    return Recruitment();
}

Recruitment RecruitmentRepository::addNewRecruitment(string duty, string intake, string deadline) {
    Recruitment newRecruitment;
    newRecruitment.setDuty(duty);
    newRecruitment.setIntake(intake);
    newRecruitment.setDeadline(deadline);

    recruitmentList.push_back(newRecruitment);

    return newRecruitment;
}

vector<Recruitment> RecruitmentRepository::getRecruitmentData()
{
    return recruitmentList;
}
