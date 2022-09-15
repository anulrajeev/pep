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

void f(string s1, string s2, int i, int j, int &count)
{
	cout<<i<<' '<<j<<'\n';
	if(j==s2.length())
		count++;
	else if(i==s1.length())
		return;
	else
	{
		if(s1[i]==s2[j])
			f(s1,s2,i+1,j+1,count);
		f(s1,s2,i+1,j,count);
	} 
}


void _main()
{
  	string s1,s2;
  	cin>>s1>>s2;
  	int count=0;
  	f(s1,s2,0,0,count);
  	cout<<count;
}

