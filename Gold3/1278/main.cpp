#include <iostream>
#include <string>
#include <cmath>

void get_actor_order(int, std::string &);


int main() {

    int n {};
    std::cin >> n;

    const int num_of_scenes {
        static_cast<int>(std::pow(2, n)) - 1
    };
    std::string order {""};

    std::cout << num_of_scenes << "\n";

    get_actor_order(n, order);
    std::cout << order;

    std::cout << n << "\n";    // Actor N acts alone last

    return 0;

}


void get_actor_order(int n, std::string &order) {

    if (n == 1) {
        order = "1\n";
        return;
    }

    get_actor_order(n - 1, order);
    order += std::to_string(n) + "\n" + order;

}