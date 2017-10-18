#include<bits/stdc++.h>
#define N 4

using namespace std;

int X[4] = {0, 1, -1, 0};
int Y[4] = {1, 0, 0, -1};
char moves[4] = {'R', 'D', 'U', 'L'};
char ans[20];
int index = 0;

bool isSafe(int x, int y, int solve[4][4], bool track[4][4])
{
    return (x >= 0 && x < 4 && y >= 0 && y < 4 && solve[x][y] == 1 && track[x][y] == false);
}

void printGrid(int arr[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void BackTrack(int x, int y, int arr[N][N], bool track[N][N])
{
    if(x == 3 && y == 3)
    {
        cout << ans << endl;
        memset(ans, '\0', sizeof(ans));
        index = 0;
        return;
    }
    for(int i=0; i<N; i++)
    {
        int next_x = x + X[i];
        int next_y = y + Y[i];
        if(isSafe(next_x, next_y, arr, track))
        {
            track[next_x][next_y] = true;
            ans[index++] = moves[i];
            BackTrack(next_x, next_y, arr, track);
            --index;
        }
    }
}

int main()
{
    int arr[N][N];
    bool track[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    track[0][0] = true;
    if(arr[3][3] == 1)
    {
        BackTrack(0, 0, arr, track);
    }
    else printf("No Solution\n");
    return 0;
}
