#include <iostream>

class String
{
private:
  char *buff;
  size_t capacity;
  size_t length;

public:

  String ();
  String (const char*);
  String (const String&);
  bool operator != (const String&) const;
  String& operator = (const String&);
  bool operator == (const String&) const;
  bool operator > (const String&) const;
  bool operator == (const char*) const;
  String& operator += (const String&);
  String& operator += (const char *);

  String& operator += (char);

  char operator [] (int) const;
  char& operator [] (int);

  friend std::istream& operator >> (std::istream&,String&);
  friend std::ostream& operator << (std::ostream&,const String&);

  size_t getLength();

  ~String();

private:
  void copy (const char*);
};

std::istream& operator >> (std::istream&,String&);
std::ostream& operator << (std::ostream&,const String&);
