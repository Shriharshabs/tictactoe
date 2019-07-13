#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j=0,k=0,inp1[10],inp2[10],merge[10],t=1,p,i1=0,i2=1,con1=0,con2=0;
    int tp[]={0,0,0,0,0,0,0,0,0};
    printf("************************************************************************************************************************************************************************");
    printf("                                                                   A SIMPLE TIC TAC TOE GAME                                                                                               \n");
    printf("************************************************************************************************************************************************************************\n");
    printgraph1();
    for(i=0;i<5;i++)
    {
        f1:
        scanf("%d",&inp1[i]);
        p=inp1[i];
        con1=p>=1&&p<=9;
        k++;
        merge[j]=inp1[i];
        j++;
        t=isvalid(inp1,merge,k,i)&&con1;
        if(t==0)
        {
            printf("Please Enter valid input\n");
            k--;
            j--;
            goto f1;
           // break;
        }
        printgraph(p,tp,i1);
        if(k>4)
        {
            if(iswin(inp1,i))
            {
                printf("\n\n\n\n\nPLAYER1 WON!!!!!!!!!!!!!!!!!");
                exit(0);
            }
        }
        if(k==9)
            break;
        f2:
        scanf("%d",&inp2[i]);
        k++;
        merge[j]=inp2[i];
        p=inp2[i];
        con2=p>=1&&p<=9;
        j++;
        t=isvalid(inp2,merge,k,i)&&con2;
        if(t==0)
        {
            printf("Enter valid input\n");
            k--;
            j--;
            goto f2;
            //exit(0);
        }
        printgraph(p,tp,i2);
        if(k>4)
        {
            if(iswin(inp2,i))
            {
                printf("\n\n\n\n\nPLAYER2 WON!!!!!!!!!!!!!!!!!!!!!!");
                exit(0);
            }
        }
    }
    printf("NOBODY WINS");
    return 0;
}

int isvalid(int inp[],int merge[],int k,int i)
{
    int j,c=0;
    for(j=0;j<k;j++)
    {

        if(inp[i]==merge[j-1])
        {
            c=1;
            break;
        }
    }
    if(c==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int iswin(int inp[],int i)
{
    int j,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,k;
    int win1[]={1,2,3};
    int win2[]={1,4,7};
    int win3[]={1,5,9};
    int win4[]={2,5,8};
    int win5[]={3,6,9};
    int win6[]={4,5,6};
    int win7[]={7,8,9};
    int win8[]={3,5,7};
    for(j=0;j<=i;j++)
    {
        for(k=0;k<3;k++)
        {
            if(win1[k]==inp[j])
            {
                c1++;
                if(c1==3)
                {
                    return 1;
                }
            }

            if(win4[k]==inp[j])
            {
                c4++;
                if(c4==3)
                {
                    return 1;
                }
            }

            if(win5[k]==inp[j])
            {
                c5++;
                if(c5==3)
                {
                    return 1;
                }
            }

            if(win6[k]==inp[j])
            {
                c6++;
                if(c6==3)
                {
                    return 1;
                }
            }
            if(win7[k]==inp[j])
            {
                c7++;
                if(c7==3)
                {
                    return 1;
                }
            }

            if(win8[k]==inp[j])
            {
                c8++;
                if(c8==3)
                {
                    return 1;
                }
            }

            if(win3[k]==inp[j])
            {
                c3++;
                if(c3==3)
                {
                    return 1;
                }
            }

            if(win2[k]==inp[j])
            {
                c2++;
                if(c2==3)
                {
                    return 1;
                }
            }
        }

    }
    return 0;
}
void printgraph(int p,char t[],int f)
{
    char b[9],i;
    if(f==0)
        t[p]='X';
    else
        t[p]='O';

    printf("%c |%c |%c\n",t[1],t[2],t[3]);
    printf("--+--+--\n");
    printf("%c |%c |%c\n",t[4],t[5],t[6]);
    printf("--+--+--\n");
    printf("%c |%c |%c\n",t[7],t[8],t[9]);
}
void printgraph1()
{
    printf("  |  |  \n");
    printf("--+--+--\n");
    printf("  |  |  \n");
    printf("--+--+--\n");
    printf("  |  |  \n");

}
