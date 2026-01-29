#include <iostream>

#ifndef TAGREMOVER_H
#define TAGREMOVER_H

class TagRemover{
    public:
        TagRemover(std::istream& in);
        void print(std::ostream& out);
        std::string removeTags();
        std::string replaceSpecialCharacters();
    private:
        std::string text;

};

#endif