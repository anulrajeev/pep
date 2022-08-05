// this prints the number of SCCs of a graph

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

void DFSRec(vi adj[], int V, int u, bool visited[], stack<int> &st)
{
	visited[u]=true;
	for(int v : adj[u])
		if(visited[v]==false)
			DFSRec(adj,V,v,visited,st);
	st.push(u);
}

stack<int> topoSort(vi adj[], int V)
{
	stack<int> st;
	bool visited[V]={false};
	for(int i=0;i<V;i++)
		if(visited[i]==false)
			DFSRec(adj,V,i,visited,st);
	return st;
}


void DFSRec2(vi transpose[], int V, int u, bool visited[])
{
	visited[u]=true;
	for(int v : transpose[u])
		if(visited[v]==false)
			DFSRec2(transpose,V,v,visited);
}

void kosarajuAlgo(vi adj[], int V)
{
	stack<int> st = topoSort(adj,V);

	vi transpose[V];
	for(int u=0;u<V;u++)
		for(int v : adj[u])
			transpose[v].push_back(u);  
/*
	for(int u=0;u<V;u++)
	{
		cout<<u<<" --> ";
		for(int v : transpose[u])
			cout<<v<<' ';
		cout<<'\n';
	}*/

	bool visited[V]={false};
	int count=0;
	while(st.size())
	{
		int u=st.top();  st.pop();
		if(!visited[u])
		{
			DFSRec2(transpose,V,u,visited);
			count++;
		}
	}
	cout<<count;
}

void _main()
{
	int V,E;
	cin>>V>>E;
	vi adj[V];
	int u,v,wt;
	for(int i=0;i<V;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	kosarajuAlgo(adj,V);

}

/*
sample input
6 6
0 1
1 2
2 3
3 4 
4 1 
3 5
*/


// this prints the strongly connected components of graph

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

void DFSRec(vi adj[], int V, int u, bool visited[], stack<int> &st)
{
	visited[u]=true;
	for(int v : adj[u])
		if(visited[v]==false)
			DFSRec(adj,V,v,visited,st);
	st.push(u);
}

stack<int> topoSort(vi adj[], int V)
{
	stack<int> st;
	bool visited[V]={false};
	for(int i=0;i<V;i++)
		if(visited[i]==false)
			DFSRec(adj,V,i,visited,st);
	return st;
}


void DFSRec2(vi transpose[], int V, int u, bool visited[])
{
	visited[u]=true;
	cout<<u<<' ';
	for(int v : transpose[u])
		if(visited[v]==false)
			DFSRec2(transpose,V,v,visited);
}

void kosarajuAlgo(vi adj[], int V)
{
	stack<int> st = topoSort(adj,V);

	vi transpose[V];
	for(int u=0;u<V;u++)
		for(int v : adj[u])
			transpose[v].push_back(u);  
/*
	for(int u=0;u<V;u++)
	{
		cout<<u<<" --> ";
		for(int v : transpose[u])
			cout<<v<<' ';
		cout<<'\n';
	}*/

	bool visited[V]={false};
	while(st.size())
	{
		int u=st.top();  st.pop();
		if(!visited[u])
		{
			DFSRec2(transpose,V,u,visited);
			cout<<'\n';
		}
	}


}

void _main()
{
	int V,E;
	cin>>V>>E;
	vi adj[V];
	int u,v,wt;
	for(int i=0;i<V;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	kosarajuAlgo(adj,V);

}



