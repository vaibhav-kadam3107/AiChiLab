// path finding using bfs

// #include <bits/stdc++.h>
// using namespace std;
// void printPath(vector<int> parent, int initial, int node){
//    while (initial != node){
//       cout<<node<<" <= ";
//       node = parent[node];
//    }
//    cout<<node<<endl;
// }
// void findPathBFS(vector<vector<int> > graphAdjList, int initial, int graphSize){
//    vector<int> parent(graphSize, 0);
//    vector<int> queue(graphSize, 0);
//    int front = -1, rear = -1;
//    vector<int> isVisited(graphSize, 0);
//    isVisited[0] = 1;
//    parent[0] = initial;
//    queue[++rear] = initial;
//    int k;
//    while (front != rear)
//    {
//       k = queue[++front];
//       for (int j:graphAdjList[k]){
//          if (isVisited[j] == 0){
//             queue[++rear] = j;
//             isVisited[j] = 1;
//             parent[j] = k;
//          }
//       }
//    }
//    for (k = 0; k < graphSize; k++)
//       printPath(parent, initial, k);
// }
// int main(){
//    vector<vector<int> > graphAdjList;
//    graphAdjList.push_back({1, 3});
//    graphAdjList.push_back({0, 2});
//    graphAdjList.push_back({1});
//    graphAdjList.push_back({4});
//    graphAdjList.push_back({0});
//    int graphSize = graphAdjList.size();
//    int initial = 0;
//    cout<<"The Path from vertex '0' to all other vertex in the graph is : \n";
//    findPathBFS(graphAdjList, initial, graphSize);
// }

// C++ program to print all paths of source to
// destination in given graph
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

// utility function for printing
// the found path in graph
void printpath(vector<int> &path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		cout << path[i] << " ";
	cout << endl;
}

// utility function to check if current
// vertex is already present in path
int isNotVisited(int x, vector<int> &path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}

// utility function for finding paths in graph
// from source to destination
void findpaths(vector<vector<int>> &g, int src, int dst, int v)
{
	// create a queue which stores
	// the paths
	queue<vector<int>> q;

	// path vector to store the current path
	vector<int> path;
	path.push_back(src);
	q.push(path);
	while (!q.empty())
	{
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		// if last vertex is the desired destination
		// then print the path
		if (last == dst)
			printpath(path);

		// traverse to all the nodes connected to
		// current vertex and push new path to queue
		for (int i = 0; i < g[last].size(); i++)
		{
			if (isNotVisited(g[last][i], path))
			{
				vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}

// driver program
int main()
{
	vector<vector<int>> g;
	// number of vertices
	int v = 4;
	g.resize(4);

	// construct a graph
	g[0].push_back(3);
	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(3);
	g[2].push_back(0);
	g[2].push_back(1);

	int src = 2, dst = 3;
	cout << "path from src " << src << " to dst " << dst
		 << " are \n";

	// function for finding the paths
	findpaths(g, src, dst, v);

	return 0;
}
