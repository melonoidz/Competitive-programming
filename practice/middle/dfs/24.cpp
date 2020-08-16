#include<iostream>
using namespace std;

int m[101][101];
int visit[101];
int d[101];
int f[101];
int n, t;

void dfs(int u){
  visit[u]=1;
  d[u]=t;
  t++;
  for(int i=0; i<n ; i++){
      if(m[u][i]==1 && visit[i]==0){
          dfs(i);
      }
  }
  f[u]=t; 
  t++;
}

int main()
{
  int u, k, v;
  t = 1;

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> u >> k;
    --u;
    for(int j = 0; j < k; ++j){
      cin >> v;
      v--;
      m[u][v] = 1; 
    //隣接行列
    }
  }

  for(int i = 0; i < n; ++i){
    if(visit[i]==0){
      dfs(i);
    }
  }

  for(int i=0; i < n; ++i){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }

  return (0);
}