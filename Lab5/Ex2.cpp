#include <bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool safe(int x ,int y , int n , vector<vector<int>> visited ,vector<vector<int>> &m ){
        if( ( x >= 0 && x < n ) && ( y >= 0 && y < n ) && visited[x][y] == 0 && m[x][y] != 0)
            return true; 
        else       return false;
    }
    void solve(vector<vector<int>> &m , int n ,vector<string>& ans , int x , int y ,vector<vector<int>> visited , string path){
        if( m[x][y] == 29){
            ans.push_back(path);
            return ;
        }
           visited[x][y] = 1;
        if( safe( x + 1 , y , n ,visited , m)){
            path.push_back('D');
            solve( m , n , ans , newx , newy , visited , path);
            path.pop_back();
        }
        if( safe( x , y-1 , n ,visited , m)){
            path.push_back('L');
            solve( m , n , ans , newx , newy , visited , path);
            path.pop_back();
        }
        if( safe( x , y+1 , n ,visited , m)){
            path.push_back('R');
            solve( m , n , ans , newx , newy , visited , path);
            path.pop_back(); }
        if( safe( x-1 , y , n ,visited , m)){
            path.push_back('U');
            solve( m , n , ans , newx , newy , visited , path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans ;
        if( m [0][0] == 0)
            return ans;
        vector<vector<int>> visited = m;
        for( int i = 0; i < n; i++)
            for( int j = 0; j < n; j++)
                visited [i][j] = 0;
        string path = "";
        solve( m , n , ans , 0 , 0 , visited , path);
        return ans;
    }   };

int main()
{
	int n = 5;  vector<vector<int>> m(n,vector<int>(n,0)
	for(int i=0,i<n;i++)
		for(int j=0;j<n;j++)
			cin>>n[i][j];
	Solution obj;
	vector<string> result = obj.findPath(m,n);
	sort(result.begin(),result.end());
	if(result.sizre() == 0)    cout<<-1;
	else
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
	return 0; }
