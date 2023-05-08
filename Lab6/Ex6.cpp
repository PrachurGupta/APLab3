#include<bits/stdc++.h>
using namespace std;

int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i : A)pq.push(i);
    int ans = 0;
    int temp = pq.top();
    pq.pop();
    while(temp < k){
        if(pq.empty()) return -1;
        int secTemp = pq.top();
        pq.pop();
        pq.push(temp+2*secTemp);
        temp = pq.top();
        pq.pop();
        ans++;
    }
    return ans ;  }
