#include <stdio.h>
#include <cstdio>
#include < string.h > 

using namespace std;

int main()
{
	struct Element
	{
		char name[100];
		char phone[20];
	};
	int count = 0;
	struct Element phoneBook[100];
	FILE *book = fopen("aphonebook.txt", "a+");
	while (fscanf(book, "%s%s", phoneBook[count].name, phoneBook[count].phone) != EOF)
	{
		count++;
	}
	int key = 1;
	int countNew = 0;
	while (key != 0)
	{
		printf("Please choose a number from 0 to 5\n");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
		{
			char name[100];
			char phone[20];
			scanf("%s", &phoneBook[count + countNew].name);
			scanf("%s", &phoneBook[count + countNew].phone);
			fprintf(book, "%s", phoneBook[count + countNew].name);
			fprintf(book, "%s", " ");
			fprintf(book, "%s\n", phoneBook[count + countNew].phone);
			countNew++;
			break;
		}
		case 2:
		{
			int i = 0;
			while (i < count + countNew)
			{
				printf("%s%s%s\n", phoneBook[i].name, " ", phoneBook[i].phone);
				i++;
			}
			break;
		}
		case 3:
		{
			int i = 0;
			char name[100];
			printf("%s\n", "Enter a name");
			scanf("%s", name);
			while (strcmp(phoneBook[i].name, name) != 0 && (i < count + countNew))
			{
				i++;
			}
			if (i == count + countNew)
			{
				printf("Sorry, don't found this name\n");
			}
			else
			{
				printf("%s\n", phoneBook[i].phone);
			}
			break;
		}
		case 4:
		{
			int i = 0;
			char phone[100];
			printf("%s\n", "Enter a phone");
			scanf("%s", phone);
			while (strcmp(phoneBook[i].phone, phone) != 0 && (i < count + countNew))
			{
				i++;
			}
			if (i == count + countNew)
			{
				printf("Sorry, don't found this phone\n");
			}
			else
			{
				printf("%s\n", phoneBook[i].name);
			}
			break;
		}
		case 5:
		{
			fflush(book);
			break;
		}
		}
		printf("\n");
	}
	fclose(book);
	return 0;
}