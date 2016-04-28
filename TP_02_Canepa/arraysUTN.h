
struct
{
    char name[51];
    int age;
    int id;
    int isEmpty;

}typedef person;

int init(person* pPers, int length);
int addPeople(person* pPers, int length);
int removePerson(person* pPers, int length, int id);
int printPerson(person* pPers, int length);
int sortPersonByName(person* pPers, int length);
int printAgeGraph(person* pPers, int length);

