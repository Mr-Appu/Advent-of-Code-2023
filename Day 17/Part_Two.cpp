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
    priority_queue <tuple<int, int, int, char, int>, vector<tuple<int, int, int, char, int>>, greater<tuple<int, int, int, char, int>>> pq;

    map <tuple<int, int, char, int>, int> vis;
    map <char, pair<int, int>> mp;

    mp['l'] = {0, -1};
    mp['r'] = {0, 1};
    mp['d'] = {1, 0};
    mp['u'] = {-1, 0};

    // Starting Node
    pq.push({0, i, j, 'l', 0});
    pq.push({0, i, j, 'r', 0});
    pq.push({0, i, j, 'd', 0});
    pq.push({0, i, j, 'u', 0});

    while(!pq.empty())
    {
        auto node = pq.top(); pq.pop();

        int x = get<1>(node);
        int y = get<2>(node);
        int val = get<0>(node);
        char dir = get<3>(node);
        int len = get<4>(node);

        if(x == n-1 && y == n-1) return val;

        if(vis[{x, y, dir, len}] == 1) continue;
        vis[{x, y, dir, len}] = 1;

        if(len < 4)
        {
            int xx = x + mp[dir].first;
            int yy = y + mp[dir].second;

            if(xx >= 0 && xx < n && yy >= 0 && yy < n) pq.push({val + value(xx, yy, arr), xx, yy, dir, len+1});
            continue;
        }

        if(x == n-1 && y == n-1) return val;

        if(dir == 'l')
        {
            if(y-1 >= 0 && len != 10) pq.push({val+value(x, y-1, arr), x, y-1, 'l', len+1});
            if(x-1 >= 0) pq.push({val+value(x-1, y, arr), x-1, y, 'u', 1});
            if(x+1 < n) pq.push({val+value(x+1, y, arr), x+1, y, 'd', 1});
        }

        if(dir == 'r')
        {
            if(y+1 < n && len != 10) pq.push({val+value(x, y+1, arr), x, y+1, 'r', len+1});
            if(x-1 >= 0) pq.push({val+value(x-1, y, arr), x-1, y, 'u', 1});
            if(x+1 < n) pq.push({val+value(x+1, y, arr), x+1, y, 'd', 1});
        }

        if(dir == 'u')
        {
            if(x-1 >= 0 && len != 10) pq.push({val+value(x-1, y, arr), x-1, y, 'u', len+1});
            if(y-1 >= 0) pq.push({val+value(x, y-1, arr), x, y-1, 'l', 1});
            if(y+1 < n) pq.push({val+value(x, y+1, arr), x, y+1, 'r', 1});
        }

        if(dir == 'd')
        {
            if(x+1 < n && len != 10) pq.push({val+value(x+1, y, arr), x+1, y, 'd', len+1});
            if(y-1 >= 0) pq.push({val+value(x, y-1, arr), x, y-1, 'l', 1});
            if(y+1 < n) pq.push({val+value(x, y+1, arr), x, y+1, 'r', 1});
        }
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
