#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Probleme {
    string nume_problema;
    string specialitate_problema;
    int durata;
    int prioritate;
    int ora_sosire;
};
struct Doctor
{
    string name;
    int available_hours = 8; 
    vector<string> assigned_problems;
	int nr_specializari;
    int ora_actuala = 9;
};
int main()
{
    ifstream inFile("input2.txt");

    int no_problems, no_doctors;
    string nume_specializare;

    inFile >> no_problems;

    vector<Probleme> probleme(no_problems);
    priority_queue<pair<int, int>> prioritate_queue;

	std::map<std::string, vector<string>> specialitate_map;

    for (int i = 0; i < no_problems; i++) {
        inFile >> probleme[i].nume_problema >> probleme[i].specialitate_problema >> probleme[i].ora_sosire >> probleme[i].durata >> probleme[i].prioritate ;
        prioritate_queue.push({ probleme[i].prioritate, i });
    }

    inFile >> no_doctors;
    vector<Doctor> doctors(no_doctors);
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> doctors[i].name;
        inFile >> doctors[i].nr_specializari;
		for (int j = 0; j < doctors[i].nr_specializari; j++)
		{
			inFile >> nume_specializare;
			specialitate_map[doctors[i].name].push_back(nume_specializare);
		}

	}


    while (!prioritate_queue.empty()) {
        auto [prioritate, index] = prioritate_queue.top(); 
        prioritate_queue.pop();

        const string& specialitate = probleme[index].specialitate_problema;
        bool problema_alocata = false;

        for (auto& doctor : doctors) {

            if (find(specialitate_map[doctor.name].begin(), specialitate_map[doctor.name].end(), specialitate) != specialitate_map[doctor.name].end()) {

                if (doctor.available_hours >= probleme[index].durata) {
  
                    doctor.assigned_problems.push_back(probleme[index].nume_problema);
                    doctor.available_hours -= probleme[index].durata;
                    problema_alocata = true;
                    break;
                }
            }
        }

        if (!problema_alocata) {
            cout << "Problema " << probleme[index].nume_problema << " nu a putut fi alocata.\n";
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


