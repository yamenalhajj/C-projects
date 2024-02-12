#include <stdio.h>
#include <string.h>
#include <ctype.h>

void transferChar(char string[] , char letter);

int main() 
{
   
    char ArrayOfCharecter[100];
    
    char removedCHAR;
    fgets(ArrayOfCharecter, sizeof(ArrayOfCharecter), stdin);
    
    transferChar(ArrayOfCharecter , removedCHAR);
    
    printf("%s", ArrayOfCharecter );
   
    return 0;
}

void transferChar(char string[] , char letter) 
{
    for (int i = 0; i < strlen(string); i++) 
    {
        letter = toupper(string[i]);
        
        if (letter == 'A' || letter == 'O' || letter == 'E' || letter == 'I' || letter == 'U') 
        
        {
            for (int j = i; j < strlen(string); j++) 
            {
                int thefollowingCHAR = j + 1;
                
                string[j] = string[thefollowingCHAR];
            }
            i--;
        }
    }
}

