#include "include/validators.h"
#include <string>
#include <unordered_map>
#include <limits>
#include <stdexcept>

namespace validator {
    bool not_start_with(std::string num_str, char forbidden) {
        //Checks if given string does NOT start with given char.
        if (forbidden > std::numeric_limits<char>::max() || forbidden < std::numeric_limits<char>::min()) {
            throw std::invalid_argument("Argument 'target_char' is out of range for 'char' type.");
        }
        return !num_str.starts_with(forbidden);
    }

    std::string zero_padded_num(std::string str, size_t field_width) {
        //Takes a std::string representing an integer and zero-padds it to a given width to ensure a fixed width std::string as a result.
        if (field_width > std::numeric_limits<size_t>::max() || field_width < std::numeric_limits<size_t>::min()) {
            throw std::invalid_argument("Argument 'field_width' is out of range for 'size_t' type in this case.");
        }
        int precision = field_width - std::min(field_width, str.size());
        return std::string(precision, '0').append(str);
    }

    bool exceeds_max_occurrence(std::string s, int max_occurrence) {
        //Checks if any character occurrs more than max_occurrence times in std::string s.
        if (max_occurrence > std::numeric_limits<int>::max() || max_occurrence < 1) {
            throw std::invalid_argument("Argument 'max_occurrence' is out of range for 'int' type or less than 1.");
        }
        std::unordered_map<char, int> m;
        bool result = false;
    
        for (int i = 0; i < static_cast<int>(s.length()); i++) {
            m[s[i]]++; 
        }
        
        for (const auto& [key, value] : m) {
            if (value > max_occurrence) {
                result = true;
            }
        }
    
        return result;
    }
}