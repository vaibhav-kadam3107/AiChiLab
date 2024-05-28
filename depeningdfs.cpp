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

    if (node->value == goal) {
        return true;
    }
    if (depth >= limit) {
        path.pop_back();
        return false;
    }

    for (Node* child : node->children) {
        if (depthLimitedSearch(child, goal, depth + 1, limit, path)) {
            return true;
        }
    }

    path.pop_back();
    return false;
}

bool dls(Node* start, const string& goal, int limit, vector<string>& path) {
    return depthLimitedSearch(start, goal, 0, limit, path);
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
    int limit = 3;
    vector<string> path;

    cout<< endl << "start state: "<<start<<" and goal state: "<< goal<<endl;

    if (dls(A, goal, limit, path)) {
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
