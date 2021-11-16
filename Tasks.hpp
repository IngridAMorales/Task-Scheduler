#ifndef __TASKS_HPP__
#define __TASKS_HPP__
#include "Tasklist.hpp" 

class Tasks: public Tasklist {
private: 
    std::string title; 
    std::string descrip; 
    Task* main_task = nullptr; 

    std::vector<Tasklist*> subtasks;	//holds the tasks

    std::vector<Tasklist*> u; //implements the undo stack 
    std::stack<TaskList*, std::vector<Tasklist*>> undo;  //holds the actions of the user to undo any operation 
    
public: 
    Tasks(const std::string &t, const std::string &d): title(t), descrip(d){} 
   ~Tasks() {} //delete vector pointers & stack 

    virtual void add_task(Tasklist* new_task){	//adds composite tasks and subtasks 
 	subtasks.push_back(new_task);
  	new_task->main_task=this;  	
    }
    virtual void delete_task(Tasklist* new_task) { }
    virtual void undo_task() { }
    virtual void edit_task(Tasklist* new_task) { } 
    virtual std::string get_title() { return subtasks->get_title();}
    virtual std::string get_descrip(){ }
};

class Subtask: public TaskList {
private: 
   std::string title; 
   std::string descrip; 
public: 
   Subtask(const std::string &t,const std::string &d):title(t), descrip(d) {}
   ~Subtask() {}
 
   void undo_task() {}
   void edit_task() {} 
   std::string get_title() { return title; }
   std::string get_descrip(){ return descrip; }
}; 

#endif 
