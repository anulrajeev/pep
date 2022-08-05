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

int minJumps(int n)
{
	int i=0, pos=0;
	while(pos<n)
	{
		i++;
		pos+=i;
	}
	if(pos==n)
		return i;

	int distance = pos-n;
	if((distance&1)==0)	
		return i;
	i++;
	distance+=i;
	if((distance&1)==0)	
		return i;
	else
		return i+1;
}

void _main()
{
  	int n;
  	cin>>n;
  	cout<<minJumps(n);

}

