#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int collatzSteps(int n) {
        int steps = 0;
        
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            steps++;
        }
        
        return steps;
    }
};