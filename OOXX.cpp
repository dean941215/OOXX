#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
srand(time(NULL));
    int turn=0,fin=0,ok=0;
    int a[5][5]={};
    char w[3];

    cout<<"�w��C��OOXX�C��\n�п�J���⬰O��X(�п�J�j�g)"<<endl;
    cin>>w[1];
    while(w[1]!='O' && w[1]!='X'){
        cout<<"�DO��X�A�Э��s��J";
        cin>>w[1];
    }
    if(w[1]=='O')
        w[2]='X';
    if(w[1]=='X')
        w[2]='O';

    while(fin==0){
        int r,i,j;
        r+=10*(rand()%3+1);
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==1)
                    cout<<setw(3)<<w[1];
                else if(a[i][j]==2)
                    cout<<setw(3)<<w[2];
                else
                    cout<<setw(3)<<i*10+j;
            }
            cout<<endl<<endl;
        }

        cout<<"����"<<w[turn%2+1]<<"�A�п�J�n��J����m�N�X"<<endl;
        if(turn%2+1!=1)
		{
			int repeat=0;

			while(repeat==0)
			{
            if(a[i][j]!=0){
                ok=0;
                r=rand()%3+1+10*(rand()%3)+10;
                i=r/10;
                j=r%10;	}
            else if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33)
            {
                ok=0;
                r=rand()%3+1+10*(rand()%3)+10;
                i=r/10;
                j=r%10;
            }
            else{
                i=r/10;
                j=r%10;

                repeat=1;}
			}
			cout<<r<<endl;
		}

		if(turn%2+1==1)
		{
            cin>>r;
            do{
                i=r/10;
                j=r%10;
                if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
                    ok=1;
                    cout<<"�Ӧ�m���s�b�A�Э��s��J";
                    cin>>r;
                }

                else if(a[i][j]!=0){
                    ok=1;
                    cout<<"�Ӧ�m�w�ϥΡA�Э��s��J";
                    cin>>r;
                }
                else{
                    ok=0;
                }
            }while(ok==1);
        }
        a[i][j]=turn%2+1;

        for(i=1 ; i<=3 ; i++){
            if(a[i][1]==a[i][2] && a[i][2]==a[i][3] && a[i][1]!=0){
                fin=turn%2+1;
            }
            if(a[1][i]==a[2][i] && a[2][i]==a[3][i] && a[1][i]!=0){
                fin=turn%2+1;
            }
        }
        if(a[1][1]==a[2][2] && a[2][2]==a[3][3] && a[1][1]!=0){
            fin=turn%2+1;
        }
        if(a[1][3]==a[2][2] && a[2][2]==a[3][1] && a[3][1]!=0){
            fin=turn%2+1;
        }

        ok=0;
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==0)
                    ok=1;

            }
        }
        if(ok==0 && fin==0){
            fin=3;
        }

        turn++;
    }

    for (int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ;j++){
            if (a[i][j]==1)
                cout<<setw(3)<<w[1];
            else if(a[i][j]==2)
                 cout<<setw(3)<<w[2];
            else
                cout<<setw(3)<<i*10+j;
        }
         cout<<endl;
    }
    if(fin==3){
        cout<<"����"<<endl;
    }
    else{
        cout<<"����"<<w[fin]<<"���"<<endl;
    }
    return 0;}
