#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>
#include "parser.h"
#include "lexer.h"

using namespace std;

Parser::Parser(std::vector<Token>& inputTokens) : tokenList(inputTokens) {};


