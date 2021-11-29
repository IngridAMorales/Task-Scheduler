#include <iostream>

#include "tasklist.hpp"
#include "task.hpp"
#include "subtask.hpp"
#include "classification.hpp"
#include "linear.hpp"
#include "magnitude.hpp" 
#include "group.hpp"
using namespace std;

int main () {

    Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
    Tasks* task = new Tasks("Final Project", "Task Scheduler", 5,"Work");
    Tasks* subtask1 = new Tasks("Scrum Meeting", "Catch up", 2,"School"); 
    Tasklist* subtask2 = new Tasks("Scrum Meeting", "Catch up", 3,"Personal"); 
    Tasklist* subtask3 = new Tasks("Scrum Meeting", "Catch up", 1,"Work"); 
    Tasklist* subtask4 = new Tasks("Scrum Meeting", "Catch up", 1,"School"); 

    test->add_task(task); 
    test->add_task(subtask1); 
    test->add_task(subtask2); 
    test->add_task(subtask3); 
    test->add_task(subtask4); 

    std::cout << "Linear Sort\n";
    Classification* sort1 = new Linear(); 
    test->set_strat(sort1); 
    test->printAll();
    
    std::cout << "Magnitude Sort\n";
    //school, personal work
    Classification* sort2 = new Magnitude(1,2,3);
    test->set_strat(sort2);
    test->printAll();

    std::cout << "Group Sort\n";
    Classification* sort3 = new Group(1,2,3);
    test->set_strat(sort2);
    test->printAll();
    
    return 0;
}
