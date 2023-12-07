#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;
 
unordered_map <char, int> strength;

void compute()
{
    strength['J'] = 1;
    strength['2'] = 2;
    strength['3'] = 3;
    strength['4'] = 4;
    strength['5'] = 5;
    strength['6'] = 6;
    strength['7'] = 7;
    strength['8'] = 8;
    strength['9'] = 9;
    strength['T'] = 10;
    strength['Q'] = 11;
    strength['K'] = 12;
    strength['A'] = 13;
}

bool cmp(const pair<string, int> p1, const pair<string, int> p2)
{
    string a = p1.first;
    string b = p2.first;

    // cout << a << ' ' << b << '\n';

    for(int i=0; i<5; i++)
    {
        if(strength[a[i]] > strength[b[i]]) return 0;
        else if(strength[a[i]] < strength[b[i]]) return 1;
    }

    return 1;
}

void solve()
{    
    // Five of a kind - 6
    // Four of a kind - 5
    // Full house - 4 
    // Three of a kind - 3
    // Two pair - 2
    // One pair - 1
    // High card - 0
    
    unordered_map <int, vector<pair<string, int>>> mp;
    
    int n; cin >> n;
    while(n--)
    {
        string str; cin >> str;
        int amount; cin >> amount;

        map <char, int> freq;
        for(auto i : str) freq[i]++;

        int joker = freq['J'];

        map <int, int> inverse;
        for(auto i : freq) 
        {
            if(i.first == 'J') continue;
            inverse[i.second]++;
        }
        
        if(joker == 0)
        {    
            if(inverse[5] == 1) mp[6].push_back({str, amount});
            else if(inverse[4] == 1) mp[5].push_back({str, amount});
            else if(inverse[3] == 1 && inverse[2] == 1) mp[4].push_back({str, amount});
            else if(inverse[3] == 1) mp[3].push_back({str, amount});
            else if(inverse[2] == 2) mp[2].push_back({str, amount});
            else if(inverse[2] == 1) mp[1].push_back({str, amount});
            else mp[0].push_back({str, amount});
        }

        if(joker == 1)
        {
            if(inverse[4] == 1) mp[6].push_back({str, amount});
            else if(inverse[3] == 1) mp[5].push_back({str, amount});
            else if(inverse[2] == 2) mp[4].push_back({str, amount});
            else if(inverse[2] == 1) mp[3].push_back({str, amount});
            else mp[1].push_back({str, amount});
        }

        if(joker == 2)
        {
            if(inverse[3] == 1) mp[6].push_back({str, amount});
            else if(inverse[2] == 1) mp[5].push_back({str, amount});
            else mp[3].push_back({str, amount});
        }

        if(joker == 3)
        {
            if(inverse[2] == 1) mp[6].push_back({str, amount});
            else mp[5].push_back({str, amount});
        }

        if(joker >= 4)
        {
            mp[6].push_back({str, amount});
        }
    }

    int temp = 0;
    int k = 1;

    for(int i=0; i<=6; i++)
    {
        vector <pair<string, int>> arr = mp[i];
        sort(arr.begin(), arr.end(), cmp);

        for(auto j : arr) 
        {
            // cout << j.first << "\n";
            temp += (k * j.second);
            k++;
        }
    }

    cout << temp << '\n';
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
