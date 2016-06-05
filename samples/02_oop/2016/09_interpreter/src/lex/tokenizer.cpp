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
Token Tokenizer::getToken (){

	if (token_peeked)
	{
		token_peeked = false;
		return peeked_token;
	}


	token_peeked = false;
	Token result;

	assert (in >> result.val_str);

	//number
	if (result.val_str[0] >= '0' && result.val_str[0] <= '9')
	{
		size_t length;
		result.val_double = stof (result.val_str,&length);
		if (length < result.val_str.length())
		{
			error (result.val_str + ":invalid number");
		}
		result.type = Token::NUMBER;
	} 
	//Uknown token (identifier)
	else {
		result.type = Token::UNKNOWN;
	}


	return result;

}
bool Tokenizer::moreTokens (){

	return (bool)in;

}
