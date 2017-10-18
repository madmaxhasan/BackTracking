#include<bits/stdc++.h>

using namespace std;

void Combination(int N, int R, char *arr, char *ans, int idx, int start)
{
    if(idx == R)
    {
        ans[idx] = '\0';
        puts(ans);
        return;
    }
    for(int i=start; i<N; i++)
    {
        ans[idx] = arr[i];
        Combination(N, R, arr, ans, idx+1, i+1);
        while(arr[i] == arr[i+1])i++;
    }
}

int main()
{
    char arr[1000], ans[1000];
    int R,N;
    while(scanf("%s %d",arr,&R))
    {
        N = strlen(arr);
        printf("Combination:\n");
        Combination(N, R, arr, ans, 0, 0);
        memset(arr, '\0', sizeof(arr));
        memset(ans, '\0', sizeof(ans));
    }
    return 0;
}
