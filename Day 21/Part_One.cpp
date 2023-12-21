#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

void bfs(int i, int j, vector<string> &arr)
{
    int n = arr.size();
    int step = 0;

    queue <pair<int, int>> q;
    q.push({i, j});

    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while(true)
    {
        int q_size = q.size();
        if(step == 64) {
            cout << q_size << '\n';
            return;
        }

        vector <vector<int>> vis(n, vector<int> (n, 0));
        while(q_size--)
        {
            auto node = q.front(); q.pop();

            for(auto d : dir)
            {
                int x = d[0] + node.first;
                int y = d[1] + node.second;

                if(x<n && x>=0 && y<n && y>=0 && arr[x][y] == '.' && !vis[x][y])
                {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        step++;
    }

}

void solve()
{
    int n = 131;

    pair <int, int> start;

    vector <string> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i].find("S") != string::npos) {
            start = {i, arr[i].find("S")};
            arr[i][start.second] = '.';
        }
    }

    bfs(start.first, start.second, arr);
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
