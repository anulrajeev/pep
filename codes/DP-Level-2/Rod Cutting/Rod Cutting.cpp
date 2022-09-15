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

int maxProfit(int price[], int n)
{
	if(n==0)
		return 0;
	int res=price[n-1];
	for(int i=1;i<n;i++)
		res=max(res,maxProfit(price,i)+maxProfit(price,n-i));
	return res;
}

void _main()
{
  	int n;
  	cin>>n;
  	int price[n];
  	for(int i=0;i<n;i++)
  		cin>>price[i];
  	cout<<maxProfit(price,n);
}

