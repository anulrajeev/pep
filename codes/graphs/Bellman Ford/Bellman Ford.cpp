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

vi bellmanFord(pair<int,pii> edge[], int V, int E)
{
	vi dist(V,INT_MAX);
	dist[1]=0;
	for(int i=0;i<V-1;i++)
		for(int j=0;j<E;j++)
		{
			int u=edge[j].second.first, v=edge[j].second.second, wt=edge[j].first;
			if(dist[u]!=INT_MAX)
				dist[v]=min(dist[v], dist[u]+wt);
		}
	return dist;
}


void _main()
{
  	int V,E;
  	cin>>V>>E;
  	V++;
  	pair<int,pii> edge[E];
  	for(int i=0;i<E;i++)
  		cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
  	vi dist = bellmanFord(edge,V,E);
  	for(int i=2;i<V;i++)
  		cout<<dist[i]<<' ';
}

