// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

class Datar
{
public:
	int den;
	char* mec;
	int god;

	Datar(int newDen, const char* newMec, int newGod) : den{ newDen }, mec{ newMec ? new char[strlen(newMec) + 1] : nullptr }, god{ newGod }
	{
		if (mec)
		{
			strcpy_s(mec, strlen(newMec) + 1, newMec);
		}
	}

	Datar() :Datar(1, "Январь", 2000) {}

	int getD() { return den; }
	void setD(int newDen) { den = newDen; }

	char* getM() { return mec; }
	void setM(char* newMec) { mec = newMec; }

	int getG() { return god; }
	void setG(int newGod) { god = newGod; }

	void printDr() {
		if (den) {
			cout << "Дата рождения: " << den << "." << mec << "." << god << "\n";
		}
		else
			cout << "Пусто\n";
	}

	~Datar() {}
};


class Yrok
{
	uint32_t vrem;
	char* nazv;
	char* prepod;
	uint32_t yroven;
public:
	Yrok(uint32_t newVrem, const char* newNazv, const char* newPrepod, uint32_t newYroven) : vrem{ newVrem },
		nazv{ newNazv ? new char[strlen(newNazv) + 1] : nullptr }, prepod{ newPrepod ? new char[strlen(newPrepod) + 1] : nullptr },
		yroven{ newYroven }
	{
		if (nazv)
		{
			strcpy_s(nazv, strlen(newNazv) + 1, newNazv);
		}
		if (prepod)
		{
			strcpy_s(prepod, strlen(newPrepod) + 1, newPrepod);
		}
	}

	Yrok() : Yrok{ 00, "Название", "Преподаватель", 0 } {}

	Yrok(const Yrok& cop) : vrem{ cop.vrem }, nazv{ cop.nazv ? new char[strlen(cop.nazv) + 1] : nullptr },
		prepod{ cop.prepod ? new char[strlen(cop.prepod) + 1] : nullptr }, yroven{ cop.yroven }
	{
		if (nazv)
		{
			strcpy_s(nazv, strlen(cop.nazv) + 1, cop.nazv);
		}
		if (prepod)
		{
			strcpy_s(prepod, strlen(cop.prepod) + 1, cop.prepod);
		}
	}

	void setVrem(uint32_t newVrem) { vrem = newVrem; }
	uint32_t getTime() const { return vrem; }

	void setNazv(char* newNazv)
	{
		if (nazv)
		{
			nazv = new char[strlen(newNazv) + 1];
			strcpy_s(nazv, strlen(newNazv) + 1, newNazv);
		}

	}
	char* getNazv() const { return nazv; }

	void setPrepod(char* newPrepod)
	{
		if (prepod)
		{
			prepod = new char[strlen(newPrepod) + 1];
			strcpy_s(prepod, strlen(newPrepod) + 1, newPrepod);
		}

	}
	char* getPrepod() const { return prepod; }

	void setYroven(uint32_t newYroven) { yroven = newYroven; }
	uint32_t getYroven() const { return yroven; }

	void print() const
	{
			cout << "\nВремя: " << vrem << "\nНазвание: " <<
				nazv << "\nПреподаватель: " << prepod << "\nУровень: " << yroven << endl;
	}

	~Yrok() { delete[] nazv; delete[] prepod; }

};

class student
{
	char* name;
	char* fam;
	Datar dr;
	uint32_t* marks;
	uint32_t colichMarks;
	Yrok* yrok;
	uint32_t colichYrok;

public:
	student(const char* newName, const char* newFam, Datar newDr, uint32_t newColichMarks, uint32_t newColichYrok) :
		name{ newName ? new char[strlen(newName) + 1] : nullptr }, fam{ newFam ? new char[strlen(newFam) + 1] : nullptr }, dr{ newDr },
		marks{ new uint32_t[newColichMarks] {} }, colichMarks{ newColichMarks }, yrok{ new Yrok[newColichYrok] {} }, colichYrok{ newColichYrok }
	{
		if (name)
		{
			strcpy_s(name, strlen(newName) + 1, newName);
		}
		if (fam)
		{
			strcpy_s(fam, strlen(newFam) + 1, newFam);
		}
	}

	student() : student("Имя", "Фамилия", { 1, "Январь", 1900 }, 3, 2) {}

	student(const student& cop) : name{ cop.name ? new char[strlen(cop.name) + 1] : nullptr }, fam{ cop.fam ? new char[strlen(cop.fam) + 1] : nullptr },
		dr{ cop.dr }, marks{ cop.marks }, yrok{ cop.yrok } {}

	void setName(char* newName)
	{
		name = new char[strlen(newName) + 1];
		strcpy_s(name, strlen(newName) + 1, newName);

	}
	char* getName() const { return name; }

	void setFam(char* newFam)
	{
		fam = new char[strlen(newFam) + 1];
		strcpy_s(fam, strlen(newFam) + 1, newFam);

	}
	char* getFam() const { return fam; }

	void randomize() const
	{
		for (int i{ 0 }; i < colichMarks; ++i)
		{
			marks[i] = rand() % (5 - 2) + 2;
		}
	}

	void print() const
	{
		cout << "\nИмя: " << name << "\nФамилия: " <<
			fam << "\nДень рождения: " << dr.den << "." << dr.mec << "." << dr.god << "\nОценки: ";
		for (int i{ 0 }; i < colichMarks; ++i)
		{
			cout << marks[i] << ' ';
		}
		cout << "\n\nУроки:\n";
		for (int i{ 0 }; i < colichYrok; ++i)
		{
			yrok->print(); 
		}
	}
	~student() { delete[] name; delete[] fam; delete[] marks; delete[] yrok; }
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	student st;
	st.randomize();
	st.print();

	/*Yrok yr(12, "Название", "Преподаватель", 7);
	yr.print();*/
}
