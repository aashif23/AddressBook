#ifndef VALIDATE_H
#define VALIDATE_H

#include "validate.h"


int validate_name(char temp[50],AddressBook *addressBook);
int validate_ph(char temp[20],AddressBook *addressBook);
int validate_email(char temp[50],AddressBook *addressBook);
int search_name(int ,AddressBook* AddressBook);
int validate_phsearch(char temp[20],AddressBook *addressBook);
int validate_emailsearch(char temp[50],AddressBook *addressBook);
#endif