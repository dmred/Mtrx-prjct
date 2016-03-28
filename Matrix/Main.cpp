// Matrix.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.


#include"stdafx.h"


#define N 3
#define M 5
int main()
{
	string name_of_file;
	char answer[4];
	setlocale(LC_ALL, "Russian");
	cout << "Ââåäèòå êîëè÷åñòâî ñòðîê è ñòîëáöîâ" << endl;
	int m, n;
	cin >> m;
	cin >> n;
	cout << "Ââåäèòå èìÿ ôàéëà" << "\n";
	cin >> name_of_file;
	matrix _matrix(m, n);
	_matrix.get_from_file(name_of_file);
	cout << "Ìàòðèöà èç ôàéëà " <<name_of_file<< " :\n";
	_matrix.print_matrix();
	cout << "--------------------------------------\n";
	cout << "Ââåäèòå ÷èñëî äëÿ ãåíåðàöèè ñëó÷àéíîé ìàòðòèöû" << "\n";
	int time;
	cin >> time;
	matrix rand_matrix(m, n, time);
	cout << "Ðàíäîìíàÿ ìàòðèöà:" << "\n";
	rand_matrix.print_matrix();
	cout << "------------------------------------------------\n";
	cout << "Õîòèòå ñëîæèòü ðàíäîìíóþ ìàòðèöó è ìàòðèöó èç ôàéëà?(yes|no)" << "\n";
	cin >> answer;
	if (strcmp("yes", answer) == 0)
	{
		matrix sum_matrix(m, n);
		sum_matrix = _matrix + rand_matrix;
		sum_matrix.print_matrix();
	}
	cout << "------------------------------------------------\n";
	cout << "Õîòèòå óìíîæèòü ðàíäîìíóþ ìàòðèöó íà ìàòðèöó èç ôàéëà?(yes|no)" << "\n";
	cin >> answer;
	if (strcmp("yes", answer) == 0)
	{
		matrix mult_matrix(m, n);
		mult_matrix = _matrix * rand_matrix;
		mult_matrix.print_matrix();
	}
	cout << "------------------------------------------------\n";
	cout << "Êàêóþ ñòðîêó âûâåñòè èç ìàòðèöû èç ôàéëà?" << "\n";
	int k;
	cin >> k;
	_matrix.get_line(k);
	cout << "\n------------------------------------------------\n";
	cout << "\n";
	cout << "Êîëè÷åñòâî ñòîëáöîâ è ñòðîê: " << "\n";
	cout << " " << _matrix.get_num_cols() << " ñòðîê è ";
	cout << " " << _matrix.get_num_rows() <<" ñòîëáöîâ" << endl;
	cout << "\n------------------------------------------------\n";
	system("pause");
    return 0;
}

