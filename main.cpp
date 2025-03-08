#include <bits/stdc++.h>
using namespace std;

void printRoute(int route[][100], int N);
bool possibleMove(int next_x, int next_y, int N, int route[][100]);
int findRoute(int x, int y, int step, int x_move[], int y_move[], int route[][100], int N);
void mainFunc(int N, int x, int y);

int main() {
    int N, x, y;
    cout << "Nhập dữ liệu: [size] / [start_x] / [start_y]  ";
    cin >> N >> x >> y;
    mainFunc(N, x, y);
    return 0;
}

void printRoute(int route[][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          cout << " " << setw(2) << route[i][j] << " ";
        }
        cout << endl;
    }
}

bool possibleMove(int next_x, int next_y, int N, int route[][100]) {
    return (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && route[next_x][next_y] == -1);
}

int findRoute(int x, int y, int step, int x_move[], int y_move[], int route[][100], int N) {
    if (step == N * N) {
        return 1;
    }
    int next_x, next_y;
    for (int i = 0; i < 8; i++) {
        next_x = x + x_move[i];
        next_y = y + y_move[i];
        if (possibleMove(next_x, next_y, N, route)) {
            route[next_x][next_y] = step;
            if (findRoute(next_x, next_y, step + 1, x_move, y_move, route, N) == 1) {
                return 1;
            } else {
                route[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}

void mainFunc(int N, int x, int y) {
    int route[100][100]; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            route[i][j] = -1; 
        }
    }

    route[x][y] = 0;

    int x_move[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_move[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    if (findRoute(x, y, 1, x_move, y_move, route, N) == 1) {
        printRoute(route, N);
    } else {
        cout << "Không có nước đi thoả mãn" << endl;
    }
}
