#include <iostream>
#include <algorithm>
using namespace std;

#define V 5
#define INF 9999

int parent[V];

struct Edge {
    int u, v, weight;
};

int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionSet(int a, int b) {
    parent[findParent(a)] = findParent(b);
}

void prim(int graph[V][V]) {
    int key[V], visited[V], total = 0;

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;

    cout << "\nPrim's MST:\n";

    for (int count = 0; count < V; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        if (u == -1) {
            cout << "Graph is disconnected\n";
            return;
        }

        visited[u] = 1;
        total += key[u];

        if (key[u] != 0)
            cout << "Vertex " << u << " Weight " << key[u] << endl;

        for (int i = 0; i < V; i++) {
            if (graph[u][i] != 0 && !visited[i] &&
                graph[u][i] < key[i]) {
                key[i] = graph[u][i];
            }
        }
    }

    cout << "Total MST Weight: " << total << endl;
}

void kruskal(Edge edges[], int e) {
    sort(edges, edges + e, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int total = 0, count = 0;

    cout << "\nKruskal's MST:\n";

    for (int i = 0; i < e && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v)) {
            cout << u << " - " << v
                 << " Weight: " << edges[i].weight << endl;

            total += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    if (count != V - 1) {
        cout << "Graph is disconnected\n";
        return;
    }

    cout << "Total MST Weight: " << total << endl;
}

int main() {
    int graph[V][V] = {0};
    Edge edges[100];
    int e = 0, choice;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter source, destination and distance:\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;

        edges[i] = {u, v, w};
    }

    do {
        cout << "\n1. Prim's Algorithm";
        cout << "\n2. Kruskal's Algorithm";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                prim(graph);
                break;

            case 2:
                kruskal(edges, e);
                break;

            case 3:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 3);

    return 0;
}