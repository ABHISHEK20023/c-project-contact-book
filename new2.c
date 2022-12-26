#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

#define reset "\x1B[0m"
#define bold "\x1B[1m"

struct add
{
    char name[21];
    long long int num;
    long long int num2;
    char address[1000];
};
struct add s;

void menu();
void add();
void search();
void delete ();
void choice(char n);
void list();
void edit();
int searchName(char *name);

int main()
{

    menu();
}
void menu()
{
    system("cls");
    fflush(stdin);
    printf("\nDATE \% s", __DATE__);
    printf("    TIME \%s", __TIME__);
    char n;
    printf("\n\n\t\t\t\t\t\t\t   -===%s== WECOME TO PHONE BOOK ==%s===-\n\n\n\n\n", bold, reset);
    printf("\t\t\t\t\t\t\t\t........................\n");
    printf("\t\t\t\t\t\t\t\t.      %s  MENU          .\n", bold);
    printf("\t\t\t\t\t\t\t\t........................\n\n\n");

    printf("\t\t   1. ADD              2. VIEW CONTACTS               3. SEARCH               4. DELETE               5. EDIT               6. EXIT\n\n");

    printf("%sEnter your choice : ", bold);
    scanf("%c", &n);
    choice(n);
}

void choice(char n)
{
    fflush(stdin);
    switch (n)
    {

    case '1':
        add();
        break;
    case '2':
        list();
        break;
    case '3':
        search();
        break;
    case '4':
        delete ();
        break;
    case '5':
        edit();
        break;
    case '6':
        system("cls");
        printf("%s\t\t\t\t\t\t\t\tTHANKS FOR USING OUR SERVICES", bold);
        sleep(2);
        system("cls");
        printf("\t\t\t\t\t\t\t\t\t    VISIT AGAIN\n\n\n\n%s", reset);
        int i, j, n = 10;

        for (i = n / 2; i <= n; i += 2)
        {
            printf("\t\t\t\t\t\t\t\t         ");
            for (j = 1; j < n - i; j += 2)
            {
                printf(" ");
            }

            for (j = 1; j <= i; j++)
            {
                printf("*");
            }

            for (j = 1; j <= n - i; j++)
            {
                printf(" ");
            }

            for (j = 1; j <= i; j++)
            {
                printf("*");
            }

            printf("\n");
        }

        for (i = n; i >= 1; i--)
        {
            printf("\t\t\t\t\t\t\t\t         ");
            for (j = i; j < n; j++)
            {
                printf(" ");
            }

            for (j = 1; j <= (i * 2) - 1; j++)
            {
                printf("*");
            }

            printf("\n");
        }
        sleep(2);
        system("cls");
        exit(1);
        break;
    default:
    {
        printf("ERROR INVALID KEY\n");

        printf("Please enter correct choice\n");

        sleep(2);
        menu();
    }
    }
}

void add()
{
v:
    system("cls");

    printf("Enter name*   : ");
    fflush(stdin);
    char ch[21];
    scanf("%[^\n]s", &ch);
    int k = 0, count = 0;

    while (ch[k] != '\0')
    {
        count++;

        k++;
    }
    if (count >= 20)
    {
        printf("Maximun character limit reached!\n\n plese try a short name\n");
        sleep(3);
        goto v;
    }

    fflush(stdin);
    FILE *fptr;
    fptr = fopen("contact.txt", "r");
    if (searchName(ch) == 1)
    {
        printf("NAME ALREADY EXISTS\n\n");
        printf("ENTER A NEW NAME ");
        sleep(3);
        add();
    }
    else
    {
        strcpy(s.name, ch);
        printf("Main number*  : ");
        scanf("%lld", &s.num);
   
        printf("second number : ");
        
        scanf("%lld", &s.num2);

      int found=0;
      
        
      
        
        

        fflush(stdin);
        printf("address       : ");
        scanf("%[^\n]s", &s.address);

        fptr = fopen("contact.txt", "a");
        fwrite(&s, sizeof(s), 1, fptr);

        printf("\n\nContact is successfully saved\n\n\n");

        fclose(fptr);
        sleep(2);
        menu();
    }
}

