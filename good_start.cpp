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

#define MOD 1000000007

const int MAX = 2000006;
int fact[MAX], invFact[MAX];

int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modExp(fact[i], MOD - 2, MOD);
    }
}

int nCr(int n, int r) {
    if (r > n | r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
bool prime(int n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}

void solve()
{
    int w,h,a,b;
    cin>>w>>h>>a>>b;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1>x2)
    {
        swap(x1,x2);
        
    }
   if(y1>y2)
   {
    swap(y1,y2);
   }

   x1+=a;
   y1+=b;
   if(x2-x1>=0 and (x2-x1)%a==0)
   {
    yes;
    return;
   }
   else if(y2-y1>=0 and (y2-y1)%b==0)
   {
    yes;
    return;
   }
   no;

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
