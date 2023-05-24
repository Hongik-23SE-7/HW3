#ifndef BoundaryClass_hpp
#define BoundaryClass_hpp

#include <iostream>
#include <fstream>
#include "RegisterRecruitment.hpp"
#include "SearchRegisteredRecruitment.hpp"
#include "SearchRecruitment.hpp"
#include "ApplyRecruitment.hpp"

class RegisterRecruitmentUI {
private:
    RegisterRecruitment *control;

    string duty;
    string deadline;
    string intake;

public:
    void registerRecruitment(ifstream& input, ofstream& output);
};

class SearchRegisteredRecruitmentUI {
private:
    SearchRegisteredRecruitment *control;

public:
    void searchRegisteredRecruitment(ifstream& input, ofstream& output);
};

class SearchRecruitmentUI {
private:
    SearchRecruitment *control;
    string companyName;
    
public:
    void searchRecruitment(ifstream& input, ofstream& output);
};


class ApplyRecruitmentUI {
private:
    ApplyRecruitment *control;
    string businessNumber;
    
public:
    void applyRecruitment(ifstream& input, ofstream& output, string memberId);
};

#endif


