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

        void display(Tasks* obj, int school, int personal, int work){
            std::vector<Tasklist*> subtasks = obj->get_Subtasks();
            for(int i = 0; i<subtasks.size()-1; i++){
                int max = i;
                for(int j = i+1; j<subtasks.size(); j++)
                    if(subtasks[j]->get_Priority() > subtasks[max]->get_Priority())
                        max = j;
                Tasklist* temp = subtasks[max];
                subtasks[max] = subtasks[i];
                subtasks[i] = temp;
            }
            for(int i = 0; i<subtasks.size(); i++)
                subtasks[i]->print();
            std::cout << "\n\n";
            for(int i = 0; i<subtasks.size(); i++)
                delete subtasks[i];
        }
    
};

#endif 