#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    string value;
    vector<Node*> children;

    Node(string val) : value(val) {}
};

bool depthLimitedSearch(Node* node, const string& goal, int depth, int limit, vector<string>& path) {
    path.push_back(node->value);

    // Check if the current node is the goal
    if (node->value == goal) {
        return true;
    }

    // Check if the depth limit is reached
    if (depth >= limit) {
        path.pop_back();  // Backtrack
        return false;
    }

    // Recursively search the children
    for (Node* child : node->children) {
        if (depthLimitedSearch(child, goal, depth + 1, limit, path)) {
            return true;
        }
    }

    // Backtrack if the goal is not found in this path
    path.pop_back();
    return false;
}

bool iterativeDeepeningDFS(Node* start, const string& goal, int maxDepth, vector<string>& path) {
    for (int limit = 0; limit <= maxDepth; ++limit) {
        path.clear();
        if (depthLimitedSearch(start, goal, 0, limit, path)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Creating the expanded graph
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* G = new Node("G");
    Node* H = new Node("H");
    Node* I = new Node("I");
    Node* J = new Node("J");
    Node* K = new Node("K");
    Node* L = new Node("L");

    A->children.push_back(B);
    A->children.push_back(C);
    A->children.push_back(D);
    B->children.push_back(E);
    B->children.push_back(F);
    D->children.push_back(G);
    D->children.push_back(H);
    E->children.push_back(I);
    E->children.push_back(J);
    G->children.push_back(K);
    G->children.push_back(L);

    string start = "A";
    string goal = "L";
    int maxDepth = 4;
    vector<string> path;

    if (iterativeDeepeningDFS(A, goal, maxDepth, path)) {
        cout << "Path found: ";
        for (const string& node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found within depth limit." << endl;
    }


    return 0;
}
