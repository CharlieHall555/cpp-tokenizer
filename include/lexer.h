#ifndef LEXER_H
#define LEXER_H

#include <vector>
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
    explicit Lexer(std::string input);
    std::vector<Token> tokenize();
    std::string serializeTokensToString();
    void writeTokensToAFile(std::ofstream &out);

private:
    int currentLine;
    int currentIndex;
    std::string target;
    std::vector<Token> completedTokens;
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