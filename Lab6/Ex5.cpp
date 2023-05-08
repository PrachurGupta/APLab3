#include<bits/stdc++.h>
using namespace std;
int t,k;
#define int long long
#define arr(a,n) vector<int> a;
ffd(i,0,n){ int k;cin>>k;a.push_back(k); }
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;string s;cin>>s;
    map<int,int>ans;
    priority_queue< pair<int,pair<int,int>> >q;
    q.push({n,{-1,-n}});
    priority_queue top;
    
    for(int i=n;i<m;i++){
        top=q.top();q.pop();
        int gap=top.first,
        l=-1*top.second.first,r=-1*top.second.second;
        if(r<l)break;
        int pos=(l+r)/2;
        

        if((gap)%2==0&&(s[i-1]=='R')) 
pos++;
        if(l<pos) 
q.push({pos+l,{-1*l,1-pos}});
        if(pos<r) 
q.push({r-pos,{-1*(pos+1),-1*r}});
        ans[pos]=i;
    }

    int nik;cin>>nik;
    while(nik--){
        int k;cin>>k;
        if(ans[k]==0)cout<<-1<<endl;
        else cout<<ans[k]<<endl;
    }
}
