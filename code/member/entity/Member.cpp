#include "Member.hpp"

string Member::getId() {
    return this->id;
}

bool Member::matchPassword(std::string password) {
    if (this->password.compare(password) == 0) {
        return true;
    } else {
        return false;
    }
}
