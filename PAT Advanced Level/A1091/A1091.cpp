#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
struct NODE{
	int x, y, z;
}node;
int X[6] = { 0,0,0,0,1,-1 };
int Y[6] = { 0,0,1,-1,0,0 };
int Z[6] = { 1,-1,0,0,0,0 };
int slice[1288][129][61];
bool index[1288][129][61] = { false };
int m, n, l, t;
bool test(int x, int y, int z) {
	if (x >= n || x < 0 || y >= m || y < 0 || z >= l || z < 0)
		return false;
	if (slice[x][y][z] == 0 || index[x][y][z] == 1)
		return false;
	return true;
}
int BFS(int x1,int y1,int z1) {
	queue<NODE>q;
	int count = 0;
	node.x = x1;
	node.y = y1;
	node.z = z1;
	q.push(node);
	index[x1][y1][z1] = true;
	while (!q.empty()) {
		NODE top = q.front();
		q.pop();
		count++;
		for (int i = 0; i < 6; i++){
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			int newz = top.z + Z[i];
			if (test(newx, newy, newz)) {
				node.x = newx;
				node.y = newy;
				node.z = newz;
				q.push(node);
				index[newx][newy][newz] = true;
			}
		}
	}
	if (count >= t)
		return count;
	else
		return 0;
}
int main(){
	cin >> n >> m >> l >> t;
	for (int z = 0;z < l;z++)
		for (int x = 0;x < n;x++)
			for (int y = 0;y < m;y++)
				cin >> slice[x][y][z];
	int ans = 0;
	for(int z=0;z<l;z++)
		for(int x=0;x<n;x++)
			for(int y=0;y<m;y++)
				if (slice[x][y][z] == 1 && index[x][y][z] == false) 
					ans += BFS(x, y, z);
	cout << ans << endl;
	system("pause");
	return 0;
}