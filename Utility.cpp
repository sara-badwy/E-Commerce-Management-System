#include "Utility.h"
#include <sstream>
#include <ctime>
#include <random>
#include <iomanip>
#include <iostream>
int Utility:: cnt = 0;
std :: string Utility:: IDGenerator() {
    std :: stringstream ss;
    auto t = std :: time(nullptr);
    std::mt19937 rng(static_cast<unsigned>(t + cnt));
    std::uniform_int_distribution<int> dist(1000, 9999);
    ss << std::setw(4) << std::setfill('0') << cnt++ << "-" << dist(rng);
    return ss.str();
}
