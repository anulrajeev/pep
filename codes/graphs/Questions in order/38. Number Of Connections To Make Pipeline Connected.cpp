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

ll mod = 1000000007;

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
	parent[x]=find(parent[x],parent);
	return parent[x];
}

void unionn(int x, int y, int parent[], vi &rank)
{
	int x_rep=find(x,parent);
	int y_rep=find(y,parent);

	if(x_rep==y_rep)
		return;
	if(rank[x_rep]<rank[y_rep])
		parent[x_rep]=y_rep;
	else if(rank[y_rep]<rank[x_rep])
		parent[y_rep]=x_rep;
	else
	{
		parent[y_rep]=x_rep;
		rank[x_rep]++;
	}
}

int connectHouses(pii connection[], int size, int n)
{
	int parent[n];
	for(int i=0;i<n;i++)
		parent[i]=i;
	vi rank(n,0);

	int removable_connections=0;
	for(int i=0;i<size;i++)
	{
		int u=connection[i].first, v=connection[i].second;
		if(find(u,parent)!=find(v,parent))
			unionn(u,v,parent,rank);
		else 
			removable_connections++;
	}	

	int islandCount=0;
	for(int i=0;i<n;i++)
		if(i==find(i,parent))
			islandCount++;
	if(removable_connections>=islandCount-1)
		return islandCount-1;
	else
		return -1;

}

void _main()
{
  	int n;
  	cin>>n;
  	int size;
  	cin>>size;
  	pii connection[size];
  	for(int i=0;i<size;i++)
  		cin>>connection[i].first>>connection[i].second;
  	cout<<connectHouses(connection, size, n);


}

/*
sample input
	8
7
0 1
1 2
4 7
5 6
4 5
6 7
0 2


Output : 2

*/