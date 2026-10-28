#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "validate.h"

int exi = 1;

void listContacts(AddressBook *addressBook) //list of contacts printing
{
     printf("+----------+-----------------+--------------+---------------------------+\n");
     printf("| %-8s | %-15s | %-10s | %-25s |\n","index","CONTACT NAME","PHONE NUMBER","EMAIL ID");
    printf("+----------+-----------------+--------------+---------------------------+\n");


    for(int j=0;j!=addressBook->contactCount;j++)
    {
       printf("| %-8d | %-15s | %-12s | %-25s |\n",j+1,addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email); 
    }   


     printf("+----------+-----------------+--------------+---------------------------+\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    
    loadContactsFromFile(addressBook);//load contacts when we open the file
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)//create contact
{
    char temp[50];
    int check;
    int i=addressBook->contactCount;

  if(i>99)//check the contacts full or not
  {

    printf("contact list full");
    return;
  }
  else
  {

   int count=0;
    do//validate name
    {
        if(count>=3)//3 times only we can re-enter names
        return;
        printf("ENTER THE NAME :\n");
	    scanf("\n%[^\n]",temp);
        count++;
        check=validate_name(temp,addressBook);
    }while(check);
    strcpy(addressBook->contacts[i].name,temp);

    count=0;

    do//validate phone number
    {
         if(count>=3)
        return;
        printf("ENTER THE PHONE NUMBER:\n");
	    scanf("%s",temp);
        count++;
        check=validate_ph(temp,addressBook);
    }while(check);
    strcpy(addressBook->contacts[i].phone,temp);

    count =0;

     do//validate email
    {
         if(count>=3)
        return;
        printf("ENTER THE EMAIL:\n");
	    scanf("%s",temp);
         count++;
        check=validate_email(temp,addressBook);
    }while(check);
    strcpy(addressBook->contacts[i].email,temp);


         i++;
        addressBook->contactCount++;

    }
}

void searchContact(AddressBook *addressBook) 
{
     int arr[100]={0};
     int c;
     int check;
     char temp[50];
     int co=0;
     int count=0;
    printf("1 search by name\n2 search by phone number\n3 search by email \n4 exit\n");
    scanf("%d",&c);

    switch(c)
    {
        case 1:
        do{
        if(co>=3)//3 times only we can re-enter names
        {
        exi=0;
        return;
        }
        temp[50];
        printf("Enter the name\n");//search contact with name
        scanf("\n%[^\n]",temp);
        co++;
        check=validate_name(temp,addressBook);
        }while(check);
          for(int i=0;i!=addressBook->contactCount;i++)
           {
             int p=strcmp(addressBook->contacts[i].name,temp);
              if(p==0)
              {
                 arr[i]=1;
                 count=1;
              }
            }     
         break;

        case 2:
        do{
        if(co>=3)
        {
        exi=0;//3 times only we can re-enter names
        return;
        }
        temp[50];
         printf("ENTER THE PHONE NUMBER:\n");
	    scanf("%s",temp);
        co++;
        check=validate_phsearch(temp,addressBook);
        }while(check);

         for(int i=0;i!=addressBook->contactCount;i++)
           {
             int p=strcmp(addressBook->contacts[i].phone,temp);
              if(p==0)
              {
                 arr[i]=1;
                 count=1;
              }
            }    
        break;

        case 3:
        do{
        if(co>=3)
        {
        exi=0;//3 times only we can re-enter names
        return;
        }
         temp[50];
        printf("ENTER THE EMAIL:\n");
	    scanf("%s",temp);
        co++;
        check=validate_emailsearch(temp,addressBook);
        }while(check);
         for(int i=0;i!=addressBook->contactCount;i++)
           {
             int p=strcmp(addressBook->contacts[i].email,temp);
              if(p==0)
              {
                 arr[i]=1;
                 count=1;
              }
            }    
        break;
        
        case 4:
        {
        exi = 0;//to exit from edit contact
        return ;
        }
        break;


        default:
        printf("Invalid option");
    }
    
    
    if(count==0)
    {
        printf("+----------------+");
        printf("\n| NO MATCH FOUND |\n");
        printf("+----------------+");
        exi=0;
        return;
    }
   
     printf("+----------+-----------------+--------------+---------------------------+\n");
     printf("| %-8s | %-15s | %-10s | %-25s |\n","INDEX","CONTACT NAME","PHONE NUMBER","EMAIL ID");
     printf("+----------+-----------------+--------------+---------------------------+\n");

    
    for(int j=0;j<100;j++)
    {
        if(arr[j]==1)
        {
            printf("| %-8d | %-15s | %-12s | %-25s |\n",j+1,addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email); 
        }   
        
    }
    printf("+----------+-----------------+--------------+---------------------------+\n");
}

void editContact(AddressBook *addressBook)
{
    searchContact(addressBook);
    if(exi==0)
    {
       return;
    }

    printf("Enter the Index to change");
    int index;
    scanf("%d",&index);
    index--;
    if(index<0||index>addressBook->contactCount)
    {
    printf("Invalid index\n");
    return;
    }
    char temp[50];
    int check;
    printf("1:edit name\n2:edit phone number\n3:edit email\n ");
    int c;
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        do{
        printf("ENTER THE NAME :\n");
	    scanf("\n%[^\n]",temp);
        check=validate_name(temp,addressBook);
        }while(check);
        strcpy(addressBook->contacts[index].name,temp);
        break;

        case 2:
        do//validate phone number
        {
        printf("ENTER THE PHONE NUMBER:\n");
	    scanf("%s",temp);
        check=validate_ph(temp,addressBook);
        }while(check);
        strcpy(addressBook->contacts[index].phone,temp);
        break;

        case 3:
        do//validate email
        {
        printf("ENTER THE EMAIL:\n");
	    scanf("%s",temp);
        check=validate_email(temp,addressBook);
        }while(check);
        strcpy(addressBook->contacts[index].email,temp);
        break;

        default:
        printf("Wrong input");
    }
    
}

void deleteContact(AddressBook *addressBook)
{
	
   searchContact(addressBook);//search contact
    if(exi==0)
    {
       return;
    }
   printf("Enter the index to delete contact");
   int Index;
   scanf("%d",&Index);
   Index--;
   if(Index<0||Index>addressBook->contactCount)
   {
    printf("Invalid index\n");
    return;
   }
   int i;
   for(i=Index;i!=addressBook->contactCount;i++)
   {
      addressBook->contacts[i]=addressBook->contacts[i+1];
   }
   addressBook->contactCount--;
}



