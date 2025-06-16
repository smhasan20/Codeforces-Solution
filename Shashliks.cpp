//bismillahhirrahmanirrahim
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define line cout<<endl
 
#define all(x) x.begin(),x.end()
#define pb push_back
#define ppb pop_back
#define lp(n) for(int i = 1; i <= n; ++i)
#define lp0(n) for(int i = 0; i < n; ++i)
#define vi vector<int>


void solve()
{
    int k,a,b,x,y;
    cin>>k>>a>>b>>x>>y;

    if(x>y)
    {
        swap(x,y);
        swap(a,b);

    }

    int da=k-a;
    int res=0;
    if(da>=0)
    {
        
        res+=da/x;
        res++;
        k-=x*res;
    }

    int db=k-b;
    if(db>=0)
    {
        
        res+=db/y;
        res++;
    }
    cout<<res<<endl;
   }

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
