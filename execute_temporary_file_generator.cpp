#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
//ifstream inFile;
void replaceAll(string &str, const string &from, const string &to)
{
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}
int main()
{
	/*
	inFile.open("cpu_exe.temp");
	if (!inFile)
	{
		cerr << "Unable to open file datafile.txt" << endl;
		exit(1); // call system to stop
	}
	*/
	ifstream ifs("cpu_exe.temp");
	string content((istreambuf_iterator<char>(ifs)),
				   (istreambuf_iterator<char>()));

	/*replaceAll(content, "MEM_ADDR=", "[92mMEM_ADDR=[0m");
	system("echo [92mGreen[0m");
	cout << content << endl;*/
	string targ1 = "MEM_ADDR=";
	size_t prev = 0;
	size_t start_pos = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	while ((start_pos = content.find(targ1, start_pos)) != string::npos)
	{
		//str.replace(start_pos, from.length(), to);
		string tmp = content.substr(prev, start_pos);
		cout << tmp;
		prev = start_pos;
		start_pos += targ1.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
		SetConsoleTextAttribute(hConsole, 10);
		cout << targ1;
		SetConsoleTextAttribute(hConsole, 15);
	}
	return 0;
}
