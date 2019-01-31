#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( )
{
	char *buf;
	string str1 = "abababab";
	string str2 = "wjwjwjwjwjwj";
	string str3 = "vivivivivivivivi";

	int size1 = (str1.size());
	int size2 = (str2.size());
	int size3 = (str3.size());

	ofstream output ("output.txt", ios::out | ios::binary);
	if (!output)
	{
		cout << "can't open file" << endl;
		exit(1);
	}

	output.write(reinterpret_cast<char *>(&size1), sizeof(int));
	output.write(str1.c_str(), size1);

	output.write(reinterpret_cast<char *>(&size2), sizeof(int));
	output.write(str2.c_str(), size2);

	output.write(reinterpret_cast<char *>(&size3), sizeof(int));
	output.write(str3.c_str(), size3);

	str1 = str2 = str3 = "";
	size1 = size2 = size3 = 0;

	output.flush();
	output.close();
	//=======================================================================
	ifstream input("output.txt", ios::in | ios::binary);
	if (!output)
	{
		cout << "can't open file" << endl;
		exit(1);
	}

	input.read(reinterpret_cast<char *>(&size1), sizeof(int));
	buf = new char[size1];
	input.read( buf, size1);
	str1 = "";
	str1.append(buf, size1);

	input.read(reinterpret_cast<char *>(&size2), sizeof(int));
	buf = new char[size2];
	input.read(buf, size2);
	str2 = "";
	str2.append(buf, size2);

	input.read(reinterpret_cast<char *>(&size3), sizeof(int));
	buf = new char[size3];
	input.read(buf, size3);
	str3 = "";
	str3.append(buf, size3);

	cout << str1 << endl << str2 << endl << str3 << endl << endl;

	return 0;
}
