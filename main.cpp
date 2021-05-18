#include <iostream>
#include <fstream>
#include<string>
#include "dinamicArray.h"
using namespace std;






typedef struct p {
	string surename, name, club;
	int score, birthYear;

	
}Player;


ostream& operator<<(ostream& out, Player& p) {
	return out << "Name: " << p.name << " Surename: " << p.surename << " Club: " << p.club << " Score: " << p.score << " Birth Year: " << p.birthYear;
}

bool operator >(Player& a, Player& b) {
	return a.score > b.score;
}




void split(string s, char c, string *dest) {
	string temp = "";
	int j = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == c || s[i] == '\0') {
			dest[j++] = temp;
			temp = "";
			continue;
		}
		temp += s[i];
	}
}

// a)
bool load(DinamicArray<Player>* dest, string filename = "Punteggi.txt"){
	ifstream file;
	file.open(filename);
	if (file.fail())return 0;

	string s = "";
	string* reader = new string[5];
	while (!file.eof()) {
		getline(file, s);
		split(s, ';', reader);
		Player* p = new Player;
		p->surename = reader[0];
		p->name = reader[1];
		p->club = reader[2];
		p->score = stoi(reader[3]);
		p->birthYear = stoi(reader[4]);
		
		dest->insert(*p);	
	}


	delete[] reader;
}


// b)
void print(DinamicArray<Player>* list, bool crescent) {
	list->sort();
	list->print(crescent);
}


// c)
void print_from_surename(DinamicArray<Player>* list, string surename) {
	int score = 0;
	bool found = 0;
	for (int i = 0; i < list->size(); i++) {
		if (list->operator[](i).surename == surename) {
			score = list->operator[](i).score;
			cout<< list->operator[](i) <<endl;
			found = 1;
			break;
		}
	}
	if (!found) return;
	for (int i = 0; i < list->size(); i++) {
		if (list->operator[](i).score == score) {
			cout << list->operator[](i) << endl;
		}
	}
}



int main() {
	DinamicArray<Player> list(10);

	load(&list);
	print(&list, 0);
	return 0;
}
