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

int maxDist(vvi &grid)
{
	int n=grid.size(), d=1, maxDist=0;
	queue<pii> q;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(grid[i][j]==0)
				grid[i][j]=-1;
			else
				grid[i][j]=0, q.push({i,j});

    if(q.size()==0 || q.size()==n*n)
    	return -1;
    
	while(q.size())
	{
		int size=q.size();
		
		for(int t=0;t<size;t++)
		{
			int i=q.front().first, j=q.front().second; q.pop();
			// cout<<i<<' '<<j<<'\n';
			//i,j-1
			if(j-1>=0 && grid[i][j-1]==-1)
				grid[i][j-1]=d, q.push({i,j-1}),  maxDist=max(maxDist, d);
			//i,j+1
			if(j+1<n && grid[i][j+1]==-1)
				grid[i][j+1]=d, q.push({i,j+1}),  maxDist=max(maxDist, d);

			//i-1,j
			if(i-1>=0 && grid[i-1][j]==-1)
				grid[i-1][j]=d, q.push({i-1,j}),  maxDist=max(maxDist, d);

			//i+1,j
			if(i+1<n && grid[i+1][j]==-1)
				grid[i+1][j]=d, q.push({i+1,j}),  maxDist=max(maxDist, d);

		}
		// cout<<d<<"\n\n";
		d++;
	}

	

	return maxDist;
}


void _main()
{
   int n;
   cin>>n;
   vvi grid(n,vi(n));
   for(int i=0;i<n;i++)
   	for(int j=0;j<n;j++)
   	  cin>>grid[i][j];
   cout<<maxDist(grid);		

}

