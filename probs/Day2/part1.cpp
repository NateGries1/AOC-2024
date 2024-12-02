#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

int main() {
    int num_safe = 0;

    string line;
    while (getline(cin, line)) {
        cout << line << endl;
        stringstream ss(line);
        vector<int> nums;

        int n;
        while (ss >> n) {
            nums.push_back(n);
        }
        int diff = nums[1] - nums[0];
        if (diff == 0) continue;

        bool valid = true;
        for (int i = 2; i < nums.size(); ++i) {
            if ((nums[i] - nums[i-1]) * diff <= 0) {
                valid = false;
            }
            if (!valid) break;
        }
        if (!valid) continue;

        for (int i = 1; i < nums.size(); ++i) {
            int diff = abs(nums[i] - nums[i-1]);
            if (diff > 3) {
                valid = false;
            }
            if (!valid) break;
        }
        if (valid) num_safe++;
    }

    cout << num_safe << endl;

}