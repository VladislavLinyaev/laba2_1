#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func1.h"
#include <stdbool.h>
bool isInt(char * data) {
	bool check = true;
	for (unsigned int i = 0; i < strlen(data); i++) {
		if (!((data[i] >= '0') && (data[i] <= '9')))
			check = false;
	}
	return check;
}


int scan_int(char * name_field)
{
	int stop = 0;
	while (!stop)
	{

		printf("%s=", name_field);
		char digit[100];
		scanf("%s", digit);
		bool b = isInt(digit);

		if (b == true)
		{
			stop = 1;
			return atoi(digit);
		}
		else
		{
			printf("error input > %s < \n", name_field);
			stop = 0;
		}
	}

	return 0;
}

void write(struct film * arr, int n){
	if (n <= 0)
	{
		return;
	}
	FILE *f=fopen("file.txt","w");
	if(!f)
		return;
	fprintf(f,"%d\n", n);
	for(int i=0; i<n; i++)
		fprintf(f,"%s %d %d %s %s %s %d\n", arr[i].title, arr[i].year, arr[i].length, arr[i].country, arr[i].genre, arr[i].director, arr[i].rank);
	fclose(f);
}
void read(struct film **arr, int *n){
FILE *f=fopen("file.txt","r");
	if(!f)
	return;

if(fscanf(f,"%d", n)!= 1)
return;
	if(*n<=0)
	return;
*arr=(struct film *)calloc(*n,sizeof(struct film));
for (int i = 0; i < *n; i++)
	fscanf(f, "%s %d %d %s %s %s %d\n", (*arr)[i].title, &(*arr)[i].year, &(*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, &(*arr)[i].rank );
fclose(f);
}
void create(struct film **arr,int *n){
	printf("n=");
	scanf("%d",n);
		if(*n<= 0)
		return;
*arr =(struct film *)calloc(*n,sizeof(struct film));
for(int i=0; i<*n;i++){

	printf("title=");
	scanf("%s",(*arr)[i].title);

	(*arr)[i].year = scan_int((char *)"year");
	(*arr)[i].length = scan_int((char *)"length");

	printf("country=");
	scanf("%s", (*arr)[i].country);
	printf("genre=");
	scanf("%s", (*arr)[i].genre);
	printf("director=");
	scanf("%s", (*arr)[i].director);

	(*arr)[i].rank = scan_int((char *)"rank");
}
}

void search_field(struct film* arr, int n, char * field, int key) {
	char search_name[100];
	char search_arr[100];

	printf("Enter the search text -> %s <- : ", field);
	scanf("%s", search_name);

	for (int i = 0; i < n; i++)
	{
		if (key == 1)
			sprintf(search_arr, "%s" , arr[i].title);
		if (key == 2)
			sprintf(search_arr, "%i", arr[i].year);
		if (key == 3)
			sprintf(search_arr, "%i", arr[i].length);
		if (key == 4)
			sprintf(search_arr, "%s", arr[i].country);
		if (key == 5)
			sprintf(search_arr, "%s", arr[i].genre);
		if (key == 6)
			sprintf(search_arr, "%s", arr[i].director);
		if (key == 7)
			sprintf(search_arr, "%i", arr[i].rank);

		char* find_string = strstr(search_arr, search_name);
		if (find_string != NULL)
			printf("find - %s %d %d %s %s %s %d\n", arr[i].title, arr[i].year, arr[i].length, arr[i].country, arr[i].genre, arr[i].director, arr[i].rank);
	}

}

void search(struct film* arr, int n) {
  char key[100]; 
  int stop = 0;
  while (stop != 1) {
	  printf("\nEnter the search field\n");
	  printf("1-title, 2-year, 3-length, 4-country, 5-genre, 6-director, 7-rank, 8-exit\n");
	  scanf("%s", &key);
	  switch (*key) {
	  case '1':
		  search_field(arr, n, (char*) "title"   , 1);
		  break;
	  case '2':
		  search_field(arr, n, (char*) "year"    , 2);
		  break;
	  case '3':
		  search_field(arr, n, (char*) "length"  , 3);
		  break;
	  case '4':
		  search_field(arr, n, (char*) "country" , 4);
		  break;
	  case '5':
		  search_field(arr, n, (char*) "genre"   , 5);
		  break;
	  case '6':
		  search_field(arr, n, (char*) "director", 6);
		  break;
	  case '7':
		  search_field(arr, n, (char*) "rank"    , 7);
		  break;
	  case '8':
		  stop = 1;
		  break;
	  default:
		  stop = 1;
		  printf("enter only from 1-8!\n");
		  break;
	  }
  }
}
