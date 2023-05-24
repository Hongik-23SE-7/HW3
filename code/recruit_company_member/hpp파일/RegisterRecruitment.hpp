#ifndef RegisterRecruitment_hpp
#define RegisterRecruitment_hpp

#include <iostream>
#include "RecruitmentRepository.hpp"

class RecruitmentRepository;

class RegisterRecruitment {
private:
    RecruitmentRepository *repository;

public:
    string addNewRecruitment(string duty, string intake, string deadlline);
};

#endif
