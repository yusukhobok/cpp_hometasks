#ifndef HOMETASK_02_IP_ADDRESS_H
#define HOMETASK_02_IP_ADDRESS_H

#include <tuple>

struct IpAddress {
    int first;
    int second;
    int third;
    int forth;

    bool operator<(const IpAddress &rhs) {
        return std::tie(this->first, this->second, this->third, this->forth) <
               std::tie(rhs.first, rhs.second, rhs.third, rhs.forth);
    }
};

std::ostream &operator<<(std::ostream &os, const IpAddress &ip);

#endif //HOMETASK_02_IP_ADDRESS_H
