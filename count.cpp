#include <iostream>
#include <cstring>

using namespace std;

//adjacency matrix with conditional edges
	//                 0 1 2 3 4 5 6 7 8 9 10
	int adj[11][11] = {0,1,1,1,1,1,1,1,1,1,0,
					   1,0,1,2,1,1,1,2,1,2,1,
					   1,1,0,1,1,1,1,1,2,1,1,
					   1,2,1,0,1,1,1,2,1,2,1,
					   1,1,1,1,0,1,2,1,1,1,1,
					   1,1,1,1,1,0,1,1,1,1,1,
					   1,1,1,1,2,1,0,1,1,1,1,
					   1,2,1,2,1,1,1,0,1,2,1,
					   1,1,2,1,1,1,1,1,0,1,1,
					   1,2,1,2,1,1,1,2,1,0,1,
					   0,1,1,1,1,1,1,1,1,1,0};
	//boolean to store visited nodes
	bool visited[11];

//recursive backtracking
//number of paths from node v to destination of min length l
int num_paths(int v, int l) {
	if(v==10 && l<=1) return 1;

	int i,j,res=0;
	visited[v] = 1;
	for(i=0;i<11;i++) {
		if( visited[i]==0 && (adj[v][i]==1 || (adj[v][i]==2 && visited[(v+i)/2])) ) {
			res += num_paths(i, l-1);
		}
	}
	visited[v] = 0;
	return res;

}

int main() {

	int i,j,n;
	//clear visited
	memset(visited, 0, sizeof(visited));
	//recursive backtracking
	cout << num_paths(0,6) << "\n";
  	return 0;
}