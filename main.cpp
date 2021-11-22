#include <iostream>

using namespace std;


int main(){
   string userInput;


   cout << "Welcome to the Task List Scheduler! " << endl << endl;
   
   while (userInput != "quit"){
    if (userInput == "display"){
   cout << "Task List" << endl;

}

else if (userInput == "add"){
   cout << "Adding New Task" << endl;
}
else if (userInput == "delete"){
  cout << "Delete Task" << endl;

}
else if (userInput == "edit"){
  cout << "Edit Task" << endl;

} 
else{
    cout << "MAIN MENU" << endl;
    cout << "display - Display all tasks" << endl;
    cout << "add     - Add new task" << endl;
    cout << "delete  - Delete task" << endl;
    cout << "edit    - Edit task" << endl;
    cout << "quit    - Quit the program" << endl << endl;

    cout << "Enter your selection now: " << endl;
    cin >> userInput;
    cout << endl;
}

}




return 0;
}
