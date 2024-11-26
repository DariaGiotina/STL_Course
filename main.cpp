#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Probleme {
    string nume_problema;
    string specialitate_problema;
    int ore_problema;
};
struct Doctor
{
    string name;
    string specialty;
    int ore = 8;
};
int main()
{
    ifstream inFile("input4_bonus.txt");

    int no_problems, no_doctors;

    inFile >> no_problems;

    vector<Probleme> probleme(no_problems);

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> probleme[i].nume_problema;
        inFile >> probleme[i].specialitate_problema;
        inFile >> probleme[i].ore_problema;
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

            find_if(doctors.begin(), doctors.end(), [&](Doctor& doctor) {
                if (doctor.specialty == probleme[i].specialitate_problema && doctor.name != "taken" && doctor.ore >= probleme[i].ore_problema)
                {
                    cout << doctor.name << " " << probleme[i].nume_problema << endl;
                    doctor.name = "taken";
                    doctor.ore -= probleme[i].ore_problema;
                    accepted = true;
                    return true;
                }
                return false;
                });
            if (accepted)
            {
                break;
            }
        }

    }

    inFile.close();

    return 0;
}


//if (probleme[i].specialitate_problema == doctors[j].specialty && doctors[j].name != "taken")
//{
//
//    cout << doctors[j].name << " " << probleme[i].nume_problema << endl;
//    doctors[j].name = "taken";
//}