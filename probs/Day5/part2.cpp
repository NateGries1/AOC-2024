#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <unordered_set>


using namespace std;

bool dfs(unordered_map<int, vector<int>>& graph, int start, int end, array<bool, 100>& visited) {
    if (start == end) {
        return true;
    }
    visited[start] = true;

    for (int i = 0; i < graph[start].size(); i++) {
        if (visited[graph[start][i]]) {
            continue;
        }
        if (dfs(graph, graph[start][i], end, visited)) {
            cout << start << endl;
            return true;
        }
    }

    return false;
}

int main() {
    int first, last;
    char c;

    int total = 0;
    unordered_map<int, unordered_set<int>> graph;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        istringstream iss(line);
        iss >> first >> c >> last;
        graph[first].insert(last);
    }

    while (getline(cin, line)) {
        //check if line is empty
        cout << line << endl;
        istringstream iss(line);
        vector<int> v;
        int n;
        char c;
        while (iss >> n >> c) {
            v.push_back(n);
        }
        v.push_back(n);

        cout << "v.size() = " << v.size() << endl;


        bool valid = true;
        for (int i = 0; i < v.size()-1; i++) {
            for (int j = i + 1; j < v.size(); j++) {
                array<bool, 100> visited = {false};
                bool result = graph[v[j]].count(v[i]);
                if (result) {
                    valid = false;
                    swap(v[i], v[j]);
                }
            }
        }
        cout << (valid? "valid" : "invalid") << endl;
        if (!valid) {
            cout << v[v.size() / 2] << endl;
            total += v[v.size() / 2];
        }
        cout << "total = " << total << endl;
    }
    cout << total << endl;
    return 0;

}