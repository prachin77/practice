#include <iostream>
using namespace std;

int c = 0;

void TOH(int n, char A, char B, char C) {
    if (n == 1) {
        c++;
        std::cout << "Disc " << n << " transferred from " << A << " to " << C << std::endl;
        return;
    }
    TOH(n - 1, A, C, B);
    c++;
    std::cout << "Disc " << n << " transferred from " << A << " to " << C << std::endl;
    TOH(n - 1, B, A, C);
}

int main() {
    int n = 3;
    TOH(n, 'A', 'B', 'C');
    std::cout << "total steps taken = " << c << std::endl;
    return 0;
}