void list()
{
    fflush(stdin);
    char r;
    system("cls");
    printf("\t\t\t\t\t\t\t%s1. LIST VIEW             2. NORMAL VIEW             3.MAIN MENU\n\n\n", bold);

    printf("%sEnter your choice :  %s", bold, reset);
    scanf("%c", &r);

    switch (r)
    {
    case '1':
    {
        system("cls");
        printf("\t\t\t\t\t\t\t\t    %s      ALL CONTACTS%s\n\n", bold, reset);
        printf("                                          S.NO.      NAME               MAIN NUMBER      SECOND NUMBER                ADDRESS            \n");
        FILE *fptr;
        fptr = fopen("contact.txt", "r");
        int j = 0;

        while (fread(&s, sizeof(s), 1, fptr))
        {

            printf("\t\t\t\t\t  %d", j + 1);
            int k = 0, count = 0;
            char ch[21];
            strcpy(ch, s.name);

            while (ch[k] != '\0')
            {
                count++;

                k++;
            }
            int n = 5;
            if (j >= 9)
            {
                n = n - 1;
            }
            for (k = 0; k < n; k++)
            {
                printf(" ");
            }
            printf("   %s ", s.name);

            for (k = 0; k < 20 - count; k++)
                printf(" ");
            printf("   %lld  ", s.num);

            long long int p;
            p = s.num;
            count = 0;
            while (p != 0)
            {
                p = p / 10;
                count++;
            }
            for (k = 0; k < 11 - count; k++)
                printf(" ");

            printf("     %lld     ", s.num2);

            p = s.num2;
            count = 0;
            while (p != 0)
            {
                p = p / 10;
                count++;
            }
            for (k = 0; k < 20 - count; k++)
                printf(" ");
            printf("%s  ", s.address);
            printf("\n");
            j++;
        }

        fclose(fptr);
        printf("\n ENTER ANY NUMBER TO GO TO MAIN MENU\n");
        getch();
        menu();
    }

    case '2':
    {
        FILE *fptr;
        fptr = fopen("contact.txt", "r");
        int i = 1;
        system("cls");
        printf("\t\t\t\t\t\t\t\t    %s      ALL CONTACTS%s\n\n", bold, reset);
        while (fread(&s, sizeof(s), 1, fptr))
        {

            printf("\t\t\t\t\t\t\t\t    CONTACT %d\n\n", i);
            printf("\t\t\t\t\t\t\t\t    NAME          :  %s \n", s.name);
            printf("\t\t\t\t\t\t\t\t    MAIN NUMBER   :  %lld \n", s.num);
            printf("\t\t\t\t\t\t\t\t    SECOND NUMBER :  %lld   \n", s.num2);
            printf("\t\t\t\t\t\t\t\t    ADDRESS       :  %s \n\n\n", s.address);
            i++;
        }
        fclose(fptr);
        printf("\n ENTER ANY NUMBER TO GO TO MAIN MENU\n");
        getch();
    }
    case '3':
        menu();
        break;
    default:
    {
        printf("PLEASE ENTER A VALID KEY\n\n");
        printf("REDIRECTING TO VIEW CONTACT\n\n");

        sleep(2);
        list();
    }
    }
}
void search()
{
    system("cls");
    printf("ENETR CONTACT NAME\n\n");
    fflush(stdin);
    char ch1[21];
    scanf("%[^\n]s", ch1);
    int k;
    FILE *fptr;
    fptr = fopen("contact.txt", "r");

    while (fread(&s, sizeof(s), 1, fptr))
    {
        if (strcasecmp(ch1, s.name) == 0)
        {
            system("cls");
            printf("CONTACT DETAILS\n\n\n");
            printf("NAME          :  %s \n", s.name);
            printf("MAIN NUMBER   :  %lld \n", s.num);
            printf("SECOND NUMBER :  %lld   \n", s.num2);
            printf("ADDRESS       :  %s \n\n\n", s.address);
            k = 1;
            break;
        }
    }
    if (k != 1)
    {
        printf("\n\n CONTACT NOT FOUND");
    }

    fclose(fptr);
    printf("\n ENTER ANY NUMBER TO GO TO MAIN MENU\n");
    getch();

    menu();
}

