#include "Utility.hpp"



bool Utility::isValid(const char* name) {
    if (name == nullptr || name[0] == '\0') {
        return false;
    }

    for (unsigned int i = 0; name[i] != '\0'; ++i) {
        if (name[i] != ' ') {
            return true;
        }
    }

    return false;
}
