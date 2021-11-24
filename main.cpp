#include <iostream>

using namespace std;


int main(){
   string userInput = "menu";
   string TaskTitle;
  string TaskDescrip;
  string TaskClass;
  int TaskPrior;

   cout << "Welcome to the Task List Scheduler! " << endl << endl;
   while (userInput != "quit"){
    if (userInput == "display"){
   cout << "Task List" << endl;

}

else if (userInput == "add"){
   cout << "Let's add A New Task to Your Task List!" << endl << endl;
   cout << "Input New Task Title: " << endl;
   cin >> TaskTitle;
   cin.ignore();
   cout << "Input Task Description: " << endl;
   cin.ignore();
   getline(cin,TaskDescrip);
   cout << "Input Task Classification (School,Work, or Personal): " << endl;
   cin >> TaskClass;
   cin.ignore();
   cout << "1 - High Priority, 2 - Medium Priority, 3 - Low Priority" << endl;
   cout << "Input Priority Level:" << endl;
   cin>> TaskPrior;
   cin.ignore();
  cout << "Adding New Task..." << endl;
}
else if (userInput == "delete"){
  cout << "Delete Task" << endl;

}
else if (userInput == "edit"){
  cout << "Edit Task" << endl;

} 
else if (userInput == "menu"){
  cout << "MAIN MENU" << endl;
    cout << "display - Display all tasks" << endl;
    cout << "add     - Add new task" << endl;
    cout << "delete  - Delete task" << endl;
    cout << "edit    - Edit task" << endl;
    cout << "quit    - Quit the program" << endl << endl;
}
else{
 cout << "Not a valid option!" << endl << endl;
 cout << "MAIN MENU" << endl;
    cout << "display - Display all tasks" << endl;
    cout << "add     - Add new task" << endl;
    cout << "delete  - Delete task" << endl;
    cout << "edit    - Edit task" << endl;
    cout << "quit    - Quit the program" << endl << endl;
}
  
    cout << "Enter your selection now (menu - Main Menu): " << endl;
    cin >> userInput;
    cin.ignore();
    cout << endl;

}

cout << "Goodbye!" << endl;


return 0;
}
