#include <iostream>

using namespace std;

int main() {
    string input;
    vector<string> matrix;

    while (cin >> input) {
        matrix.push_back(input);
    }

    int count = 0;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            bool up = i >= 1;
            bool down = i < matrix.size() - 1;
            bool left = j >= 1;
            bool right = j < matrix[i].size() - 1;
            if (matrix[i][j] != 'A') continue;

            if (up && left && down && right) {
                if (
                    abs(matrix[i-1][j-1] - matrix[i+1][j+1]) == 6 &&
                    matrix[i-1][j-1] + matrix[i+1][j+1] == 160 &&
                    abs(matrix[i+1][j-1] - matrix[i-1][j+1]) == 6 &&
                    matrix[i+1][j-1] + matrix[i-1][j+1] == 160)
                {
                    ++count;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}