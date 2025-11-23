// createdata.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef struct
{
    char	firstName[30];
    char	lastName[30];
    int		age;
} Person;

long fileSize(FILE *input);

int main(void)
{
    FILE	*fpData;
 
    Person people[] =
    {
          { "Moe", "Howard", 83 }
        , { "Larry", "Fine", 81 }
        , { "Curley", "Howard", 79 }
        , { "Robin", "Williams", 61 }
        , { "Larry", "Sanders", 60 }
        , { "Howard", "Stern", 58 }
        , { "Steven", "Wright", 56 }
        , { "Harrison", "Andrew", 58 }
        , { "Harrison", "Ford", 63 }
        , { "Elton", "John", 63 }
    };

    printf("Struct size: %d\n", sizeof(Person));
    
    if ( ( fpData = fopen( "people.dat", "wb" ) ) == NULL )
    {
       printf( "File could not be opened.\n" );
       return 1;
    }

    fwrite(people, sizeof(Person), 10, fpData);

    fclose(fpData);

    if ( ( fpData = fopen( "people.dat", "rb" ) ) == NULL )
    {
       printf( "File could not be opened.\n" );
       return 1;
    }

    printf("FileSize: %d\n", fileSize(fpData));

    fclose(fpData);

}
        
long fileSize(FILE *input)
{
    long orgPos;
    long startPos;
    long endPos;

    orgPos = ftell(input);          // save orig file position
    rewind(input);
    startPos = ftell(input); // this should set startPos to 0
    fseek(input, 0, SEEK_END);
    endPos = ftell(input);
    fseek(input, orgPos, SEEK_SET); // restore orig position
    
    return(endPos - startPos);
}
