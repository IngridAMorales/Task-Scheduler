#ifndef __LINEAR_HPP__
#define __LINEAR_HPP__

#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "classification.hpp"


class Linear : public Classification{
    public:
        Linear(){}
        virtual ~Linear(){}

        //need a  way to check whether tasks in subtask vector 
        void display(Tasks* tasklist){
            
            std::vector<Tasklist*> subtasks = tasklist->get_Subtasks();
            for(int i = 0; i<subtasks.size()-1; i++){
                int min = i;
                for(int j = i+1; j<subtasks.size(); j++)
                    if(subtasks[j]->get_Priority() < subtasks[min]->get_Priority())
                        min = j;
                Tasklist* temp = subtasks[min];
                subtasks[min] = subtasks[i];
                subtasks[i] = temp;
            }
            for(int i = 0; i<subtasks.size(); i++)
                subtasks[i]->print();
        }
    
};

#endif 