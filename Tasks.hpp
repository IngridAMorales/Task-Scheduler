#ifndef __TASKS_HPP__
#define __TASKS_HPP__

class Tasks: public Tasklist {
private: 
    std::vector<TaskList*> s;	//vector will implement the stack
    std::stack<TaskList*, std::vector<TaskList*> >t; 	//stack holds the Tasks  
    
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
