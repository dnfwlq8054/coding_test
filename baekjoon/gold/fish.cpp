#include <iostream>
#include <cstdio>

using namespace std;

int result = 0;

const int dx[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
const int dy[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };

struct Fish {
	int x;
	int y;
	int dir;
	int fish_number;
	bool fish_live;
};

void stimulation(int v[4][4], Fish fish[], int shark_x, int shark_y, int sum) {

	int cp_v[4][4];
	Fish cp_fish[16];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cp_v[i][j] = v[i][j];
	}
	for (int i = 0; i < 16; i++)
		cp_fish[i] = fish[i];

	int n = cp_v[shark_x][shark_y];
	cp_v[shark_x][shark_y] = -1;	//먹힘

	// 상어 위치 갱신
	int shark_dir = cp_fish[n].dir;
	cp_fish[n].fish_live = false;

	sum += cp_fish[n].fish_number;
	if (sum > result) result = sum;

	//물고기 이동
	for (int i = 0; i < 16; i++) {
		if (cp_fish[i].fish_live) {
			int x = cp_fish[i].x;
			int y = cp_fish[i].y;
			int dir = cp_fish[i].dir;

			int next_x = x + (dx[dir]);
			int next_y = y + (dy[dir]);

			while (next_x < 0 || next_x > 3 || next_y < 0 || next_y > 3 || (shark_x == next_x && shark_y == next_y)) {
				dir = (dir + 1) % 8;
				next_x = x + (dx[dir]);
				next_y = y + (dy[dir]);
			}

			//물고기 swap
            if(cp_v[next_x][next_y] == -1){
			    int swap_fish = cp_v[next_x][next_y];
			    cp_fish[i].x = next_x;
			    cp_fish[i].y = next_y;
			    cp_fish[i].dir = dir;
			    cp_fish[swap_fish].x = x;
			    cp_fish[swap_fish].y = y;

                cp_v[next_x][next_y] = i;
				cp_v[x][y] = swap_fish;
			}
			else {
                cp_fish[i].x = next_x;
			    cp_fish[i].y = next_y;
			    cp_fish[i].dir = dir;
                
				cp_v[next_x][next_y] = i;
				cp_v[x][y] = -1;
			}
		}
	}
	//상어 이동
	for (int i = 1; i < 4; i++) {
		int dir_x = dx[shark_dir] * i;
		int dir_y = dy[shark_dir] * i;
		int next_x = shark_x + dir_x;
		int next_y = shark_y + dir_y;

		if (next_x < 0 || next_x > 3 || next_y < 0 || next_y > 3)
			break;

		if (cp_v[next_x][next_y] != -1)
			stimulation(cp_v, cp_fish, next_x, next_y, sum);
	}
}

int main()
{
	int v[4][4];
	Fish fish[16];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, _dir;
			scanf("%d %d", &num, &_dir);
			num--; _dir--;
			v[i][j] = num;
			fish[num].x = i;
			fish[num].y = j;
			fish[num].dir = _dir;
            fish[num].fish_live = true;
			fish[num].fish_number = num + 1;
		}
	}
	stimulation(v, fish, 0, 0, 0);
	printf("%d\n", result);
	return 0;
}