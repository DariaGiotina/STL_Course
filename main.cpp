#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Probleme {
    string nume_problema;
    string specialitate_problema;
};
struct Doctor
{
    string name;
    string specialty;
};
int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    
    inFile >> no_problems;

    vector<Probleme> probleme(no_problems);
	
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> probleme[i].nume_problema;
        inFile >> probleme[i].specialitate_problema;
    }

    inFile >> no_doctors;
    vector<Doctor> doctors(no_doctors);
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> doctors[i].name;
        inFile >> doctors[i].specialty;
    }

    for (int i = 0; i < no_problems; i++)
    {
        bool accepted = false;
        for (int j = 0; j < no_doctors; j++)
        {
            if (probleme[i].specialitate_problema == doctors[j].specialty)
            {
                accepted = true;
                break;
            }
        }
        if (accepted)
        {
            cout << probleme[i].nume_problema << " Acceptat" << '\n';
        }
        else
        {
            cout << probleme[i].nume_problema << " Respins" << '\n';
        }
    }

    inFile.close();

    return 0;
}