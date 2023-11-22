#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

int create_account();
int signin();
void withdraw_amount();
void deposit_amount();
void encrypt();
void decrypt();
void mask_password();
int open_file();
int close_file();
int calculate_emi();
void exit();

struct detailsOfAccountHolder
{
    char full_name[256];
    char father_name[256];
    char date_of_birth[10];
    char gender;
    char phone_number[10];
    char email_address[256];
    char residential_address[500];
    char city[50];
    char state[50];
    char pin_code[6];
    int income;
    char pan[100];
    char aadhar_number[12];
    char account_type[100];
    long int account_number;
    char login_password[256];
    int transaction_pin;
    int account_balance;
};

int main()
{
    int main_choice;
    printf("\n\n\t\t\t\t\t\tWelcome To DSA BANK!");
    goto start_menu;
    start_menu:
    printf("\n\t\t1.New Account\n\t\t2.Sign in To Existing Account\n\t\t3.Bank Calculator\n\t\t4.Exit");
    printf("\n\t\tEnter choice: ");
    scanf("%d", &main_choice);
    switch (main_choice)
    {
    case 1:
        printf("CREATE A BANK ACCOUNT");
        break;
    
    case 2: 
        printf("SIGN IN TO EXISTING ACCOUNT");
        break;

    case 3:
        printf("BANK CALCULATOR");
        break;

    case 4:
        program_exit();
        break;

    default:
        printf("Invalid choice!");
        goto start_menu;
    }
    return 0;
}

int create_account()
{
    int choice = 0, flag = 0;
    struct detailsOfAccountHolder details;
    printf("\nFull Name: ");
    scanf("%[^\n]s", &details.full_name);
    fflush(stdin);
    printf("\nFather's Name: ");
    scanf("%[^\n]s", &details.father_name);
    fflush(stdin);
    printf("\nEnter Date of Birth in form (DD/MM/YYYY): ");
    scanf("%[^\n]s", &details.date_of_birth);
    fflush(stdin);
    while (true)
    {
        choice = 0;
        printf("\nGender(Enter choice 1:Male\t2:Female\t3:Transgender) : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            details.gender = 'M';
            break;
        }
        else if (choice == 2)
        {
            details.gender = 'F';
            break;
        }
        else if (choice == 3)
        {
            details.gender = 'T';
            break;
        }
        else
        {
            printf("Invalid choice for gender!\n");
        }    
    }
    while (true)
    {
        flag = 1;
        printf("\nEnter phone number: ");
        scanf("%[^\n]s", &details.phone_number);
        fflush(stdin);
        if (strlen(details.phone_number) != 10)
        {
            printf("\nPhone number must contain 10 digits!");
            continue;
        }
        for (int i = 0; i < strlen(details.phone_number); i++)
        {
            if (((int) details.phone_number[i] < 48) || ((int) details.phone_number[i] >57))
            {
                flag = 0;
                break;
            }  
        }
        if (flag == 1)
        {
            break;
        }
        else{
            printf("\nPhone number must contain digits only!");
            continue;
        } 
    }
    printf("\nEnter Email-Address: ");
    scanf("%[^\n]s", &details.email_address);
    fflush(stdin);
    printf("\nEnter Residential-Address: ");
    scanf("%[^\n]s", &details.residential_address);
    fflush(stdin);
    printf("\nEnter City: ");
    scanf("%[^\n]s", &details.city);
    fflush(stdin);
    printf("\nEnter State: ");
    scanf("%[^\n]s", &details.state);
    fflush(stdin);
    while (true)
    {
        flag = 1;
        printf("\nEnter pin code: ");
        scanf("%[^\n]s", &details.pin_code);
        fflsuh(stdin);
        if (strlen(details.pin_code) != 6)
        {
            printf("\nPin code must contain 6 digits!");
            continue;
        }
        for (int i = 0; i < strlen(details.pin_code); i++)
        {
            if (((int) details.pin_code[i] < 48) || ((int) details.pin_code[i] >57))
            {
                flag = 0;
                break;
            }  
        }
        if (flag == 1)
        {
            break;
        }
        else{
            printf("\nPin code must contain digits only!");
            continue;
        } 
    }
    while (true)
    {
        printf("\nEnter income: ");
        scanf("%d", &details.income);
        if(details.income <= 0){
            printf("Income cannot be less than or equal to zero!");
            continue;
        }
        else{
            break;
        }
    }
    while (true)
    {
        printf("\nEnter PAN: ");
        scanf("%[^\n]s", &details.pan);
        fflush(stdin);
        if (strlen(details.pan) != 10)
        {
            printf("\nENter valid PAN: ");
            continue;
        }
        else
        {
            break;
        }  
    }
    while (true)
    {
        flag = 1;
        printf("\nEnter Aadhaar Number: ");
        scanf("%[^\n]s", &details.aadhar_number);
        fflsuh(stdin);
        if (strlen(details.pin_code) != 6)
        {
            printf("\nPin code must contain 6 digits!");
            continue;
        }
        for (int i = 0; i < strlen(details.pin_code); i++)
        {
            if (((int) details.pin_code[i] < 48) || ((int) details.pin_code[i] >57))
            {
                flag = 0;
                break;
            }  
        }
        if (flag == 1)
        {
            break;
        }
        else{
            printf("\nPin code must contain digits only!");
            continue;
        } 
    }

    while (true)
    {
        choice = 0;
        printf("Account Type (Enter choice 1:Savings\t2:Current) : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            strcpy(details.account_type, "Savings");
            break;
        }
        else if (choice == 2)
        {
            strcpy(details.account_type, "Current");
            break;
        }
        else
        {
            printf("Invalid choice for account type!\n");
        }    
    } 
    details.account_balance = 0;
    return 0;
}

