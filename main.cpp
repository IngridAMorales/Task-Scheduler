#include <iostream>

#include "tasklist.hpp"
#include "task.hpp"
#include "subtask.hpp"
#include "classification.hpp"
#include "linear.hpp"
#include "magnitude.hpp" 
using namespace std;

int main () {

    Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
    Tasks* task = new Tasks("Final Project", "Task Scheduler", 5,"School");
    Tasks* subtask1 = new Tasks("Scrum Meeting", "Catch up", 2,"Work"); 
    Tasklist* subtask2 = new Tasks("Scrum Meeting", "Catch up", 3,"Personal"); 
   // Tasklist* subtask3 = new Tasks("Scrum Meeting", "Catch up", 1,"School"); 
    test->add_task(task); 
    test->add_task(subtask1); 
    test->add_task(subtask2); 
/*
    Classification* sort1 = new Linear(); 
    test->set_strat(sort1); 
    test->printAll();
  */  
    Classification* sort2 = new Magnitude(1,2,3);
    test->set_strat(sort2);
    test->printAll();
    
    return 0;
}
