#include <string>

#ifndef VALIDATORS_H
#define VALIDATORS_H

namespace validator {
    bool not_start_with(std::string num_str, char forbidden);
    std::string zero_padded_num(std::string str, size_t field_width);
    bool exceeds_max_occurrence(std::string s, int max_occurrence);
}

#endif