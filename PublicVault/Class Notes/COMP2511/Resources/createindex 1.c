// createindex.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define APP_NAME "Week09Demo"

typedef enum {FIRST, LAST, YEAR} IndexKey;

typedef union
{
    char	first[30];
    char	last[30];
    int		age;
} KeyType;

typedef struct
{
    char	firstName[30];
    char	lastName[30];
    int		age;
} Person;

typedef struct
{
    KeyType		key;
    long		filePos;
} IndexRecord;

typedef struct
{
    IndexKey	idxKey;	
    char		appName[20];
    int			recCount;
} IndexHeader;

// function prototypes
long fileSize(FILE *input); //computes file size
int compare(const void *left, const void *right); //used by qsort

IndexKey indexKey;

int main(void)
{
    FILE	*fpData;
    FILE	*fpIndexLastName;

    int		readCount;
    int		writeCount;
    int		dataRecordCount;
    int		indexRecordCount;
    long	filePos;

    IndexHeader	indexHeader;
    IndexRecord	*indexRecords;
    Person		temp = {"","", 0};
    
    indexKey = LAST; // change to FIRST or YEAR if creating other type of index file
    
    // open data file for reading
    if ((fpData = fopen("people.dat", "rb")) == NULL)
    {
        printf("ERROR - can not open data file.\n");
        return 1;
    }

    // open index file for writing
    if ((fpIndexLastName = fopen("lastname.idx", "wb")) == NULL)
    {
        printf("ERROR - can not open/create index file.\n");
        return 1;
    }
    
    // calculate record count in data file
    dataRecordCount = fileSize(fpData) / sizeof(Person);

    // allocate an array to hold an equal number
    //  of index records
    indexRecords = (IndexRecord *) calloc(dataRecordCount, sizeof(IndexRecord));
   // indexRecords = (IndexRecord*)malloc(dataRecordCount * sizeof(IndexRecord));


    // populate index header record
    indexHeader.idxKey = indexKey;
    strcpy(indexHeader.appName, APP_NAME);
    indexHeader.recCount = dataRecordCount;

    rewind(fpData);
    filePos = ftell(fpData);
    indexRecordCount = 0;

    // Read first data record
    readCount = fread(&temp, sizeof(Person), 1, fpData);

    // Process all data records
    while (!feof(fpData) && (readCount == 1))
    {
        // populate index record from data record
		// would need to change argument accordingly in strcpy invocation below if
		//       sorting by another field. For example:
        // indexRecords[indexRecordCount].key.age = temp.age; // if sorting by age
        strcpy(indexRecords[indexRecordCount].key.last, temp.lastName);
        indexRecords[indexRecordCount].filePos = filePos;
        
        // added a record - increment to next element
        indexRecordCount++;              

        // store file pos before next read advances it
        filePos = ftell(fpData);

        // read next record
        readCount = fread(&temp, sizeof(Person), 1, fpData);
    }

    // Sort array of index records in memory
    //  based on return value of compare function
    qsort(indexRecords, indexRecordCount, sizeof(IndexRecord), compare);

    printf("Index Header Size: %d\nIndex Record Size: %d\n\n"
                            , sizeof(IndexHeader), sizeof(IndexRecord));
    
    printf("Creating Index File\n");	

    // write Index Header to file
    writeCount = fwrite(&indexHeader, sizeof(IndexHeader), 1, fpIndexLastName);

    // Write Index Records to file
    writeCount = fwrite(indexRecords, sizeof(IndexRecord), indexRecordCount, fpIndexLastName);

    printf("%d Records Processed\n", writeCount);

    printf("\nFileSize: %d\n\n", fileSize(fpIndexLastName));

    // release this memory and set it free
    free(indexRecords);

    // close files and go home
    fclose(fpData);
    fclose(fpIndexLastName);
}


// calculates the size of a file
long fileSize(FILE *input)
{
    long orgPos;
    long startPos;
    long endPos;

    orgPos = ftell(input);          // save orig file position
    rewind(input);
    startPos = ftell(input); // should ALWAYS be 0
    fseek(input, 0, SEEK_END);
    endPos = ftell(input);
    fseek(input, orgPos, SEEK_SET); // restore orig position
    
    return(endPos - startPos);
}

// function that qsort points to
int compare(const void *left, const void *right)
{
    // cast pointer parameters to IndexRecord
    IndexRecord *pLeft = (IndexRecord *) left;
    IndexRecord *pRight = (IndexRecord *) right;

	// would need to be updated if sorting on another key
    return strcmp((pLeft->key.last), (pRight->key.last));

	
	// The following code is commented out but could be used instead if we wanted to sort 
	// by first name when the last names are the same.

	// PLEASE NOTE: Would not work in this situation since our index records only hold one field!

	   
	/*
	
	int result;

	// cast pointer parameters to IndexRecord
    IndexRecord *pLeft = (IndexRecord *) left;
    IndexRecord *pRight = (IndexRecord *) right;

    result = strcmp((pLeft->key.last), (pRight->key.last));// comparing last names

	if (result != 0)
	{
		return result; // for case where last names are not the same
	}
	else // for the case where last names are the same, we return result of comparing the first names
	{
		return strcmp((pLeft->key.first), (pRight->key.first)); //comparing first names
	}

	*/
}