bool sigin()
{
    int card_number, flag;
    char password[256];
    printf("Enter card number: ");
    scanf("%d", &card_number);
    printf("Enter password: ");
    mask_password(password);
    if(flag == 1){
        return true;
    }
    else{
        return false;
    }
}

void withdraw_amount(){
    int acc_num, flag, withdraw_money,index = 0, n=0;
    struct detailsOfAccountHolder details[n];
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < n; i++)
    {
        if (details[i].account_number == acc_num)
        {
            printf("\nName: %s", details[i].full_name);
            printf("\nAccount Balance: %d", details[i].account_balance);
            flag = 1;
            index = i;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nEnter amount to withdraw");
        scanf("%d", &withdraw_money);
        details[index].account_balance = details[index].account_balance - withdraw_money;
        printf("\nAmount Withdrawn = %d", withdraw_money);
        printf("\nAccount balance = %d", details[index].account_balance);
    }
    else
    {
        printf("Account Not Found!");
    }
}

void deposit_amount(){
    int acc_num, flag, deposit_money,index = 0, n=0;
    struct detailsOfAccountHolder details[n];
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < n; i++)
    {
        if (details[i].account_number == acc_num)
        {
            printf("\nName: %s", details[i].full_name);
            printf("\nAccount Balance: %d", details[i].account_balance);
            flag = 1;
            index = i;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nEnter amount to deposit");
        scanf("%d", &deposit_amount);
        details[index].account_balance = details[index].account_balance + deposit_money;
        printf("\nAmount Deposited = %d", deposit_money);
        printf("\nAccount balance = %d", details[index].account_balance);
    }
    else
    {
        printf("Account Not Found!");
    }
}

void encrypt(char password[], int key)
{
    for (int i = 0; i < strlen(password); i++)
    {
        password[i] = password[i] - key;
    }
}

void decrypt(char password[], int key)
{
    for (int i = 0; i < strlen(password); i++)
    {
        password[i] = password[i] + key;
    }
}

void mask_password(char password[])
{
    char ch;
    int i;
    while (ch = _fgetchar() != 13)
    {
        printf("*");
        password[i] = ch;
        i++;
    }
    password[i] = '\0';
}

int open_file(){

}

int close_file(){

}

int calculate_emi(){
    float amount, rate_of_interest, time_period, emi, total;
    printf("Enter amount: ");
    scanf("%f",&amount);
    printf("Enter rate of interest: ");
    scanf("%f",&rate_of_interest);
    printf("Enter time period(in months): ");
    scanf("%f",&time_period);
    rate_of_interest = rate_of_interest / (12 * 100);
    emi = (amount * rate_of_interest * pow(1 + rate_of_interest, time_period)) / (pow(1 + rate_of_interest, time_period) - 1);
    total = emi*time_period;
    printf("\nMonthly EMI = %f", emi);
    printf("\nTotal amount = %f", total);
    printf("\nInterest Amount = %f", total-amount);
    return 0;
}

void program_exit(){
    printf("You have logged out successfully. We cherish your relationship with us.");
    exit(0);
}