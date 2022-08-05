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

#define maxN 100004

void inititalise(int sieve[])
{
	fill(sieve,sieve+maxN,1);
	sieve[0]=sieve[1]=0;

	for(int i=2;i*i<=maxN;i++)
		if(sieve[i])
			for(int j=2*i;j<=maxN;j+=i)
				if(sieve[j])
					sieve[j]=0;
}


void _main()
{
	int sieve[maxN];
	inititalise(sieve);
  	int n;
  	cin>>n;
  	for(int i=2;i<=n;i++)	
  		if(sieve[i])
  			cout<<i<<' ';

}

