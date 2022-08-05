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

void ABUtil(vi adj[], int V, int u, bool visited[], int parent[],int disc[], int low[], bool ap[], vector<pii> &res,int timer=0)
{
	visited[u]=true;
	disc[u]=low[u]=timer;
	// cout<<u<<" --> "<<disc[u]<<"/"<<low[u]<<'\n';
	int child_count=0;
	for(int v : adj[u])
		if(visited[v]==false)
		{
			child_count++;
			parent[v]=u;
			ABUtil(adj,V,v,visited,parent,disc,low,ap,res,timer+1);
			low[u]=min(low[u], low[v]);
			if(parent[u]==-1 && child_count==2 )
				ap[u]=true;
			if(parent[u]!=-1 && low[v]>=disc[u])
				ap[u]=true;

			if(low[v]>disc[u])
				res.push_back({u,v});
		}
		else if(v!=parent[u])
			low[u]=min(low[u], disc[v]);
	// cout<<u<<" --> "<<disc[u]<<"/"<<low[u]<<'\n';
}




// this considers the zero vertex
void ArticulationBridges(vi adj[], int V)
{
	int parent[V], disc[V], low[V];
	bool visited[V]={false}, ap[V]={false};
	vector<pii> res;
	for(int i=0;i<V;i++)
		if(visited[i]==false)
		{
			parent[i]=-1;
			ABUtil(adj,V,i,visited,parent,disc,low,ap,res);
		}

	for(auto p : res)
		cout<<p.first<<' '<<p.second<<'\n';
}

void _main()
{
 	int V,E;
 	cin>>V>>E;
 	vi adj[++V];
 	int u,v;
 	for(int i=0;i<E;i++) 	
 	{
 		cin>>u>>v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}
 	ArticulationBridges(adj,V);

}

