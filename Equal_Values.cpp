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
   int n;
   cin>>n;
   int a[n];

   lp0(n)
   {
    cin>>a[i];
   }   
   map<int,int>l,r,l1,r1;
   l[0]=0;

   for(int i=1;i<n;i++)
   {
       if(a[i]==a[i-1])
       {
        l[i]=l[i-1];
       }
       else
       {
        l[i]=i;
       }
   }

   r[n-1]=0;
   for(int i=n-2;i>=0;i--)
   {
    if(a[i]==a[i+1])
    {
        r[i]=r[i+1];
    }
    else
    {
        r[i]=n-1-i;
    }
   }

   vector<int>v;

   v.push_back(a[0]);
   l1[0]=l[0];
   r1[0]=r[0];
   int j=1;

   for(int i=1;i<n;i++)
   {
    if(v.back()!=a[i])
    {
        v.pb(a[i]);
        l1[j]=l[i];
        r1[j]=r[i];
        j++;
    }

   }

  int ans=LLONG_MAX;
   for(int i=0;i<v.size();i++)
   {
      int res=l1[i]*v[i];
      res+=(r1[i]*v[i]);
      ans=min(ans,res);
   }

   cout<<ans<<endl;


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
