#include <bits/stdc++.h>
using namespace std;

#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// Recursive utility function implementing DFS and backtracking
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V) // Base case: all vertices are colored
        return true;

    for (int c = 1; c <= m; c++) { // Try different colors
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color

            if (graphColoringUtil(graph, m, color, v + 1)) // Recur to color the next vertex (DFS)
                return true;

            color[v] = 0; // Backtrack if coloring does not lead to a solution
        }
    }
    return false; // No color can be assigned to this vertex
}

bool graphColoring(bool graph[V][V], int m) {
    int color[V] = {0};

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(color);
    return true;
}

void printSolution(int color[]) {
    cout << "Solution Exists: Following are the assigned colors\n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";
    cout << "\n";
}

int main() {
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };

    int m = 3;

    graphColoring(graph, m);
    return 0;
}




// path finding using dfs

// // C++ implementation
// #include <bits/stdc++.h>
// using namespace std;

// // An utility function to add an edge in an
// // undirected graph.
// void addEdge(vector<int> v[],
// 			int x,
// 			int y)
// {
// 	v[x].push_back(y);
// 	v[y].push_back(x);
// }

// // A function to print the path between
// // the given pair of nodes.
// void printPath(vector<int> stack)
// {
// 	int i;
// 	for (i = 0; i < (int)stack.size() - 1;
// 		i++) {
// 		cout << stack[i] << " -> ";
// 	}
// 	cout << stack[i];
// }

// // An utility function to do
// // DFS of graph recursively
// // from a given vertex x.
// void DFS(vector<int> v[],
// 		bool vis[],
// 		int x,
// 		int y,
// 		vector<int> stack)
// {
// 	stack.push_back(x);
// 	if (x == y) {

// 		// print the path and return on
// 		// reaching the destination node
// 		printPath(stack);
// 		return;
// 	}
// 	vis[x] = true;

// 	// if backtracking is taking place
// 	if (!v[x].empty()) {
// 		for (int j = 0; j < v[x].size(); j++) {
// 			// if the node is not visited
// 			if (vis[v[x][j]] == false)
// 				DFS(v, vis, v[x][j], y, stack);
// 		}
// 	}

// 	stack.pop_back();
// }

// // A utility function to initialise
// // visited for the node and call
// // DFS function for a given vertex x.
// void DFSCall(int x,
// 			int y,
// 			vector<int> v[],
// 			int n,
// 			vector<int> stack)
// {
// 	// visited array
// 	bool vis[n + 1];

// 	memset(vis, false, sizeof(vis));

// 	// DFS function call
// 	DFS(v, vis, x, y, stack);
// }

// // Driver Code
// int main()
// {
// 	int n = 10;
// 	vector<int> v[n], stack;

// 	// Vertex numbers should be from 1 to 9.
// 	addEdge(v, 1, 2);
// 	addEdge(v, 1, 3);
// 	addEdge(v, 2, 4);
// 	addEdge(v, 2, 5);
// 	addEdge(v, 2, 6);
// 	addEdge(v, 3, 7);
// 	addEdge(v, 3, 8);
// 	addEdge(v, 3, 9);

// 	// Function Call
// 	DFSCall(4, 8, v, n, stack);

// 	return 0;
// }
