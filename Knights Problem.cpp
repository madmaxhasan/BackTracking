#include<bits/stdc++.h>

using namespace std;

int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int counter = 1;

bool isSafe(int x, int y, int solve[8][8])
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && solve[x][y] == -1);
}

void printSolution(int solve[8][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            printf("%d ",solve[i][j]);
        }
        printf("\n");
    }
}

void BackTrack(int idx, int x, int y, int N, int arr[8][8], int solve[8][8])
{
    if(idx == N*N)
    {
        cout << "\nPrinting Solution: " << counter++ << endl;
        printf("\n");
        printSolution(solve);
        return;
    }
    for(int i=0; i<8; i++)
    {
        int next_x = x + X[i];
        int next_y = y + Y[i];
        if(isSafe(next_x, next_y, solve))
        {
            solve[next_x][next_y] = idx;
            BackTrack(idx+1, next_x, next_y, N, arr, solve);
            solve[next_x][next_y] = -1;
        }
    }
}

int main()
{
    int arr[8][8];
    int solve[8][8];
    memset(solve, -1, sizeof(solve));
    memset(arr, 0, sizeof(arr));
    cout << "Knight Moves Backtrack" << endl;
    solve[0][0] = 0;
    BackTrack(1, 0, 0, 8, arr, solve);
    return 0;
}
