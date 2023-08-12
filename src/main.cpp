#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unordered_map>

/*Gör en funktion som skapar en slumpmässig fyrsiffrig portkod med följande villkor:
- Koden får börja med vilken siffra som helst, inklusive 0, men inte med 1
- Ingen siffra i koden får finnas mer än två gånger. 2234 är ok men inte 2232.*/

bool not_start_with(std::string num_str, char forbidden);
std::string zero_padded_num(std::string str, size_t field_width);
bool exceeds_max_occurrence(std::string s, int max_occurrence);

int main() {
    std::srand(std::time(nullptr)); //Use current time as seed for random generator.
    const int offset = 0;
    const int range = 10000;
    int random_num_count = 0;
    const char banned_start_char = '1';
    const int max_occurrence_count = 2;

    while (random_num_count < 10) {
        int random_num = offset + (std::rand() % range);
        std::string random_num_str = std::to_string(random_num);
        if (random_num_str.length() != 4) {
            random_num_str = zero_padded_num(random_num_str, 4);
        }
        if (not_start_with(random_num_str, banned_start_char) && !exceeds_max_occurrence(random_num_str, max_occurrence_count)) {
            std::cout << random_num_str << '\n';
            random_num_count++;
        }
    }
    
    return 0;
}

bool not_start_with(std::string num_str, char forbidden) {
    //Checks if given string does NOT start with given char.
    return !num_str.starts_with(forbidden);
}

std::string zero_padded_num(std::string str, size_t field_width) {
    if (field_width > std::numeric_limits<size_t>::max() || field_width < std::numeric_limits<size_t>::min()) {
        throw std::invalid_argument("Argument 'field_width' is out of range for 'size_t' type in this case.");
    }
    int precision = field_width - std::min(field_width, str.size());
    return std::string(precision, '0').append(str);
}

bool exceeds_max_occurrence(std::string s, int max_occurrence) {
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
