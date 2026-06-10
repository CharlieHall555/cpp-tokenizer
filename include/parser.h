#ifndef PARSER_H
#define PARSER_H

#include <optional>
#include <string>
#include "tokenizer.h"

struct BaseNode
{
    virtual ~BaseNode() = default;
};


struct Id : BaseNode{
    std::string var;
};

struct Assg : BaseNode{
    Id id;
    BaseExpr value;
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

class Parser {
public:
    Parser();
    BaseNode parse(std::list<Token> tokenList);
private:
    BaseNode current();
    BaseNode next();

};


#endif