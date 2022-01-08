/**
    Name : Muhammad Jamil Hasan
    ID: 212902029
    Project Name : Phonebook Application
    Date created : 26/12/2021
    Description : By using this file we can save contacts and do these listed operations in it.
        1) add a contact.
        2) view all contacts.
        3) remove a contact.
        4) search details of any contact number.
        5) update details of any contact.
        6) delete all contacts present in phonebook.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char name[30];
    char area_code[4];
    long int mobile_no;
    char sex[8];
    char mail[100];
};


typedef struct person person;

void add_contact();
void list_record();
void print_menu();
void search_contact();
void remove_contact();
void update_contact();
void remove_all();
void take_input(person *p);


int main()
{
    start();
    return 0;
}

void start()
{
    int choice;
    while(1)
    {
        print_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add_contact();
                getchar();
                getchar();
                break;
            case 2:
                list_record();
                getchar();
                getchar();
                break;
            case 3:
                search_contact();
                getchar();
                getchar();
                break;
            case 4:
                remove_contact();
                getchar();
                getchar();
                break;
            case 5:
                update_contact();
                getchar();
                getchar();
                break;
            case 6:
                remove_all();
                getchar();
                getchar();
                break;
            default :
                system("cls");
                printf("Thanks for using the phonebook : )\n");
                getchar();
                getchar();
                exit(1);
        }
    }
}

void print_menu()
{
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  Welcome TO My phone book                    *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) Add a Contact\n\n");
    printf("\t\t\t2) Contact List\n\n");
    printf("\t\t\t3) Search a Contact\n\n");
    printf("\t\t\t4) Remove a Contact\n\n");
    printf("\t\t\t5) Update a Contact\n\n");
    printf("\t\t\t6) Delete all Contacts\n\n");
    printf("\t\t\t7) Exit Phonebook\n\n\n");

    printf("\t\t\t\tEnter your Choice : ");
}

void add_contact()
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook.txt", "ab+");
    if (fp == NULL)
    {
        printf(" ERROR IN OPENING THE FILE, PLSEASE TRY AGAIN!\n");
        printf("\n ....Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("cls");
        printf("RECORD HAS BEEN ADDED SUCCESSFULLY\n");
        printf("\n .... Press any key to continue ....\n");

    }
}

void take_input(person *p)
{
    system("cls");

    getchar();
    printf("Enter name : ");
    scanf("%[^\n]s",p->name);

    printf("Enter Area code : ");
    scanf("%s",p->area_code);

    printf("Enter mobile no : ");
    scanf("%ld",&p->mobile_no);

    printf("Enter sex : ");
    scanf("%s",p->sex);

    printf("Enter email : ");
    scanf("%s",p->mail);
}

void list_record()
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook.txt", "rb");
    if (fp == NULL)
    {
        printf(" ERROR IN OPENING THE FILE, PLSEASE TRY AGAIN!\n");
        printf("\n .... Press any key to continue ....\n");
        return;
    }
    else
    {
        person p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in this phonebook                   *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t\t     AREA CODE\t\t     PHONE NO\t\t        SEX\t\t             EMAIL\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 19 - strlen(p.area_code);
            int len3 = 15;
            int len4 = 21 - strlen(p.sex);
            printf("%s",p.name);
            for(i=0;i<len1;i++) printf(" ");

            printf("%s",p.area_code);
            for(i=0;i<len2;i++) printf(" ");

            printf("+880%ld",p.mobile_no);
            for(i=0;i<len3;i++) printf(" ");

            printf("%s",p.sex);
            for(i=0;i<len4;i++) printf(" ");

            printf("%s",p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\n .... Press any key to continue ....\n");

    }
}

void search_contact()
{
    system("cls");
    long int phone;
    printf("Enter the Phone number of the contact : ");
    scanf("%ld",&phone);

    FILE *fp;
    fp = fopen("phonebook.txt", "rb");
    if (fp == NULL)
    {
        printf(" ERROR IN OPENING THE FILE, PLSEASE TRY AGAIN!\n");
        printf("\n .... Press any key to continue ....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mobile_no == phone)
            {
                printf("\n\n  NAME\t\t\t\t     AREA CODE\t\t     PHONE NO\t\t        SEX\t\t             EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.area_code);
                int len3 = 15;
                int len4 = 21 - strlen(p.sex);
                printf("%s",p.name);
                for(i=0;i<len1;i++) printf(" ");

                printf("%s",p.area_code);
                for(i=0;i<len2;i++) printf(" ");

                printf("+880%ld",p.mobile_no);
                for(i=0;i<len3;i++) printf(" ");

                printf("%s",p.sex);
                for(i=0;i<len4;i++) printf(" ");

                printf("%s",p.mail);
                printf("\n");

                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            system("cls");
            printf("Contact not found\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\n .... Press any key to continue ....\n");
    }

}

void remove_contact()
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the contact to remove from phonebook : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("phonebook.txt", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf(" ERROR IN OPENING THE FILE, PLSEASE TRY AGAIN!\n");
        printf("\n .... Press any key to continue ....\n");
        return;
    }
    else
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mobile_no == phone)
            {
                system("cls");
                printf("Contact has been removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found! Please try with another number...\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook.txt");
        rename("temp","phonebook.txt");
        fflush(stdin);
        printf("\n .... Press any key to continue ....\n");

    }

}

void update_contact()
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the Contact to update the details : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("phonebook.txt", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf(" ERROR IN OPENING THE FILE, PLSEASE TRY AGAIN!\n");
        printf("\n .... Press any key to continue ....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mobile_no == phone)
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("cls");
                printf("CONTACT HAS BEEN UPDATED SUCCESSFULLY\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found! Please try with another number...\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook.txt");
        rename("temp","phonebook.txt");
        fflush(stdin);
        printf("\n .... Press any key to continue ....\n");
    }
}

void remove_all()
{
    char choice;
    system("cls");
    remove("./phonebook.txt");
    printf("All data in the phonebook has been deleted successfully\n");
    printf("\n .... Press any key to continue ....\n");
}
