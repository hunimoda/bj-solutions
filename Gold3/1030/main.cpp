#include <iostream>

int n;
int k;

int get_parent_idx(int);
bool is_parent_black(int, int);
bool is_idx_center(int);
bool is_new_center(int, int);
bool is_black(int, int);


int main() {

    int s, r1, r2, c1, c2;
    std::cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            std::cout << is_black(i, j);
        }
        std::cout << std::endl;
    }

}


int get_parent_idx(int idx) {

    return idx / n;

}


bool is_parent_black(int i, int j) {

    int parent_i = get_parent_idx(i);
    int parent_j = get_parent_idx(j);

    return is_black(parent_i, parent_j);

}


bool is_idx_center(int idx) {

    return ((n - k) / 2 <= idx && idx < (n + k) / 2);

}


bool is_new_center(int i, int j) {

    i %= n;
    j %= n;

    return is_idx_center(i) && is_idx_center(j);

}


bool is_black(int i, int j) {
    if (i == 0 && j == 0) return false;

    // If parent was black, I am black
    if (is_parent_black(i, j)) return true;

    // If I am the new center, I am black
    if (is_new_center(i, j)) return true;

    // but if I am not, I am white
    return false;

}