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
            bool up = i >= 3;
            bool down = i < matrix.size() - 3;
            bool left = j >= 3;
            bool right = j < matrix[i].size() - 3;

            if (up) {
                if (matrix[i][j] == 'X' && matrix[i - 1][j] == 'M' && matrix[i - 2][j] == 'A' && matrix[i - 3][j] == 'S') {
                    count++;
                }
            }
            if (down) {
                if (matrix[i][j] == 'X' && matrix[i + 1][j] == 'M' && matrix[i + 2][j] == 'A' && matrix[i + 3][j] == 'S') {
                    count++;
                }
            }
            if (left) {
                if (matrix[i][j] == 'X' && matrix[i][j - 1] == 'M' && matrix[i][j - 2] == 'A' && matrix[i][j - 3] == 'S') {
                    count++;
                }
            }
            if (right) {
                if (matrix[i][j] == 'X' && matrix[i][j + 1] == 'M' && matrix[i][j + 2] == 'A' && matrix[i][j + 3] == 'S') {
                    count++;
                }
            }
            if (up && left) {
                if (matrix[i][j] == 'X' && matrix[i - 1][j - 1] == 'M' && matrix[i - 2][j - 2] == 'A' && matrix[i - 3][j - 3] == 'S') {
                    count++;
                }
            }
            if (up && right) {
                if (matrix[i][j] == 'X' && matrix[i - 1][j + 1] == 'M' && matrix[i - 2][j + 2] == 'A' && matrix[i - 3][j + 3] == 'S') {
                    count++;
                }
            }
            if (down && left) {
                if (matrix[i][j] == 'X' && matrix[i + 1][j - 1] == 'M' && matrix[i + 2][j - 2] == 'A' && matrix[i + 3][j - 3] == 'S') {
                    count++;
                }
            }
            if (down && right) {
                if (matrix[i][j] == 'X' && matrix[i + 1][j + 1] == 'M' && matrix[i + 2][j + 2] == 'A' && matrix[i + 3][j + 3] == 'S') {
                    count++;
                }
            }
        }
    }
    cout << count << endl;


    return 0;

}