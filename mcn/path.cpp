#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    void dijkstra(int src, vector<int>& dist, vector<int>& prev) {
    dist.assign(V, INT_MAX);
    prev.assign(V, -1);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}


    void printPath(int src, int dest, const vector<int>& prev) {
        if (dest == -1) return;
        vector<int> path;
        for (int at = dest; at != -1; at = prev[at])
            path.push_back(at);

        cout << "\nPath from " << src << " to " << dest << ": ";
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << (i ? " -> " : "\n");
        }
    }

    void printRoutingTable(int src, int dest = -1) {
        vector<int> dist, prev;
        dijkstra(src, dist, prev);

        if (dest != -1) printPath(src, dest, prev);

        cout << "\nRouting Table for Node " << src << ":\n";
        cout << "Dest\tDist\tNextHop\n";

        for (int i = 0; i < V; ++i) {
            if (i == src) continue;
            cout << i << "\t";
            if (dist[i] == INT_MAX) {
                cout << "INF\t-\n";
            } else {
                cout << dist[i] << "\t";
                int next = i;
                while (prev[next] != src && prev[next] != -1) next = prev[next];
                cout << (prev[next] == src ? next : -1) << "\n";
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of nodes: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter each edge (src dest weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src, dest;
    cout << "Enter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;

    if (src >= 0 && src < V && dest >= 0 && dest < V) {
        g.printRoutingTable(src, dest);
    } else {
        cout << "Invalid source/destination!\n";
    }

    return 0;
}
