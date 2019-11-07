#include<stdio.h>
#include<queue>
#include<map>
#include<string.h>
using namespace std;
#define MAX_N 100000
int k;

void bfs(int n){
    queue<int> q;
    int t[MAX_N+1], te;
    memset(t, -1, sizeof(t));
    q.push(n);t[n]=0;
    while(!q.empty()){
        te=q.front();q.pop();
        if(te+1==k||te-1==k||te*2==k){
            printf("%d\n", t[te]+1);
            return;
        }
        if(te+1 <=MAX_N && t[te+1]==-1){
            q.push(te+1);
            t[te+1]=t[te]+1;
        }
        if(te>=1 && t[te-1]==-1){
            q.push(te-1);
            t[te-1]=t[te]+1;
        }
        if(te*2<=MAX_N && t[te*2]==-1){
            q.push(te*2);
            t[te*2]=t[te]+1;
        }

    }
}

int main() {
    int n;
    while(~scanf("%d %d", &n, &k)){
        if(n==k)
            printf("0\n");
        else
            bfs(n);
    }
    return 0;
}