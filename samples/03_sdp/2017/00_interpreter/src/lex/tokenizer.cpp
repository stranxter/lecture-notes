#include <iostream>
#include <assert.h>


#include "tokenizer.h"
#include "../errors.h"


using namespace std;


Token::Token ():type (Token::ERROR) {}

Token::Token (int _type, string _val_str, double _val_double):
           type(_type),val_str(_val_str),val_double(_val_double){}


Tokenizer::Tokenizer (istream &_in):in(_in),token_peeked(false){

}

Token Tokenizer::peekToken (){
	if (!token_peeked)
	{
		peeked_token = getToken();
		token_peeked = true;
	}
	
	return peeked_token;

}


const int nkeywords = 7;
string keywords[nkeywords] = {"start",
 		                      "end",
 		                      "if",
 		                      "then",
 		                      "else",
 		                      "assign",
 		                      "printline"};


Token Tokenizer::getToken (){

	if (token_peeked)
	{
		token_peeked = false;
		return peeked_token;
	}


	token_peeked = false;
	Token result;
	result.type = Token::UNKNOWN;

	assert (in >> result.val_str);

	//number
	if (result.val_str[0] >= '0' && result.val_str[0] <= '9')
	{
		size_t length;
		result.val_double = std::stof (result.val_str,&length);
		if (length < result.val_str.length())
		{
			error (result.val_str + ":invalid number");
		}
		result.type = Token::NUMBER;
	} 
	//Uknown token (identifier)
	else {

		int i;
		for (i = 0; i < nkeywords && keywords[i] != result.val_str; i++);

		if (i < nkeywords)
		{
			result.type = Token::KW_START + i;

		}

	}

	if (result.type == Token::UNKNOWN && 
	    (result.val_str == "+" ||
	     result.val_str == "^"))
	{	
		result.type = Token::ARITH_OPER;
	}



	return result;

}
bool Tokenizer::moreTokens (){

	return (bool)in;

}
