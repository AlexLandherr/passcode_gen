#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unordered_map>
#include <stdexcept>
#include "include/validators.h"

/*Gör en funktion som skapar en slumpmässig fyrsiffrig portkod med följande villkor:
- Koden får börja med vilken siffra som helst, inklusive 0, men inte med 1
- Ingen siffra i koden får finnas mer än två gånger. 2234 är ok men inte 2232.

Knapparna på en koddosa sitter enligt följande:
1 2 3
4 5 6
7 8 9
  0

Villkoret är att varje siffra ska ligga intill siffran före. D.v.s. efter siffran 2 får det bara komma 1, 3, 4, 5, 6, eller 2.
Efter 7 får det bara komma 4, 5, 8, 0 eller 7, osv.
Koden 5968 är ok. Koden 5961 är inte ok.*/

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
            try {
                random_num_str = validator::zero_padded_num(random_num_str, 4);
            } catch (const std::invalid_argument& ex) {
                std::cout << ex.what() << '\n';
            } catch (const std::exception& ex) {
                std::cout << ex.what() << '\n';
            }
        }
        try {
            if (validator::not_start_with(random_num_str, banned_start_char) && !validator::exceeds_max_occurrence(random_num_str, max_occurrence_count)) {
                std::cout << random_num_str << '\n';
                random_num_count++;
            }
        } catch (const std::invalid_argument& ex) {
            std::cout << ex.what() << '\n';
        } catch (const std::exception& ex) {
            std::cout << ex.what() << '\n';
        }
    }
    
    return 0;
}
