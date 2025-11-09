#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class Graph {
public:
    map<char, vector<char>> adj;

    void addEdge(char u, char v) {
        adj[u].push_back(v);
    }

    void BFS(char start) {
        set<char> visited;
        queue<char> q;

        visited.insert(start);
        q.push(start);

        cout << "BFS traversal starting from " << start << ": ";

        while (!q.empty()) {
            char node = q.front();
            q.pop();
            cout << node << " ";

            for (auto neighbor : adj[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFS(char start) {
        set<char> visited;
        stack<char> s;

        s.push(start);

        cout << "DFS traversal starting from " << start << ": ";

        while (!s.empty()) {
            char node = s.top();
            s.pop();

            if (visited.find(node) == visited.end()) {
                cout << node << " ";
                visited.insert(node);
            }

            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    s.push(*it);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;

    g.addEdge('A', 'B');
    g.addEdge('A', 'D');
    g.addEdge('B', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'E');
    g.addEdge('D', 'E');

    g.BFS('A');
    g.DFS('A');

    return 0;
}
