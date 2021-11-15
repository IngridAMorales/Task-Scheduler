#ifndef __TASKS_HPP__
#define __TASKS_HPP__
#include "Tasklist.hpp" 

class Tasks: public Tasklist {
private: 
    std::vector<Tasklist*> subtasks;	//holds the tasks

    std::vector<Tasklist*> u; //implements the undo stack 
    std::stack<TaskList*, std::vector<Tasklist*>> undo;  //holds the actions of the user to undo any operation 
    
public: 
    Tasks(Tasklist* sub, std::string title, std::string descrip): Tasklist(title, descrip) {} 
   ~Tasks() {}

    virtual void add_task(){ }
    virtual void delete_task() { }
    virtual void undo_task() { }
    virtual void edit_task() { } 
    virtual void display_task() {}
};

class Subtask: public TaskList {
public: 
   Subtask(std::string title, std::descrip): Tasklist(title, descrip) {}
   ~Subtask() {}

   void delete_task() {} 
   void undo_task() {}
   void edit_task() {} 
   void display_task() {}
}; 

#endif 
