#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;
 
void compute()
{

}

void solve()
{
    int n = 140;

    vector <string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    // Expand
    vector <int> row(n+1, 0), col(n+1, 0);
    for(int i=0; i<n ;i++)
    {
        int row_flag = 1;
        int col_flag = 1;

        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == '#') row_flag = 0;
            if(arr[j][i] == '#') col_flag = 0;
        }
        
        int add = 1; // Part 1
        int add = 999999; // Part 2

        if(row_flag) row[i+1] += add;
        if(col_flag) col[i+1] += add;

        row[i+1] += row[i];
        col[i+1] += col[i];
    }

    vector <pair<int, int>> points;
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == '#') points.push_back({i, j});
        }
    }

    int ans = 0;
    for(int i=0; i<points.size(); i++)
    {
        for(int j=i+1; j<points.size(); j++)
        {
            int temp = 0;
            temp += abs(points[i].first - points[j].first) +  abs(points[i].second - points[j].second);
            temp += row[max(points[j].first, points[i].first) + 1] - row[min(points[j].first, points[i].first)];
            temp += col[max(points[j].second, points[i].second) + 1] - col[min(points[j].second, points[i].second)];
            ans += temp;
        }
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
