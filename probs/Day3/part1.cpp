#include <iostream>


using namespace std;

int main() {
    string input;
    int total = 0;

    while (cin >> input) {
        int index = 0;
        while (index < input.size()) {
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