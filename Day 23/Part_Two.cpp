// My Fav Advent of Code 2023 Problem
// Graph compression

#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int n;
int ans;
unordered_map <int, vector<pair<int, int>>> graph;
unordered_map <int, int> vis;

void dfs(int node, int count)
{
    if(node == (n*n - 2)) 
    {
        ans = max(ans, count);
        return;
    }

    vis[node] = 1;

    for(auto adj_node : graph[node])
    {
        if(vis[adj_node.first] != 1) dfs(adj_node.first, count+adj_node.second);
    }

    vis[node] = 0;
}

void compress()
{
    for(auto nodes : graph)
    {
        if(nodes.second.size() == 2)
        {
            auto node = nodes.second;
            
            auto node_1 = node[0];
            auto node_2 = node[1];

            // node 1
            for(auto &i : graph[node_1.first])
            {
                if(i.first == nodes.first)
                {
                    i.first = node_2.first;
                    i.second = node_2.second + i.second;
                }
            }

            // node 2
            for(auto &i : graph[node_2.first])
            {
                if(i.first == nodes.first)
                {
                    i.first = node_1.first;
                    i.second = node_1.second + i.second;
                }
            }
        }
    }
}

void solve()
{
    n = 141;

    vector<string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector <vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] != '#')
            {
                for(auto k : dir)
                {
                    int x = i + k[0];
                    int y = j + k[1];

                    if(x>=0 && y>=0 && x<n && y<n && arr[x][y] != '#')
                    {
                        graph[i*n + j].push_back({x*n + y, 1});
                    }
                }
            }
        }
    }

    compress();

    dfs(1, 0);

    cout << ans << '\n';
}

signed main(void) 
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;

    compute();
    
    for(int i=0;i<t;i++)
    {
        // cout << "Case #" << i+1 << ": "; // Kick Start
        solve();
    }

	return 0;
}
