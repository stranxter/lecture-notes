#include <iostream>
#include <cstring>

char* mystrcat (const char *s1, const char *s2)
{
    //char result[strlen(s1)+strlen(s2)+1];
    char* result = new char [strlen(s1)+strlen(s2)+1];

    strcpy (result,s1);
    strcat (result,s2);

    return result;
}

struct myarray
{
    int *p;
    size_t size;
};

myarray intcat (myarray a1, myarray a2)
{
    /*  a = {1,2,2,1,2,1}, 
        b = {4,5,4,5,4,5,7} 
    */
   
   myarray result;
   result.size = a1.size + a2.size;
   result.p = new int [result.size];

   for (size_t i = 0; i < a1.size; i++)
   {
       result.p[i] = a1.p[i];
   }
   for (size_t i = 0; i < a2.size; i++)
   {
       result.p[i+a1.size] = a2.p[i];
   }

   return result;

}

void printarray (myarray arr)
{
    for (size_t i = 0; i < arr.size; i++)
    {
        std::cout << arr.p[i] << " ";
    }

    std::cout << "\n";
}

int main ()
{   

    int x = 20;

    char s1[] = "Kalin",
         s2[] = "Georgiev";
    
    char *cat = mystrcat (s1,s2);
    std::cout << cat << std::endl;
    delete cat;

    int a1[] = {1,2,3,4,5,6,7,8,9,0};
    int a2[] = {0,9,8,7,6,5,4,3,2,1};


/*    myarray a,b;
    a.p = a1;
    a.size = 10;
    b.p = a2;
    b.size = 10;
    myarray c = {a1,10};
*/
    printarray (intcat ({a1,10},{a2,10}));
}