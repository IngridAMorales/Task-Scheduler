#include "gtest/gtest.h"
#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"

TEST(SubTasks, SubtasksTitle){ 
  Subtask* test = new Subtask("Final Project", "Task Scheduler"); 
  EXPECT_EQ(test->get_title(), "Final Project"); 
}
TEST(SubTasks,SubtasksDescrip) { 
  Subtask* test = new Subtask("Final Project", "Task Scheduler");
  EXPECT_EQ(test->get_descrip(), "Task Scheduler");
} 

TEST(Tasks,TaskTitle) { 
  Tasks* test = new Tasks("Cs100", "Software Construction"); 
  Tasks* task = new Tasks("Final Project", "Task Scheduler");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up"); 
  test->add_task(task); 
  task->add_task(subtask); 
  EXPECT_EQ(test->get_title(), "Cs100Final ProjectScrum Meeting"); 
} 
TEST(PrintTask, NoSubtasks){ 
  Tasks* test = new Tasks("Cs100", "Software Construction");
  std::stringstream s; 
  test->print_tasks(s); 
  EXPECT_EQ(s.str(), "Cs100 : Software Construction \n");  
}
TEST(PrintTask, PrintAllTasks){
  Tasks* test = new Tasks("Cs100", "Software Construction"); 
  Tasklist* task = new Tasks("Final Project", "Task Scheduler");
  test->add_task(task); 
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up");
  test->add_task(subtask); 

  std::stringstream s;
  test->print_tasks(s);
  EXPECT_EQ(s.str(), "Cs100 : Software Construction \nFinal Project : Task Scheduler \nScrum Meeting : Catch up \n"); 
}
/*
TEST(PrintTask, PrintSubtasks) { 
  Tasks* test = new Tasks("Cs100", "Software Construction");
  Tasks* task = new Tasks("Final Project", "Task Scheduler");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up");
  test->add_task(task);
  task->add_task(subtask);

  std::stringstream s;
  test->print_tasks(s);
EXPECT_EQ(s.str(), "Cs100 - Software Construction \nFinal Project - Task Scheduler \nScrum Meeting - Catch up \n");
  
}
*/
TEST(Task, DeleteTask) { 
  Tasks* test = new Tasks("Cs100", "Software Construction");
  Tasks* task = new Tasks("Final Project", "Task Scheduler");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up");
  test->add_task(task);
  task->add_task(subtask);
  test->delete_task(task);

  std::stringstream s;
  test->print_tasks(s);
EXPECT_EQ(s.str(), "Cs100 : Software Construction \n");
}
TEST(Task, DeleteSubTask) {
  Tasks* test = new Tasks("Cs100", "Software Construction");
  Tasks* task = new Tasks("Final Project", "Task Scheduler");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up");
  test->add_task(task);
  task->add_task(subtask);
  task->delete_task(subtask);

  std::stringstream s;
  test->print_tasks(s);
EXPECT_EQ(s.str(), "Cs100 : Software Construction \nFinal Project : Task Scheduler \n");
}
TEST(Task, SetTitle){ 
  Tasks* test = new Tasks("Cs100", "Software Construction");
  test->set_title("135a"); 
  
  std::stringstream s;
  test->print_tasks(s);
EXPECT_EQ(s.str(), "135a : Software Construction \n"); 
}
TEST(Task, EditSubTask) {
  Tasks* test = new Tasks("Cs100", "Software Construction");
  Tasks* task = new Tasks("Final Project", "Task Scheduler");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up");
  test->add_task(task);
  test->add_task(subtask);
  test->edit_title(subtask, "Sprint"); 

  std::stringstream s;
  test->print_tasks(s);
EXPECT_EQ(s.str(), "Cs100 : Software Construction \nFinal Project : Task Scheduler \nSprint : Catch up \n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
