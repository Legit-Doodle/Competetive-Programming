#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000007;
const string space = " ";

void pre(){}

void solve(){
    int n,x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<ll> mx(n+1,INT_MIN);
    mx[0] = 0;

    for(int i=1;i<=n;i++){
        ll cur = 0;
        for(int j=0;j<i;j++) cur += a[j];
        mx[i] = cur;

        for(int j=i;j<n;j++){
            cur += a[j];
            cur -= a[j-i];
            mx[i] = max(mx[i],cur);
        }
    }

    for(int k=0;k<=n;k++){
        ll ans = 0;
        for(int i=0;i<=n;i++){
            ans = max(ans,mx[i] + min(k,i)*x);
        }
        cout << ans << space;
    }
    cout << endl;
}

int main()
{
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

   int t;
   cin>>t;
   
   pre();

   while(t--)
   {
      solve();
   }
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}
