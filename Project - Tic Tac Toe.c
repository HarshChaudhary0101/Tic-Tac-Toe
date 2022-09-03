#include<stdio.h>
#include<stdlib.h>
void comp(int [3][3], int, char);
void rules();
void player();
void print(int a[3][3]);
int winO(int a[3][3]);
int winX(int a[3][3]);
void draw(int a[3][3]);
void smart(int x);
void comp(int a[3][3], int b, char c);
int main()
{
    char a;
    rules();
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        smart(1); // To play with smart computer
        break;
    case 2:
        smart(2); // To play with evil computer
        break;
    case 3:
        player(); // To play with another player
        break;
    case 4:
        exit(0);
    }
    return 0;
}
void rules() // To print choices
{
    printf("                                                Tic Tac Toe\n");
    printf("Enter your choice\n");
    printf("1. Want to play with smart computer\n");
    printf("2. Want to play with evil computer\n");
    printf("3. Want to play with another player\n");
    printf("4. Exit\n");
}
void player() // To play with another computer
{
    int a[3][3],i,j,p,z;
    for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
            {
                a[i][j]=' ';
            }
    while(1)
    {
        print(a);
        printf("\nPlayer 1, Enter the position - ");
        scanf("%d",&p);
        p--;
        i=p/3; j=p%3;
        if(p>=0&&p<=9&&a[i][j]!='X'&&a[i][j]!='O')
            a[i][j]='O';
        else
            continue;
        print(a);
        z=winO(a);
        if(z==3)
        {
            printf("\n\n            Player 1 WON");
            exit(0);
        }
        draw(a);
        printf("\nPlayer 2, Enter the position - ");
        scanf("%d",&p);
        p--;
        i=p/3; j=p%3;
        if(p>=0&&p<=9&&a[i][j]!='X'&&a[i][j]!='O')
            a[i][j]='X';
        else
            continue;
        print(a);
        z=winX(a);
        if(z==3)
        {
            printf("\n\n            Player 2 WON");
        }
    }
}
void print(int a[3][3]) // To print 2D array
{
    int i,j;
    system("cls");
    printf("                                                Tic Tac Toe\n");
    printf("First Player - O\n");
    printf("Second Player - X\n\n");
    i=1;
    while(i<=9)
    {
        printf("     |     |     ");
        printf("\n");
        printf("  %d  |  %d  |  %d  ",i,i+1,i+2);
        printf("\n");
        printf("_____|_____|_____");
        printf("\n");
        i=i+3;
    }
    printf("\n");
     for(i=0;i<=2;i++)
        {
            printf("\n");
            printf("     |     |");
            printf("\n");
            for(j=0;j<=1;j++)
            {
                printf("  %c  |",a[i][j]);
            }
            printf("  %c",a[i][j]);
            printf("\n_____|_____|_____");
        }
}
int winO(int a[3][3]) // To check if player 1 won or not
{
    int i,j,n,t,m,z=0;
    for(i=0;i<=2;i++)
        {
            n=0; t=0; m=0;
            for(j=0;j<=2;j++)
            {
                if(a[i][j]=='O')
                    n++;
                if(a[j][i]=='O')
                    t++;
                if(a[j][j]=='O')
                    m++;
            }
            if(a[i][3-(i+1)]=='O')
                z++;
            if(n==3 || t==3 || m==3)
            {
                printf("\n\n                Player 1 WON");
                exit(0);
            }
        }
    return z;
}
int winX(int a[3][3]) // To check if player 2 won or not
{
    int i,j,n,t,m,z=0;
    for(i=0;i<=2;i++)
        {
            n=0; t=0; m=0;
            for(j=0;j<=2;j++)
            {
                if(a[i][j]=='X')
                    n++;
                if(a[j][i]=='X')
                    t++;
                if(a[j][j]=='X')
                    m++;
            }
                if(a[i][3-(i+1)]=='X')
                    z++;
                if(n==3 || t==3 || m==3)
                {
                    printf("\n\n                Player 2 WON");
                    exit(0);
                }
            }
    return z;
}
void draw(int a[3][3]) // To check if match is draw
{
    int i,j,n=0;
    for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
            if(a[i][j]=='X'||a[i][j]=='O')
                n++;
    if(n==9)
    {
        printf("\n\n          Game Draw");
        exit(0);
    }
}
void smart(int x) // To play with smart/evil computer
{
    int a[3][3],i,j,p,z,k;
    for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
            {
                a[i][j]=' ';
            }
    while(1)
    {
        print(a);
        printf("\nPlayer 1, Enter the position - ");
        scanf("%d",&p);
        p--;
        i=p/3; j=p%3;
        if(p>=0&&p<=9&&a[i][j]!='X'&&a[i][j]!='O')
            a[i][j]='O';
        else
            continue;
        print(a);
        z=winO(a);
        if(z==3)
        {
            printf("\n\n            Player 1 WON");
            exit(0);
        }
        draw(a);
        for(k=1;k<=2;k++)
            {
                if(k==1)
                    comp(a,x,'X');
                else
                    comp(a,x,'O');
                print(a);
                z=winX(a);
                if(z==3)
                {
                    printf("\n\n            Player 2 WON");
                    exit(0);
                }
                draw(a);
            }
    }
}
void comp(int a[3][3], int b, char c) // To fill X by computer
{
    int i,j,n,t,m,z=0,g,n1=0,t1=0,m1=0;
    for(i=0;i<=2;i++)
        {
            n=0; t=0; m=0;
            for(j=0;j<=2;j++)
            {

                if(a[i][j]==c)
                    n++;
                if(n==2)
                    {
                        for(g=0;g<=2;g++)
                                if(a[i][g]!='O' && a[i][g]!='X')
                                {
                                    a[i][g]='X';
                                    n1=2;
                                    break;
                                }
                        if(g==3)
                            n=0;
                        else
                            if(b==1)
                                break;
                    }
                if(a[j][i]==c)
                    t++;
                if(t==2)
                    {
                        for(g=0;g<=2;g++)
                                if(a[g][i]!='O' && a[g][i]!='X')
                                {
                                    a[g][i]='X';
                                    t1=2;
                                    break;
                                }
                        if(g==3)
                            t=0;
                        else
                            if(b==1)
                                break;
                    }
                if(a[j][j]==c)
                    m++;
                if(m==2)
                    {
                        for(g=0;g<=2;g++)
                                if(a[g][g]!='O' && a[g][g]!='X')
                                {
                                    a[g][g]='X';
                                    m1=2;
                                    break;
                                }
                        if(g==3)
                            m=0;
                        else
                            if(b==1)
                                break;
                    }
            }
            if(a[i][2-i]==c)
                z++;
                if(z==2)
                {
                    for(g=0;g<=2;g++)
                        if(a[g][2-g]!='O' && a[g][2-g]!='X')
                            {
                                a[g][2-g]='X';
                                break;
                            }
                        if(g==3)
                            z=0;
                        else
                            if(b==1)
                                break;
                }
            if(n==2 || t==2 || m==2)
                if(b==1)
                    break;
            if(n==2 || t==2 || m==2 || z==2)
                if(b==2 && c=='X')
                    break;
        }
        if(c=='O')
            if(z!=2 && n1!=2 && t1!=2 && m1!=2)
            {
                for(i=0;i<=2;i++)
                    for(j=0;j<=2;j++)
                        if(a[i][j]!='O' && a[i][j]!='X')
                            {
                                a[i][j]='X';
                                return;
                            }
        }
}
