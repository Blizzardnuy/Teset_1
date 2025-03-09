#include <iostream>
#include <string>
using namespace std;

struct Discipline {
    string name;
    short grade;
};

struct Student {
    string firstName;
    Discipline* disciplines;
    int disciplineCount;
};

int countGrades(Student* group, int studentCount) {
    int counter = 0;
    for (int i = 0; i < studentCount; ++i) {
        for (int j = 0; j < group[i].disciplineCount; ++j) {
            if (group[i].disciplines[j].grade == 4 || group[i].disciplines[j].grade == 5)
                ++counter;
        }
    }
    return counter;
}

int main() {
    setlocale(0, "");
    int studentCount;
    cout << "������� ���������� ���������: ";
    cin >> studentCount;

    Student* group = new Student[studentCount];

    for (int i = 0; i < studentCount; ++i) {
        cout << "\n������� ������ ��� �������� " << i + 1 << ":\n";

        cout << "���: ";
        cin >> group[i].firstName;

        cout << "������� ���������� ���������: ";
        cin >> group[i].disciplineCount;

        group[i].disciplines = new Discipline[group[i].disciplineCount];

        for (int j = 0; j < group[i].disciplineCount; ++j) {
            cout << "������� �������� ���������� " << j + 1 << ": ";
            cin >> group[i].disciplines[j].name;
            cout << "������� ������: ";
            cin >> group[i].disciplines[j].grade;
        }
    }

    cout << "\n���������� ������ �� 4 �� 5 � ������: " << countGrades(group, studentCount) << endl;

    for (int i = 0; i < studentCount; ++i) {
        delete[] group[i].disciplines;
    }
    delete[] group;
}

