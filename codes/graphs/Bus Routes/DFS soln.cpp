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


void findDest(vvi &routes, unordered_map<int,vi> &m, int dest, int u, int d, unordered_set<int> buses_taken, unordered_set<int> stops_visited, int &ans)
{
	stops_visited.insert(u);

	if(ans!=INT_MAX)
		return;
	if(u==dest)
		{ ans=d; return; }

	for(int bus : m[u])
		if(buses_taken.count(bus)==0)
		{
			buses_taken.insert(bus);
			for(int stop : routes[bus])
				if(!stops_visited.count(stop))
					findDest(routes, m, dest, stop, d+1, buses_taken, stops_visited, ans);
		}
}


int minBuses(vvi &routes, int src, int dest)
{
	unordered_set<int> buses_taken, stops_visited;
	unordered_map<int,vi>m;
	for(int i=0;i<routes.size();i++)
		for(int j=0;j<routes[0].size();j++)
			m[j].push_back(i);
	int ans=INT_MAX;
	findDest(routes, m, dest, src, 0, buses_taken, stops_visited, ans);
	return (ans!=INT_MAX?ans:-1);
}

void _main()
{
  	int m,n;
  	cin>>m>>n;
  	vvi routes(m,vi(n));
  	for(int i=0;i<m;i++)
  		for(int j=0;j<n;j++)
  			cin>>routes[i][j];
  	int src,dest;
  	cin>>src>>dest;
  	cout<<minBuses(routes,src,dest);
}



/*
Input :

4 3
1 2 7
3 4 5
5 6 7
2 3 4
1 6

Output : 2

m:
1 --> 1
2 --> 1,4
3 --> 2,4
4 --> 2,4
5 --> 2,3
6 --> 3
7 --> 1,3


                 4  5     6 
				 |   \   /
              b4 |  b3\ / b3
                 2     7
			      \   /
			b1	   \ /	b1
					1




*/