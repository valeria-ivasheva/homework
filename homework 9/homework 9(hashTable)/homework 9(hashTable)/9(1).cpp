#include "hashTable.h"
#include <string>

int main()
{
	FILE *text = fopen("text.txt", "r");
	HashTable* hash = makeHashTable();
	std::string word = "";
	while (fscanf(text, "%s", word) != EOF)
	{
		addElement(hash, word);
	}
	fclose(text);
	printHash(hash);
	deleteHash(hash);
	system("pause");
	return 0;
}