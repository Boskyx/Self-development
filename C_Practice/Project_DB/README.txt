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
