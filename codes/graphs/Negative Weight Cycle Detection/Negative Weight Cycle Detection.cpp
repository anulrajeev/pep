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

bool DFSRec(vector<pii> adj[], int V, int u, int d, bool visited[], bool recSt[])
{
	visited[u]=recSt[u]=true;
	for(auto p : adj[u])
	{
		int v=p.first, wt=p.second;

		if(visited[v]==false)
		{
			if(DFSRec(adj,V,v,d+wt,visited,recSt))
				return true;
		}
		else if(recSt[v])
		{
			if(d+wt<0)
				return true;
		}

	}
	recSt[u]=false;
}

bool checkNegativeCycle(vector<pii> adj[], int V)
{
	bool visited[V]={false}, recSt[V]={false};
	for(int i=0;i<V;i++)
		if(visited[i]==false)
			if(DFSRec(adj,V,i,0,visited,recSt))
				return true;
	return false;
}

void _main()
{
  	int V,E;
  	cin>>V>>E;
  	vector<pii> adj[V];
  	int u,v,wt;
  	for(int i=0;i<E;i++)
  	{
  		cin>>u>>v>>wt;
  		adj[u].push_back({v,wt});
  	}
  	cout<<checkNegativeCycle(adj,V);


}

