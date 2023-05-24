#include "SignUp.hpp"

using namespace std;

void SignUp::companyMemberSignUp(string id, string password, string companyName, string businessNumber) {
    repository = MemberRepository::getMemberRepository();
    CompanyMember member = {id, password, companyName, businessNumber};
    repository->addNewMember(member);
}

void SignUp::generalMemberSignUp(string id, string password, string name, string residentRegistrationNumber) {
    repository = MemberRepository::getMemberRepository();
    GeneralMember member = {id, password, name, residentRegistrationNumber};
    repository->addNewMember(member);
}
