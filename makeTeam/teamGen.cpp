#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

std::vector<string> v;

void swap (int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void randomize()
{
    srand (time(NULL));
    for(int i = v.size()-1; i>0; i--)
    {
        int j = rand()%(i+1);
        swap(v.at(i), v.at(j));
    }
}
char makeTeam()
{
	char res;
	ifstream infile;
	string myStr;

	infile.open("input.csv",std::ifstream::in);

	if(infile.is_open()) 
	{
		while(getline(infile, myStr))
			v.push_back(myStr);

		infile.close();
		
	}
	else {
		cout << "Unknown Problem Detected while opening file\n";
	}

	cout << "Are you sure to generate team ? [y/n] : ";
	cin >> res;
	return res;
}

void writeOutput()
{
	int cnt=1, c=0, teamNo=1;
	ofstream outfile;
	outfile.open("output.csv",std::ofstream::out);

	if(outfile.is_open()) 
	{
		vector<string>::iterator it;
		for(it = v.begin(); it != v.end(); it++)
		{
			if(cnt % 2 != 0) {
				outfile << "TEAM " << teamNo << " :"<< endl;
				teamNo++;
			}
			outfile << *it << endl;
			
			if(cnt %2 == 0) {
				outfile << endl;
			}
			cnt++;
		}
		return;
	}

	cout << "Unknown Problem Detected while opening file\n";
	return;
}

void showTeams()
{
	int cnt=1;
	ifstream infile;
	string myStr;

	infile.open("output.csv",std::ifstream::in);

	if(infile.is_open()) 
	{
		while(getline(infile, myStr)) {
			cout << myStr << endl;
		}
		infile.close();
	}
	else {
		cout << "Unknown Problem Detected while opening file\n";
	}
}

int main(int argc, char const *argv[])
{
	char ch;
	string com;
	string t;
	cout << "Type 'start-idc' to Generate Team\n\n >> ";
	cin >> com;

	if(com != "start-idc") {
		return -1;
	}

	if(makeTeam() == 'y')
	{
		randomize();
		writeOutput();
		cout << "Do you want to display the teams here? [y/n] ";
		cin >> ch;

		if(ch!='y') {
			cout << "\nPlease check 'output.csv' file\n";
			return 0;
		}

		cout << "Type 'show-teams' to Generate Team\n\n >> ";
		cin >> t;
		if(t == "show-teams") {
			cout << "\n";
			showTeams();
		}

		cout << "\nPlease check 'output.csv' file\n";
	}
	return 0;
}