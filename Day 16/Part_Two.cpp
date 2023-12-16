#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int bfs(int i, int j, string direction, vector <string> &arr)
{
    int n = arr.size();

    queue <pair<pair<int, int>, string>> q; // <x, y> , <dir> 
    vector <vector<map<string, int>>> vis(n, vector<map<string, int>> (n));
    map <string, pair<int, int>> dir;
    dir["right"] = {0, 1};
    dir["left"] = {0, -1};
    dir["up"] = {-1, 0};
    dir["down"] = {1, 0};

    // starting node
    q.push({{i, j}, direction});

    while(!q.empty())
    {

        auto node = q.front(); q.pop();
        
        int x = node.first.first;
        int y = node.first.second;
        string next = node.second;

        if(x<0 || y<0 || x>=n || y>=n) continue;

        if(vis[x][y][next] == 1) continue;
        vis[x][y][next] = 1;

        if(arr[x][y] == '.')
        {
            int xx = x + dir[next].first;
            int yy = y + dir[next].second;
            q.push({{xx, yy}, next});
        }

        if(arr[x][y] == '|' && (next == "right" || next == "left"))
        {
            q.push({{x-1, y}, "up"});
            q.push({{x+1, y}, "down"});
        }
        else if(arr[x][y] == '|')
        {
            int xx = x + dir[next].first;
            int yy = y + dir[next].second;
            q.push({{xx, yy}, next});
        }

        if(arr[x][y] == '-' && (next == "up" || next == "down"))
        {
            q.push({{x, y-1}, "left"});
            q.push({{x, y+1}, "right"});
        }
        else if(arr[x][y] == '-')
        {
            int xx = x + dir[next].first;
            int yy = y + dir[next].second;
            q.push({{xx, yy}, next});
        }

        if(arr[x][y] == '\\')
        {
            if(next == "right") q.push({{x+1, y}, "down"});
            if(next == "down") q.push({{x, y+1}, "right"});

            if(next == "up") q.push({{x, y-1}, "left"});
            if(next == "left") q.push({{x-1, y}, "up"});
        }

        if(arr[x][y] == '/')
        {
            if(next == "right") q.push({{x-1, y}, "up"});
            if(next == "up") q.push({{x, y+1}, "right"});  

            if(next == "down") q.push({{x, y-1}, "left"});
            if(next == "left") q.push({{x+1, y}, "down"});
        }
    }

    int ans = 0;

    for(auto i : vis)
    {
        for(auto j : i) ans += j.size() >= 1;
    }

    return ans;
}

void solve()
{
    int n = 110;

    vector <string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = 0;

    for(int i=0; i<n; i++)
    {
        ans = max({ans, bfs(0, i, "down", arr), bfs(i, 0, "right", arr), bfs(n-1, i,"up", arr), bfs(i,n-1, "left", arr)});
    }

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
