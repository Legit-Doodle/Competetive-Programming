#include<bits/stdc++.h>
using namespace std;

vector<int> solve(){
    int n,m;
    cin >> n >> m;

    long long g[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = LONG_MAX;


    for(int i=0;i<m;i++){
        int a,b,p;
        cin >> a >> b >> p;

        g[a][b] = p;
    }

    long long dist[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = g[i][j];

    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != LONG_MAX
                        && dist[i][k] != LONG_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    long long ans = LONG_MAX;
    int a=-1,b=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;

            if(dist[i][j] == LONG_MAX || dist[j][i] == LONG_MAX) continue;

            long long price = dist[i][j] + dist[j][i]; 

            if(price == ans){
                if(a+b > i+j){
                    a = i;
                    b = j;
                }
            }
            else if(price < ans){
                a=i;
                b=j;
                ans = price;
            }
        }
    }

    vector<int> res(3);
    res[0] = (ans == LONG_MAX ? 1000000 : ans);
    res[1] = a;
    res[2] = b;
    return res;
}

int main()
{
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

   int t;
   cin>>t;

   while(t--)
   {
      vector<int> res = solve();
      for(int i=0;i<3;i++) cout << res[i] << " ";
   }
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}
