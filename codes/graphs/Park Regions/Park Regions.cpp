#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;

ll mod = 1000000009;

void _main();
int main(){
 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
 #endif
	_main();
	return 0;
}

int find(int x, int parent[])
{
	if(x==parent[x])
		return x;
	parent[x]=find(parent[x], parent);
	return parent[x];}

void unionn(int x, int y, int parent[], vi &rank)
{
	int x_rep = find(x, parent);
	int y_rep = find(y, parent);

	if(rank[x_rep]<rank[y_rep])
		parent[x_rep]=y_rep;
	else if(rank[y_rep]<rank[x_rep])
		parent[y_rep]=x_rep;
	else
	{
		parent[y_rep]=x_rep;
		rank[x_rep]++;
	}}


int getRegions(vs &maze)
{
	int n=maze.size(), N=n+1;
	int parent[N*N];
	for(int i=0;i<N*N;i++)
		parent[i]=i;
	vi rank(N*N, 0);

	for(int i=0;i<N-1;i++)
	{
		unionn(i,i+1,parent,rank);
		unionn(N*N-i-1, N*N-i-2, parent, rank);
	}
	for(int i=0;i<N*N-N;i+=N)
	{
		unionn(i,i+N,parent,rank);
		unionn(i+N-1,i+N-1+N,parent,rank);
	}



	// for(int i=0;i<N*N;i++)
	// 	cout<<i<<" --> "<<find(i,parent)<<'\n';

	int count=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(maze[i][j]=='/')
			{
				int point1 = (i+1)*N+j;
				int point2 = i*N+(j+1);
				if(find(point1,parent)==find(point2,parent))
				{
					// cout<<point1<<' '<<point2<<'\n';
					count++;
				}
				else
					unionn(point1,point2,parent,rank);
			}
			else if(maze[i][j]=='\\')
			{
				int point1 = i*N+j;
				int point2 = (i+1)*N+(j+1);
				if(find(point1,parent)==find(point2,parent))
				{
					// cout<<point1<<' '<<point2<<'\n';
					count++;
				}
				else
					unionn(point1,point2,parent,rank);
			}
		}
	return count;
}

void _main()
{
  	int n;
  	cin>>n;
  	vs maze(n);
  	for(int i=0;i<n;i++)
  		cin>>maze[i];
  	cout<<getRegions(maze);
}

