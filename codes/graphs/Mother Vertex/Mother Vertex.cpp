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

void DFSRec(vi adj[], int V, int u, bool visited[])
{
	visited[u]=true;
	for(int v : adj[u])
		if(visited[v]==false)
			DFSRec(adj,V,v,visited);
}


int findMother(vi adj[], int V)
{
	int mother;
	bool visited[V]={false};
	
	for(int i=1;i<V;i++)
		if(visited[i]==false)
		{
			DFSRec(adj,V,i,visited);
			mother=i;
		}

	fill(visited,visited+V,false);
	DFSRec(adj,V,mother,visited);
	for(int i=1;i<V;i++)
		if(visited[i]==false)
			return -1;
	return mother;

}

void _main()
{
	int V,E;
	cin>>V>>E;
	V++;
	vi adj[V];
	int u,v;
	for(int i=0;i<V;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}

	cout<<findMother(adj,V);

}
