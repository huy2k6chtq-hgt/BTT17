#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

struct Graph {
    int k;
    Node** adjLists; 
};

Node* createNode(int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = nullptr;
    return newNode;
}

Graph* createGraph(int v) {
    Graph* graph = new Graph;
    graph->k = v;
    graph->adjLists = new Node*[v + 1];
    for (int i = 0; i <= v; i++)
        graph->adjLists[i] = nullptr;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void BFS(Graph* graph, int startVertex) {
    bool* visited = new bool[graph->k + 1]{false};
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);
    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        cout << currVertex << " ";
        int tempAdj[20]; 
        int count = 0;
        Node* temp = graph->adjLists[currVertex];
        
        while (temp) {
            if (!visited[temp->vertex]) {
                tempAdj[count++] = temp->vertex;
            }
            temp = temp->next;
        }
        sort(tempAdj, tempAdj + count, greater<int>());
        for (int i = 0; i < count; i++) {
            visited[tempAdj[i]] = true;
            q.push(tempAdj[i]);
        }
    }
    cout << endl;
}

int main() {
    int V = 11;
    Graph* graph = createGraph(V);
    addEdge(graph, 1, 2); addEdge(graph, 1, 6); addEdge(graph, 1, 7); 
    addEdge(graph, 1, 8); addEdge(graph, 1, 9); addEdge(graph, 1, 10);
    addEdge(graph, 2, 3); addEdge(graph, 2, 11);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5); addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    addEdge(graph, 10, 11);
    for (int i = 1; i <= V; i++) {
        Node* temp = graph->adjLists[i];
        cout << "Dinh " << i << ": ";
        while (temp) {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << "\n";
    }
    cout << "\n ";
    BFS(graph, 1);
    return 0;
}