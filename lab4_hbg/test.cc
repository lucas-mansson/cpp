#include "TagRemover.h"
#include <fstream>
#include <string> 

using namespace std;

void testInput(){
    ifstream file("test.html");
    TagRemover tr = TagRemover(file);
}

bool test_removeTags(){

    ifstream file("test.html");
    TagRemover tr = TagRemover(file);
    string correct = "This is a line without a tag\n This is a line with one tag\n And this  line has two tags\n A line with a starting tag\n which finished on this line\n Special chars: &lt;&gt;&nbsp;&amp;";
    string removedTags = tr.removeTags();

    cout << correct.compare(removedTags) << endl;

    cout << endl;

    return correct == removedTags;
}

bool test_replaceSpecialCharacters(){
    ifstream file("test.html");
    TagRemover tr = TagRemover(file);

    string correct = "This is a line without a tag\nThis is <tag tag> a line with one tag\nAnd this <tag> line has two tags <...>\nA line with a starting tag < ..... continues<\n... we're still in a tag ...\n... finishes> which finished on this line <last tag>\nSpecial chars: <> &";
    string replaced = tr.replaceSpecialCharacters();

    cout << correct.compare(replaced) << endl;

    cout << endl;
    
    return correct == replaced;
}

void test_print(){
    ifstream file("test.html");
    TagRemover tr = TagRemover(file);
    tr.print(cout);
}

int main(){
    
    if(test_removeTags()){
        cout << "Removed tags successfully" << endl;
    }else{
        cout << "Didnt remove all tags. You suck at programming noob" << endl;
    }

    if(test_replaceSpecialCharacters()){
        cout << "Replaced special characters successfully" << endl;
    }else{
        cout << "Didnt replace special characters. You suck at programming noob" << endl;
    }
    
    test_print();
    
    return -1;
}