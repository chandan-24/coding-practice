#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector <ll> g[], bool v[], ll s)
{
    stack <ll> st;
    v[s]=true;
    st.push(s);
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        cout<<s<<" ";
        for(ll i=0; i<g[s].size(); i++)
        {  
            if(v[g[s][i]] == false)
            {
                st.push(g[s][i]);
                v[g[s][i]]=true;
            }
        }
    }
    cout<<"\n";
}

int main()
{
    ll n,e;
    cin>>n>>e;
    vector <ll> g[n+5] ;
    bool v[n+5];
    memset(v, false, sizeof(v));
    while(e--)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll con=0;
    for(ll i=1; i<=n; i++)
    {
        if(v[i]==false)
        {
            dfs(g,v,i);
            con++;
        }
    }
    cout<<con;
    return 0;
}
