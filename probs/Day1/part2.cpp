#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int similarity_sum = 0;

    vector<int> nums;
    unordered_map<int, int> freq_map;

    int n1, n2;

    while (cin >> n1 >> n2) {
        nums.push_back(n1);
        freq_map[n2]++;
    }


    for (int n : nums) {
        similarity_sum += n * freq_map[n];
    }

    cout << similarity_sum << endl;

}