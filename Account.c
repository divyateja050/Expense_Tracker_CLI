#include<stdio.h>
#include<stdlib.h>
void date()
{
    int d,m,y;
    float time;
    printf("Date(dd/mm/yy)  :");
    scanf("%d/%d/%d",&d,&m,&y);
    printf("Time(hh.min)    :");
    scanf("%f",&time);
    FILE*dt=fopen("statement.txt","a");
    fprintf(dt,"\n--------------Welcome-----------------\n");
    fprintf(dt,"Date :%d/%d/%d",d,m,y);
    fprintf(dt,"\nTime :%.2f\n",time);
    fclose(dt);
}
int funtion(int exp)
    {
        int blc,bla;
       FILE*n;
       FILE*ac=fopen("balance.txt","r");
    fscanf(ac,"%d",&blc);
    fclose(ac);
    printf("\nA/c Balance :%d\n",blc);
     if(blc<=0)
        {
            printf("out of money!\nplease deposit money\n");
            printf("\nDeposit amount :");
            scanf("%d",&blc);
            n=fopen("balance.txt","w");
            fprintf(n,"\n%d\n",blc);
            fclose(n);
        }
        else if(blc<=0 && exp>=0)
        {
            printf("Not enough money!\nplease deposit money\n");
            printf("\nDeposit amount :");
            scanf("%d",&blc);
            n=fopen("balance.txt","w");
            fprintf(n,"\n%d\n",blc);
            fclose(n);
        }
        bla=blc-exp;
        FILE*m=fopen("balance.txt","w");
        fprintf(m,"%d\n",bla);
        fclose(m);
        return bla;
    }

int products()
{
    int n,i,x,rate;
    printf("Number of Products :");
    scanf("%d",&x);
    int*price=(int*) calloc(x,sizeof(int));
        FILE*prd=fopen("statement.txt","a");
      fprintf(prd,"\n\t----------------------------------------\n\tcount\trate\tPrice\tProduct Name\n\t----------------------------------------\n");
      fclose(prd);
    for(i=0;i<x;i++)
    {
        char item[20];
        printf("\nProduct name:");
        scanf("%s",&item);
        printf("No. of %s:",item);
        scanf("%d",&n);
        printf("price :");
        scanf("%d",&rate);
        price[i]=n*rate;
    FILE*prd=fopen("statement.txt","a");
        fprintf(prd,"\t%d   X   %.2d\t%2d\t%s \n",n,rate,price[i],item);
        fclose(prd);
    }
    int j=0;
    while(j<x)
    {
        price[j+1]=price[j] + price[j+1];
        j++;
    }
        FILE*pd=fopen("statement.txt","a");
        fprintf(pd,"\t----------------------------------------\n\tExpenditure:\t%2d \n\t----------------------------------------\n",price[x-1]);
        fclose(pd);
        printf("Total Expenditure :%d \n",price[x-1]);
    return price[x-1];
}
int main()
{
    char*name=(char*) malloc(30*sizeof(char));
    int pin,n;
    printf("Username\t:");
    gets(name);
    printf("Enter Your PIN  :");
    scanf("%d",&pin);
    if(strcmp(name,"Divyateja")==0 && pin==8844)
    {
    while(1 && n!=4)
        {
            int a,x,b,c=0,money,dmoney=0,balance;
            printf("\n\t1)Balance check\n\t2)Deposit amount\n\t3)Shopping details\n\t4)Logout\n\tChoose option :");
            scanf("%d",&n);
            FILE*ac=fopen("balance.txt","r");
                    fscanf(ac,"%d",&a);
                    fclose(ac);
            switch(n)
            {
                case 1:
                    date();
                    printf("\n\tBalance Enquiry!\n");
                    FILE*ac=fopen("balance.txt","r");
                    fscanf(ac,"%d",&a);
                    fclose(ac);
                    printf("\tCurrent A/c Balance : Rs.%d \n",a);
                    break;
                case 2:
                    date();
                    printf("Enter Deposit Amount :");
                    scanf("%d",&dmoney);
                    FILE*n=fopen("balance.txt","r");
                    fscanf(n,"%d",&b);
                    fclose(n);
                    money=dmoney+b;
                    FILE*m=fopen("balance.txt","w");
                    fprintf(m,"%d",money);
                    fclose(m);
                    printf("\n\t\t\t\tYour amount of Rs.%d is successfully Deposited!\n",dmoney);
                    break;
                case 3:
                    date();
                    printf("\n\t\t!Products Details!\n");
                    c=products();
                    balance=funtion(c);
                    printf("Current balance :%d\n",balance);
                    break;
                case 4:
                    printf("\n\t\tAccount logout successful!\n");
                    break;
                default :
                    printf("\nINVALID option!\n");
            }
            int cu;
            FILE*ab=fopen("balance.txt","r");
                    fscanf(ab,"%d",&cu);
                    fclose(ab);
            FILE*id=fopen("statement.txt","a");
            fprintf(id,"\nA/c holder name :%s\n",name);
            fprintf(id,"A/c Balance     :Rs.%d\n",a);
            fprintf(id,"Deposited Amount:Rs.%d\n",dmoney);
            fprintf(id,"Expenditure     :Rs.%d\n",c);
            fprintf(id,"Current A/c Balance :Rs.%d",cu);
            fprintf(id,"\n--------------THANK YOU--------------\n");
            fclose(id);

        }
    }
    else
    {
        printf("INVALD Username or PIN!");
    }
        return 0;
}
