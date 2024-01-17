#include <iostream>
#include <fstream>

struct Student
{
    int fn;
    char name[50];
    double grade;
};


void createFile()
{
    Student students[] = {{100,"Kalin",5},
                          {200,"Borislav",6},
                          {300,"Victorya",6.5}};

    std::ofstream out ("students.bin",std::ios::binary);            

    out.write((char*)students,sizeof(Student)); 
    out.write((char*)(students+1),sizeof(Student)); 
    out.write((char*)(students+2),sizeof(Student)); 
}

void readRecord(int n)
{
   Student test;
   std::ifstream in ("students.bin",std::ios::binary);

   in.seekg(n*sizeof(Student));
   in.read((char*)&test,sizeof(Student));
   std::cout << test.name << std::endl;
}

void changeRecord(int n, const Student& s)
{

  std::fstream out ("students.bin",std::ios::binary | std::ios::in | std::ios::out);            

  out.seekp(sizeof(Student));
  out.write((char*)&s,sizeof(Student));

  Student test;
  out.seekg(2*sizeof(Student));
  out.read((char*)&test,sizeof(Student));
  std::cout << test.name << std::endl;  

}

int main()
{

    createFile();

    Student test = {400,"Borislava",6};
    //changeRecord(1,test);

  

}