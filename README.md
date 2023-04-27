# JournalProject
## Version 0 Beta 1:
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
  
## Version 0 Beta 1.1.0:
- Features:
  + Added manual entry for username and password
- Issues:
  + Known Issues from 0B1
  + Still no account sign up
  + Login checking system is not optimal. Need to Login in first then show the other options on the menu
  + Journals are not saved correctly
  + Can only display the first entry that was put in
- Upcoming Features:
  + Known features
  + Attach users to their journal

## Version 0 Beta 1.1.1:
- Fixes:
  + switching from using map to vector to save journals correctly
  + Journal is now displaying all entries
- Upcoming Fixes:
  + Save the journal vector as json
  + Able to read the json to know journals are in there base on their account

## Version 0 Beta 1.1.2:
- Fixes:
  + Save the journal vector as json
  + Able to read the json to know journals are in there base on their account
- Upcoming Fixes -> Beta 1.2.0:
  + Able to load JSON and Print it
  + Move Print function as hard code from main.cpp to journal.h


## Version 0 Beta 1.2.0:
- Fixes:
  + Able to load JSON and Print it
  + Move Print function as hard code from main.cpp to journal.h
  + Fixed first screen with limited option with just logging in
  + After logging in you will have your entries load up in the background
  
## Version 0 Beta 1.2.1:
- Fixes:
  + Testing version 0 beta 1.2.1 of the project. Building checking if the json exist, if
    not then continue instead of breaking the program
- Need to Fix:
  + Automatic Generate ID and Assign for each journal of each user
  + Automatic add in timestamp of creation date
  + Add the timestamp in JSON

## Version 0 Beta 1.2.2:
- Fixes:
  + Automatic Generate ID and Assign for each journal of each user
  + Automatic add in timestamp of creation date
  + Add the timestamp in JSON
- Need to Add:
  + Add remove function
  + Make sure when remove, the entries is not removed entirely, but everything on it will be blank
  + Fix up Print with the remove so that non-blank entries are displaying 

## Version 0 Beta 1.2.3:
- Fixes:
  + Added remove function
  + When removed, entry became blank instead of completely remove. This is in order to hold the integrity of JSON structure
  + Print now print non-blank entries for users

## Version 1.0 Beta
- Features:
  + Account Creation
  + Daily Journal Creation
  + Remove by Journal ID
  + Print as see fit
  + File Save as Json only when logged out ( For security )
