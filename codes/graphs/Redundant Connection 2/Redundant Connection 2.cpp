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

pii findRedundant(pii edge[], int E)
{
	int V=E+1;

	vi indegree(V, -1);
	int blacklist1=-1, blacklist2=-1;
	for(int i=0;i<E;i++)
	{
		int u=edge[i].first, v=edge[i].second;

		if(indegree[v]==-1)
			indegree[v]=i;
		else
		{
			blacklist1=indegree[v];
			blacklist2=i;
			break;
		}
	}


	int parent[V];
	for(int i=0;i<V;i++)
		parent[i]=i;
	vi rank(V, 0);

	bool cycle_exist=false;

	for(int i=0;i<E;i++)
		if(i!=blacklist2)
		{
			int u=edge[i].first, v=edge[i].second;
			if(find(u,parent)!=find(v,parent))
				unionn(u,v,parent,rank);
			else
				return edge[i];
		}

	return edge[blacklist2];
}

void _main()
{
    int E;
    cin>>E;
    pair<int,int> edge[E];
    for(int i=0;i<E;i++)	
    	cin>>edge[i].first>>edge[i].second;
    pii ans=findRedundant(edge,E);
    cout<<ans.first<<' '<<ans.second;

}

