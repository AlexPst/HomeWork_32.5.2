// HomeWork_32.5.2.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <chrono>
#include <map>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

int get_current_year() {
	using namespace std::chrono;

	return static_cast<int>(year_month_day{ time_point_cast<days>(system_clock::now()) }.year());
}

struct CinInfo {

	string nameFilm;
	int year;
	string nameStudio;
	string director;
	map<std::string, std::string> actors;
	string heroes;


};


void InputCinToJSon() {
	
	bool isActiv = false;
	ofstream cinFile("C:/Users/Alex/source/repos/HomeWork_32.5.2/HomeWork_32.5.2/cinemas.json");
	string ans;
	vector<CinInfo>cinVec;
	do {
		CinInfo cinInfo;
		std::cout << "Please input name of film" << endl;
		getline(cin, cinInfo.nameFilm);
		std::cout << "Please input director of film" << endl;
		getline(cin, cinInfo.director);
		std::cout << "Please input main actor" << endl;
		string nameHero;
		string nameActor;
		getline(cin, nameActor);
		std::cout << "Please input main hero" << endl;
		getline(cin, nameHero);
		cinInfo.actors[nameActor] = nameHero;
		std::cout << "Please input studio" << endl;
		getline(cin, cinInfo.nameStudio);
		std::cout << "Please input year of production" << endl;
		cin >> cinInfo.year;
		if (cinInfo.year > get_current_year() || cinInfo.year <= 0)
		{
			std::cout << "Please correct date of production film" << endl;
			cin >> cinInfo.year;
		}

		std::cout << "Do you continued input info about film" << endl;
		std::cout << "Y or N" << endl;
		cin >> ans;
		if (ans == "y")
		{
			isActiv = true;
		}
		else
		{
			isActiv = false;
		}
		cin.ignore();
		cinVec.push_back(cinInfo);
	} while (isActiv);



	if (cinFile.is_open()) {
		json dict;
		for (int i = 0; i < cinVec.size(); ++i) {

			dict = json::object({
				{"nameFilm", cinVec[i].nameFilm},
				{"nameStudio", cinVec[i].nameStudio},
				{"release date", cinVec[i].year},
				{"director", cinVec[i].director},
				{"actor", cinVec[i].actors}
				});
			cinFile << dict;
		}
		
	}

}

void deserData(string path) 
{
	ifstream file(path);
	json j_complete = json::parse(file);
	cout << setw(4) << j_complete << endl;

}



int main()
{
	//InputCinToJSon();
	const std::string INPUT_PATH = "C:/Users/Alex/source/repos/HomeWork_32.5.2/HomeWork_32.5.2/cinemas.json";
	deserData(INPUT_PATH);
	
	return 0;
	
}
