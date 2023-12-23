#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

map <char, pair<int, int>> mp;

int ans;

void dfs(pair<int, int> node, vector<string> &arr, vector<vector<int>> &vis, int count)
{
    int n = arr.size();

    if(node.first == n-1) {
        ans = max(ans, count);
        return;
    }

    int x = node.first;
    int y = node.second;

    vis[x][y] = 1;

    vector <vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    if(mp.find(arr[x][y]) != mp.end())
    {
        int xx = x + mp[arr[x][y]].first;
        int yy = y + mp[arr[x][y]].second;

        if(xx >= 0 && xx < n && yy >= 0 && yy < n && arr[xx][yy] != '#' && vis[xx][yy] == 0)
        {
            dfs({xx, yy}, arr, vis, count+1);
        }
    }
    else
    {
        for(auto i : dir)
        {
            int xx = x + i[0];
            int yy = y + i[1];

            if(xx >= 0 && xx < n && yy >= 0 && yy < n && arr[xx][yy] != '#' && vis[xx][yy] == 0)
            {
                dfs({xx, yy}, arr, vis, count+1);
            }
        }
    }

    vis[x][y] = 0;
}

void solve()
{
    int n = 141;

    vector<string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    pair<int, int> start = {0, 1};
    vector<vector<int>> vis(n, vector<int>(n, 0));
    mp['<'] = {0, -1};
    mp['>'] = {0, 1};
    mp['^'] = {-1, 0};
    mp['v'] = {1, 0};

    dfs(start, arr, vis, 0);

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
