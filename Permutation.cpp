#include<bits/stdc++.h>

using namespace std;

void Permute(char s[], int index, int N)
{
    if(index == N)printf("%s\n",s);
    else
    {
        for(int i=index; i<=N; i++)
        {
            swap(s[index], s[i]);
            Permute(s, index+1, N);
            swap(s[index], s[i]);
        }
    }
}

void PermuteWithoutSwap(int idx, char *arr, char *ans, bool *taken, int N)
{
    if(idx == N)
    {
        ans[idx] = '\0';
        cout << ans << endl;
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(taken[i] == false)
        {
            taken[i] = true;
            ans[idx] = arr[i];
            PermuteWithoutSwap(idx+1, arr, ans, taken, N);
            taken[i] = false;
            while(arr[i] == arr[i+1])i++;
        }
    }
}

int main()
{
    char arr[100] = "123";
    char ans[100];
    bool taken[4];
    int len = strlen(arr);
    PermuteWithoutSwap(0, arr, ans, taken, len);
    return 0;
}