void delete ()
{
    system("cls");
    printf("%sENTER NAME OF THE CONTACT YOU WANT TO DELETE%s\n\n", bold, reset);
    char d[21];
    scanf("%[^\n]s", &d);

    fflush(stdin);
    FILE *fptr, *temp;
    fptr = fopen("contact.txt", "r");
    temp = fopen("temp.txt", "a");
    int found = 0;
    while (fread(&s, sizeof(s), 1, fptr))
    {
        if (strcasecmp(d, s.name) == 0)
        {
            found = 1;
        }

        else
        {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);
    if (found == 1)
    {

        remove("contact.txt");
        rename("temp.txt", "contact.txt");
        printf("\n\n CONTACT DELETED\n\n");
        printf(" REDIRECTTING TO MAIN MENU\n");
        sleep(2);

        menu();
    }
    else
    {
        remove("temp.txt");

        printf("\n\n CONTACT NOT EXISTS\n\n");
        printf(" REDIRECTTING TO MAIN MENU\n");
        sleep(2);

        menu();
    }
}

int searchName(char *name)
{
    int k = 0;
    FILE *fptr;
    fptr = fopen("contact.txt", "r");

    while (fread(&s, sizeof(s), 1, fptr))
    {
        if (strcasecmp(name, s.name) == 0)
        {
            k = 1;
            break;
        }
    }
    fclose(fptr);
    return k;
}

void edit()
{
    system("cls");
    fflush(stdin);
    FILE *fptr, *temp;
    fptr = fopen("contact.txt", "r");
    temp = fopen("temp.txt", "a");
    printf("%sENTER NAME OF THE CONTACT YOU WANT TO EDIT%s\n\n", bold, reset);
    char d[21];
    scanf("%[^\n]s", &d);

    if (searchName(d) == 0)
    {
        printf("\n\n CONTACT NOT EXISTS\n\n");
        printf(" REDIRECTTING TO MAIN MENU\n");
        sleep(2);
        fclose(fptr);
        fclose(temp);
        menu();
        return;
    }

    while (fread(&s, sizeof(s), 1, fptr))
    {
        if (strcasecmp(d, s.name) == 0)
        {
        X:
            system("cls");
            printf("ENTER NEW DETAILS\n\n");
            printf("Enter name*   : ");
            fflush(stdin);
            char newname[21];
            scanf("%[^\n]s", &newname);
            if (searchName(newname) == 0)
            {

                fflush(stdin);
                printf("Main number*  : ");
                long long int newnum;
                scanf("%lld", &newnum);

                printf("second number : ");
                long long int newnum1;
                scanf("%lld", &newnum1);
                printf("address       : ");
                char newaddress[100];
                fflush(stdin);
                scanf("%[^\n]s", &newaddress);
                fflush(stdin);
                strcpy(s.name, newname);
                strcpy(s.address, newaddress);
                s.num = newnum;
                s.num2 = newnum1;
                fwrite(&s, sizeof(s), 1, temp);
                sleep(1);
            }
            else
            {
                printf("\nNAME ALREADY EXISTS\n");
                printf("ENTER A NEW NAME ");
                sleep(2);
                goto X;
            }
        }
        else
        {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }
    fclose(fptr);
    fclose(temp);
    remove("contact.txt");
    rename("temp.txt", "contact.txt");
    printf("\n\n CONTACT EDITED\n");
    printf(" REDIRECTTING TO MAIN MENU\n");
    sleep(2);

    menu();
}
