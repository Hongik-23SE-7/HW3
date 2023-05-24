#include "SignUp.hpp"

using namespace std;

void SignUp::signUp(std::string id, std::string password, std::string name) {
    repository = MemberRepository::getMemberRepository();
    Member member = {id, password, name};
    repository->addNewMember(member);
}