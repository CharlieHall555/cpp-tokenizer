#ifndef PARSER_H
#define PARSER_H

#include <optional>
#include <string>
#include <vector>
#include <memory>
#include "lexer.h"

struct BaseNode
{
    virtual ~BaseNode() = default;
};


struct Id : BaseNode{
    std::string var;
};

struct BaseExpr : BaseNode {     
    virtual ~BaseExpr() = default;
};

struct NumberExpr : BaseExpr {
    double value;
};

struct StringExpr : BaseExpr {
    std::string value;
};

struct BoolExpr : BaseExpr {
    bool value;
};

struct Assg : BaseNode{
    Id id;
    std::unique_ptr<BaseNode> value;
};

class Parser {
public:
    Parser(std::vector<Token>& inputTokens);
    std::unique_ptr<BaseNode> parse();
private:
    std::vector<Token> tokenList;
    int tokenIndex = 0;
    Token& current();
    Token& next();
};


#endif