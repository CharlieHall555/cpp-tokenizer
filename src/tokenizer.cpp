#include "tokenizer.h"
#include "stringutil.h"
#include <string>
#include <list>
#include <set>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

static set<string> keywords = {};
static set<string> operators = {"+", "-", "=", "/", "*"};
static set<string> digits = {"0" , "1", "2", "3", "4", "5", "6", "7", "8", "9"};

string tokenToString(Token token)
{

    string tokenContent = token.content;
    if (tokenContent == "\n")
    {
        tokenContent = " ";
    }

    return tokenTypeToString(token.type) + " '" + tokenContent + "'";
}

string tokenTypeToString(TokenType type)
{
    switch (type)
    {
    case TokenType::Identifier:
        return "Identifier";

    case TokenType::Number:
        return "Number";

    case TokenType::String:
        return "String";

    case TokenType::Operator:
        return "Operator";

    case TokenType::Unknown:
        return "Unknown";

    case TokenType::Keyword:
        return "Keyword";

    case TokenType::StatComplete:
        return "StatComplete";

    default:
        return "Failed To Convert";
    }
}

Lexer::Lexer() : currentLine(1), currentIndex(0), currentToken{"", TokenType::Unknown} {}

bool Lexer::isStartOfToken(char currentChar)
{
    if (currentChar == ' ')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Lexer::isTokenComplete(Token current_token, char currentChar, char nextChar)
{
    string previewNext = current_token.content + string(1, nextChar);
    if (current_token.type == TokenType::Identifier)
    {
        if (nextChar == ' ' || nextChar == '\n')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (current_token.type == TokenType::Operator)
    {
        if (operators.find(previewNext) != operators.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (current_token.type == TokenType::String)
    {

        if (currentChar == '"' && (nextChar == ' ' || nextChar == '\n'))
        {
            return true;
        }
        else
        {

            return false;
        }
    }

    else if (current_token.type == TokenType::StatComplete)
    {
        return true;
    }
    else if (current_token.type == TokenType::Number)
    {
        if (nextChar == ' ' || nextChar == '\n')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

TokenType Lexer::getTokenType(char startChar)
{
    string startCharString = string(1, startChar);

    if (operators.find(startCharString) != operators.end())
    {
        return TokenType::Operator;
    }
    else if (startChar == '\n')
    {
        return TokenType::StatComplete;
    }
    else if (digits.find(startCharString) != digits.end())
    {
        return TokenType::Number;
    }
    else if (startChar == '"')
    {
        return TokenType::String;
    }

    else
    {
        return TokenType::Identifier;
    }
}

void Lexer::addToToken(Token &token, char currentChar)
{
    token.content = token.content + string(1, currentChar);
}

void Lexer::finalizeToken(Token &token)
{
    if (token.type == TokenType::String){
        token.content = stringutil::strip(token.content , '"');
    }

    completedTokens.push_back(token);
    token = Token{"", TokenType::Unknown};
}

bool Lexer::isTokenEmpty(Token token)
{
    return token.content == "";
}

void Lexer::startToken(Token &token, char currentChar)
{
    if (isTokenEmpty(token))
    {
        token.content = string(1, currentChar);
        token.type = getTokenType(currentChar);
    }
    else
    {
        cout << "token must be empty to add" << endl;
    }
}

void Lexer::writeTokensToAFile(std::ofstream &out)
{
    out << this->serializeTokensToString();
}

string Lexer::serializeTokensToString()
{

    string output = "";
    for (Token eachToken : completedTokens)
    {
        output += tokenToString(eachToken) + '\n';
    }
    return output;
}

list<Token> Lexer::tokenize(string input)
{
    completedTokens.clear();
    currentToken = Token{"", TokenType::Unknown};
    currentLine = 1;
    currentIndex = 0;

    istringstream stream(input);
    string line;

    while (getline(stream, line))
    {
        currentLine++;
        line = stringutil::strip(line, ' ');
        line += '\n';
        if (line == "\n")
        {
            continue;
        }

        for (int columnIndex = 0; columnIndex < line.length(); columnIndex++)
        {
            char nextChar = line[columnIndex + 1];
            char eachChar = line[columnIndex];

            if (isTokenEmpty(currentToken) == false)
            {
                addToToken(currentToken, eachChar);

                if (isTokenComplete(currentToken, eachChar, nextChar))
                {
                    finalizeToken(currentToken);
                }
            }
            else
            {
                if (isStartOfToken(eachChar))
                {
                    startToken(currentToken, eachChar);
                    if (isTokenComplete(currentToken, eachChar, nextChar))
                    {
                        finalizeToken(currentToken);
                    }
                }
            }
        }
    }

    return completedTokens;
}
