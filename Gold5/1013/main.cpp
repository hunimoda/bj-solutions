#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool pattern_matches(string);


int main() {

    // Get num of test cases
    int num_of_tests {};
    cin >> num_of_tests;

    string test_case {};

    // Loop for num of test cases
    for (int i {0}; i < num_of_tests; ++i) {

        // Get test case input
        cin >> test_case;

        // Check if test case passes and print YES
        if (pattern_matches(test_case)) {
            cout << "YES" << endl;
        }

        // Print NO if it doesn't pass
        else {
            cout << "NO" << endl;
        }

    }

    return 0;

}


/***************************
 * Check if pattern matches
 *  Pattern A: 100+1+
 *  Pattern B: 01
 ***************************/
bool pattern_matches(string pattern) {

    // Check for pattern until it becomes empty
    while (pattern.size() > 0) {
        
        size_t pattern_size = pattern.size();

        // If pattern size is 1, no pattern matches
        if (pattern_size == 1) return false;

        // If the pattern starts with B, 
        if (pattern.substr(0, 2) == "01") {

            // remove B from pattern and continue checking
            pattern.erase(0, 2);
            continue;

        }
        
        // Pattern A is at least length 4
        if (pattern_size < 4) return false;

        // Pattern A must start with "100"
        if (pattern.substr(0, 3) != "100") return false;

        int last_index {3};

        // Move the index until it meets its first '1'
        while (pattern.at(last_index) == '0') {
            
            // If no '1' was found until the end, pattern doesn't match
            if (last_index >= pattern_size - 1) {
                return false;
            }

            last_index++;

        }

        // If the pattern ends with '1', the pattern matches
        if (last_index >= pattern_size - 1) return true;

        // If the first '1' is followed immediately by '0',
        // remove A from pattern and continue checking
        if (pattern.at(++last_index) == '0') {

            pattern.erase(0, last_index);
            continue;

        }

        // Move the index until it meets its last '1'
        while (pattern.at(last_index) == '1') {

            // If the pattern ends with ones, the pattern matches
            if (last_index >= pattern_size - 1) {
                return true;
            }

            last_index++;

        }
        last_index--;

        // Check for pattern starting from last_index or (last_index + 1)
        return pattern_matches(pattern.substr(last_index)) || 
                pattern_matches(pattern.substr(last_index + 1));

    }
    
    // When no pattern is left, the pattern matches
    return true;

}