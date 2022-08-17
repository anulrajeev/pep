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

pii findPair(int A[], int n, int target)
{
  unordered_set<int> s;
  for(int i=0;i<n;i++)
    if(s.count(target+A[i]))
      return {min(A[i],target+A[i]), max(A[i],target+A[i])};
    else if(s.count(A[i]-target))
      return {min(A[i],A[i]-target), max(A[i],A[i]-target)};    
    else
      s.insert(A[i]);
  return {INT_MAX,INT_MAX};
}

void _main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
      cin>>A[i];
    int target;
    cin>>target;
    pii p = findPair(A,n,target);
    if(p.first==INT_MAX)
      cout<<-1;
    else
      cout<<p.first<<' '<<p.second;

}

