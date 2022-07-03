#include <eigen3/Eigen/Core>

int main() {
    Eigen::Matrix4d m;
    m << 1,  2,  3,   4,
         5,  6,  7,   8,
         9, 10, 11,  12,
        13, 14, 15,  16;
    m(1, 2) += 1;
    return 0;
}
