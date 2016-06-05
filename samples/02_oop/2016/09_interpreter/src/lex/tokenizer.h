#ifndef __TOKENIZER_H
#define __TOKENIZER_H

#include <string>

using namespace std;


struct Token
{
	static const int ERROR = -1;
	static const int NUMBER = 0;
	static const int UNKNOWN = 1;


	Token ();
	Token (int _type, string _val_str, double _val_double);

	int type;
	string val_str;
	double val_double;

};

class Tokenizer
{
private:
	istream &in;
	bool token_peeked;
	Token peeked_token;
public:
	Tokenizer (istream &_in);

	Token peekToken ();
	Token getToken ();
	bool moreTokens ();

};


#endif