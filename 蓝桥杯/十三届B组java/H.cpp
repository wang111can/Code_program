#include <bits/stdc++.h>
#define x first
#define y second


using namespace std;

char g[510][510];
// 源点 为 100 100
int n, m;
string str;

int main() {
	cin >> n >> str;
	int a = 500, b = 0, c = 0, d = 500 ; // 右上角  左下角  
	int x = 210, y = 210;
	int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    for (int i = 0;i < 510;i ++ ) {
        for (int j = 0;j < 510;j ++ ) {
            g[i][j] = '1';
        }
    }
	g[x][y] = '2';		
	for (int i = 0;i < 4;i ++ ) {
            int xx = x + dx[i], yy = y + dy[i];	
            if (g[xx][yy] != '2') {
		        g[xx][yy] = '*';
            		        		a = min(a, xx), b = max(b, yy);
		                c = max(c, xx), d = min(d, yy);   
                
            }
            
	}
	for (auto t : str) {
		if (t == 'U') {
			x -= 1;
		}
		else if (t == 'L') {
			y -= 1;
		}
		else if (t == 'R') {
			y += 1;
		}
		else if (t == 'D') {
			x += 1;
		}
		g[x][y] = '2';
		for (int i = 0;i < 4;i ++ ) {
            int xx = x + dx[i], yy = y + dy[i];	
            if (xx >= 0 && yy >= 0 && xx < 510 && yy < 510 && g[xx][yy] != '2') {
		        g[xx][yy] = '*';
		        		a = min(a, xx), b = max(b, yy);
		                c = max(c, xx), d = min(d, yy);   
            }
		       
		}
		a = min(a, x), b = max(b, y);
		c = max(c, x), d = min(d, y);
	} 


    // for (int i = a;i <= c;i ++ ) {
    //     for (int j = d;j <= b;j ++ ) {
    //         cout << g[i][j] ;
    //     }   
    //     cout << endl;
    // }


    queue<pair<int, int>> q; q.push({0, 0}); q.push({500, 500});
q.push({500, 0});
q.push({0, 500});

    while (q.size()) {
        pair<int, int> t = q.front(); q.pop();
        for (int i = 0;i < 4;i ++ ) {
            int xx = t.x + dx[i], yy = t.y + dy[i];
            if (xx >= 0 && yy >= 0 && xx < 510 && yy < 510) {
                if (g[xx][yy] == '1') {
                    g[xx][yy] = ' ';
                    q.push({xx, yy});
                }
            }
        }
    }
    for (int i = a;i <= c;i ++ ) {
        for (int j = d;j <= b;j ++ ) {
            if (g[i][j] == '1') {
                cout << '*';
            }
            else if (g[i][j] == '2') {
                cout << ' ';
            }
            else cout << g[i][j];
        }   
        cout << endl;
    }


}
