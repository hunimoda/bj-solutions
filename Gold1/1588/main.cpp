#include <iostream>


int get_digit_by(const int n, const int idx, const int init_value) {

    /*** Sequence after 1 second ********/
    static int sequence[3][3] {
        { 1, 3, 2 }, 
        { 2, 1, 1 }, 
        { 2, 3, 2 }
    };
    /************************************/

    if (n == 0) return init_value;

    const int parent_idx { idx / 3 };
    const int parent_digit {
        get_digit_by(n - 1, parent_idx, init_value)
    };

    return sequence[parent_digit - 1][idx % 3];

}


int main() {

    int count[3] {};

    int init_value {};
    int left {};
    int right {};
    int n {};

    std::cin >> init_value >> left >> right >> n;

    for (int i { left }; i <= right; i++) {
        count[get_digit_by(n, i, init_value) - 1]++;
    }

    for (int i {}; i < 3; i++) {
        std::cout << count[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;

}