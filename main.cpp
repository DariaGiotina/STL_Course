#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Probleme {
    string nume_problema;
    string specialitate_problema;
    int durata;
};
struct Doctor
{
    string name;
    string specialitate;
    int available_hours = 8; 
    vector<string> assigned_problems;
};
int main()
{
    ifstream inFile("input4_bonus.txt");

    int no_problems, no_doctors;

    inFile >> no_problems;

    vector<Probleme> probleme(no_problems);

    for (int i = 0; i < no_problems; i++) {
        inFile >> probleme[i].nume_problema >> probleme[i].specialitate_problema >> probleme[i].durata;
    }

    inFile >> no_doctors;
    vector<Doctor> doctors(no_doctors);
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> doctors[i].name;
        inFile >> doctors[i].specialitate;
    }


    for (const auto& problem : probleme) {
        for (auto& doctor : doctors) {
            if (doctor.specialitate == problem.specialitate_problema && doctor.available_hours >= problem.durata) {
                doctor.assigned_problems.push_back(problem.nume_problema);
                doctor.available_hours -= problem.durata;
                break; 
            }
        }
    }

    for (const auto& doctor : doctors) {
        cout << doctor.name << " " << doctor.assigned_problems.size();
        for (const auto& problem_name : doctor.assigned_problems) {
            cout << " " << problem_name;
        }
        cout << endl;
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