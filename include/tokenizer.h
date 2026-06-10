#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <list>
#include <string>
#include <fstream>

enum class TokenType
{
    Keyword,
    Identifier,
    Operator,
    Number,
    String,
    StatComplete,
    Unknown
};

std::string tokenTypeToString(TokenType type);

struct Token
{
    std::string content;
    TokenType type;
};

class Lexer{
public:
    Lexer();
    std::list<Token> tokenize(std::string input);
    std::string serializeTokensToString();
    void writeTokensToAFile(std::ofstream &out);

private:
    int currentLine;
    int currentIndex;
    std::list<Token> completedTokens;
    Token currentToken;

    bool isStartOfToken(char currentChar);
    bool isTokenComplete(Token current_token, char currentChar, char nextChar);
    TokenType getTokenType(char startChar);
    void addToToken(Token &token, char currentChar);
    void finalizeToken(Token &token);
    bool isTokenEmpty(Token token);
    void startToken(Token &token, char currentChar);
};

#endif