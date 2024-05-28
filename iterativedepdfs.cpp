#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    string value;
    vector<Node *> children;

    Node(string val) : value(val) {}
};

bool depthLimitedSearch(Node *node, const string &goal, int depth, int limit, vector<string> &path)
{
    path.push_back(node->value);

    // Check if the current node is the goal
    if (node->value == goal)
    {
        return true;
    }

    // Check if the depth limit is reached
    if (depth >= limit)
    {
        path.pop_back(); // Backtrack
        return false;
    }

    // Recursively search the children
    for (Node *child : node->children)
    {
        if (depthLimitedSearch(child, goal, depth + 1, limit, path))
        {
            return true;
        }
    }

    // Backtrack if the goal is not found in this path
    path.pop_back();
    return false;
}

bool iterativeDeepeningDFS(Node *start, const string &goal, int maxDepth, vector<string> &path)
{
    for (int limit = 0; limit <= maxDepth; ++limit)
    {
        path.clear();
        if (depthLimitedSearch(start, goal, 0, limit, path))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Creating the expanded graph
    Node *A = new Node("A");
    Node *B = new Node("B");
    Node *C = new Node("C");
    Node *D = new Node("D");
    Node *E = new Node("E");
    Node *F = new Node("F");
    Node *G = new Node("G");
    Node *H = new Node("H");
    Node *I = new Node("I");
    Node *J = new Node("J");
    Node *K = new Node("K");
    Node *L = new Node("L");

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

    if (iterativeDeepeningDFS(A, goal, maxDepth, path))
    {
        cout << "Path found: ";
        for (const string &node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found within depth limit." << endl;
    }

    return 0;
}

/*1. Node Class:
Attributes:
value: A string representing the value of the node.
children: A vector of pointers to other Node objects, representing the child nodes of the current node.
Purpose: Defines a basic node structure for constructing a graph.
2. Depth Limited Search Function (depthLimitedSearch):
Attributes:
node: Pointer to the current node being explored.
goal: The value of the target node we are searching for.
depth: The current depth of the search.
limit: The maximum depth allowed for the search.
path: A vector of strings representing the path from the start node to the current node.
Algorithm:
Recursively explores the graph up to a specified depth (limit).
Backtracks if the depth limit is reached without finding the goal node.
Returns true if the goal node is found within the depth limit, false otherwise.
3. Iterative Deepening Depth-First Search Function (iterativeDeepeningDFS):
Attributes:
start: Pointer to the starting node of the graph.
goal: The value of the target node we are searching for.
maxDepth: The maximum depth allowed for the search.
path: A vector of strings representing the path from the start node to the goal node.
Algorithm:
Performs depth-limited searches iteratively with increasing depth limits from 0 to maxDepth.
Utilizes depthLimitedSearch function to perform the depth-limited searches.
Returns true if the goal node is found within any depth limit, false otherwise.
4. Main Function:
Attributes:
A, B, ..., L: Pointers to Node objects representing the nodes of the graph.
start: The value of the start node.
goal: The value of the target node we are searching for.
maxDepth: The maximum depth allowed for the search.
path: A vector of strings representing the path from the start node to the goal node.
Algorithm:
Constructs the graph by creating nodes (A, B, ..., L) and defining their relationships.
Sets the start node value, goal node value, and maximum depth limit.
Calls the iterativeDeepeningDFS function to search for a path from the start node to the goal node.
Prints the path if found, otherwise, prints a message indicating no path within the depth limit.
Overall:
The code implements an iterative deepening depth-first search (IDDFS) algorithm to find a path from the start node to the goal node in a graph. It utilizes depth-limited searches with increasing depths until the goal node is found or until the maximum depth limit is reached. The program effectively constructs a graph, searches for a path, and prints the result accordingly.
*/

/*1. Node Class:
Defines a class Node with attributes value (string) and children (vector of pointers to Node objects).
Each node represents a point in the graph, with value indicating its identifier and children representing its neighboring nodes.
2. Depth Limited Search Function (depthLimitedSearch):
Begins at a given node and recursively explores its children up to a specified depth limit.
Maintains a path vector to track the path from the start node to the current node.
If the goal node is found within the depth limit, returns true.
If the depth limit is reached without finding the goal node, backtracks and returns false.
3. Iterative Deepening Depth-First Search Function (iterativeDeepeningDFS):
Iterates over increasing depth limits from 0 to maxDepth.
Calls depthLimitedSearch function with each depth limit to perform a depth-limited search.
Returns true if the goal node is found within any depth limit, otherwise returns false.
4. Main Function:
Constructs a graph by creating nodes (A, B, ..., L) and defining their relationships.
Sets the start node value (A), goal node value (L), and maximum depth limit (4).
Calls iterativeDeepeningDFS to search for a path from the start node to the goal node.
Prints the path if found, otherwise prints a message indicating no path within the depth limit.
Working:
The graph is constructed with nodes A to L, and their connections are defined.
The main function sets the start node as A, the goal node as L, and the maximum depth limit as 4.
The iterative deepening depth-first search is performed, starting from depth 0 up to depth 4.
At each depth, the depth-limited search is executed.
If a path from A to L is found within the depth limit, it prints the path.
If no path is found within the depth limit, it prints a message indicating no path exists.
Example Output:
Suppose there's a graph where nodes A to L are connected as described in the code. If there exists a path from node A to node L within a depth limit of 4, the program will print the path, otherwise, it will print a message indicating that no path exists within the given depth limit.*/