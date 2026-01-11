#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
string tinhThanh[] = {"", "Ha noi", "Hai duong", "Hai phong", "Uong bi", "Bac giang", 
                      "Bac ninh", "Thai nguyen", "Son tay", "Hoa binh", "Phu ly", "Hung yen"};

const int N = 11;
int matrix[N + 1][N + 1] = {0};
vector<int> adj[N + 1];
void addEdge(int u, int v) {
    matrix[u][v] = matrix[v][u] = 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(int x) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    visited[x] = true;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << tinhThanh[u] <<" -> " ;
        vector<int> neighbors;
        for (int v = 1; v <= N; v++) {
            if (matrix[u][v] == 1 && !visited[v]) {
                neighbors.push_back(v);
            }
        }
        sort(neighbors.begin(), neighbors.end(), greater<int>());
        for (int v : neighbors) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    addEdge(1, 2); addEdge(1, 6); addEdge(1, 7); addEdge(1, 8); addEdge(1, 9); addEdge(1, 10);
    addEdge(2, 3); addEdge(2, 11);
    addEdge(3, 4);
    addEdge(4, 5); addEdge(4, 6);
    addEdge(5, 6);
    addEdge(10, 11);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    BFS(1);
    return 0;
}