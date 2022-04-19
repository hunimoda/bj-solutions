#include <iostream>

using namespace std;

int compute_gcd(int, int);

int main() {

    int sausages {};
    int critics {};

    cin >> sausages >> critics;
    
    // 소시지가 더 많으면 평론가들에게 차례로 나누어주고
    // 남은 소시지를 분배한다.
    sausages %= critics;
    
    int slice_count {0};

    // 분배하고도 남은 소시지가 있다면 자르기 시작
    if (sausages) {

        // 소시지 수: G * a, 평론가 수: G * b
        int G {compute_gcd(critics, sausages)};
        int a {sausages / G};
        int b {critics / G};

        // 여러 개의 소시지를 하나의 긴 소시지로 생각하고
        // 평론가들에게 할당될 양만큼 차례로 잘라서 나눠주되
        // 자르는 부분이 소시지 개개를 나누는 지점일 경우 제외
        slice_count = G * (b - 1);

    }

    cout << slice_count << endl;

    return 0;

}

// a과 b는 자연수
int compute_gcd(int a, int b) {

    int r {};

    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;

}