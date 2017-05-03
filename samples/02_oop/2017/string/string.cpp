#include "string.h"
#include <cstring>
#include <cassert>

#define OVERSIZE_LIMIT 2
#define BUFFER_INCREASE_FORMULA(a) a*2
#define INPUT_BUFFER_SIZE 5
#define EMPTY_STRING_BUFF 10

String::String ()
{
    capacity = EMPTY_STRING_BUFF;
    buff = new char[capacity];
    buff[0] = 0;
    length = 0;
}

String::String (const char *s)
{
  copy (s);
}

void String::copy (const char *s)
{
  length = strlen (s);
  capacity = length + 1;
  buff = new char [capacity];
  strcpy (buff,s);
}

String::String (const String &s)
{
  copy (s.buff);
}

bool String::operator != (const String &s) const
{
  return strcmp (buff,s.buff) != 0;
}

bool String::operator == (const String &s) const
{

  return strcmp (buff,s.buff) == 0;

  /*return !(this->operator != (s));
  return !(operator != (s));
  return !((*this).operator != (s));
  return !((*this) != s);
  return !(s != *this);*/
}

String& String::operator = (const String &s)
{

  if (this != &s)
  {
      if (capacity > s.length &&
          capacity < OVERSIZE_LIMIT*s.length)
      {
        strcpy (buff,s.buff);
        length = s.length;
      } else {
        delete buff;
        copy (s.buff);
      }
  }
  return *this;
}

bool String::operator > (const String &s) const
{
  return strcmp (buff,s.buff) > 0;
}

bool String::operator == (const char *s) const
{
  return strcmp (buff,s) == 0;
}

String& String::operator += (const char *s)
{
  if (capacity <= length + strlen(s) ||
      capacity >= OVERSIZE_LIMIT* (length + strlen(s)))
  {
      capacity = length + strlen(s) + 1;
      length = length + strlen(s);
      char *newBuff = new char [capacity];

      strcpy (newBuff,buff);
      delete buff;

      strcat (newBuff,s);
      buff = newBuff;
  } else {
    strcat (buff,s);
    length += strlen(s);
  }

  return *this;

}


String& String::operator += (const String &s)
{

  return *this += s.buff;

}

char String::operator [] (int index) const
{
  assert (index >= 0 && index < length);

  return buff[index];
}

char& String::operator [] (int index)
{
  assert (index >= 0 && index < length);

  return buff[index];
}

String::~String()
{
  delete buff;
}

String& String::operator += (char c)
{
  if (capacity == length+1)
  {
    capacity = BUFFER_INCREASE_FORMULA(capacity);
    char *newBuff = new char [capacity];

    strcpy (newBuff,buff);
    delete buff;
    buff = newBuff;
  }
  buff[length] = c;
  ++length;
  buff[length] = 0;

  return *this;
}


std::istream& operator >> (std::istream &in,String &s)
{

  char inputBuff[INPUT_BUFFER_SIZE];
  s = "";
  size_t charactersRead = 0;

  do
  {

    /*От документацията на getline:
    The failbit flag is set if the function extracts no characters,
    or if the delimiting character is not found once (n-1) characters
    have already been written to s*/
    in.clear(); //изчистваме failbit от предишната итерация

    in.getline(inputBuff,INPUT_BUFFER_SIZE);
    charactersRead = strlen (inputBuff);
    s += inputBuff;
  }
  while (charactersRead == INPUT_BUFFER_SIZE-1);

  return in;

}
std::ostream& operator << (std::ostream &out,const String &s)
{
  return out << s.buff;
}

size_t String::getLength()
{
  return length;
}
