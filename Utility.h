#ifndef UNTITLED2_utility_H
#define UNTITLED2_utility_H
#include <string>
class Utility {
private:
    static int cnt;
    Utility() = default;
public:
    static std::string IDGenerator();
};
#endif
