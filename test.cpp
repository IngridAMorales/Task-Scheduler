#include "gtest/gtest.h"
#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"

TEST(SubTasks, GetSubtaskRow){ 
  Subtask* test = new Subtask("Final Project", "Task Scheduler",1,"School"); 
  std::vector<std::string> v{"Final Project", "Task Scheduler", "1", "School"}; 
  EXPECT_EQ(test->get_data(),v); 
}

TEST(AddTasks,AddingTasksRow) { 
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up", 1,"School"); 
  test->add_task(task); 
  task->add_task(subtask); 
  std::vector<std::string> v{"Cs100","Software Construction","1","School","Final Project", "Task Scheduler", "1", "School","Scrum Meeting", "Catch up","1","School" };
 
 EXPECT_EQ(test->get_data(), v); 
}
TEST(AddTasks,TwoComposites) {
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Tasks("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  test->add_task(subtask);
  std::vector<std::string> v{"Cs100","Software Construction","1","School","Final Project", "Task Scheduler", "1", "School","Scrum Meeting", "Catch up","1","School" };

 EXPECT_EQ(test->get_data(), v);
}

TEST(Task, DeleteTask) { 
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  task->add_task(subtask);
  test->delete_task(task);

   std::vector<std::string> v{"Cs100", "Software Construction", "1", "School"};
EXPECT_EQ(test->get_data(),v );
}

TEST(Task, DeleteSubTask) {
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  task->add_task(subtask);
  task->delete_task(subtask);

   std::vector<std::string> v{"Final Project", "Task Scheduler", "1", "School"};
EXPECT_EQ(task->get_data(), v);
}

TEST(Task, SetTitle){ 
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  test->set_title("135a"); 
   std::vector<std::string> v{"135a", "Software Construction", "1", "School"};
EXPECT_EQ(test->get_data(), v); 
}

TEST(Task, EditSubTask) {
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Tasks("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
 test->add_task(subtask);
  test->edit_title(subtask, "Sprint"); 
std::vector<std::string> v{"Cs100","Software Construction","1","School","Final Project", "Task Scheduler", "1", "School","Sprint", "Catch up","1","School" };
EXPECT_EQ(test->get_data(),v);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
