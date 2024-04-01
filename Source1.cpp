#include <iostream>
#include <cstdio>
using namespace std;


//Дано текстовий файл. Підрахувати кількість символів у ньому.
//Дано текстовий файл. Підрахувати кількість рядків у ньому.




int countSymbols(FILE* file) {
	int count = 0;
	char ch;
	while (!feof(file)) {
		ch = fgetc(file);
		count++;
	}

	return count;

}



int countLines(FILE* file) {
	int count = 0;
	const int MAXSIZE = 100;
	char line[MAXSIZE];
	while (fgets(line, MAXSIZE, file) != nullptr) {
		line[strcspn(line, "\n")] = '\0';
		count++;
	}
	return count;
}

int main() {

	const char fileName[] = "lorem.txt";
	
	FILE* file;
	errno_t errCode;

	errCode = fopen_s(&file, fileName, "r");

	int countSymb = 0;
	int countLine = 0;

	if (errCode == 0) {
		countLine = countLines(file);
		
		fclose(file);
	}

	errCode = fopen_s(&file, fileName, "r");

	if (errCode == 0) {
		countSymb = countSymbols(file);
		fclose(file);
	}
	
	cout << "Count of symbols: " << countSymb << endl;
	cout << "Count of strings: " << countLine << endl;

	return 0;
}