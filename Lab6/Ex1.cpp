class Solution {
public:
    int lastStoneWeight(vector<int>& stone) {
        priority_queue <int> pq;

        for(int i=0;i<stone.size();i++)
            pq.push(stone[i]);

        while(pq.size()>1)
        {
            int one = pq.top();   pq.pop();
            int two = pq.top();   pq.pop();
            if( one != two )
                pq.push(one - two);
        }
        if(pq.size() == 0)
            return 0;
        return pq.top();
    } 
};
