#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

class User {
protected:
    std::string username, password, id;
public:
    User(const std::string &_username, const std::string &_password);
    virtual ~User() = default;

    void setUserName(const std::string &_n);
    void setPassword(const std::string &_password);

    const std::string& getUserName() const;
    const std::string& getPassword() const;
    const std::string& getId() const;
};

#endif