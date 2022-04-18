#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int test_cases {};
    cin >> test_cases;

    for (int i {0}; i < test_cases; ++i) {
        int start_position {};
        int end_position {};

        cin >> start_position >> end_position;

        const int distance {end_position - start_position};
        const int max_step {static_cast<int>(floor(sqrt(distance)))};
        const int max_step_square {static_cast<int>(pow(max_step, 2))};

        if (distance == max_step_square) {
            cout << (2 * max_step - 1) << endl;
        } else if (distance <= max_step_square + max_step) {
            cout << (2 * max_step) << endl;
        } else {
            cout << (2 * max_step + 1) << endl;
        }
    }

    return 0;

}