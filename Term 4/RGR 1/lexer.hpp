#pragma once
#include <iostream>

enum SymbolicTokenClass
{
    Letter = 1,
    Digit,
    Dot,
    Comma,
    Semicolon,
    Colon,
    Arithmetic,
    Compare,
    LSqBracket,
    RSqBracket,
    LBracket,
    RBracket,
    Space,
    EndLine,
    EndOfFile,
    Other
};

struct SymbolicToken
{
    SymbolicTokenClass clazz;
    int value;

    void Set(SymbolicTokenClass clazz_, int value_)
    {
        clazz = clazz_;
        value = value_;
    }
};

SymbolicToken transliterator(char raw_char)
{
    SymbolicToken symbolicToken;

    if (std::tolower(raw_char) >= 'a' && std::tolower(raw_char) <= 'z')
        symbolicToken.Set(SymbolicTokenClass::Letter, raw_char);
    else if (raw_char >= '0' && raw_char <= '9')
        symbolicToken.Set(SymbolicTokenClass::Digit, raw_char);
    else if (raw_char == '.')
        symbolicToken.Set(SymbolicTokenClass::Dot, raw_char);
    else if (raw_char == ',')
        symbolicToken.Set(SymbolicTokenClass::Comma, raw_char);
    else if (raw_char == ';')
        symbolicToken.Set(SymbolicTokenClass::Semicolon, raw_char);
    else if (raw_char == ':')
        symbolicToken.Set(SymbolicTokenClass::Colon, raw_char);
    else if (raw_char == '+' || raw_char == '-' || raw_char == '*' || raw_char == '/' || raw_char == '%')
        symbolicToken.Set(SymbolicTokenClass::Arithmetic, raw_char);
    else if (raw_char == '=' || raw_char == '<' || raw_char == '>' || raw_char == '!')
        symbolicToken.Set(SymbolicTokenClass::Compare, raw_char);
    else if (raw_char == '[')
        symbolicToken.Set(SymbolicTokenClass::LSqBracket, raw_char);
    else if (raw_char == ']')
        symbolicToken.Set(SymbolicTokenClass::RSqBracket, raw_char);
    else if (raw_char == '(')
        symbolicToken.Set(SymbolicTokenClass::LBracket, raw_char);
    else if (raw_char == ')')
        symbolicToken.Set(SymbolicTokenClass::RBracket, raw_char);
    else if (raw_char == '\t' || raw_char == ' ')
        symbolicToken.Set(SymbolicTokenClass::Space, raw_char);
    else if (raw_char == '\n')
        symbolicToken.Set(SymbolicTokenClass::EndLine, raw_char);
    else if (raw_char == EOF)
        symbolicToken.Set(SymbolicTokenClass::EndOfFile, raw_char);
    else 
        symbolicToken.Set(SymbolicTokenClass::Other, raw_char);

    return symbolicToken;
}
