#include <iostream>
using namespace std;

class Student {
    private:
        static int studentTotal;
    public:
        string name;
        string status;
        int age;

        Student(string pName, int pAge) {
            name = pName;
            age = pAge;
            status = "New Student";
            ++studentTotal; // mengetahui berapa objek mahasiswa
            cout << name << " Created " << " Status " << status << endl;
            cout << endl;
        }

        ~Student(){
            cout << name << " Deleted " << endl;
            --studentTotal;
            cout << endl;
        }

        static int getStudentTotal(){
            return studentTotal;
        } // static artinya bisa mengakses seluruh objek tanpa menggunakan objek

        static void setStudentTotal(int pStudentTotal){
            studentTotal = pStudentTotal;
        }
};

int Student::studentTotal = 0; // memberikan nilai awal melalui static member

int main() {
    cout << "Total student: " << 
    Student::getStudentTotal() << endl;

    Student student1("Budi", 20);
    Student student2("Andi", 21);

    Student::setStudentTotal(10);

    cout << "Total student: " << 
    Student::getStudentTotal() << endl;
    {
        Student student3("Joko", 22);
        Student student4("Joni", 23);
        cout << "Total student: " << 
        Student::getStudentTotal() << endl;
    } // namanya bracket, didalam bracket dieksekusi dahulu
    cout << "Total student: " << 
    Student::getStudentTotal() << endl;
    return 0;
}