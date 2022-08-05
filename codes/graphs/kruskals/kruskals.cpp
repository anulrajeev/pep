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


int find(int x, vi &parent)
{
	if(x==parent[x])
		return x;
	parent[x]=find(parent[x], parent);
	return parent[x];
}

void unionn(int x, int y, vi &parent, vi &rank)
{
	int x_rep = find(x,parent);
	int y_rep = find(y,parent);

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



void kruskals(pair<int,pii> edge[], int E, int V)
{
	vector<pii> mst;
	 int res=0;

	 vector<int> parent(V);
	 for(int i=0;i<V;i++)
	 	parent[i]=i;
	 vector<int> rank(V,0);
	 

	for(int i=0, count=0; count<V-1 && i<E ;i++)
	 {
	 	int u=edge[i].second.first, v=edge[i].second.second, wt=edge[i].first;
	 	if(find(u, parent)!=find(v, parent))
	 	{
	 		res+=wt;
	 		mst.push_back({u,v});
	 		unionn(u,v,parent,rank);
	 		count++;
	 	}

	 }

	 for(auto p : mst)
	 	cout<<'{'<<char('A'+p.first)<<','<<char('A'+p.second)<<'}'<<'\n';
	 cout<<"result = "<<res;
}

void _main()
{
	 int V,E;
	 cin>>V>>E;
	 pair<int,pii> edge[E];
	 int u,v,wt;
	 for(int i=0;i<E;i++)	
	 	cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;

	 sort(edge, edge+E);

	 for(auto e : edge)
	 		cout<<'{'<<char('A'+e.second.first)<<","<<char('A'+e.second.second)<<"} --> "<<e.first<<'\n';
	 
	 kruskals(edge,E,V);


}






/*

I/P : 
6 7
0 2 5
0 1 6
1 2 3
1 3 8
2 3 7
2 4 12
3 4 10

O/P : 
{B,C} --> 3
{A,C} --> 5
{A,B} --> 6
{C,D} --> 7
{B,D} --> 8
{D,E} --> 10
{C,E} --> 12
{B,C}
{A,C}
{C,D}
{D,E}
result = 25
		 //sample graph in the notebook
*/