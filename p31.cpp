
#include<iostream>
using namespace std;
#define V 5

class prims
{   
	public:

	int minKey(int key[], bool mstSet[]);
	void primMST(int graph[V][V]);
    void printMST(int parent[], int graph[V][V]);
};

int prims:: minKey(int key[], bool mstSet[])
{
	int min = 99, min_index;

	for (int i = 0; i < V; i++)
	{
		cout<<"keys :"<<key[i]<<" ";
		if (mstSet[i] == false && key[i] < min)
		{
           
			min = key[i];
			cout<<"\nmin:"<<min<<"\n";
		    min_index = i;
			cout<<"minindex:"<<min_index<<"\n";
		}
	}
	return min_index;
}

void prims::primMST(int graph[V][V])
{

	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++)
	{
		key[i] = 99;
		mstSet[i] = false;
    }
	
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	 {
		int u = minKey(key, mstSet);
		cout<<"\nkey :"<<u<< "for :"<<key[u]<<"\n";
		cout<<"mstset :"<<u<< "for :"<<mstSet[u]<<"\n";
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			cout<<"hhhh\n";
			if (graph[u][v]!=0 && mstSet[v] == false && graph[u][v] < key[v])
            {
				cout<<"nn\n";
				parent[v] = u;
				key[v] = graph[u][v];

			}
		}
	}

	// Print the constructed MST
	printMST(parent, graph);
}

void prims::printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";
}

// Driver's code
int main()
{
	prims p1;
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	p1.primMST(graph);

	return 0;
}

// This code is contributed by rathbhupendra
/*output
Edge 	Weight
0 - 1 	2 
1 - 2 	3 
0 - 3 	6 
1 - 4 	5*/
