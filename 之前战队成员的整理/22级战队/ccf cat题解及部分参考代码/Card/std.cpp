#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
	ll l,c;
} t[30005];
ll n,g,sum,q,ans=1e18;
map<ll,ll>m;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>t[i].l;
	}
	for(int i=1; i<=n; i++) {
		cin>>t[i].c;
		if(!m.count(t[i].l))m[t[i].l]=t[i].c;
        else m[t[i].l]=min(m[t[i].l],t[i].c);
	}
	for(int i=1; i<=n; i++) {
		for(map<ll,ll>::iterator it=m.begin(); it!=m.end(); it++) {
			ll d=gcd(it->first,t[i].l);
			if(!m.count(d))m[d]=it->second+t[i].c;
			else m[d]=min(m[d],it->second+t[i].c);
		}
	}
	if(!m.count(1))cout<<-1;
	else cout<<m[1];
	return 0;
}