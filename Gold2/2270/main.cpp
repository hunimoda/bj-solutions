#include <iostream>
#include <vector>
#include <cmath>


class Rod {

private:
    std::vector<int> disks;

public:
    void push(int);
    bool is_empty() const;
    int get_top_disk() const;
    void move_n_disks_to(Rod *, int);
    void show_disks() const {
        for (int i {}; i < disks.size(); i++) {
            std::cout << disks.at(i) << ' ';
        }
        std::cout << std::endl;
    }

};


void solve(Rod *[3], int &, int &);


int main() {

    int total_disk_count {};
    int init_disk_count[3] {};

    // Row [1]: Input total number of disks
    std::cin >> total_disk_count;

    // Row [2]: Input initial number of disks for each rod
    for (int i {}; i < 3; i++) {
        std::cin >> init_disk_count[i];
    }

    Rod *rods[3] {};

    // Row [3] ~ Row [5]: Input disk numbers for each rod
    for (int r {}; r < 3; r++) {
        rods[r] = new Rod;  // Create Rod object

        for (int i {}; i < init_disk_count[r]; i++) {
            int disk {};
            std::cin >> disk;

            // Push disk in each rod
            rods[r]->push(disk);
        }
    }

    int des_rod {};
    int move_count {};
    /*** Calculate **************************************/
    solve(rods, des_rod, move_count);
    /****************************************************/

    // Show calculation results
    std::cout << des_rod << "\n";
    std::cout << move_count << std::endl;

    // Delete Rod objects
    for (int r {}; r < 3; r++) {
        delete rods[r];
    }

    return 0;

}


/*** Rod class method implementations *******************/
void Rod::push(int disk) {

    disks.push_back(disk);

}


bool Rod::is_empty() const {

    return (disks.size() == 0);

}


int Rod::get_top_disk() const {

    return disks.at(disks.size() - 1);

}


void Rod::move_n_disks_to(Rod *des, int num_of_disks) {

    for (int i {}; i < num_of_disks; i++) {
        disks.pop_back();
        des->push(num_of_disks - i);
    }    

}


/*** Helper Functions ***********************************/

int get_complete_disk(Rod *rods[3]) {

    int complete_disk { -1 };

    for (int i {}; i < 3; i++) {
        if (rods[i]->is_empty()) continue;

        if (complete_disk >= 0) return -1;

        complete_disk = i;
    }

    return complete_disk;

}


void find_two_smallest_rods(Rod *rods[3], 
        int &rod_w_disk_1, int &rod_w_top_disk) {

    int top_disk_until_now { -1 };

    for (int r {}; r < 3; r++) {
        if (rods[r]->is_empty()) continue;

        const int curr_top_disk {
            rods[r]->get_top_disk()
        };

        if (curr_top_disk == 1) {
            rod_w_disk_1 = r;
        } else if (top_disk_until_now == -1) {
            top_disk_until_now = curr_top_disk;
            rod_w_top_disk = r;
        } else if (curr_top_disk < top_disk_until_now) {
            rod_w_top_disk = r;
        }
    }

}

/*** MAIN ALGORITHM *************************************/
void solve(Rod *rods[3], int &des_rod, int &move_count) {

    // If all the disks are moved(= only one rod 
    // contains disks), update des_rod to the rod number
    // that contains all disks and return
    const int complete_disk { get_complete_disk(rods) };

    if (complete_disk >= 0) {
        des_rod = complete_disk;
        return;
    }

    // Find two rods each with disk 1 & second-least 
    // top disk, say 'top_disk'
    int rod_w_disk_1 {};
    int rod_w_top_disk {};
    
    find_two_smallest_rods(rods, rod_w_disk_1, rod_w_top_disk);
    std::cout << rod_w_disk_1 << ' ' << rod_w_top_disk << std::endl;
    const int top_disk {
        rods[rod_w_top_disk]->get_top_disk()
    };

    // Move disk 1 through disk ('top_disk'-1) to top 
    // of disk 'top_disk'
    rods[rod_w_disk_1]->move_n_disks_to(
        rods[rod_w_top_disk], top_disk - 1
    );

    // Update move_count:
    // Add {2^('top_disk' - 1) - 1};
    move_count += std::pow(2, top_disk - 1) - 1;
    move_count %= 1'000'000;

    // Solve for partially solved rods
    solve(rods, des_rod, move_count);

}