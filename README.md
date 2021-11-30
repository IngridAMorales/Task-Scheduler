# Task Scheduler
 
 > Authors: Viviane Fernando (https://github.com/nwarn003) Ingrid Morales (https://github.com/IngridAMorales) Tracy Vu (https://github.com/uvutracy) Kendrew Christanto(https://github.com/kendrewchris)
 

## Project Description
* As we are all college students, productivity and time management are important skills to have as a student so that we can stay on top of all our tasks. Making an application that keeps track of our assignments along with their priorities, will make sure we succeed in our all our classes.
* We will be using C++, Git and Github to implement our task scheduler. 
* Input would be the task title, description, classifications (school, personal, work), and priority. The user will prioritize each task and classification. Our program sorts our subtasks depending on urgency of the task and the urgency of the classification. 

 
## Class Diagram
![Final Project](https://user-images.githubusercontent.com/68444503/143988465-4a124263-b753-47db-ad6f-31f13688ef12.png)


 
 ## Design Patterns
* We will be using the composite pattern to implement our task lists for our task scheduler. We decided to use the composite design pattern because a task list is a hierarchy of tasks that are composed with subtasks. When the user creates a task, they will have the option to extend the task to include subtasks as part of this one task. Subtasks cannot have other subtasks so they are the primitive types of the composite pattern. Implementing the composite design pattern simplified structuring the task lists. 
* We will be using the strategy pattern to implement the classification for our task scheduler.  We decided to use the strategy design pattern because we want the user to be able to change the classification of a task into either "class", "work", or personal" and make them interchangeable inside the original task in case the user wants to change the classification.  After the user creates a task, they will have the option of changing the classification of the task so each class with be grouped together making the task scheduler more clean and efficient.  Implementing a strategy design pattern enables the user to select which classification they want to put their task under. 

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
