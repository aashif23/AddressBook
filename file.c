#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE* fptr=fopen("contacts.csv","w");
    
     if(fptr==NULL)
       {
         perror("fopen");
       }

         fprintf(fptr,"#%d\n",addressBook->contactCount);

     for(int i=0;i!=addressBook->contactCount;i++)
       {
         fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
       }
       fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE* fptr=fopen("contacts.csv","r");
    if(fptr==NULL)
    {
        perror("fopen");
    }
      fscanf(fptr,"#%d\n",&addressBook->contactCount);
      for(int j=0;j!=addressBook->contactCount;j++)
      {
      fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
      }
        fclose(fptr);
}
