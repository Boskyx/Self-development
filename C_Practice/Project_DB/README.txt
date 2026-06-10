The aim of the project is to create a db that can store name and password.
Data will be insert by a UX that permits to insert name and pass and push on the db (button send not now implemented)
The first window will have 2 options
1) Insert or Read (to abilitate the 2 options is required a password that switch on a box in green if is ok or remains red if the pass
is incorrect)
Insert open another window where you can write your info and then send to the db
Read permits to see all the db and do a search inside it

#########################
Update date: 29.03.2025

PROBLEM
When we run the main (due to the fact that it has is fist row the window func) it opens the windows but in old versione (box where you
can write things and then press enter to see in the terminal the output)
This Window func has also the feature to enable or disable the box where you write things (in that way only if you click on 
the box the program allow you to write, otherwise you cannot write and the enter button is disabled)

TODO
- Convert all the code in c (it derives from python)
- Windowinsert Library func will only manage the windows
    it has the first window with 2 button READ Insert
    The buttons are disabled and there is a box for the password (if corret a flag green shown it and the boxes will have the border green)
    If you push read it change the windows and shows all the data in the file 
    If you push Insert it open a windows where you can write name and password and insert on the db
- Library has to store all the functions to find, insert data 

TODO FUTURE
- encrypt the data inside the db.txt file, now is accessible

OUTPUT OF TODAY WORK:

DO
-Created the main windows, the password is a variable per-determined 
-Created the 2 boxes (Read Insert), create the sistem that if you insert the correct password it change the box flag password from red to green
-Created the system that if you put the correct password it enables the 2 main boxes 

PENDING
-find a way that if you click on Read or Insert Box it kill the actual windows and reopen a new open, i'm trying via a new library for the read window but
it generates some conflict when run the main.c, maybe because it's finding a way to open 2 windows when compiled???


################## 
30.03.2025

TODO
- Convert all the code in c (it derives from python) -> DONE
- Windowinsert Library func will only manage the windows
    it has the first window with 2 button READ Insert -> DONE
    The buttons are disabled and there is a box for the password (if corret a flag green shown it and the boxes will have the border green) ->DONE
    If you push read it change the windows and shows all the data in the file 
    If you push Insert it open a windows where you can write name and password and insert on the db
- Library has to store all the functions to find, insert data 

TODO FUTURE
- encrypt the data inside the db.txt file, now is accessible

DO
- Defined a way to change windows when you click on the Read or Insert button

NOT DO
- create the 2 windows for READ and Insert
- join the main code with the 2 window to manage the way of inserting or reading the information from and on the 
  db file

#########################
Update date: 27.04.2025 #
#########################

PROBLEM
-   in INSERT mode when you put some letters it refresh immediately and it doesn save the entire string

DONE
-   Modified the main so the struct db is only inside the libray.c
-   Modified the windowsmain.c now it take the FILE *fp (the opening and close is in the main.c) as argumetn for the 2 windows mode 
-   Windowmode now for the INSERT screen create 2 boxes (Name and password) + 1 red for the send function (it will call the push() to insert on the db)

NOT DO
-   Creation of the 2 windows for READ and Insert
-   Join the main code with the 2 window to manage the way of inserting or reading the information from and on the 
    db file


#########################
Update date: 28.04.2025 #
#########################

PROBLEM
-   in INSERT mode when you put some letters it refresh immediately and it doesn't save the entire string
    RESOLVED but i had to put the entire code of the InsertMode on the windowmain file, this is not very helpfull


DONE
-   Adjusted the windowmain now it call the push() and insert the name


NOT DO
-   adjusted in the windowmain when you write the name and passwrod the send button doesnt work


#########################
Update date: 11.05.2025 #
#########################


PROBLEM
-   When you run the programm it goes in segmentation fault (core dumped)
    -> RESOLVED because when you run the program you have to specify in the terminal the name of the file

DONE
-   Resolved, the password is correctly insert in the database file 
-   Delete part of the code in the push() function, it doesn't required the linked list approach, it has only to write the things inside the .txt file

NOT DO
-   Resolve the problem when you click the read button it prints the linked list from the last entry to the first, but in this case we need the inverse list 
    I tried to reverse it but it doesnt work now


#########################
Update date: 21.05.2025 #
#########################

