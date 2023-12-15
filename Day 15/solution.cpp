#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int ans_part1;
unordered_map <int, vector<pair<string, int>>> mp; // hash, <string, focal_length>
map <string, int> vis; 

int str_hash(string &str)
{
    int val = 0;

    for(auto i : str)
    {
        val = long(i) + val;
        val *= 17;
        val %= 256;
    }

    return val;
}

void solve()
{
    string str; cin >> str;
    int n = str.length();

    ans_part1 += str_hash(str);

    if(str[n-1] == '-')
    {
        string sub_str =  str.substr(0, n-1);
        if(vis[sub_str])
        {
            int sub_str_hash = str_hash(sub_str);
            
            int idx = 0;
            for(auto i : mp[sub_str_hash])
            {
                if(i.first == sub_str) break;
                else idx++;
            }

            mp[sub_str_hash].erase(mp[sub_str_hash].begin() + idx);

            vis[sub_str] = 0;
        }
        return;
    }

    int focal_length = str[n-1] - '0';
    string sub_str = str.substr(0, n-2);
    int sub_str_hash = str_hash(sub_str);

    if(vis[sub_str])
    {
        int idx = 0;
        for(auto i : mp[sub_str_hash])
        {
            if(i.first == sub_str) break;
            else idx++;
        }

        mp[sub_str_hash][idx] = {sub_str, focal_length};
    }
    else
    {
        vis[sub_str] = 1;
        mp[sub_str_hash].push_back({sub_str, focal_length});
    }
}

void fun()
{
    int ans_part2 = 0;

    for(auto i : mp)
    {
        int temp = 1;
        for(auto j : i.second)
        {
            ans_part2 += (i.first + 1) * temp * j.second;
            temp++;
        }
    }

    cout << ans_part2 << '\n';
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
    cin >> t;

    compute();
    
    for(int i=0;i<t;i++)
    {
        // cout << "Case #" << i+1 << ": "; // Kick Start
        solve();
    }

    cout << ans_part1 << '\n';

    fun();

	return 0;
}
