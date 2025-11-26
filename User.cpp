#include "User.h"
#include "Utility.h"

User::User(const std::string &_username, const std::string &_password):
    username(_username), password(_password) {
    id = Utility::IDGenerator();
}

void User::setUserName(const std::string &_n) {
    username = _n;
}

void User::setPassword(const std::string &_password) {
    password = _password;
}

const std::string& User::getUserName() const {
    return username;
}

const std::string& User::getPassword() const {
    return password;
}

const std::string& User::getId() const {
    return id;
}