#include<stdio.h>

int b[3][3]={0};
int num=-1,com;
int ip,jp;
int c1=0,c2=0;
int c1i[3],c1j[3],c2i[3],c2j[3];

void output(){
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if(!(j%2)){
                if(!(b[i][j/2])) printf("%s"," ");
                else printf("%d",b[i][j/2]+1);
            }
            else printf("|");
        }
        printf("\n");
        if(i<2){
            for(int j=0;j<5;j++){
                printf("-");
            }
        }
        printf("\n");
    }
}

void writeMark(){
    switch(com){
        case 1:ip=0;jp=0;break;
        case 2:ip=0;jp=1;break;
        case 3:ip=0;jp=2;break;
        case 4:ip=1;jp=0;break;
        case 5:ip=1;jp=1;break;
        case 6:ip=1;jp=2;break;
        case 7:ip=2;jp=0;break;
        case 8:ip=2;jp=1;break;
        case 9:ip=2;jp=2;break;
    }
    b[ip][jp]=num;
}

void limit3(){
    if(num==1){
        if(c1==3){
            b[c1i[0]][c1j[0]]=0;
            c1i[0]=c1i[1];
            c1j[0]=c1j[1];
            c1i[1]=c1i[2];
            c1j[1]=c1j[2];
            c1i[2]=ip;
            c1j[2]=jp;
            c1--;
        }
        else{
            c1i[c1]=ip;
            c1j[c1]=jp;
        }
        c1++;
    }
    else{
        if(c2==3){
            b[c2i[0]][c2j[0]]=0;
            c2i[0]=c2i[1];
            c2j[0]=c2j[1];
            c2i[1]=c2i[2];
            c2j[1]=c2j[2];
            c2i[2]=ip;
            c2j[2]=jp;
            c2--;
        }
        else{
            c2i[c2]=ip;
            c2j[c2]=jp;
        }
        c2++;
    }
}

int judgei(){
    int x,y;
    switch(jp){
        case 0:x=1;y=2;break;
        case 1:x=0;y=2;break;
        case 2:x=0;y=1;break;
    }
    if(b[ip][jp]+b[ip][x]+b[ip][y]==3||b[ip][jp]+b[ip][x]+b[ip][y]==-3){
        return 1;
    }
    return 0;
}
int judgej(){
    int x,y;
    switch(ip){
        case 0:x=1;y=2;break;
        case 1:x=0;y=2;break;
        case 2:x=0;y=1;break;
    }
    if(b[ip][jp]+b[x][jp]+b[y][jp]==3||b[ip][jp]+b[x][jp]+b[y][jp]==-3){
        return 1;
    }
    return 0;
}
int judgecross(){
    if(b[1][1]+b[0][0]+b[2][2]==3||b[1][1]+b[0][0]+b[2][2]==-3){
        return 1;
    }
    if(b[1][1]+b[0][2]+b[2][0]==3||b[1][1]+b[0][2]+b[2][0]==-3){
        return 1;
    }
//    switch(com){
//        case 1:if(num+b[1][1]+b[2][2]==3||num+b[1][1]+b[2][2]==-3) return 1;break;
//        case 3:if(num+b[1][1]+b[2][0]==3||num+b[1][1]+b[2][0]==-3) return 1;break;
//        case 7:if(num+b[1][1]+b[0][2]==3||num+b[1][1]+b[0][2]==-3) return 1;break;
//        case 9:if(num+b[1][1]+b[0][0]==3||num+b[1][1]+b[0][0]==-3) return 1;break;
//        case 5:if(num+b[0][0]+b[2][2]==3||num+b[0][0]+b[2][2]==-3) return 1;if(num+b[0][2]+b[2][0]==3||num+b[0][2]+b[2][0]==-3) return 1;break;
//    }
    return 0;
}

int main(void)
{
    int flag=0;
    while(1){
        num*=-1;
        printf("Player %d\n",num+1);
        printf("Which compartment? >>> "),scanf("%d",&com);
        writeMark();
        limit3();
        output();
        flag=judgei();
        if(!flag) flag=judgej();
        if(!flag) flag=judgecross();
        if(flag==1){
            printf("---Player %d wins!---\n",num+1);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    b[i][j]=0;
                }
            }
        }
    }

    return 0;
}
