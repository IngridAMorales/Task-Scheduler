#include <iostream>

#include "tasklist.hpp"
#include "task.hpp"
#include "subtask.hpp"
#include "classification.hpp"
#include "linear.hpp"

using namespace std;

int main () {

    Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
    Tasks* task = new Tasks("Final Project", "Task Scheduler", 5,"School");
    Tasklist* subtask1 = new Tasks("Scrum Meeting", "Catch up", 2,"School"); 
    Tasklist* subtask2 = new Tasks("Scrum Meeting", "Catch up", 3,"School"); 
    Tasklist* subtask3 = new Tasks("Scrum Meeting", "Catch up", 1,"School"); 
    test->add_task(task); 
    test->add_task(subtask1); 
    test->add_task(subtask2); 
    test->add_task(subtask3); 

    Classification* sort = new Linear();

    sort->display(test);

    return 0;
}