#include <bits/stdc++.h>

#define int int64_t
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>

#define pii pair<int, int>
#define vp vector<pii>
#define vvp vector<vp>

#define vc vector<char>
#define vvc vector<vc>

#define vd vector<double>
#define vvd vector<vd>

#define vb vector<bool>
#define vvb vector<bool>

using namespace std;

// Logic
// dz= 를 제외한 나머지 크로아티아 알파벳은 2개의 알파벳이 1개로 바뀌는 것이고
// dz= 는 3개의 알파벳이 1개로 바뀌는 것이다
// 따라서 크로아티아 알파벳의 등장 횟수를 안다면 알파벳의 수가 얼마나 감소하는지 확인할 수 있다.
// 단, dz=와 z=는 중복하여 세어질 수 있으므로 유의해야 한다.

// Implementation
// string.substr(index, length) 와 string 비교를 이용하면 부분 문자열이 맞는지 확인 할 수 있다. (Line.46)
int32_t main()
{
    string s;
    cin >> s;
    

    vector<string> dict = {"c=", "c-", "d-", "lj", "nj", "s=", "z=", "dz="};
    vi cnt(dict.size(), 0);
    for(int i = 0; i < dict.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            if(j+dict[i].size() > s.size())
                continue;
            
            cnt[i] += (s.substr(j, dict[i].size()) == dict[i]);
        }
    }


    int ans = s.size();
    for(int i = 0; i < cnt.size()-2; i++)
        ans -= cnt[i];
    int cnt_original_zz = cnt[cnt.size()-2] - cnt[cnt.size()-1];
    ans -= cnt_original_zz;
    ans -= 2*cnt[cnt.size()-1];


    cout << ans << "\n";
    
}