#include "RegisterRecruitment.hpp"
#include <iostream>
using namespace std;

string RegisterRecruitment::addNewRecruitment(string duty, string intake,string deadline) {
    repository = RecruitmentRepository::getRecruitmentRepository();

    Recruitment recruitment = repository->addNewRecruitment(duty, intake, deadline);
    string result = "";

    result.append(recruitment.getDuty());
    result.append(" ");
    result.append(recruitment.getIntake());
    result.append(" ");
    result.append(recruitment.getDeadline());

    return result;
    }
