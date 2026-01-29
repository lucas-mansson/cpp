#include <iostream>
#include <fstream>
#include "User.h"
#include "UserTable.h"

using namespace std;

int main(){
    
    UserTable userTable("users.txt");
    userTable.addUser(User(1234, "Lucas Månsson"));

    cout << "number of users: " << userTable.getNbrUsers() << endl;

    cout << userTable.find(21330) << endl;
    cout << userTable.find(21331) << endl;
    cout << userTable.find("Jens Holmgren") << endl;

    cout << "tesfindNbr: " << testFindNbr(userTable) << endl;
    

    ofstream output("output.txt");
    userTable.print(output);
    
    return -1;
}