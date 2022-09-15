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

bool f(string s1, int m, string s2, int n, string s3, int p)
{
	if(p==0)
		return true;

	bool ans=false;
	if(m>0 && s1[m-1]==s3[p-1])
		ans=f(s1,m-1,s2,n,s3,p-1);
	if(n>0 && s2[n-1]==s3[p-1])
		ans=ans||f(s1,m,s2,n-1,s3,p-1);
	return ans;
}

bool checkInterleave(string s1, string s2, string s3)
{
	if(s1.length()+s2.length()!=s3.length())
		return false;
	return f(s1,s1.length(),s2,s2.length(),s3,s3.length());
}

void _main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	cout<<(checkInterleave(s1,s2,s3)?"true":"false");
}

