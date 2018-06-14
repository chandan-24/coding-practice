#include<bits/stdc++.h>
using namespace std;
#define ll long long

void init(ll a[], ll size[], ll n)
{
    for(ll i=1; i<=n; i++)
    {
        a[i]=i;
        size[i]=1;
    }
}

ll root(ll a[], ll i)
{
    while(a[i]!=i)
    {
        i=a[i];
    }
    return i;
}

void connect(ll g[], ll size[], ll a, ll b)
{
    ll root_a = root(g,a);
    ll root_b = root(g,b);
    
    if(root_a == root_b)
        return;
    
    if(size[root_a]>=size[root_b])
    {
        g[root_b]=g[root_a];
        size[root_a]+=size[root_b];
        size[root_b]=0;
    }
    else
    {
        g[root_a]=g[root_b];
        size[root_b]+=size[root_a];
        size[root_a]=0;
    }
}

int main()
{
    ll n,e;
    cin>>n>>e;
    ll g[n+5];
    ll size[n+5];
    
    init(g,size,n);
    
    ll a,b;
    while(e--)
    {
        cin>>a>>b;
        
        connect(g,size,a,b);
    }
    
    ll count=0;
    for(ll i=1; i<=n; i++)
        if(size[i]!=0)
            count++;
            
    cout<<count;
        
    return 0;
}














