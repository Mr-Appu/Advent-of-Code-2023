#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int value(int i, int j, vector<string> &arr)
{
    return arr[i][j] - '0';
}

int dijkstra(int i, int j, vector <string> &arr)
{
    int n = arr.size();
    priority_queue <pair<int, pair<pair<int, int>, string>>, vector<pair<int, pair<pair<int, int>, string>>>, greater<pair<int, pair<pair<int, int>, string>>>> pq;

    vector <vector<map<string, int>>> vis(n, vector<map<string, int>> (n));

    // Starting Node
    pq.push({0, {{i, j}, ""}});

    while(!pq.empty())
    {
        auto node = pq.top(); pq.pop();

        int x = node.second.first.first;
        int y = node.second.first.second;

        int val = node.first;
        string dir = node.second.second;

        if(dir.length() == 4) dir = dir.substr(1, 3);

        char back = dir[dir.length() - 1];

        if(vis[x][y][dir] == 1) continue;
        vis[x][y][dir] = 1;

        if(x == n-1 && y == n-1) return val;

        // left 
        if(y-1 >= 0 && dir != "lll" && back != 'r') pq.push({val+value(x, y-1, arr), {{x, y-1}, dir+"l"}});

        // right
        if(y+1 < n && dir != "rrr" &&  back != 'l') pq.push({val+value(x, y+1, arr), {{x, y+1}, dir+"r"}});

        // down
        if(x+1 < n && dir != "ddd" && back != 'u') pq.push({val+value(x+1, y, arr), {{x+1, y}, dir+"d"}});

        // up
        if(x-1 >= 0 && dir != "uuu" && back != 'd') pq.push({val+value(x-1, y, arr), {{x-1, y}, dir+"u"}});
    }

    return -1;
}

void solve()
{
    int n = 141;

    vector <string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << dijkstra(0, 0, arr);
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
