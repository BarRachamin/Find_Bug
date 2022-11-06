 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

	  int Bug_1() 
{
		   
	   int a = 4,b = 7; //bug if you want set two variable in int you need use (,) and not (;) between

         float c;

	   scanf("%f",&c);//bug in scanf you forgot use(&) after the (,) and we use it Because that's how he adds it to the same address

	   if (5 == c)// bug in condition when you want to compare you need use (==) or (===) and not (=) Because it's for setting a variable

	   printf("%f", c); //bug you forgot the (f) in the printf when you need to print somthing

	
}


	  int Bug_2()
	  {
		  int x, y;
		  int nums[6];
		  int* arrPtr;

		  // Section A - Print the variables
		  puts("***** Section A *****");
		  scanf("%d", &x); // bug: you forgot to ask the user for number to calculate
		  scanf("%d", &y); // bug: you forgot to ask the user for number to calculate
		  printf(" Base = %d\n", x);
		  printf(" Height = %d\n", y);
		  printf(" Area = %d\n", x * y);
		  // Section B - Print the static array "nums".
		  puts("***** Section B *****");
		  int i = 0;
		  while (i < 6) {
			  nums[i] = i; //Inserts a number (i) at the position of i in the array so that we can print it after that and there will be no garbage there
			  printf(" nums[%d] = %d\n", i, nums[i]);
			  i++; // forgot to Advance the counter so that it can exit the loop and it will not be an infinite loop
		  }

		  // Section C - Print allocated array.
		  puts("***** Section C *****");
		  arrPtr = (int*) malloc(sizeof(int) * 10);
		  if (arrPtr) {
			  for (i = 0; i < 6; i++) {
				  arrPtr[i] = i;//bug: forgot to Put values ​​in the array so it can then print them

				  printf(" array[%d] = %d\n", i, arrPtr[i]);
				  
			  }
		  }
		  else {
			  printf("Error Allocating Memory!\n");
			  exit(1);
		  }
		  return 0;
		  free(arrPtr);// forgot free when use malloc
	   }


	  // struct to collect counting info about english letters found in a text file.
		  typedef struct letter {
		  char small;
		  char big;
		  int counter;
		  struct letter* next; // bug:forgot to use next and prev in the struct
		  struct letter* prev;
	  }letter;
	  //Function to free linked list
	  void freeList(letter* head) {
		  letter* releaseItem;
		  letter* runItem = head;
		  while (runItem != NULL) {
			  releaseItem = runItem;
			  runItem = runItem->next;
			  free(releaseItem);
		  }
	  }
	  int main()
	  {
		  //Next two string represents all the english alphabets (small and capital)
		  
		  char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
		  char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		  int lettersCountArr[20] = { 0 };
		  char readChar, ch;
		  FILE* f;
		  f = fopen("myFile.txt", "r");

		  // Display the content of myFile.txt and count letters
		  printf("the content of myFile.txt :\n");
		  while ((readChar = fgetc(f)) != EOF) //bug : you need to wirte (EOF) that End of File and that how he can do where you need to stop 
		  {
			  printf("%c", readChar);
			  for (int i = 0; i < strlen(smallAlpha); ++i)
			  {
				  if (readChar == smallAlpha[i] || readChar == bigAlpha[i])
				  
				 
				  lettersCountArr[i]++;
			      
			  }
		  }
		  fclose(f);

		  // Build Linked list from file content
		  // Every node represent English letter (small and big).
		  letter* HEAD = NULL;
		  letter* TAIL = NULL;
		  for (int j = 0; j < strlen(smallAlpha); ++j)
		  {
			  letter* letterItem = (letter*)malloc(sizeof(letter));
			  if (!letterItem) {
				  puts("Error Allocating Memory!");
				  exit(1);
			  }
			  letterItem->small = 'a' + j;
			  letterItem->big = 'A' + j;
			  letterItem->counter = lettersCountArr[j];
			  // Creating the linked list
			  if (HEAD == NULL)
			  {
				  TAIL = letterItem;
				  HEAD = letterItem;
				  letterItem->next = NULL;
				  letterItem->prev = NULL;
			  }
			  else
			  {
				  letterItem->next = HEAD;
				  letterItem->prev = NULL;
				  HEAD->prev = letterItem;
				  HEAD = letterItem;
			  }
			  return 0;
		  }
	  }

