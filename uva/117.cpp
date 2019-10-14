#include<bits/stdc++.h>
using namespace std;
int graph[30][30];
int deg[30];
void floyd(){
    int i,j,k;
    for(k=0;k<27;++k)
        for(i=0;i<27;++i)
            for(j=0;j<27;++j)
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
}
void calculate(int sum){
   int i,od1=-1,od2=-1;
   for( i =0;i<30;i++)
    if(deg[i]%2==1){
     od1 = i;
     break;
    }
   for(i=29;i>0;i--)
    if(deg[i]%2==1){
     od2 = i;
     break;
    }
    if(od1<0 && od2<0){
        printf("%d\n",sum);
     return;
    }
    floyd();
    printf("%d\n",graph[od1][od2]+sum);
}
int main(){
    int i=0,j=0,k=0,l=0,m=0,n=0,v=0,u=0,sum=0;
    char str[1000];
    while(scanf("%s",str) == 1){
        for(i=0;i<27;i++){
            for(j=0;j<30;++j)
                graph[i][j] = 24000;
            graph[i][i] = 0;
        }   
        sum = 0;
        u = str[0] - 'a';
        l = strlen(str);
        sum += l;
        v = str[l-1] - 'a';
        graph[u][v] = graph[v][u] = l;
        deg[u]++; deg[v]++;
        while(true){
            cin >> str;
            if(!strcmp(str,"deadend"))
                break;
            u = str[0] - 'a';
            l = strlen(str);
            v = str[l-1] - 'a';
            graph[u][v] = graph[v][u] = l;
            sum +=l;
            deg[u]++; deg[v]++;
        }
        calculate(sum);
        memset(deg,0,sizeof(deg));
    }
    return 0;
}
