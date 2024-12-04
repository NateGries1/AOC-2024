#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

int main() {
    string input;
    int total = 0;
    bool can_mul = true;

    while (cin >> input) {
        int index = 0;
        while (index < input.size()) {
            if (can_mul) {
                if (input.substr(index, 7) == "don't()") {
                    can_mul = false;
                    index += 7;
                    continue;
                }
            } else {
                if (input.substr(index, 4) == "do()") {
                    can_mul = true;
                    index += 4;
                } else {
                    index++;
                    continue;
                }
            }
            cout << "index: " << index << " letter: " << input[index] << " can_mul" << can_mul << endl;
            int n1 = 0;
            int n2 = 0; 
            if (index < input.size() - 3 && input[index] == 'm' && input[index + 1] == 'u' && input[index + 2] == 'l' && input[index + 3] == '(') {
                index += 4;
                while (index < input.size() && input[index] >= '0' && input[index] <= '9') {
                    n1 = n1 * 10 + (input[index] - '0');
                    index++;
                }
                if (index < input.size() && input[index] != ',') continue;
                index++;
                while (index < input.size() && input[index] >= '0' && input[index] <= '9') {
                    n2 = n2 * 10 + (input[index] - '0');
                    index++;
                }
                if (input[index] != ')') continue;
                index++;
                total += n1 * n2;
            } else {
                index++;
            }
        }
    }
    cout << total << endl;


    return 0;

}