#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "classification.hpp"
#include "linear.hpp"
#include "magnitude.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintMenu();

int main(){
   string userInput = "menu";
   string TaskTitle;
  string TaskDescrip;
  string TaskClass;
  string subtasksOption;
  string SubTaskTitle;
  string SubTaskDescrip;
  string SubTaskClass;
  string TaskListTitle;
  string TaskListDescrip;
  string TaskListClass;
  int TaskPrior;
  int SubTaskPrior;
  int TaskListPrior;

   cout << "Welcome to the Task List Scheduler! " << endl << endl;
   cout << "Let's Name Your Task List!" << endl << endl;
   getline(cin,TaskListTitle);
  cout << "Input Task List Description: " << endl;
   getline(cin,TaskListDescrip);
  cout << "Input Task Classification (School,Work, or Personal): " << endl;
   cin >> TaskListClass;
   cin.ignore();
   cout << "1 - High Priority, 2 - Medium Priority, 3 - Low Priority" << endl;
   cout << "Input Priority Level:" << endl;
   cin>> TaskListPrior;
   Tasks* list = new Tasks(TaskListTitle,TaskListDescrip,TaskListPrior,TaskListClass);
  cout << endl << "Your Task List has been created!" << endl << endl;
  
 while (userInput != "quit"){
    if (userInput == "display"){
    string displayInput;
   cout << "How would you like to display your Tasks?(Linear,Magnitude,Group)" << endl;
  cin>> displayInput;
  if (displayInput == "Linear"){
cout << "Task List" << endl << endl;
   Classification* sort1 =new Linear();
list->set_strat(sort1);
list->printAll();
}
else if(displayInput == "Magnitude"){
  int SchoolRank,PersonalRank,WorkRank;
  cout << "Please rank each classification: (1 = Low Priority, 2 = Medium Priority, 3 = High Priority)" << endl;
 cout << "School Priority: " << endl;
 cin >> SchoolRank;
 cout << endl << "Personal Priority: ";
 cin >> PersonalRank;
 cout << endl << "Work Priority: ";
 cin >> WorkRank;
 cout << endl << endl << "Task List (Magnitude Sort)" << endl << endl;
 Classification* sort1 = new Magnitude(SchoolRank,PersonalRank,WorkRank);
 list->set_strat(sort1);
 list->printAll(); 
}
else{
 cout << "Group" << endl;
}
}

else if (userInput == "add"){
   cout << "Let's add A New Task to Your Task List!" << endl << endl;
   cout << "Input Task Title: " << endl;
   getline(cin,TaskTitle);
   cout << "Input Task Description: " << endl;
   getline(cin,TaskDescrip);
   cout << "Input Task Classification (School,Work, or Personal): " << endl;
   cin >> TaskClass;
   cin.ignore();
   cout << "1 - High Priority, 2 - Medium Priority, 3 - Low Priority" << endl;
   cout << "Input Priority Level:" << endl;
   cin>> TaskPrior;
   cin.ignore();
  Tasks* task = new Tasks(TaskTitle, TaskDescrip,TaskPrior,TaskClass);
   list->add_task(task);
   cout << "Would you like to create subtasks?" << endl << endl;
   cin >> subtasksOption;
   cin.ignore();

   while (subtasksOption!= "no"){
     cout << "Let's add A New SubTask to Your Task!" << endl << endl;
   	cout << "Input New SubTask Title: " << endl;
   	getline(cin,SubTaskTitle);
     cout << "Input SubTask Description: " << endl;
   	getline(cin,SubTaskDescrip);
     cout << "Input SubTask Classification (School,Work, or Personal): " << endl;
   	cin >> SubTaskClass;
   	cin.ignore();
   cout << "1 - High Priority, 2 - Medium Priority, 3 - Low Priority" << endl;
   	cout << "Input Priority Level:" << endl;
   	cin>> SubTaskPrior;
   	cin.ignore();
 Tasklist* subtask = new Subtask(SubTaskTitle,SubTaskDescrip,SubTaskPrior,SubTaskClass);
   //list->add_task(new Subtask(SubTaskTitle,SubTaskDescrip,SubTaskPrior,SubTaskClass));
   list->add_task(subtask);
   cout << "Subtask added!" << endl << endl;

   cout << "Would you like to create subtasks?" << endl << endl;
   cin >> subtasksOption;
   cin.ignore();
}
} 
else if (userInput == "delete"){
  string deleteTask;
  cout << "What is the title of the task you would like to delete?" << endl;
  getline(cin,deleteTask);
 // vector<Tasklist*> copy = list->get_Subtasks();
  for (int i=0;i<list->get_Subtasks().size();++i){
  if (list->get_Subtasks().at(i)->get_title() == deleteTask){
   list->delete_task(list->get_Subtasks().at(i));
   }
}
}
else if (userInput == "edit"){
  string editTask;
  cout << "What is the title of the task you would like to edit?" << endl;
  getline(cin,editTask);
  //vector<Tasklist*> copy = list->get_Subtasks();
  for (int i=0;i<list->get_Subtasks().size();++i){
  if (list->get_Subtasks().at(i)->get_title() == editTask){
   list->edit_title(list->get_Subtasks().at(i),"InputString");
   }
  }
}
else if (userInput == "menu"){
  PrintMenu();
}
else{
 cout << "Not a valid option!" << endl << endl;
 PrintMenu();
}
  
    cout << "Enter your selection now (menu - Main Menu): " << endl;
    cin >> userInput;
    cin.ignore();
    cout << endl;
}
delete list;
cout << "Goodbye!" << endl;


return 0;
}

void PrintMenu(){
    cout << "MAIN MENU" << endl;
    cout << "display - Display all tasks" << endl;
    cout << "add     - Add new task" << endl;
    cout << "delete  - Delete task" << endl;
    cout << "edit    - Edit task" << endl;
    cout << "quit    - Quit the program" << endl << endl;
}
