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
#define vvb vector<vb>

using namespace std;
// Logic
// 색종이의 수가 작은 편이기에 검은 색종이를 실제로 붙이고 넓이를 구해볼 수 있다.
// 색종이의 수가 많아져 일일이 붙일 수 없지만 흰 도화지는 확인 할 수 있다면 '누적합'을 사용해볼 수 있다.

// Implementation
// count(begin_iter, end_iter, value) 를 사용하여 값의 개수를 셀 수 있다. O(n^2)
int32_t main()
{

    vvb grid(101, vb(101, 0));

    int n;
    cin >> n;


    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10; k++)
                grid[y+j][x+k] = 1;
    }    

    int ans = 0;
    for(int i = 0; i < 101; i++)
        ans += count(grid[i].begin(), grid[i].end(), 1);
        
    cout << ans << "\n";
    
}