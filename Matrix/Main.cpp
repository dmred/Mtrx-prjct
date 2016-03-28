// Matrix.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"


#define N 3
#define M 5
int main()
{
	string name_of_file;
	char answer[4];
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ����� � ��������" << endl;
	int m, n;
	cin >> m;
	cin >> n;
	cout << "������� ��� �����" << "\n";
	cin >> name_of_file;
	matrix _matrix(m, n);
	_matrix.get_from_file(name_of_file);
	cout << "������� �� ����� " <<name_of_file<< " :\n";
	_matrix.print_matrix();
	cout << "--------------------------------------\n";
	cout << "������� ����� ��� ��������� ��������� ��������" << "\n";
	int time;
	cin >> time;
	matrix rand_matrix(m, n, time);
	cout << "��������� �������:" << "\n";
	rand_matrix.print_matrix();
	cout << "------------------------------------------------\n";
	cout << "������ ������� ��������� ������� � ������� �� �����?(yes|no)" << "\n";
	cin >> answer;
	if (strcmp("yes", answer) == 0)
	{
		matrix sum_matrix(m, n);
		sum_matrix = _matrix + rand_matrix;
		sum_matrix.print_matrix();
	}
	cout << "------------------------------------------------\n";
	cout << "������ �������� ��������� ������� �� ������� �� �����?(yes|no)" << "\n";
	cin >> answer;
	if (strcmp("yes", answer) == 0)
	{
		matrix mult_matrix(m, n);
		mult_matrix = _matrix * rand_matrix;
		mult_matrix.print_matrix();
	}
	cout << "------------------------------------------------\n";
	cout << "����� ������ ������� �� ������� �� �����?" << "\n";
	int k;
	cin >> k;
	_matrix.get_line(k);
	cout << "\n------------------------------------------------\n";
	cout << "\n";
	cout << "���������� �������� � �����: " << "\n";
	cout << " " << _matrix.get_num_cols() << " ����� � ";
	cout << " " << _matrix.get_num_rows() <<" ��������" << endl;
	cout << "\n------------------------------------------------\n";
	system("pause");
    return 0;
}

