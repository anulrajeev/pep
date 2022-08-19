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

int firstOcc(vvi &grid, int i)
{
	int beg=0, end=grid.size()-1, res=grid.size();
	while(beg<=end)
	{
		int mid=beg+(end-beg)/2;
		if(grid[i][mid]==1)
		{
			res=mid;
			if(mid==0||grid[i][mid-1]!=1)
				return res;
			end=mid-1;
		}
		else
			beg=mid+1;
	}
	return res;
}

int getCount(vvi &grid)
{
	int count=0;
	int n=grid.size();
	for(int i=0;i<n;i++)
		count+=firstOcc(grid,i);
	return count;
}

void _main()
{
  	int n;
  	cin>>n;
  	int count=0;
  	vvi grid(n,vi(n));
  	for(int i=0;i<n;i++)
  		for(int j=0;j<n;j++)
  		{
  			cin>>grid[i][j];
  			if(grid[i][j]==0)
  				count++;
  		}
  	cout<<getCount(grid);
}

