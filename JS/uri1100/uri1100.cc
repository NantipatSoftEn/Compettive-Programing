#include <iostream>
#include <set>
#include <queue>
#include <climits>
using namespace std;

#define N 8

// Below arrays details all 8 possible movements 
// for a knight
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

// Check if (x, y) is valid chess board coordinates
// Note that a knight cannot go out of the chessboard
bool valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	return true;
}

// queue node used in BFS
struct Node
{
	// (x, y) represents chess board coordinates
	// dist represent its minimum distance from the source
	int x, y, dist;

	// Node constructor
	Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}

	// As we are using struct as a key in a std::set, 
	// we need to overload < operator
	// Alternatively we can use std::pair<int, int> as a key
	// to store coordinates of the matrix in the set

	bool operator<(const Node& o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

// Find minimum number of steps taken by the knight 
// from source to reach destination using BFS
int BFS(Node src, Node dest)
{
	// set to check if matrix cell is visited before or not
	set<Node> visited;
	
	// create a queue and enqueue first node
	queue<Node> q;
	q.push(src);

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and process it
		Node node = q.front();
		q.pop();

		int x = node.x;
		int y = node.y;
		int dist = node.dist;
		
		// if destination is reached, return distance
		if (x == dest.x && y == dest.y)
			return dist;

		// Skip if location is visited before
		if (!visited.count(node))
		{
			// mark current node as visited
			visited.insert(node);

			// check for all 8 possible movements for a knight
			// and enqueue each valid movement into the queue
			for (int i = 0; i < 8; ++i) 
			{
				// Get the new valid position of Knight from current
				// position on chessboard and enqueue it in the 
				// queue with +1 distance
				int x1 = x + row[i];
				int y1 = y + col[i];

				if (valid(x1, y1))
					q.push({x1, y1, dist + 1});
			}
		}
	}

	// return INFINITY if path is not possible
	return INT_MAX;
}

// main function
int main()
{
 string a, b;
	 while (cin >> a >> b) {
	 	cout << "To get from " << a << " to " << b << " takes ";
	 	Node src = {a[0]- 'a', a[1]-'1'};
	 	Node dest = {b[0]- 'a', b[1]-'1'};
		cout <<  BFS(src, dest) << " knight moves." << endl;
		
	 }


	return 0;
}