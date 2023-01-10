#include <iostream>
#include <fstream>
#include <cstring>

struct Student
{
    int fn;
    double grade;
    char name[100];
};


struct Students_array
{
    Student *arr;
    size_t size;
};

void addStudent(Students_array& students, Student s)
{
    Student *newArray = new Student[students.size+1];

    for(int i = 0; i < students.size; ++i)
    {
        newArray[i] = students.arr[i];
    }

    newArray[students.size] = s;
    ++students.size;

    delete []students.arr;//може да е nullptr, но това не е проблем
    students.arr = newArray;
}

Student inputStudent(std::istream &in)
{
    Student s;

    in >> s.fn;

    in.get();

    in.getline(s.name,100);

    in >> s.grade;

    return s;
}

void outputStudent(Student s)
{
    std::cout << "fn:" << s.fn << std::endl;

    std::cout << "name:" << s.name << std::endl;

    std::cout << "grade:" << s.grade << std::endl;
    
}

void outputStudents(Students_array ss, std::ostream &out)
{

    out << ss.size << std::endl;
    for (int i = 0; i < ss.size; ++i)
    {
        out << ss.arr[i].fn << std::endl;

        out << ss.arr[i].name << std::endl;

        out << ss.arr[i].grade << std::endl;
    }
}

void inputStudents(Students_array &students, const char *fname)
{
    std::ifstream myfile (fname);

    Student s;
    int nStudents;

    myfile >> nStudents;

    for (int i = 0; i < nStudents; ++i)
    {
        s=inputStudent(myfile);
        addStudent(students,s);
    }
}

void listStudentsFromFile (const char *fname)
{

    Students_array arr = {nullptr,0};
    inputStudents(arr,fname);
    outputStudents(arr,std::cout);
}

void addStudentToFile(const char *fname)
{
    Students_array arr = {nullptr,0};
    inputStudents(arr,fname);  

    Student newStudent = inputStudent(std::cin);
    addStudent(arr,newStudent);

    std::ofstream myfile (fname);
    outputStudents(arr,myfile);


}

int main(int argc, char* argv[]) 
//argv[0]->file name
{

    if (argc != 3)
    {
        std::cerr << "Invalide number of agruments. Usage: \n"
                     "sdb command file. \n";
        return 1;
    }

    if (strcmp(argv[1],"list") == 0)
    {
        listStudentsFromFile(argv[2]);   
    }

    if (strcmp(argv[1],"add") == 0)
    {
        addStudentToFile(argv[2]);   
    }
}