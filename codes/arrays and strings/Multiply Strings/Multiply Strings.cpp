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

string add(string s1, string s2)
{
    string res;
    int i=s1.length()-1, j=s2.length()-1, d, carry=0;
    
    while(i>=0 && j>=0)
    {
        int sum=(s1[i]-'0')+(s2[j]-'0');
        d=(sum+carry)%10;
        carry=(sum+carry)/10;
        res.push_back(d+'0');
        i--,j--;
    }
    
    while(i>=0)
    {
        int sum=(s1[i]-'0');
        d=(sum+carry)%10;
        carry=(sum+carry)/10;
        res.push_back(d+'0');
        i--;
    }
    
    while(j>=0)
    {
        int sum=(s2[j]-'0');
        d=(sum+carry)%10;
        carry=(sum+carry)/10;
        res.push_back(d+'0');
        j--;
    }
    
    if(carry)
    	res.push_back(carry+'0');

    reverse(res.begin(), res.end());
    return res;
}


string product(string s1, string s2)
{

  	string A = (s1>s2?s1:s2);
  	string B = (s1<s2?s1:s2);

  	// cout<<A<<'\n'<<B<<"\n\n";
  	vs res;

  	int d,carry=0,zeroes=0;
  	for(int i=B.length()-1;i>=0;i--,zeroes++)
  	{
  		string s;
  		for(int i=0;i<zeroes;i++)
  			s.push_back('0');

  		for(int j=A.length()-1;j>=0;j--)
  		{
  			int prod = (A[j]-'0')*(B[i]-'0');
  			d=(prod+carry)%10;
  			carry=(prod+carry)/10;
  			s.push_back(d+'0');
  		}

  		if(carry)
  		{
  			s.push_back(carry+'0');
  			carry=0;
  		}

  		reverse(s.begin(), s.end());
  		// cout<<s<<'\n';
  		res.push_back(s);
  	}

  	// cout<<"\n\n\n";
  	string ans;
  	for(int i=0;i<res.size();i++)
  		ans=add(ans, res[i]); 	
  	return ans;
}


void _main()
{
  	string s1, s2;
  	cin>>s1>>s2;
  	cout<<product(s1,s2);

}

