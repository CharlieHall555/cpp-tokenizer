#ifndef PARSER_H
#define PARSER_H

#include <optional>
#include <string>

struct Node {

};

struct SimpleExpr {     
    virtual ~SimpleExpr() = default;
};

struct NumberExpr : SimpleExpr {
    double value;
};

struct StringExpr : SimpleExpr {
    std::string value;
};

struct BoolExpr : SimpleExpr {
    bool value;
};

class Parser {
    public
};


#endif