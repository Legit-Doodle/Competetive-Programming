#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const ll mod = 1000000007;

void pre(){}

void solve(){
   int n; cin >> n;
   string s; cin >> s;

   // "aa" -> 2
   // "aba","aca"->3
   // "abca","acba"->4

   if(0<=s.find("aa") && s.find("aa") <n){
      cout << 2 << endl;
      return;
   }

   if(0<=s.find("aba") && s.find("aba") <n){
      cout << 3 <<endl;
      return;
   }

   if(0<=s.find("aca") && s.find("aca") <n){
      cout << 3 <<endl;
      return;
   }

   if(0<=s.find("abca") && s.find("abca") <n){
      cout << 4 <<endl;
      return;
   }

   if(0<=s.find("acba") && s.find("acba") <n){
      cout << 4 <<endl;
      return;
   }

   if(0<=s.find("abbacc") && s.find("abbacc") <n){
      cout << 7 <<endl;
      return;
   }

   if(0<=s.find("accabb") && s.find("accabb") <n){
      cout << 7 <<endl;
      return;
   }
   cout << -1 << endl;
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
