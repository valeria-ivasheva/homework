#include "hashTable.h"
#include <string>

int main()
{
	FILE *text = fopen("text.txt", "r");
	HashTable* hash = makeHashTable();
	char word[100] = "";
	while (fscanf(text, "%s", word) != EOF)
	{
		addElement(hash, word);
	}
	fclose(text);
	printHash(hash);
	characteristicHash(hash);
	deleteHash(hash);
	system("pause");
	return 0;
}