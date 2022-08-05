#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
int main()
{
    int m,n;
    cin>>m>>n;
    vvi matrix(m,vi(n));
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>matrix[i][j];
    vvi transpose(n,vi(m));
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        transpose[j][i]=matrix[i][j];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        cout<<transpose[i][j]<<' ';
      cout<<'\n';
    }
    return 0;
}

