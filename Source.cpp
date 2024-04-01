#include <iostream>
#include <cstdio>
using namespace std;


//���� ��������� ����. ϳ��������� ������� ���, 
// �� ����������� � �������, ���� ���� ����������.










int searchCount(FILE* file, char searchChar) {
	const int MAXSIZE = 20;
	int count = 0;
	char line[MAXSIZE];
	while (fgets(line, MAXSIZE, file) != nullptr) {
		line[strcspn(line, " ")] = '\0'; // ������ �� ��������
		if (line[0] == searchChar) {
			count++;
		}
	}
	return count;
}

int main() {

	const char path[] = "lorem.txt";
	FILE* startFile;
	errno_t errFile = fopen_s(&startFile, path, "r");
	
	char searchChar;
	cout << "Enter searched char\n";
	cin >> searchChar;
	int count = 0;

	if (errFile == 0) {
		count = searchCount(startFile, searchChar);
		fclose(startFile);
	}
	
	cout << "Total count: " << count;

	return 0;
}