DONE
-   Resolved the problem linked with the Read button for the Read screen, it went in segmentation fault caused by the while loop tha was infinite
-   Resolved the problem with READ, cancelled the linked list and in the Windowmode we read directly the file and print the buffer, easy and fast
-   Insert a button in READ and INSERT to go in the HOME

TO DO
-   Change the Read screen
-   Creation of a cryption system (i started it but the decription doesn work very well)


#########################
Update date: 22.05.2025 #
#########################

DONE
-   Created a Cryptograph system, now if you read the txt file you are not able to understand name and passwords inserted
-   Changed the Read Screen 

TO DO
-   Create a way to delete some entry, from READ screen you can select the entry e press delete
    After the delete the file will have removed the row and bring up by 1 row all the other entries

#########################
Update date: 24.05.2025 #
#########################

TO DO
-   2 new functions for delete anche check in what box you are clicking (it will help maybe for select the correct row when you want to delete something into the txt file)


#########################
Update date: 24.05.2025 #
#########################

DONE
-   implemented the raygui library to create button on the read mode


#########################
Update date: 02.06.2025 #
#########################

TO DO 
-   Create 2 functions delete_row and change_row to handle if you want to change name or password of a line or if you want to delete completelly

DONE
-   Created the delete_row function it creates a copy of the file and put inside all the rows expection for the one selected for the delete

PROBLEM
-   It goes back to the home but it doesnt update the file so you will keep see the row deleted

#########################
Update date: 20.07.2025 #
#########################

TO DO
-   Linked the info box on the readscreen to the Password, in that way it doesn't go in overlapping
-   Use the makefile to find the path of raylib and automated the include of the path
-   CREATE the first screen where you ask for the password and if corret you go in the main screen

DONE
-   Discoverd that the #include could not handle a variabile because the preprocessor starts before the compiler and the makefile
    But with FILES := $(shell find / -type f -name raylib.h 2>/dev/null | head -n 1) you can store the path inside the var FILES 
    Here we use head -n 1 because there are 2 paths but we want only the first one

#########################
Update date: 27.07.2025 #
#########################

TO DO 
- Insert a Home_page in enum to handle the insert of the passw before go inside the Read and Insert Screen
  If is the first time (so there isn't the Key.txt file) it ask to create from the home_page, after this one it only ask to insert it and it do the check if is correct.
  Before that it encryp it in the txt file.	
- Create the main page layout and the encryption of the password set by the user in the key.txt file.
  Remember when do the check do decrypt it before.

DONE BUT NOT COMPLETED
- Insert the MAIN PAGE for handling the passw insert in Windowmain.c as enum and the switch case
- Insert the main_page_screen functionr in the Windomode.c and .h  



#########################
Update date: 01.08.2025 #
#########################

TO DO
- Implement home_page_screen (better if call it LOG IN PAGE), it has to open a main screen where it ask for a password before give you the possibility to select read o insert.
- READ & INSERT need to give you the possibility to LOG OUT and came back to the LOG IN PAGE 


#########################
Update date: 03.08.2025 #
#########################

TO DO 
- Finish the implementation for the log_in page
- Log_in_page -> Fix the highlight of the box for the password insert (green when you click on it)
- Log_in_page -> Fix the insertion of the Key and the store of it in the Private.txt file.
- Log_in_page -> Insert the send button and manage the storing of the key in the Private.txt + message when the key was stored "successfully stored"
- Log_in_page -> Complete the else function if the Private.txt exists and is not empty
- Log_in_page -> Create the encryption system for the Key stored in the Private.txt file
- Change the home_page, it doesn't required any more the password insertion

DONE
- Resolved the problem with the log_in page segm. fault, the way to check the file Private.txt is by using the fread() with a buffer with 1 byte as a check between the file and the buffer
  The fread() reads the specified amount of data from one stream and stored it in the buffer. 
  The function stored the first byte in the buffer and check if it's 0 or not.
  0 stands for no data in the file given. 
- Fixed the highlight of the box for the insertion
- Log_in_page -> adjust the screen when the Private.txt is filled and now it check if you insert the correct password
                 when the password is correct it automatically send in the Home Page.
- Home_page -> change the logic, now it doesn't required the password and you can go in READ and INSERT


NOT DO
- Log_in_page need to encrypt the master_key when you put in the Private.txt!!! CREATE A SPECIFIC FUNCTION IN LIBRARY FOR ENCRYPTION AND DECRYPTION!!!
- Home_page adjust the QUIT logic to come back to the log_in page
