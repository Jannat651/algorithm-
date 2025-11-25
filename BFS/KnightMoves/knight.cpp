#include <bits/stdc++.h>
using namespace std;

struct Pos { int x, y; };

int main() {
    string s1, s2;
    int dx[] = {-2,-1,1,2, 2,1,-1,-2};
    int dy[] = { 1, 2,2,1,-1,-2,-2,-1};

    while(cin >> s1 >> s2) {
        int sx = s1[0]-'a', sy = s1[1]-'1';
        int ex = s2[0]-'a', ey = s2[1]-'1';

        if(sx==ex && sy==ey) {
            cout << "To get from " << s1 << " to " << s2 << " takes 0 knight moves.\n";
            continue;
        }

        int dist[8][8];
        memset(dist, -1, sizeof(dist));
        queue<Pos> q;

        dist[sx][sy] = 0;
        q.push({sx,sy});

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(int i=0;i<8;i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx>=0 && nx<8 && ny>=0 && ny<8 && dist[nx][ny]==-1){
                    dist[nx][ny] = dist[cur.x][cur.y]+1;
                    q.push({nx,ny});
                }
            }
        }

        cout << "To get from " << s1 << " to " << s2 << " takes "
             << dist[ex][ey] << " knight moves.\n";
    }
}

