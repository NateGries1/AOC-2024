#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int diff_sum = 0;

    vector<int> nums1;
    vector<int> nums2;

    int n1, n2;

    while (cin >> n1 >> n2) {
        nums1.push_back(n1);
        nums2.push_back(n2);
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for (int i = 0; i < nums1.size(); i++) {
        diff_sum += abs(nums1[i] - nums2[i]);
    }

    cout << diff_sum << endl;

}