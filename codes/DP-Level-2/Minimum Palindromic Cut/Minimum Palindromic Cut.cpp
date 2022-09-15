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

bool isPalindrome(string s, int i, int j)
{
	while(i<j)
		if(s[i++]!=s[j--])
			return false;
	return true;
}

int minPalindromeCut(string s, int start, int end)
{
	if(start==end)
		return 0;

	if(isPalindrome(s,start,end))
		return 0;
	
	int res=end-start+1;
	for(int i=start;i<=end;i++)
		if(isPalindrome(s,start,i))
			res = min(res, minPalindromeCut(s,i+1,end)+1);
	return res;
}

void _main()
{
  	string s;
  	cin>>s;
  	cout<<minPalindromeCut(s,0,s.length()-1);
}

