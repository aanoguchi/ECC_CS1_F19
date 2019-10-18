// Lab 4, 5.26.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
  // make ofstream to make a file
	ofstream html;

	// open a output file
	html.open("html.html");
	string name,
		   yourself;

	//writing input into the file
	cout << "Enter your name: ";
	getline(cin, name);
	html << name << endl;
	cout << "Describe yourself: ";
	getline(cin, yourself);
	html << yourself << endl;

	//display the file
	if (html) {
		
		html << "<html>" << endl;
		cout << "<head>" << endl;
		cout << "</head>" << endl;
		cout << "<body>" << endl;
		cout << "\t<center>" << endl;
		cout << "\t\t<h1>" << name << "<h1>"
			<< endl;
		cout << "\t</center>" << endl;
		cout << "\t<hr />" << endl;
		cout << "\t" << yourself
			<< endl;
		cout << "\t<h1>" << endl;
		cout << "<body>" << endl;
		cout << "</head>" << endl;
	}
	//show an error if the file could not be opened
	else {
		cout << "ERROR OPENING FILE";
	}
	// close the file
	html.close();

	return 0;
}

