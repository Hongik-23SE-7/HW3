#ifndef SearchRegisteredRecruitment_hpp
#define SearchRegisteredRecruitment_hpp

#include <iostream>
#include "RecruitmentRepository.hpp"

class RecruitmentRepository;

class SearchRegisteredRecruitment {
private:
    RecruitmentRepository* repository;

public:
    string showRegisteredRecruitment();
};

#endif
