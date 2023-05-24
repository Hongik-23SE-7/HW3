#include "SearchRegisteredRecruitment.hpp"
#include <iostream>
using namespace std;

string SearchRegisteredRecruitment::showRegisteredRecruitment() {
    repository = RecruitmentRepository::getRecruitmentRepository();

    vector<Recruitment> allRecruitments = repository->getRecruitmentData();

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
