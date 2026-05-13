// Problem:  Luogu P2249 【深基13.例1】查找
// Link:     https://www.luogu.com.cn/problem/P2249
// Author:   nine19een
// Date:     2025-07-11

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e6 + 5;
void find1st(int t,int nums[maxn],int N)
{
   	int left = 1, right = N, ans = -1;
	while(left <= right)
    {
		int middle = (left + right)/2;
        if(t < nums[middle])
        {
            right = middle - 1;
            continue;
        }
        else if(t > nums[middle])
        {
            left = middle + 1;
        }
        else if(t == nums[middle])
        {
			ans = middle;
			right = middle - 1;
        }
    }
	cout << ans << " ";	
}
int nums_[maxn];
int target[100005], n, m;
int main()
{
	memset(nums_, 0, maxn);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> nums_[i];
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> target[i];
	}
	for(int i = 1; i <= m; i++)
	{
		find1st(target[i], nums_, n);
	}
    return 0;
}

// -----------------------------------------------------------------
// Date:     2025-11-11

#include<bits/stdc++.h>
using namespace std;

int n, m;

void query(int t_num, vector<int> &a){
	auto it = a.end();
	it = lower_bound(a.begin(), a.end(), t_num);
	if(it != a.end() && *it == t_num){
		cout << it - a.begin() + 1 << " ";
	} else {
		cout << -1 << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= m; ++i){
		int target_num;
		cin >> target_num;
		query(target_num, a);
	}
	return 0;
}
