# My Life Planner

## Project Description
### Introduction:
My Life Planner is a diary management system that enables users to securely and logically store and manage their private ideas, experiences, and events.

Users will be able to make, manage, and view entries using the system's user-friendly interface. Additionally, the system will include a search feature to make it easier for users to locate particular entries, searching by the entry name or date.

### Objectives:
- To offer customers a safe and convenient platform on which to organize and preserve their private diary entries.
- To enable users to sort entries according to various criteria.
- To offer a search option to assist users in finding certain entries.

### Methodology:
_need words here_
- Using stack to build entry journal as in a database
- Each Journal will be give a unique ID and a timestamp of creation
- Password protection will be optional at creation time or further in future
- If password is requested then we will have keyword generation by user choice and using PIV checking system to check on keyword entry everytime.
- Journal unique ID can be searched using Binary Tree search algorithm
- Among deletion unique ID of all items will not be changed or reorganized
_the logic we plan to implement_

*************************************************
********* Diary Management System *********
*************************************************
Methods:
- Add a new journal
- Open Previous Journal
- Search for a journal
  - Date
  - Name
- Delete 
*************************************************

### Timeline:
- Week 1: 
  - Get acquainted with the project's libraries and tools.
- Week 2 to 4: 
  - Create the user interface and put the functionality for managing and creating entries into place.
- Week 5 to 6: 
  - Implement the search and classification features between weeks five and six.
- Week 7 to 8: 
  - Implement the security and encryption features in weeks seven and eight.
- Week 9 to 10: 
  - Debugging and testing in weeks nine and ten.
- Week 11: 
  - Finishing touches and paperwork.

### Conclusion:
- MyDiary is a helpful application for users who wish to securely and efficiently manage the entries in their personal diaries. 
- Users' personal information will be secured by the system's user-friendly design, strong features, and rigorous security. 
- The project will provide a top-notch and useful diary management system, and completion is anticipated in 11 weeks.


## Layered Developement Schedule
### 1. Functional Minimun:

- Creating journals

- Deleting journals

### 2. Low Target:

- Viewing journals

- Editing journals

### 3. Desireable Target:

- Searching journals (by name or date)

### 4. High Target:

- Good writing system

- Change fonts

### 5. Extras:

- Search by text in journal



## Team Members' Roles

### Meet the team:

- Sarthak Adhikari

- Triet Nguyen

- Brooklyn Dressel

### Meeting Plan:
Our group will meet one to two times a week via discord call.  The time will vary week to week depending on our schedules.

### Work Distribution:
We plan to split the work evenly in all aspects of our projects creation, working together on pseudo-code and logic as well as the actual implementation of that logic as code.


## Assessment

### Main Usage:

The main usage of a diary management system would be to provide a platform for individuals to write and manage their personal diary. It would allow users to record their daily events, thoughts, and experiences in a private and secure environment. The system would provide features such as date-wise categorization, text formatting, and search functionality to make it easy for users to access and review their diary entries. Additionally, the system may also offer features such as password protection, backup and restore options, and customization options to enhance the user experience. The overall goal of a diary management system would be to make it simple and convenient for individuals to keep a record of their personal lives.

### Main Users:

A diary management system would primarily be used by those who wanted to keep a log of their daily activities, ideas, and experiences. Students, professionals, authors, and anybody else who wishes to keep a secret, private journal might all be among these users.

### Criteria For Success:

1. User-friendly interface: The system should be easy to use and intuitive, allowing users to quickly and easily input and access their diary entries.

2. Well-organized data: The system should provide an efficient and effective way to categorize and store diary entries, making it simple for users to retrieve and review their information.

3. Customization options: The system should offer customization options to allow users to personalize the look and feel of their diary, such as font and color options.

4. Search functionality: The system should provide a fast and accurate search feature to allow users to quickly find specific diary entries.

5. Reliability: The system should be stable and dependable, ensuring that users can access their diary entries without interruption.

6. Additional features: The system should offer additional features that enhance the diary-keeping experience, such as the ability to insert images and videos, password protection.


# JournalProject
Version 0 Beta 1:
- Features:
  + Application have hard code login credential as "admin"
  + Able to run and add new journal based on manual ID
  + Able to add Entry at the moment
- Issues:
  + No GUI at the moment, only CLI
  + Unable to check if ID is already available
  + Cannot update entry
  + No Login, hard code build auto login
- Upcoming Features:
  + GUI coming soon
  + Add in timestamp
  + Able to check ID
  + Manual Login and Manual Sign Up

Version 0 Beta 1.1:
- Fixes:
  + Added manual entry for username and password
  + Switching from using map to vector to save journals correctly
  + Journal is now displaying all entries
  + Able to load JSON and Print it
  + Move Print function as hard code from main.cpp to journal.h
  + Fixed first screen with limited options
  + After login you will have your entries load up
