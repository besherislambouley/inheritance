/*
 * it is easy to see that the answer to each child is the MST of the remaining edges
 * that means we can sort the edges by the value and give every edge to the first child that could take it without forming cycles
 * we notice that we can use binary search to choose the child we are giving  the current edge to 
 * we can build k dsu ( memory = k*n ) to check if the current child is able to maintain this edge
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
int n , m , k ;
int ans [300009];
pair<pi,pi>e[300009];
// dsu 
int p[1009][10009] , sz[1009][10009];
int get ( int node, int t ) {
	if ( p [node][t] == node ) return node;
	return p[node][t] = get ( p[node][t],t );
}
void merge ( int a , int b ,int t ){
	a = get ( a , t ) ;
	b = get ( b , t ) ;
	if ( a == b ) return ;
	if ( sz [a][t] < sz [b][t] ) swap (a , b ) ;
	p [b][t] = a ;
	sz[a][t] += sz[b][t];
}
int main () {
	mem ( ans , -1 ) ;
	cin >> n >> m >> k ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int a , b , c ;
		scanf("%d%d%d",&a,&b,&c);
		a -- ,b -- ;
		e[i] = { { c , i } , { a , b } } ;
	}
	sort ( e , e + m ) , reverse ( e , e +m ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < k ; j ++ ) {
			p [i][j] = i , sz [i][j] = 1 ;
		}
	}
	for ( int i = 0 ; i < m ; i ++ ) {
		int l = -1 , r = k ;
		while ( r - l > 1 ) {
			if ( get( e[i].se.fi , mid ) != get( e[i].se.se , mid ) ) r = mid;
			else l = mid ;
		}
		if ( r != k ) {
			ans [ e[i].fi.se ] = r ;
			merge ( e[i].se.fi , e[i].se.se , r ) ;
		}
	}
	for ( int i = 0 ; i < m ; i ++ ) printf("%d\n",ans[i]+1);
}

