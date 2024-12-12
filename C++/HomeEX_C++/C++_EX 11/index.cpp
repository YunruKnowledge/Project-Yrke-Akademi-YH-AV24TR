#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_PERSON 3

typedef struct Person
{
    unsigned int id;
    string name;
    unsigned int age;
} person_t;

void fillPersonArr(person_t *arr, int length);
void printPersonsArr(person_t *arr, int length);

void swap(person_t *a, person_t *b);
void sortPerson(person_t *arr, int size);

int main(void)
{
    person_t personArr[MAX_PERSON];

    fillPersonArr(personArr, MAX_PERSON);

    cout << "Unsorted: " << endl;
    printPersonsArr(personArr, MAX_PERSON);

    cout << "Sorted: " << endl;
    sortPerson(personArr, MAX_PERSON);
    printPersonsArr(personArr, MAX_PERSON);

    return 0;
}

void fillPersonArr(person_t *arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i].id = 10 - i;

        cout << "Enter person name: ";
        cin >> arr[i].name;

        do
        {
            cout << "Enter person age: ";
            cin >> arr[i].age;
            if (cin)
            {
                break;
            }
            else
            {
                cout << "Age mustn't contain any letters" << endl;
                cin.clear();
                cin.ignore();
            }
        } while (1);
    }
}

void printPersonsArr(person_t *arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << "Person [" << arr[i].id << "] name is: " << arr[i].name << " and is " << arr[i].age << " years old!" << endl;
    }
}

void swap(person_t *a, person_t *b)
{
    person_t temp = *a;
    *a = *b;
    *b = temp;
}

void sortPerson(person_t *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (arr[j].id >= arr[j + 1].id)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}