
#include<bits/stdc++.h>
using namespace std;

long findMaximumSum(vector<int> stockPrice,int k){
    int n = stockPrice.size();
    if(n<k) return -1;
    map<int,int> mp;
    long sum = 0;

    for(int i=0;i<k;i++){
        mp[stockPrice[i]]++;
        sum += stockPrice[i];
    }

    long ans = -1;
    if(mp.size() == k) ans = sum;

    for(int i=k;i<n;i++){
        sum += stockPrice[i];
        sum -= stockPrice[i-k];

        mp[stockPrice[i]]++;
        mp[stockPrice[i-k]]--;
        if(mp[stockPrice[i-k]] == 0){
            mp.erase(stockPrice[i-k]);
        }

        if(mp.size() == k) ans = max(ans,sum);
    }

    return ans;
}

void solve(){ 
        int n; cin >> n;
         vector<int> stockPrice(n);

         for(int i=0;i<n;i++){
            cin >> stockPrice[i];         
        }

    int k;cin >> k;

    cout << findMaximumSum(stockPrice,k) << endl;
}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
   #endif

   int t;
   cin>>t;
   while(t--)
   {
      solve();
      cout<<"\n";
   }
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}
