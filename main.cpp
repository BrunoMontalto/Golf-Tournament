#include <iostream>
#include <fstream>
#include<string>
#include "dinamicArray.h"
using namespace std;

typedef struct p {
	string surename, name, club;
	int birthYear;
	float score;
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
		p->score = atof(reader[3].c_str());
		p->birthYear = stoi(reader[4]);
		
		dest->insert(*p);	
	}


	delete[] reader;
	return 1;
}


// b)
void print(DinamicArray<Player>* list, bool crescent) {
	list->sort();
	list->print(crescent);
}


// c)
void print_from_surename(DinamicArray<Player>* list, string surename) {
	float score = 0;
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
		if (list->operator[](i).score == score && list->operator[](i).surename != surename) {
			cout << list->operator[](i) << endl;
		}
	}
}


// d)
void delete_from_score(float score, DinamicArray<Player>* list) {
	for (int i = list->size()-1; i >= 0;i--) {
		if (list->operator[](i).score == score) {
			list->pop(i);
		}
	}
}


int main() {
	DinamicArray<Player> list(10);
	if (!load(&list)) {
		cout << "File not found" << endl;
		return 1;
	};
	cout << "--Data loaded--" << endl;
	print(&list, 1);
	cout << endl;

	string sn;
	cout << "Insert surename: ";
	cin >> sn;
	print_from_surename(&list, sn);

	float score;
	cout << "\nDelete users with score?: ";
	cin >> score;
	delete_from_score(score, &list);
	print(&list, 1);

	return 0;
}
