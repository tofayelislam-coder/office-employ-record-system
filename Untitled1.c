#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x,int y);
void add_data();
void edit_data();
void delete_data();
void view_data();
void search_data();
void name_edit();
void age_edit();
void salary_edit();
void all_data_edit();

struct {
    char first_name[50];
    int age;
    float salary;
}employee;
FILE *fp,*fp1;
int main()
{
    printf("\n\n\t\tWELCOME TO EMPLOYEE RECORD SYSTEM");

    while(1){
     int choice;
     printf("\n =================== ");
     printf("\n  Main Menu.");
     printf("\n ===================.\n");
     printf("[1] Add Employee Record\n");
     printf("[2] Edit Employee Record \n");
     printf("[3] Delete Employee Record\n");
     printf("[4] View All Employee Record\n");
     printf("[5] Search Employee Record\n");
     printf("[6] Exit\n");
     printf("\n\n\n\t\tEnter your choice  :  ");
     scanf("%d",&choice);

     switch(choice)
     {
        case 1:
            add_data();
            break;
        case 2:
            edit_data();
            break;
        case  3:
            delete_data();
            break;
        case 4:
            view_data();
            break;
        case 5:
            search_data();
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("\n\n\t\t\t\tWrong choice !\n\n");
            break;

        }
    }
}
void add_data()
{
        system("cls");
        fp=fopen("employee data save.txt","a+");
        {
            printf("\n\n\n\t\t\t\tEnter Your Name : ");
            scanf("%s",employee.first_name);
            printf("\n\t\t\t\tEnter Age : ");
            scanf("%d",&employee.age);
            printf("\n\t\t\t\tEnter The Basic Salary : ");
            scanf("%f",&employee.salary);
            fprintf(fp,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
            printf("\n\n\t\t\t\tRecord insert successful");

        }

       fclose(fp);

}
void view_data()
{
    system("cls");
    fp=fopen("employee data save.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    fp=fopen("employee data save.txt","r");
    {
        printf("\n\n\n\t\t Name            Age             Salary\n");
        printf("========================================================================================");
        while(fscanf(fp,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
        {
            printf("\n\nYour Name is : %s",employee.first_name);
            printf("\nAge : %d",employee.age);
            printf("\nSalary : %.2f",employee.salary);
        }
        printf("\n\n=========================================================================================");
    }
   fclose(fp);


}
void search_data()
{
    system("cls");
    char name[30];
    fp = fopen("employee data save.txt","r");
    printf("\n\n\n\t\t\t\tEnter Your Name  :  ");
    scanf("%s",&name);
    if(fp == NULL)
    {
            printf("file does not found !");
            exit(1);
    }
    else{
        fp=fopen("employee data save.txt","r");
        {
            while(fscanf(fp,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
            {
                if(strcmp(employee.first_name,name)==0)
                {
                    printf("\n\n\n\t\tName            Age            Salary\n");
                    printf("========================================================================================");
                    printf("\n\nYour Name is : %s",employee.first_name);
                    printf("\nAge : %d",employee.age);
                    printf("\nSalary : %.2f",employee.salary);
                    printf("\n\n=========================================================================================");
                }
           }
        }
    }
    fclose(fp);
}
void delete_data()
{
    system("cls");
     fp = fopen("employee data save.txt","r");
     fp1 = fopen("temp.txt","a");
     char name[100];
     int f=0;
     printf("\n\n\n\t\t\t\tEnter Your Name You Want To Delete :  ");
     scanf("%s",&name);

     while(fscanf(fp,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
     {
            if(strcmp(employee.first_name,name)==0)
            {
                    f =1;
                    printf("\n\n\n\t\t\t\tDelete successfull\n\n");
            }
            else
            {
                fprintf(fp1,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
            }

     }
     if(f==0)
     {
            printf("\n\n\t\t\tname not found");
     }
     fclose(fp);
     fclose(fp1);
     fp = fopen("employee data save.txt","w");
     fclose(fp);
     fp = fopen("employee data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        fprintf(fp,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void edit_data()
{
    system("cls");
    int choice;
    fp = fopen("Student data save.txt","r");
    fp1 = fopen("temp.txt","a");
    printf("\n\n\t\t\twhat would you like to edit?");
    printf("\n\n\t\t\t[1] Name Edit ");
    printf("\n\t\t\t[2] Age Edit");
    printf("\n\t\t\t[3] Salary Edit");
    printf("\n\t\t\t[4] All Data Edit");
    printf("\n\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
         case 1:
             name_edit();
             break;
         case 2:
            age_edit();
            break;
         case 3:
            salary_edit();
            break;
         case 4:
            all_data_edit();
            break;
         default:
            printf("\n\n\t\t\t\tWrong choice !\n\n");
            break;

    }

}
void name_edit()
{
    system("cls");
    fp = fopen("employee data save.txt","r");
    fp1 = fopen("temp.txt","a");
    char name[20];
    char present_first_name[20];
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your First Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        if(strcmp(employee.first_name,name)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Name :");
            scanf("%s",present_first_name);
            fprintf(fp1,"%s %d %f\n",present_first_name,employee.age,employee.salary);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t First Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("employee data save.txt","w");
    fclose(fp);
    fp = fopen("employee data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        fprintf(fp,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void age_edit()
{
    system("cls");
    fp = fopen("employee data save.txt","r");
    fp1 = fopen("temp.txt","a");
    char name[20];
    int present_age;
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        if(strcmp(employee.first_name,name)==0)
        {
            printf("\n\t\tRecord Found");
            f =1;
            printf("\n\n\t\t\tEnter The New Age :");
            scanf("%d",&present_age);
            fprintf(fp1,"%s %d %f\n",employee.first_name,present_age,employee.salary);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("employee data save.txt","w");
    fclose(fp);
    fp = fopen("employee data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        fprintf(fp,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);


}
void salary_edit()
{
    system("cls");
    fp = fopen("employee data save.txt","r");
    fp1 = fopen("temp.txt","a");
    char name[20];
    float present_salary;
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        if(strcmp(employee.first_name,name)==0)
        {
            printf("\n\t\tRecord Found");
            f =1;
            printf("\n\n\t\t\tEnter The New Salary :");
            scanf("%f",&present_salary);
            fprintf(fp1,"%s %d %f\n",employee.first_name,employee.age,present_salary);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("employee data save.txt","w");
    fclose(fp);
    fp = fopen("employee data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        fprintf(fp,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
void all_data_edit()
{
    system("cls");
    char name[20];
    fp = fopen("employee data save.txt","r");
    fp1 = fopen("temp.txt","a");
    char present_first_name[20];
    int present_age;
    float present_salary;
    int f=0;
    printf("\n\n\n\t\t\t\t Enter Your Name :  ");
    scanf("%s",name);
    while(fscanf(fp,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        if(strcmp(employee.first_name,name)==0)
        {
            f =1;
            printf("\n\n\t\t\tEnter The New Name :");
            scanf("%s",present_first_name);
            printf("\n\n\t\t\tEnter The New Age :");
            scanf("%d",&present_age);
            printf("\n\n\t\t\tEnter The New Salary :");
            scanf("%f",&present_salary);
            fprintf(fp1,"%s %d %f\n",present_first_name,present_age,present_salary);
            printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
        }
        else
        {
            fprintf(fp1,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
        }

    }
    if(f==0)
    {
            printf("\n\n\t\t\t First Name not found");
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("employee data save.txt","w");
    fclose(fp);
    fp = fopen("employee data save.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %d %f\n",employee.first_name,&employee.age,&employee.salary)!=EOF)
    {
        fprintf(fp,"%s %d %f\n",employee.first_name,employee.age,employee.salary);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);


}
//COORD coord={0,0};

//void gotoxy(int x,int y)
//{
    //coord.X=x;
   // coord.Y=y;
   // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//}
