#include <iostream>

#include "tasklist.hpp"
#include "task.hpp"
#include "subtask.hpp"
#include "classification.hpp"
#include "linear.hpp"
#include "magnitude.hpp"

using namespace std;

int main () {
    Tasks* test = new Tasks("Cs100", "Software Construction", 7,"School"); 
    Tasks* task = new Tasks("Final Project", "Task Scheduler", 4,"Work");
    Tasklist* subtask1 = new Subtask("Scrum Meeting", "Catch up", 3,"Personal"); 
    Tasklist* subtask2 = new Subtask("Scrum Meeting", "Catch up", 5,"School"); 
    Tasklist* subtask3 = new Subtask("Scrum Meeting", "Catch up", 10,"School"); 
    test->add_task(task); 
    test->add_task(subtask1); 
    test->add_task(subtask2); 
    test->add_task(subtask3); 



    Classification* sort = new Magnitude();
    Classification* sort2 = new Linear();

    //school = 1, personal =2, work =3
    sort->display(test,1,2,3);
    sort2->display(test,0,0,0);

    return 0;
}