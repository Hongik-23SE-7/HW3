#include "SignUp.hpp"
#include "../entity/CompanyMember.hpp"

using namespace std;

void SignUp::signUp(string id, string password, string companyName, string businessNumber) {
    repository = MemberRepository::getMemberRepository();
    CompanyMember member = {id, password, companyName, businessNumber};
    repository->addNewMember(member);
}