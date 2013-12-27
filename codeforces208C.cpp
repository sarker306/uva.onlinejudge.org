#include <cstdio>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

list<int> adj[100005];
int n;
int lvl[100005], cntLvl[100005];

double bfs(){
	double res = 0;
	queue<int> q;
	
	for ( int i = 0 ; i <= n ; i++ ) cntLvl[i] = lvl[i] = 0;
	q.push(0);
	lvl[0] = 1;
	cntLvl[1]++;
	while ( q.empty() == false ){
		int u = q.front();
		q.pop();
		
		for ( list<int>::iterator ptr = adj[u].begin() ; ptr != adj[u].end() ; ptr++ ){
			int v = *ptr;
			if ( lvl[v] == 0 ){
				q.push(v);
				lvl[v] = lvl[u] + 1;
				//res += 1.0/lvl[v];
				cntLvl[lvl[v]]++;
			}
		}
	}

 	for ( int i = 1 ; i <= n ; i++ ){
	 //	printf("Level %d : %d\n", i, cntLvl[i]);
		res += (cntLvl[i] * 1.0) / i;
	}
 
	return res;
}

int main(){
	while ( cin >> n ){
		for ( int i = 1 ; i < n ; i++ ){
			int u, v;
			
			cin >> u >> v;
			u--, v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		printf("%.10lf\n", bfs());
	}
	
	return 0;
}

