// lab7.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

const int ROWS = 10;
const int COLS = 10;
int A[10][10] = { 0 };
int numOddNodes = 0;

int getNumNodes();
void getBinaryRelation(int A[][COLS]);
void printAdjacencyMatrix(int A[][COLS], int numNodes);


int main()
{
	int numNodes = getNumNodes();
	getBinaryRelation(A);
	cout << endl;
	printAdjacencyMatrix(A, numNodes);

	if (numOddNodes == 0 || numOddNodes == 2) {
		cout << "An Euler path does exist in the graph" << endl;
	}
	else {
		cout << "An Euler path does not exist in the graph" << endl;
	}

    return 0;
}

int getNumNodes() {
	int numNodes;
	cout << "How many nodes are in the graph? ";
	cin >> numNodes;
	return numNodes;
}

void getBinaryRelation(int A[][COLS]) {
	
	char character;
	int row = 0;
	int col = 0;

	cout << endl;
	cout << "Please input the binary relation for the graph:" << endl;
	cin >> character;	// ditch the '{'

	while (character != '}') {

		cin >> character;
		cin >> int(row);
		cin >> character;
		cin >> int(col);
		cin >> character >> character;

		A[row - 1][col - 1] = 1 ;

	}


}

void printAdjacencyMatrix(int A[][COLS], int numNodes) {

	cout << "The Adjacency Matrix is: " << endl;

	int nodeParity = 0;

	for (int i = 0; i < numNodes; ++i) {

		for (int j = 0; j < numNodes; ++j) {
			
			if (A[i][i] == 1) nodeParity += 2;			// check parity on the diagonal
			else if (A[i][j] == 1) nodeParity += 1;		// 

			cout << A[i][j] << " ";

		}

		if (nodeParity % 2 == 1) ++numOddNodes;
		cout << endl;
	}
	cout << endl;
}

