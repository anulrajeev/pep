

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;
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

string getInfix(string s)
{
	string res, dummy;
	int n=s.length();
	if(s.length()==3)
		return res+s[1]+s[0]+s[2];
	switch(s[1])
	{
		case '+':	
		case '-':	
		case '*':	
		case '/':	res=s.substr(1,n-2);
					// cout<<res<<'\n';
					return "("+getInfix(res)+s[0]+s[n-1]+")";
		default :   res=s.substr(2,n-2);
					// cout<<res<<'\n';
					return "("+dummy+s[1]+s[0]+getInfix(res)+")";
					// return "("+s[0]+s[n-1]+res+")";			
	}
}

int evaluate(string s)
{
	
	int n=s.length();
	if(s.length()==3)
		return s[1]+s[0]+s[2];
	switch(s[1])
	{
		case '+':	
		case '-':	
		case '*':	
		case '/':	res=s.substr(1,n-2);
					// cout<<res<<'\n';
					return "("+getInfix(res)+s[0]+s[n-1]+")";
		default :   res=s.substr(2,n-2);
					// cout<<res<<'\n';
					return "("+dummy+s[1]+s[0]+getInfix(res)+")";
					// return "("+s[0]+s[n-1]+res+")";			
	}
}





void _main()
{
   string s;
   cin>>s;
   cout<<getInfix(s);  	

}

	