#include<stdio.h>
#include "contact.h"
#include "validate.h"
#include "string.h"
#include <ctype.h>
extern int exi;

int validate_name(char temp[50],AddressBook *addressBook)//validate name
{
    int count=0;
    for(int i=0;temp[i]!='\0';i++)
    {
        if(isalpha(temp[i]))
        count++;
        else if(temp[i]==' ')
        {

        }
        else
        {
        printf("Name should only contain alphabets\n");
        return 1;
        break;
        }
    }
   if(count<4) 
     {
      printf("Name must contain at least 4 character\n");
      return 1;
     }
   else
   return 0;
}

int validate_ph(char temp[50],AddressBook *addressBook)//validate phone number
{
  if((temp[0])>='6'&&temp[0]<='9')
  {
    int count=0;
     for(int i=0;temp[i]!='\0';i++)
     {
       if(isdigit(temp[i]))
       {
        count++;
       }
     }
     if(count==10)
     {
          for(int i=0;i!=addressBook->contactCount;i++)
         {
            int c= strcmp(temp,addressBook->contacts[i].phone);
           if(c==0)
           {
              printf("Number already exisist\n");
              return 1;
            }
         }
      return 0;
     }
     else
     printf("Phone number must contain exactly 10 digits\n");
     return 1;
   
  }
  else
  {
     if(isdigit(temp[0]))
     printf("First digit must be between 6 and 9\n");
     else
     printf("Symbols are not allowed in phone number\n");
     return 1;
  }
}

int validate_email(char temp[50],AddressBook *addressBook)//validate email

{
    int i=0;
    for(int i=0;temp[i]!='\0';i++)
    {
        if(isalnum(temp[i])||temp[i]=='@'||temp[i]=='.')
        {

        }
        else
        {
        printf("Invalid symbol\n");
        return 1;
        }
    }
    if(isalpha(temp[i]))
    {

    }
    else
    {
        printf("Invalid character\n");
    return 1;
    }
   char *p=strchr(temp,'@');
   char *p1=strchr(temp,'.');
   if(p1!=NULL&&p!=NULL)
   {
    
      while(temp[i]!='@')
      {
       i++;
      }
      int j=i+1;
      if(isalpha(temp[j]))
      {
         
      }
      else
      {
         printf("Invalid Domain\n");
      return 1;
      }
      while(temp[j]!='\0')
      {
        if(isalpha(temp[j])||temp[j]=='.')
        {
            
        }
        else
        {
            printf("extra characters used\n");
            return 1;
        }
        j++;
      }
       for(int i=0;i!=addressBook->contactCount;i++)
         {
            int c= strcmp(temp,addressBook->contacts[i].email);
           if(c==0)
           {
              printf("Email already exisist\n");
              return 1;
            }
         }
      return 0;
   }
   else
   {
    if(p==NULL)
    {
        printf("Missing '@'\n");
    }
    if(p1==NULL)
    {
        printf("Missing '.'\n");
    }
   }
   return 1;
}
int validate_phsearch(char temp[20],AddressBook *addressBook)
{
  if((temp[0])>='6'&&temp[0]<='9')
  {
    int count=0;
     for(int i=0;temp[i]!='\0';i++)
     {
       if(isdigit(temp[i]))
       {
        count++;
       }
     }
     if(count==10)
     {
      return 0;
     }
     else
     printf("Phone number must contain exactly 10 digits\n");
     return 1;
   
  }
  else
  {
     if(isdigit(temp[0]))
     printf("First digit must be between 6 and 9\n");
     else
     printf("Symbols are not allowed in phone number\n");
     return 1;
  }
}
int validate_emailsearch(char temp[50],AddressBook *addressBook)
{
    int i=0;
    for(int i=0;temp[i]!='\0';i++)
    {
        if(isalnum(temp[i])||temp[i]=='@'||temp[i]=='.')
        {

        }
        else
        {
        printf("Invalid symbol\n");
        return 1;
        }
    }
    if(isalpha(temp[i]))
    {

    }
    else
    {
        printf("Invalid character\n");
    return 1;
    }
   char *p=strchr(temp,'@');
   char *p1=strchr(temp,'.');
   if(p1!=NULL&&p!=NULL)
   {
    
      while(temp[i]!='@')
      {
       i++;
      }
      int j=i+1;
      if(isalpha(temp[j]))
      {
         
      }
      else
      {
         printf("Invalid Domain\n");
      return 1;
      }
      while(temp[j]!='\0')
      {
        if(isalpha(temp[j])||temp[j]=='.')
        {
            
        }
        else
        {
            printf("extra characters used\n");
            return 1;
        }
        j++;
      }
      return 0;
   }
   else
   {
    if(p==NULL)
    {
        printf("Missing '@'\n");
    }
    if(p1==NULL)
    {
        printf("Missing '.'\n");
    }
   }
   return 1;
}