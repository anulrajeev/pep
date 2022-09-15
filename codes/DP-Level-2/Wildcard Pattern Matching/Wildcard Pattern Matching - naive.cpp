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

int f(string s, string p, int i, int j)
{
    int m=s.length(), n=p.length();

    if(i==m&&j==n)
      return true;
    if(i==m)
      if(p[j]=='*'&&j+1==n)
        return true;
      else
        return false;
    if(j==n)
      return false;
    if(p[j]=='?')
      return f(s,p,i+1,j+1);
    if(p[j]=='*')
    {
      for(int k=i;k<=m;k++)
      {
        // cout<<k<<' '<<j+1<<'\n';
        if(f(s,p,k,j+1))
        {
          return true;
        }
      }
      return false;
    }
    if(s[i]==p[j])
      return f(s,p,i+1,j+1);
    
    // cout<<s[i]<<' '<<p[j]<<'\n';

    return false;
}

void _main()
{
    string s,p;
    cin>>s>>p;
    cout<<(f(s,p,0,0)?"true":"false");
}

