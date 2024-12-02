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

        bool is_safe = false;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    temp.push_back(nums[j]);
                }
            }

            int diff = temp[1] - temp[0];
            if (diff == 0) continue;


            bool valid = true;
            for (int i = 2; i < temp.size(); ++i) {
                if ((temp[i] - temp[i-1]) * diff <= 0) {
                    valid = false;
                } else {
                    diff = temp[i] - temp[i-1];
                }
                if (!valid) break;
            }
            if (!valid) continue;

            for (int i = 1; i < temp.size(); ++i) {
                int diff = abs(temp[i] - temp[i-1]);
                if (diff > 3) {
                    valid = false;
                }
                if (!valid) break;
            }
            if (valid) {
                is_safe = true;
                break;
            }
        }
        if (is_safe) num_safe++;
    }

    cout << num_safe << endl;

}