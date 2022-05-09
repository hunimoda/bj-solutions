#include <iostream>

int init_value {};
int count[3] {};

void count_digits_in_range(const int, const int, const int);


int main() {

    int left {};
    int right {};
    int n {};

    std::cin >> init_value >> left >> right >> n;
    count_digits_in_range(n, left, right);

    for (int i {}; i < 3; i++) {
        std::cout << count[i] << ' ';
    }
    std::cout << std::endl;

    return 0;

}

/*** Helper Functions ************************************/
void increment_count_for(const int digit) {

    count[digit - 1]++;

}


void decrement_count_for(const int digit) {

    count[digit - 1]--;

}


void reset_count() {

    for (int i {0}; i < 3; i++) {
        count[i] = 0;
    }

}


void calculate_next_count() {

    int prev_count[3] { count[0], count[1], count[2] };

    count[0] = 1 * prev_count[0] + 2 * prev_count[1] + 0 * prev_count[2];
    count[1] = 1 * prev_count[0] + 1 * prev_count[1] + 2 * prev_count[2];
    count[2] = 1 * prev_count[0] + 0 * prev_count[1] + 1 * prev_count[2];

}
/*********************************************************/


void count_digits_in_range(const int n, const int left, const int right) {

    /*** STATIC ******************************************/
    static int sequence[3][3] {
        { 1, 3, 2 }, 
        { 2, 1, 1 }, 
        { 2, 3, 2 }
    };

    static int left_digit[21] {};
    static int right_digit[21] {};
    /*****************************************************/

    /*** Base Case ***************************************/
    if (n == 0) {
        left_digit[0] = init_value;
        right_digit[0] = init_value;

        reset_count();
        increment_count_for(init_value);
        return;
    }

    /*** Recursion ***************************************/
    const int parent_left { left / 3 };
    const int parent_right { right / 3 };

    count_digits_in_range(n - 1, parent_left, parent_right);
    // left_digit[n - 1] & right_digit[n - 1] are up-to-date

    calculate_next_count();

    /*** Uncount out of range digits *********************/
    const int left_offset { left % 3 };
    const int right_offset { right % 3 };

    const int parent_left_digit { left_digit[n - 1] };
    const int parent_right_digit { right_digit[n - 1] };

    for (int l {0}; l < left_offset; l++) {
        const int digit_to_uncount = 
                sequence[parent_left_digit - 1][l];
        decrement_count_for(digit_to_uncount);
    }
    for (int r {2}; r > right_offset; r--) {
        const int digit_to_uncount = 
                sequence[parent_right_digit - 1][r];
        decrement_count_for(digit_to_uncount);
    }

    /*** Update left_digit & right_digit for stage n *****/
    left_digit[n] = sequence[parent_left_digit - 1][left_offset];
    right_digit[n] = sequence[parent_right_digit - 1][right_offset];

}