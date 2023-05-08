#include <bits/stdc++.h>
using namespace std;
class Graph{
	int V; 
	list<int> *adj;
	vector<int> indegree;
	void alltopologicalSortUtil(vector<int>& res,bool visited[]);
public:
	Graph(int V); 
	void addEdge(int v, int w);
	void alltopologicalSort();
};
Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	for (int i = 0; i < V; i++) indegree.push_back(0);}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w); 
	indegree[w]++;}
void Graph::alltopologicalSortUtil(vector<int>& res,bool visited[]){
	bool flag = false;
	for (int i = 0; i < V; i++){
		if (indegree[i] == 0 && !visited[i]){
			list<int>:: iterator j;
			for (j = adj[i].begin(); j != adj[i].end(); j++)indegree[*j]--;
			res.push_back(i);
			visited[i] = true;
			alltopologicalSortUtil(res, visited);
			visited[i] = false;
			res.erase(res.end() - 1);
			for (j = adj[i].begin(); j != adj[i].end(); j++)indegree[*j]++;
			flag = true;
	}}
	if (!flag){
		for (int i = 0; i < res.size(); i++)cout << res[i] << " ";
		cout << endl;
}}
void Graph::alltopologicalSort()
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)visited[i] = false;
	vector<int> res;
	alltopologicalSortUtil(res, visited);
}
int main(){
	Graph g(6);
	int u,v;
    	for(int i=0;i<6;i++){
        		cin>>u>>v;
        g.addEdge(u,v);
    	}   
	cout << "All Topological sorts\n";
	g.alltopologicalSort();
	return 0;
}
