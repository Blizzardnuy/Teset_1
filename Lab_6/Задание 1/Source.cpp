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
    cout << "Введите количество студентов: ";
    cin >> studentCount;

    Student* group = new Student[studentCount];

    for (int i = 0; i < studentCount; ++i) {
        cout << "\nВведите данные для студента " << i + 1 << ":\n";

        cout << "Имя: ";
        cin >> group[i].firstName;

        cout << "Введите количество дисциплин: ";
        cin >> group[i].disciplineCount;

        group[i].disciplines = new Discipline[group[i].disciplineCount];

        for (int j = 0; j < group[i].disciplineCount; ++j) {
            cout << "Введите название дисциплины " << j + 1 << ": ";
            cin >> group[i].disciplines[j].name;
            cout << "Введите оценку: ";
            cin >> group[i].disciplines[j].grade;
        }
    }

    cout << "\nКоличество оценок от 4 до 5 в группе: " << countGrades(group, studentCount) << endl;

    for (int i = 0; i < studentCount; ++i) {
        delete[] group[i].disciplines;
    }
    delete[] group;
}

