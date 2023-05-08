#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,x
    cin>>n >>m;
    priority_queue<pair<ll,ll>> pq;map<ll,ll> mp;
    for(ll i=0;i<n;i++)
    {
        cin>>x;         mp[x]++;
        pq.push({mp[x],x});
        cout<<pq.top().second<<" "<<pq.top().first<<endl;
    }
return 0; 
}
