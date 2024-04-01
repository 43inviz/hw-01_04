#include <iostream>
#include <cstdio>
using namespace std;


//Дано масив рядків. Записати їх у файл, розташувавши кожен елемент масиву на окремому рядку зі збереженням порядку.

int main() {


	int count;
	cout << "Enter count of lines: ";
	cin >> count;
	cin.ignore();

	
	char** fullArr = new char*[count];

	const int SIZE = 100;

	for (int i = 0; i < count; i++) {
		cout << "Enter line: ";
		char string[SIZE];
		cin.getline(string, SIZE);
		fullArr[i] = new char[SIZE];
		strcpy_s(fullArr[i], SIZE, string);
	}

	const char fileName[] = "result.txt";
	FILE* file; 
	errno_t errCode;
	
	errCode = fopen_s(&file, fileName, "w");

	if (errCode == 0) {
		for (int i = 0; i < count; i++) {
			fputs(fullArr[i], file);
			fputc('\n', file);
			if (feof(file)) {
				break;
			}
		}
		fclose(file);
	}



	return 0;
}