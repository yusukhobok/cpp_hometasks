#include <iostream>

#include "ip_address.h"


std::ostream &operator<<(std::ostream &os, const IpAddress &ip) {
    os << ip.first << "." << ip.second << "." << ip.third << "." << ip.forth << std::endl;
    return os;
}