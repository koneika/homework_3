#include <iostream>
#include <ctime>
using namespace std;

const int N = 10;

void gui() { // it`s just gui lol
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

void input(int a[N]) {
	cout << "Input 10 numbers" << endl;
	for(int i = 0; i < N; ++i) // 10 times we just write data to variable
		cin >> a[i];
}

void output(int a[N]) {
	for(int i = 0; i < N; ++i)// 10 times we write data which we input
		cout << a[i] << " "; // without endl for beautiful see
	cout << endl; // just endl
}

void LogicalSearchItem(int a[N], int c, int& zero) { // here we find digit on all of arrays
	int counter = zero; // need for counting times, how much times we found our digit on all of arrays lol

	cin >> zero; // write your digit and if that digit have on all of arrays, true
	for (int i = 0; i < N; ++i) {
		// THIS BLOCK OF LOGICAL NEED FOR FIND MORE THAN 2 TIME, IF I FIND 1 TIMES, IT WILL SAY WE FOUND IT, IF WE HAVE 2 TIME, WE WILL TAKE 2 MESSAGE ABOU "WE FOUND IT" + "WE FOUND IT", SO HERE I CREATED IF 1 TIMES MESSAGE ALREADY HAVE, NO NEED TO WRITE A MESSAGE AGAIN IF YOU FIND 2 TIME SO OR MORE THE SAME NUMBER ON ALL OF ARRAYS
		if (zero == a[i]) {
			// its normal logic
			if (c == false) // stop sending a message after 1 times show
				cout << "we find " << zero << " on item(s) "; // here we opening cout
			c = true; // it`s for stop sending a message if we already have a message

			++counter; // its works without showing, so its need for understand how much times we have found the same digit
		}

	}




	if (c == true)
		cout << counter << " times" << endl; // here we close cout

	if (c < 1) {
		cout << "we didnt find " << zero << " on item(s)" << endl;
		c = false;
	}
	zero = 0; // if i dont create it, i will take a bug on counting all of arrays
}

void IndexedSearchItem(int a[N], int& zero, int c) {
	cout << "which number do you want to find by index?" << endl;
	cin >> zero;

	for (int i = 0; i < N; ++i)
	if(a[i] == zero)
		c = true;

	if (c == true)
		cout << "we find " << zero <<  " on index(es)";

	for(int i = 0; i < N; ++i) {
		if(a[i] == zero) {
			cout << " " << i + 1;
			c = true;
		}
	}

	cout << endl;

	if (c < 1) {
		cout << "we didnt find index " << endl;
		c = false;
	}

	zero = 0; // if i dont create it, i will take a bug on counting all of arrays
}
void CopyArrayToOtherArray(int a[N], int a_new[N]) {
	cout << "in new item we have this digits before" << endl << endl;
	for (int i = 0; i < N; ++i) {
		cout << a_new[i] << " ";
	}

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
	for(int i = 0; i < N; ++i)
		zero += a[i];
	cout << zero << endl;
	zero = 0; // for reset result
}

void MinMax(int a_new[N]) {
	for(int i = 0; i < N; ++i)
		cout << a_new[i] << " ";
	cout << endl;
}

void Reset(int a[N]){
	for (int i = 0; i < N; ++i)
		a[i] = 0;
	cout << "reset successful" << endl;
}

void main() {
	int a[N] = {0}, a_new[N] = {0};
	char chose;
	int zero = 0;
	bool c = 0;
	
	do{
	//system("cls"); //clear my old gui
	gui();
	cin >> chose;

	system("cls"); //clear my old gui
	
	switch (chose){
		case 'r':
			input(a);
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
			LogicalSearchItem(a, c, zero);
			system("pause");
			system("cls");
			continue;
		case '4':
			IndexedSearchItem(a, zero, c);
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
			MinMax(a_new);
			system("pause");
			system("cls");
			continue;
		case '8':
			continue;
		case 'x':
			Reset(a);
			system("pause");
			system("cls");
			continue;
	}
	}while(chose != '8');	

	system("pause");
}