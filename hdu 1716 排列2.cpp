//STL next_permutation()

#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
    int a[4], t;
    bool flag=false;
    while(scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3])){
        if(a[0]==0 &&a[1]==0 &&a[2]==0 &&a[3]==0)
            break;
        if(flag)
            printf("\n");
        flag=true;
        t=-1;
        sort(a, a+4);
        do{
            if(a[0]==0)
                continue;
            if(t==-1){
                t=a[0];
                printf("%d%d%d%d", a[0], a[1], a[2], a[3]);
            }else if(a[0]!=t){
                t=a[0];
                printf("\n%d%d%d%d", a[0], a[1], a[2], a[3]);
            }else
                printf(" %d%d%d%d", a[0], a[1], a[2], a[3]);
        }while(next_permutation(a, a+4));
        printf("\n");
    }
    return 0;
}
