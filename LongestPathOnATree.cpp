#include <bits/stdc++.h>
#define N 100001

using namespace std;

struct Edge {
	int nod;
	int w;
	Edge(int nod, int w) {
		this->nod = nod;
		this->w = w;
	}
};

int n;
vector<Edge> A[N];
int d[N];

void input() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		A[u].push_back(Edge(v,w));
		A[v].push_back(Edge(u,w));
	}
}

int BFS(int u) {
	queue<int> Q;
	for (int v = 1; v <= n; v++) d[v] = -1;
	Q.push(u);
	d[u] = 0;
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (int i = 0; i < A[v].size(); i++) {
			Edge e = A[v][i];
			int x = e.nod;
			int w = e.w;
			if (d[x] == -1) {
				Q.push(x);
				d[x] = d[v] + w;
			}
		}
	}
	int maxDist = 0;
	int sol_v = -1;
	for (int v = 1; v <= n; v++) {
		if (d[v] > maxDist) {
			maxDist = d[v];
			sol_v = v;
		}
	}
	return sol_v;
}

void solve() {
	int s = 1;
	int x = BFS(s);
	int y = BFS(x);
	cout << d[y];
}

int main(int argc, char const *argv[]) {
	input();
	solve();
	return 0;
}
