#include <iostream>
#include <cstring>
using namespace std;

class Student {
    private:
        char* name;
        int fNum;
        double grade;

    public:
        Student(){
            name = nullptr;
            fNum = 0;
            grade = 0.0;
        }

        Student(const char* n, int fn, double g){
            name = new char[strlen(n) + 1];
            strcpy(name, n);
            fNum = fn;
            grade = g;
        }

        Student(const Student& other){
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            fNum = other.fNum;
            grade = other.grade;
        }

        Student& operator=(const Student& other){
            if(this != &other){
                delete[] name;
                name = new char[strlen(other.name)+ 1];
                strcpy(name, other.name);
                fNum = other.fNum;
                grade = other.grade;
            }
            return *this;
        }

        ~Student(){
            delete[] name;
        }

        const char* getName() const {return name;}
        int getFacultyNumber() const {return fNum;}
        double getGrade() const{return grade;}
        void setGrade(double g){grade = g;}

        void print()const{
            cout << "Name: " << name << ", Faculty number: " << fNum << ", Grade: " << grade << endl;
        }
};

class StudentList{
    private:
        Student *students;
        int size;
        int capacity;

    public:
        StudentList(int cap){
            capacity = cap;
            size = 0;
            students = new Student[capacity];
        }

        void addStudent(const Student& s){
            if(size >= capacity){
                cout << "The list of students is full! You can't add more students!\n";
                return;
            }
            students[size++] = s;
        }

        Student& getBestStudent(){
            int bestIndex = 0;
            for(int i = 0; i < size; i++){
                if(students[i].getGrade() > students[bestIndex].getGrade()){
                    bestIndex = i;
                }
            }
            return students[bestIndex];
        }

        const Student& getStudentByIndex(int i)const{
            if(i < 0 || i >= size){
                cout << "Your index is invalid!\n";
                exit(1);
            }
            return students[i];
        }

        void swapStudents(int i, int j){
            if(i < 0 || j < 0 || i >= size || j >= size){
                cout << "Your indexes are invalid for swap!\n";
                return;
            }

            Student temp;
            temp = students[i];
            students[i] = students[j];
            students[j] = temp;
        }

        void printAllStudents()const{
            for(int i = 0; i < size; i++){
                cout << i + 1 << ". ";
                students[i].print();
            }
        }

        ~StudentList(){
            delete[] students;
        }
};

int main()
{
    StudentList sList(5);

    sList.addStudent(Student("Krasimir Gushmakov", 121223008, 5.29));
    sList.addStudent(Student("Ivan Vulev", 121224142, 4.21));
    sList.addStudent(Student("Petar Dermenjiev", 121224078, 5.67));
    sList.addStudent(Student("Martin Rakov", 121225004, 3.45));
    sList.addStudent(Student("Neno Cherniradev", 121224132, 4.81));

    cout << "All students on the list:\n";
    sList.printAllStudents();

    Student& best = sList.getBestStudent();
    cout << "The best student before update is:\n";
    best.print();

    if(best.getGrade() < 5.5){
        best.setGrade(best.getGrade() + 0.5);
    }else{
        best.setGrade(6.0);
    }

    cout << "The best student after update is:\n";
    best.print();

    const Student& index = sList.getStudentByIndex(1);
    cout << "The student with index you chose is:\n";
    index.print();

    sList.swapStudents(2, 4);
    cout << "The students list after the swap is:\n";
    sList.printAllStudents();


    return 0;
}
