#include<stdio.h>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

struct Node{
	int a, b, c, d, t;
	bool operator == (const Node &t)const{
		return a==t.a &&b==t.b&&c==t.c&&d==t.d;
	}
}node, e, temp;

bool book[10000];//false为素数

int GetI(Node node){
	return node.a*1000+node.b*100+node.c*10+node.d;
}

void prime(){
	memset(book, false, sizeof(book));
	for(int i=2; i<10000; i++)
		if(!book[i])
			for(int j=2; j<=10000/i; j++)
				book[i*j]=true;
}

void bfs(Node node){
	queue<Node> q;
	map<int, int> map1;
	q.push(node);
	//a*1000+b*100+c*10+d
	while(!q.empty()){
		node = q.front();
		q.pop();
		if(map1[GetI(node)]==1)continue;
		map1[GetI(node)]=1;
		temp.a=node.a;temp.b=node.b;temp.c=node.c;temp.d=node.d;temp.t=node.t+1;
		for(int i=1; i<=9; i++){
			temp.a=i;
			if(i!=node.a&&!book[GetI(temp)]){
				if(temp==e){
					printf("%d", temp.t);
					return;
				}
				else
					q.push(temp);
			}
		}
		temp.a=node.a;
		for(int i=0; i<=9; i++){
			temp.b=i;
			if(i!=node.b&&!book[GetI(temp)]){
				if(temp==e){
					printf("%d", temp.t);
					return;
				}
				else
					q.push(temp);
			}
		}
		temp.b=node.b;
		for(int i=0; i<=9; i++){
			temp.c=i;
			if(i!=node.c&&!book[GetI(temp)]){
				if(temp==e){
					printf("%d", temp.t);
					return;
				}
				else
					q.push(temp);
			}
		}
		temp.c=node.c;
		for(int i=0; i<=9; i++){
			temp.d=i;
			if(i!=node.d&&!book[GetI(temp)]){
				if(temp==e){
					printf("%d", temp.t);
					return;
				}
				else
					q.push(temp);
			}
		}
		temp.d=node.d;
	}
	printf("Impossible");
}

int main() {
	int t, t1, t2;
	//prime打表
	prime();
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &t1, &t2);
		if(t1==t2){
			printf("0");
		}else{
			node.d=t1%10;t1/=10;node.c=t1%10;t1/=10;node.b=t1%10;t1/=10;node.a=t1%10;
			e.d=t2%10;t2/=10;e.c=t2%10;t2/=10;e.b=t2%10;t2/=10;e.a=t2%10;
			node.t=0;
			bfs(node);
		}
		printf("\n");
	}
	return 0;
}