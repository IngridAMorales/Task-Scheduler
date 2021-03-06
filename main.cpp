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
    //Tasks* subtask1 = new Tasks("Scrum Meeting 1", "Catch up", 2,"Work"); 
    Tasklist* subtask2 = new Subtask("Scrum Meeting 2", "Catch up", 3,"Personal"); 
  
    test->add_task(task);
    test->add_task(new Tasks("Scrum Meeting 1", "Catch up", 2,"Work"));  
    test->add_task(new Subtask("Scrum Meeting 3", "Catch up", 1,"School")); 
   test->add_task(new Subtask("Scrum Meeting 4", "Catch up", 1,"School"));

    Classification* sort1 = new Linear(); 
    test->set_strat(sort1); 
    test->printAll();
  /* 
    Classification* sort2 = new Magnitude(1,2,3);
    test->set_strat(sort2);
    test->printAll();
 */   
    return 0;
}
