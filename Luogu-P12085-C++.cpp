// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P12085
// Author:   nine19een
// Date:     2025-09-05

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 5e5 + 5;
struct Node{
	ll val, prev, next;
};
Node l[maxn];
ll N, K, idx, head, tail;
bool b[maxn];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

void Init(){
	head = 0;
	tail = 1;
	l[head].next = 2;
	l[tail].prev = head;
	idx = 2;
}

void Insert(ll num){
	Node p = {num, l[tail].prev, tail};
	l[l[tail].prev].next = idx;
	l[tail].prev = idx;
	l[idx++] = p;
}

void removeANDadd(ll idx){
	ll p_next = l[idx].next, p_prev = l[idx].prev;
	b[idx] = true;
	if(l[p_next].val != 0){
		l[p_next].val += l[idx].val;
		pq.push({l[p_next].val, p_next});
	}
	if(l[p_prev].val != 0){
		l[p_prev].val += l[idx].val;
		pq.push({l[p_prev].val, p_prev});
	}
	l[p_next].prev = p_prev;
	l[p_prev].next = p_next;
}

void Op(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq){
	while(b[pq.top().second] || l[pq.top().second].val != pq.top().first){			//pq : first->val second->idx
		pq.pop();
	}				
	ll min_num = pq.top().first;
	removeANDadd(pq.top().second);
}

void read(ll &x) {
	int sign = 1;
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			sign = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x *= sign;
}

int main(){
	Init();
	read(N);
	read(K);
	for(int i = 1; i <= N; ++i){
		ll num;
		read(num);
		pq.push({num, idx});
		Insert(num);
	}
	while(K--){
		Op(pq);
	}
	for(int i = l[head].next; i != 1; i = l[i].next){
		printf("%lld ", l[i].val);
	}
	return 0;
}
