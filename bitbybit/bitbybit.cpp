#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void set(int* reg, int i)
{
	reg[i] = 1;
}

void clear(int* reg, int i)
{
	reg[i] = 0;
}

void lor(int* reg, int i, int j)
{
	if(reg[i] == 1 || reg[j] == 1) {
        reg[i] = 1;
    }
    else if (reg[i] == 0 && reg[j] == 0) {
        reg[i] = 0;
    }
    else {
        reg[i] = -1;
    }
}

void land(int* reg, int i, int j)
{
    if(reg[i] == 1 && reg[j] == 1) {
        reg[i] = 1;
    }
    else if(reg[i] == 0 || reg[j] == 0) {
        reg[i] = 0;
    }
    else {
        reg[i] = -1;
    }
}

int main()
{
	int CISCregister[32] = {};
	int* preg = CISCregister;

	int instructions = 0;

	cin >> instructions;
	cin.ignore(100000, '\n');
	while (instructions != 0)
	{
		// Assigning regitser to -1, repesenting unknown state.
		for (int i = 0; i <= 31; i++) {
			CISCregister[i] = -1;
		}

		for (int k = 0; k < instructions; k++)
		{
			string input;
			vector<string> tokens;
			if (getline(cin, input)) {
				string buf;
				stringstream ss(input);
				while (ss >> buf)
					tokens.push_back(buf);

				if (tokens[0] == "SET")
				{
					set(preg, stoi(tokens[1]));
				}
				else if (tokens[0] == "CLEAR")
				{
					clear(preg, stoi(tokens[1]));
				}
				else if (tokens[0] == "OR")
				{
					lor(preg, stoi(tokens[1]), stoi(tokens[2]));
				}
				else if (tokens[0] == "AND")
				{
					land(preg, stoi(tokens[1]), stoi(tokens[2]));
				}
			}
		}
		for (int i = 31; i >= 0; i--) {
			if (CISCregister[i] == -1)
				cout << "?";
			else
				cout << CISCregister[i];
		}
		cout << endl;

		cin >> instructions;
		cin.ignore(100000, '\n');
	}
	return 0;
}