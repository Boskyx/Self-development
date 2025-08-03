#include "/home/boskyx/Documents/raylib/src/raylib.h"
#include <string.h>
#include <stdio.h>
#include "library.h"
#include "Windowmain.h"
#include "Windowmode.h"


#define MAX_INPUT_CHARS 32
// Keycode for enter button on keyboard is 257
void window(FILE *fp)
{
    // Inizializza la finestra
    /*Creazione dell'enum così da gestire le 3 modalità della finestra
    Quando si avvia la parte di codice della finestra parte subito con la HOME la quale richiama
    la funzione homescrren nella libreria windowmode che disegna la schermata principale
    In base al testo che si sceglierà READ o INSERT la switch case modificherà lo screen facendo entrare
    in quella schermata*/
    FILE *log_in;
    const float ScreenWidth = 800.0;
    const float ScreenHeight = 450.0;
    typedef enum {HOME, READ, INSERT, LOG_IN} ScreenMode;
    ScreenMode currentscreen = LOG_IN;
    InitWindow(ScreenWidth, ScreenHeight, "Project DataBase");
    char text[MAX_INPUT_CHARS + 1] = "", sent[MAX_INPUT_CHARS + 1] = "", password[]="andrea"; // Buffer per il testo
    int letterCount = 0;
    Rectangle Read = { ScreenWidth / 2 -150, ScreenHeight / 2 - 25, 100, 50 };
    Rectangle Insert = { ScreenWidth / 2+50 , ScreenHeight / 2 - 25, 100, 50 };
    Rectangle Home = { ScreenWidth -30, 0 , 30, 30};
    Rectangle PasswordCheck = {0,0,10,10};
    Rectangle Passwordtest={5,50,80,30};
    char name[MAX_INPUT_CHARS]="", password_insert[MAX_INPUT_CHARS]="";
    int letterCountInsertName=0, letterCountInsertPasword=0, namePressed=0, passwordPressed=0;
    Rectangle Name = { ScreenWidth / 4 -50, ScreenHeight / 2 - 25, 100, 50 };
    Rectangle Password = { ScreenWidth / 2+50 , ScreenHeight / 2 - 25, 200, 50};
    Rectangle Read_screen = { 3, 3, 800, 450 };
    Rectangle Send = { ScreenWidth / 2-25 , ScreenHeight / 2 + 113, 50, 50};
    Rectangle log_in_ins_passw= { ScreenWidth / 2-200, ScreenHeight / 2, 400, 50};
    Rectangle log_in_send_passw= { ScreenWidth / 2-200, ScreenHeight / 2+100, 100, 50};
    bool flagpassword=false; //flag false == RED, true == GREEN
    int ReadPressed=0;
    int InsertPressed=0;
    int nameReady=0, passwordReady=0;
    int log_in_new_passw=0, log_in_send_button=0, master_key_sent=0;
    char Master_Key[MAX_INPUT_CHARS+1]="";
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        switch (currentscreen)
        {

	case LOG_IN:
	    {
		log_in=fopen("Private.txt", "a+");
		size_t ByteRead;
		char buffer[1];
		if ((ByteRead=fread(buffer, 1, sizeof(buffer), log_in))==0)
			{
				
				if(CheckCollisionPointRec(GetMousePosition(), log_in_ins_passw)&&IsMouseButtonPressed(0))
				{
					if(log_in_new_passw==0){log_in_new_passw=1;}
					else{log_in_new_passw=0;}	
				}
				if(CheckCollisionPointRec(GetMousePosition(), log_in_send_passw)&&IsMouseButtonPressed(0))
				{
					if(log_in_send_button==0){log_in_send_button=1;}
					else{log_in_send_button=0;}	
				}
				if (log_in_new_passw==1){
					ShowCursor();
					int key =GetCharPressed();
					while (key > 0)
					 {
						if ((key >= 32) && (key <= 126) && (letterCount < MAX_INPUT_CHARS))
						{
						    Master_Key[letterCount] = (char)key;
						    Master_Key[letterCount + 1] = '\0'; // Null-terminate
						    letterCount++;
						}
						key = GetCharPressed();
					}
					    // Rimuovi carattere con backspace
					    if (IsKeyPressed(KEY_BACKSPACE))
					    {
						if (letterCount > 0)
						{
						    letterCount--;
						    Master_Key[letterCount] = '\0';
						}
					    }
					  
				}
			
				if(log_in_send_button==1){fprintf(log_in, "%s", Master_Key); master_key_sent=1;}
				fclose(log_in);
				log_in_page(log_in_ins_passw, log_in_send_passw, Master_Key, log_in_new_passw,master_key_sent, log_in_send_button);
			}
		else
			{
				char Master_Key_Input[MAX_INPUT_CHARS]="",Master_Key_File[MAX_INPUT_CHARS]="";
				int key = GetCharPressed(), log_in_new_passw=0;
				BeginDrawing();
				ClearBackground(RAYWHITE);
				DrawRectangleRec(log_in_ins_passw, LIGHTGRAY);
				DrawText("Insert Master_Key", ScreenWidth/2, ScreenHeight/2, 30, BLACK);	
				if (CheckCollisionPointRec(GetMousePosition(), log_in_ins_passw)&&IsMouseButtonPressed(0))
				 {                                            
					 log_in_new_passw=1;                                                     
				 }                                                                               
				while (key > 0&&log_in_new_passw==1)                                                     
				  {                                                                                       
					 if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
					 {                                                                       
					     Master_Key_Input[letterCount] = (char)key;
					     Master_Key_Input[letterCount + 1] = '\0'; // Null-terminate                        
					     letterCount++;                                                               
					 }                                                                  
					 key = GetCharPressed();                 
												   
				     // Rimuovi carattere con backspace                                                   
					 if (IsKeyPressed(KEY_BACKSPACE))                                       
					 {                                                                      
						 if (letterCount > 0)                    
						 {                                                         
							 letterCount--;                                        
							text[letterCount] = '\0';                                      
						 }                      
					}                                            
				 } 	
				fgets(Master_Key_File, sizeof(Master_Key_File), log_in);
				if(strcmp(Master_Key_Input, Master_Key_File)==0)
					{
						DrawText("Password correct", ScreenWidth/2, ScreenHeight/2, 30, BLACK);
						currentscreen=HOME;		
					}	
				EndDrawing();
			}
	    } break;
        case HOME:
            {
                // CheckCollisionPointRec controlla se il mouse e' sopra read o insert e se ha cliccato
                if (CheckCollisionPointRec(GetMousePosition(), Read)&&IsMouseButtonPressed(0)&&flagpassword) 
                    {
                        ReadPressed=1;
                    }
                if (CheckCollisionPointRec(GetMousePosition(), Insert)&&IsMouseButtonPressed(0)&&flagpassword) 
                    {
                        InsertPressed=1;
                    }

                // Gestione input
                if (!flagpassword)
                {
                    int key = GetCharPressed();
                    while (key > 0)
                    {
                        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                        {
                            text[letterCount] = (char)key;
                            text[letterCount + 1] = '\0'; // Null-terminate
                            letterCount++;
                        }
                        key = GetCharPressed();
                    }

                    // Rimuovi carattere con backspace
                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        if (letterCount > 0)
                        {
                            letterCount--;
                            text[letterCount] = '\0';
                        }
                    }
                }
                //controlla se esiste testo nel buffer e appena si preme enter fa il check sulla password
                //poi prende la casella di testo e la svuota cosi da scrivere altro testo
                if(strlen(text)>0 && GetKeyPressed()==257)
                {
                    if(strcmp(text, password)==0) //password inserita corretta, mette il flagpassword a true cosi non puoi piu inserire il testo
                    {
                        text[0]='\0';
                        flagpassword=true;

                    }
                    else //password wrong, it delete the buffer and you can try again
                    {
                        text[0]='\0';
                    }
                    letterCount=0;
                }
                //CHANGE SCREEN WINDOW BETWEEN INSERT OR READ BY SWITCHING CASE 
                if (InsertPressed==1)
                {
                    currentscreen=INSERT;
                    InsertPressed=0;
                }
                if (ReadPressed==1)
                {
                    currentscreen=READ;
                    ReadPressed=0;
                }
                homescreen(flagpassword, Read, Insert, PasswordCheck, Passwordtest,text);
            } break;
        
        case READ:
            {
		//Check in the Windowmode if the Option box has selected the "delete" option, in that case it cames back to the home and reopen the fp    
                int delete_row=readscreen(fp, Read_screen, Home); 
                if (CheckCollisionPointRec(GetMousePosition(), Home)&&IsMouseButtonPressed(0)||delete_row==1) {currentscreen=HOME; fclose(fp); fp=fopen("database.txt", "a+");}

            } break;

        case INSERT:
            {
                if (CheckCollisionPointRec(GetMousePosition(), Name)&&IsMouseButtonPressed(0)) 
                {
                    if(namePressed==0) {namePressed=1;}
                    else {namePressed=0;}

                }
                if (CheckCollisionPointRec(GetMousePosition(), Password)&&IsMouseButtonPressed(0)) 
                {
                    if(passwordPressed==0) {passwordPressed=1;}
                    else {passwordPressed=0;}
                }
                if (CheckCollisionPointRec(GetMousePosition(), Send)&&IsMouseButtonPressed(0)&&nameReady==1&&passwordReady==1) 
                {
                    push(fp, name, password_insert);
                    name[0]='\0';
                    letterCountInsertName=0;
                    password_insert[0]='\0';
                    letterCountInsertPasword=0;
                    nameReady=0;
                    passwordReady=0;
                    currentscreen=HOME;
                }
                if (CheckCollisionPointRec(GetMousePosition(), Home)&&IsMouseButtonPressed(0)) {currentscreen=HOME;}
                /*
                ########################################
                NAME INPUT
                ########################################
                */

                if (namePressed==1 && passwordPressed==0)
                {
                    int key = GetCharPressed();
                    while (key > 0)
                    {
                        if ((key >= 32) && (key <= 125) && (letterCountInsertName < MAX_INPUT_CHARS))
                        {
                            name[letterCountInsertName] = (char)key;
                            name[letterCountInsertName + 1] = '\0'; // Null-terminate
                            letterCountInsertName++;
                        }
                        key = GetCharPressed();
                    }
                    nameReady=1;
                }

                /*
                ########################################
                PASSWORD INPUT
                ########################################
                */
           
                if (passwordPressed==1 && namePressed==0)
                {
                    int key = GetCharPressed();
                    while (key > 0)
                    {
                        if ((key >= 32) && (key <= 125) && (letterCountInsertPasword < MAX_INPUT_CHARS))
                        {
                            password_insert[letterCountInsertPasword] = (char)key;
                            password_insert[letterCountInsertPasword + 1] = '\0'; // Null-terminate
                            letterCountInsertPasword++;
                        }
                        key = GetCharPressed();
                    }
                    passwordReady=1;
                }
                insertscreen(Name, Home,Password, Send, name, password_insert, namePressed, passwordPressed);
            } break;

        }


    }

    CloseWindow();
    }

