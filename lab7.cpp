/* Name: Norris, Joel R.
 * Class: CSCI_3080
 * Instructor: Dr. Pettey
 * Title: Lab 7
 * Description:
 * read in the number of nodes and a binary relation representing a graph.  
 * The program will create an adjacency matrix from the binary relation.  
 * The program will then print the adjacency matrix and whether or not an Euler path exists. 
 */

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
	// get user data, number of nodes and binary relation
	int numNodes = getNumNodes();
	getBinaryRelation(A);
	cout << endl;

	// output the adjacency matrix
	printAdjacencyMatrix(A, numNodes);

	// determine is a euler path exists and output result
	if (numOddNodes == 0 || numOddNodes == 2) {
		cout << "An Euler path does exist in the graph" << endl;
	}
	else {
		cout << "An Euler path does NOT exist in the graph" << endl;
	}

    return 0;
}


// get user data for number of nodes in the graph
int getNumNodes() {
	int numNodes;
	cout << "How many nodes are in the graph? ";
	cin >> numNodes;
	return numNodes;
}


// get user data in the form of a binary relation
void getBinaryRelation(int A[][COLS]) {
	
	char character;
	int row = 0;
	int col = 0;

	cout << endl;
	cout << "Please input the binary relation for the graph:" << endl;
	cin >> character;	// ditch the '{'

	// loop through the rest of the input and build out the adjacency matrix on the fly
	// discard the characters { , ( )
	// just grab the numeric values and use those to populate the rows / columns
	while (character != '}') {

		cin >> character;
		cin >> int(row);
		cin >> character;
		cin >> int(col);
		cin >> character >> character;

		A[row - 1][col - 1] = 1 ;		// offset for array index count

	}


}


// output the adjacency matrix and check the number of odd nodes at the same time
void printAdjacencyMatrix(int A[][COLS], int numNodes) {

	int nodeParity = 0;		// track node parity for each row / node

	for (int i = 0; i < numNodes; ++i) {		// rows

		nodeParity = 0;

		for (int j = 0; j < numNodes; ++j) {	// cols
			
			if (A[i][i] == 1) nodeParity += 2;			// check parity on the diagonal, a loop adds 2 to the parity count
			else if (A[i][j] == 1) nodeParity += 1;		// otherwise it's just a single connection, 

			cout << A[i][j] << " ";

		}

		if ((nodeParity % 2) == 1) ++numOddNodes;			// if the node parity is odd update the count of odd nodes
		cout << endl;

	}
	cout << endl;
}

