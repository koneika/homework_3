#include <iostream>
#include <ctime>
using namespace std;

const int N = 10;

void gui() { 
	cout << "r. Input 10 times a random digits to item(range 0-10)" << endl;
	cout << "1. Input digit to item(10 times)" << endl;
	cout << "2. Output from item" << endl;
	cout << "3. Search digit by items" << endl;
	cout << "4. Search digit by items and show index" << endl;
	cout << "5. Create new_item and copy/paste from old_item" << endl;
	cout << "6. Count all array" << endl;
	cout << "7. Where minimum or maximum on new_item?" << endl;
	cout << "8. Exit" << endl << endl;
	cout << "x. Reset" << endl << endl;
}

void random(int a[N]) {
	srand(time(NULL));
	for(int i = 0; i < N; ++i) 
		a[i] = (rand()/5000)+1;
}

void input(int a[N]) {
	cout << "Input 10 numbers" << endl;
	for(int i = 0; i < N; ++i) 
		cin >> a[i];
}

void output(int a[N]) {
	for(int i = 0; i < N; ++i)
		cout << a[i] << " "; 
	cout << endl; 
}

void LogicalSearchItem(int a[N], int c, int& zero) {
	int temp, counter = zero;

	cin >> temp;
	for (int i = 0; i < N; ++i) {
		
		if (temp == a[i]) {

			if (c == false) 
				cout << "we find " << temp << " on item(s) ";
			c = true;

			++counter;
		}
	}

	if (c == true)
		cout << counter << " times" << endl;

	if (c < 1) {
		cout << "we didnt find " << temp << " on item(s)" << endl;
		c = false;
	}
}

void IndexedSearchItem(int a[N], int& zero, bool boolean) {
	int temp = zero;

	cout << "which number do you want to find by index?" << endl;
	cin >> temp;

	for (int i = 0; i < N; ++i)
	if(a[i] == temp)
		boolean = true;

	if (boolean == true)
		cout << "we find " << temp <<  " on index(es)";

	for(int i = 0; i < N; ++i) {
		if(a[i] == temp) {
			cout << " " << i + 1;
			boolean = true;
		}
	}

	cout << endl;

	if (boolean < 1) {
		cout << "we didnt find index " << endl;
		boolean = false;
	}

	boolean = false;
}

void CopyArrayToOtherArray(int a[N], int a_new[N]) {
	cout << "in new item we have this digits before" << endl << endl;
	for (int i = 0; i < N; ++i)
		cout << a_new[i] << " ";

	for(int i = 0; i < N; ++i)
		a_new[i] = a[i];
	cout << endl;
	cout << "Successful" << endl << endl;

	cout << "in new item we have this digits now" << endl;
	for (int i = 0; i < N; ++i)
		cout << a_new[i] << " ";
	cout << endl;
}

void CountItemInArray(int a[N], int& zero) {
	int temp = zero;

	for(int i = 0; i < N; ++i)
		temp += a[i];
	cout << temp << endl;
}

void MinMax(int a_new[N], int& zero, bool boolean) {
	int temp = zero;
	cin >> boolean;

	for(int j = 0; j < N - 1; ++j)
		for(int i = 0; i < N - 1; ++i) {
			if (boolean == 1) {
				if (a_new[i] > a_new[i + 1]) {
					temp = a_new[i];
					a_new[i] = a_new[i + 1];
					a_new[i + 1] = temp;
				}
			}
			else {
				if (a_new[i] < a_new[i + 1]) {
					temp = a_new[i];
					a_new[i] = a_new[i + 1];
					a_new[i + 1] = temp;
				}
			}
		}
	
	cout << a_new[N - 1] << endl;


}

void Reset(int a[N], int a_new[N]){
	for (int i = 0; i < N; ++i)
		a[i] = 0, a_new[i] = 0;
}

void main() {
	int a[N] = {0}, a_new[N] = {0}, zero = 0;
	char chose;
	bool boolean = 0;
	
	do{

	gui();
	cin >> chose;

	system("cls");
	
	switch (chose){
		case 'r':
			random(a);
			system("cls");
			continue;
		case '1':
			input(a);
			system("cls");
			continue;
		case '2':
			output(a);
			system("pause");
			system("cls");
			continue;
		case '3':
			LogicalSearchItem(a, boolean, zero);
			system("pause");
			system("cls");
			continue;
		case '4':
			IndexedSearchItem(a, zero, boolean);
			system("pause");
			system("cls");
			continue;
		case '5':
			CopyArrayToOtherArray(a, a_new);
			system("pause");
			system("cls");
			continue;
		case '6':
			CountItemInArray(a, zero);
			system("pause");
			system("cls");
			continue;
		case '7':
			MinMax(a_new, zero, boolean);
			system("pause");
			system("cls");
			continue;
		case '8':
			continue;
		case 'x':
			Reset(a, a_new);
			system("cls");
			continue;
	}
	}while(chose != '8');	

	system("pause");
}