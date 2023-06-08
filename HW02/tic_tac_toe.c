/*
 * tic_tac_toe.c
 *
 *  Created on: Oct 5, 2020
 *      Author: Andrew Sabee
 *      YT Vid:
 */

#include "tic_tac_toe.h"

#define VOLT_0P60 745      // 0.85 /(3.3/4096)
#define VOLT_2P70 3351      // 2.50 /(3.3/4096)
int board[3][3] = {{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};

int8_t xPos;
int8_t yPos;
bool xPlaying;
bool xStarted = true;
/*******************************************************************************
* Function Name: tic_tac_toe_hw_init
********************************************************************************
* Summary: Initializes all the hardware resources required for tic tac toe game
*          (IO Pins, ADC14, Timer32_1, Timer32_2).
* Returns:
*  Nothing
*******************************************************************************/
void tic_tac_toe_hw_init(void)
{
    ece353_MKII_S2_Init();
    T32_1_init();
    T32_2_init();
    ece353_ADC14_PS2_XY();
    //center cursor
    xPos = 1;
    yPos = 1;
    //reset board in case a game was being played previously
    board[0][0] = 0;
    board[0][1] = 0;
    board[0][2] = 0;
    board[1][0] = 0;
    board[1][1] = 0;
    board[1][2] = 0;
    board[2][0] = 0;
    board[2][1] = 0;
    board[2][2] = 0;
    //toggle who starts
    xPlaying = xStarted;
    xStarted = !xStarted;

    //Draw Grid
    // Horizontal Lines
    lcd_draw_rectangle(SCREEN_CENTER_COL, UPPER_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLUE);
    lcd_draw_rectangle(SCREEN_CENTER_COL,LOWER_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLUE);

    //Vertical Lines
    lcd_draw_rectangle(LEFT_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH, LINE_LENGTH,LCD_COLOR_BLUE);
    lcd_draw_rectangle(RIGHT_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH,LINE_LENGTH,LCD_COLOR_BLUE);
}

/*******************************************************************************
* Function Name: tic_tac_toe_example_board
********************************************************************************
* Summary: Prints out an example of what the tic-tac-toe board looks like
* Returns:
*  Nothing
*******************************************************************************/
void tic_tac_toe_example_board(void)
{
    // Horizontal Lines
    lcd_draw_rectangle(SCREEN_CENTER_COL, UPPER_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLUE);
    lcd_draw_rectangle(SCREEN_CENTER_COL,LOWER_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLUE);

    //Vertical Lines
    lcd_draw_rectangle(LEFT_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH, LINE_LENGTH,LCD_COLOR_BLUE);
    lcd_draw_rectangle(RIGHT_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH,LINE_LENGTH,LCD_COLOR_BLUE);

    // Top Row
    lcd_draw_image(LEFT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_RED,LCD_COLOR_BLACK);
    lcd_draw_image(CENTER_COL,UPPER_ROW,X_WIDTH,X_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
    lcd_draw_image(RIGHT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_GREEN,LCD_COLOR_BLACK);

    // Center Row
    lcd_draw_image(LEFT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLUE,LCD_COLOR_BLACK);
    lcd_draw_image(CENTER_COL,CENTER_ROW,X_WIDTH,X_HEIGHT,Bitmaps_O,LCD_COLOR_ORANGE,LCD_COLOR_BLACK);
    lcd_draw_image(RIGHT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_CYAN,LCD_COLOR_BLACK);

    // Lower Row
    lcd_draw_image(LEFT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_MAGENTA,LCD_COLOR_BLACK);
    lcd_draw_image(CENTER_COL,LOWER_ROW,X_WIDTH,X_HEIGHT,Bitmaps_X,LCD_COLOR_GRAY,LCD_COLOR_BLACK);
    lcd_draw_image(RIGHT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BROWN,LCD_COLOR_BLACK);
}

/*******************************************************************************
* Function Name: tic_tac_toe_play_game
********************************************************************************
* Summary: Enters the code that plays the tic_tac_toe game.  Once called, this
*          function should never return!
* Returns:
*  Nothing
*******************************************************************************/
void tic_tac_toe_play_game(void)
{
    //start in center of board

    bool returnToCenter = true;
    tic_tac_toe_hw_init();

    while(1){
        if(SCREEN_READY){
            update_screen();
            SCREEN_READY = false;
        }
        if(BUTTON_PRESSED){
            BUTTON_PRESSED = false;
            if(board[xPos][yPos] == 0){ //spot has not been claimed
                board[xPos][yPos] = (xPlaying) ? 1 : 2;
                while(!SCREEN_READY){}; //wait and update screen
                update_screen();
                SCREEN_READY = false;
                winDetection(); //see if the game is over
                xPlaying = !xPlaying; //toggle current player
            }
             //if spot has already been claimed we just ignore the button press
        }
        if(PS2_X_DIR > VOLT_2P70){//joystick is pushed to the right and was previously in the center
            xPos = returnToCenter ? ++xPos : xPos;
            returnToCenter = false;
        }
        else if(PS2_X_DIR < VOLT_0P60){
            xPos = returnToCenter ? --xPos : xPos;
            returnToCenter = false;
        }
        else if(PS2_Y_DIR > VOLT_2P70){
            yPos = returnToCenter ? --yPos : yPos;
            returnToCenter = false;
        }
        else if(PS2_Y_DIR < VOLT_0P60){
            yPos = returnToCenter ? ++yPos : yPos;
            returnToCenter = false;
        }
        else
            returnToCenter = true;

        xPos = xPos % 3;
        yPos = yPos % 3;
        if(xPos < 0)
            xPos = 2;
        if(yPos < 0)
            yPos = 2;
    }
}

void update_screen(void){
    //draw top row
    lcd_draw_rectangle(
           LEFT_COL,
           UPPER_ROW ,
           SQUARE_SIZE,
           SQUARE_SIZE,
           LCD_COLOR_BLACK);
    if(board[0][0] == 1) {// draw an X
        if(xPos == 0 & yPos == 0){//cursor is on this square
            lcd_draw_rectangle(
                       LEFT_COL,
                       UPPER_ROW ,
                       SQUARE_SIZE,
                       SQUARE_SIZE,
                       LCD_COLOR_RED);
            lcd_draw_image(LEFT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
        }
        else{
            lcd_draw_image(LEFT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
        }
    }
    else if(board[0][0] == 2){ //draw an O
        if(xPos == 0 & yPos == 0){
            lcd_draw_rectangle(
                              LEFT_COL,
                              UPPER_ROW ,
                              SQUARE_SIZE,
                              SQUARE_SIZE,
                              LCD_COLOR_RED);
            lcd_draw_image(LEFT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
        }
        else{
            lcd_draw_image(LEFT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
        }
    }
    else if(xPos == 0 & yPos == 0){
        lcd_draw_rectangle(
                          LEFT_COL,
                          UPPER_ROW ,
                          SQUARE_SIZE,
                          SQUARE_SIZE,
                          LCD_COLOR_GREEN);
        if(xPlaying){
            lcd_draw_image(LEFT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
        }
        else {
            lcd_draw_image(LEFT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
        }
    }

    lcd_draw_rectangle(
               CENTER_COL,
               UPPER_ROW ,
               SQUARE_SIZE,
               SQUARE_SIZE,
               LCD_COLOR_BLACK);
   if(board[1][0] == 1){ // draw an X
       if(xPos == 1 & yPos == 0){
           lcd_draw_rectangle(
                          CENTER_COL,
                          UPPER_ROW ,
                          SQUARE_SIZE,
                          SQUARE_SIZE,
                          LCD_COLOR_RED);
        lcd_draw_image(CENTER_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(CENTER_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
       }
   }
   else if(board[1][0] == 2){ //draw an O
       if(xPos == 1 & yPos == 0){
           lcd_draw_rectangle(
                              CENTER_COL,
                              UPPER_ROW ,
                              SQUARE_SIZE,
                              SQUARE_SIZE,
                               LCD_COLOR_RED);
           lcd_draw_image(CENTER_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(CENTER_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
       }
   }
   else if(xPos == 1 & yPos == 0){
       lcd_draw_rectangle(
                                 CENTER_COL,
                                 UPPER_ROW ,
                                 SQUARE_SIZE,
                                 SQUARE_SIZE,
                                 LCD_COLOR_GREEN);
      if(xPlaying){
        lcd_draw_image(CENTER_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
      else {
         lcd_draw_image(CENTER_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
   }

   lcd_draw_rectangle(
                   RIGHT_COL,
                   UPPER_ROW ,
                   SQUARE_SIZE,
                   SQUARE_SIZE,
                   LCD_COLOR_BLACK);
    if(board[2][0] == 1){ // draw an X
        if(xPos == 2 & yPos == 0){
            lcd_draw_rectangle(
                               RIGHT_COL,
                               UPPER_ROW ,
                               SQUARE_SIZE,
                               SQUARE_SIZE,
                               LCD_COLOR_RED);
           lcd_draw_image(RIGHT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
        }
        else{
            lcd_draw_image(RIGHT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
        }
    }
    else if(board[2][0] == 2) {//draw an O
        if(xPos == 2 & yPos == 0){
            lcd_draw_rectangle(
                               RIGHT_COL,
                               UPPER_ROW ,
                               SQUARE_SIZE,
                               SQUARE_SIZE,
                               LCD_COLOR_RED);
           lcd_draw_image(RIGHT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
        }
        else{
            lcd_draw_image(RIGHT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
        }
    }
    else if(xPos == 2 & yPos == 0){
        lcd_draw_rectangle(
                                  RIGHT_COL,
                                  UPPER_ROW ,
                                  SQUARE_SIZE,
                                  SQUARE_SIZE,
                                  LCD_COLOR_GREEN);
       if(xPlaying){
          lcd_draw_image(RIGHT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
       }
       else {
           lcd_draw_image(RIGHT_COL,UPPER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
       }
   }

    //draw middle row
    lcd_draw_rectangle(
           LEFT_COL,
           CENTER_ROW ,
           SQUARE_SIZE,
           SQUARE_SIZE,
           LCD_COLOR_BLACK);
    if(board[0][1] == 1){ // draw an X
        if(xPos == 0 & yPos == 1){
            lcd_draw_rectangle(
                       LEFT_COL,
                       CENTER_ROW ,
                       SQUARE_SIZE,
                       SQUARE_SIZE,
                       LCD_COLOR_RED);
            lcd_draw_image(LEFT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
        }
        else{
            lcd_draw_image(LEFT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
        }
    }
    else if(board[0][1] == 2) {//draw an O
        if(xPos == 0 & yPos == 1){
            lcd_draw_rectangle(
                       LEFT_COL,
                       CENTER_ROW ,
                       SQUARE_SIZE,
                       SQUARE_SIZE,
                       LCD_COLOR_RED);
       lcd_draw_image(LEFT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
        }
        else{
            lcd_draw_image(LEFT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
        }
    }
    else if(xPos == 0 & yPos == 1){
        lcd_draw_rectangle(
                                  LEFT_COL,
                                  CENTER_ROW ,
                                  SQUARE_SIZE,
                                  SQUARE_SIZE,
                                  LCD_COLOR_GREEN);
      if(xPlaying){
         lcd_draw_image(LEFT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
      else {
         lcd_draw_image(LEFT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
  }

    lcd_draw_rectangle(
              CENTER_COL,
              CENTER_ROW ,
              SQUARE_SIZE,
              SQUARE_SIZE,
              LCD_COLOR_BLACK);
   if(board[1][1] == 1){ // draw an X
       if(xPos == 1 & yPos == 1){
           lcd_draw_rectangle(
                         CENTER_COL,
                         CENTER_ROW ,
                         SQUARE_SIZE,
                         SQUARE_SIZE,
                         LCD_COLOR_RED);
       lcd_draw_image(CENTER_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(CENTER_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
       }
   }
   else if(board[1][1] == 2){ //draw an O
       if(xPos == 1 & yPos == 1){
           lcd_draw_rectangle(
                         CENTER_COL,
                         CENTER_ROW ,
                         SQUARE_SIZE,
                         SQUARE_SIZE,
                         LCD_COLOR_RED);
       lcd_draw_image(CENTER_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(CENTER_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
       }
   }
   else if(xPos == 1 & yPos == 1){
       lcd_draw_rectangle(
                                 CENTER_COL,
                                 CENTER_ROW ,
                                 SQUARE_SIZE,
                                 SQUARE_SIZE,
                                 LCD_COLOR_GREEN);
      if(xPlaying){
         lcd_draw_image(CENTER_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
      else {
         lcd_draw_image(CENTER_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
     }

   lcd_draw_rectangle(
                 RIGHT_COL,
                 CENTER_ROW ,
                 SQUARE_SIZE,
                 SQUARE_SIZE,
                 LCD_COLOR_BLACK);
   if(board[2][1] == 1) {// draw an X
       if(xPos == 2 & yPos == 1){
           lcd_draw_rectangle(
                            RIGHT_COL,
                            CENTER_ROW ,
                            SQUARE_SIZE,
                            SQUARE_SIZE,
                            LCD_COLOR_RED);
         lcd_draw_image(RIGHT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(RIGHT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
       }
   }
   else if(board[2][1] == 2){ //draw an O
       if(xPos == 2 & yPos == 1){
           lcd_draw_rectangle(
                                       RIGHT_COL,
                                       CENTER_ROW ,
                                       SQUARE_SIZE,
                                       SQUARE_SIZE,
                                       LCD_COLOR_RED);
         lcd_draw_image(RIGHT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(RIGHT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
       }
   }
   else if(xPos == 2 & yPos == 1){
       lcd_draw_rectangle(
                                 RIGHT_COL,
                                 CENTER_ROW ,
                                 SQUARE_SIZE,
                                 SQUARE_SIZE,
                                 LCD_COLOR_GREEN);
         if(xPlaying){
            lcd_draw_image(RIGHT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
         }
         else {
            lcd_draw_image(RIGHT_COL,CENTER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
         }
     }

    //draw bottom row
   lcd_draw_rectangle(
           LEFT_COL,
           LOWER_ROW ,
           SQUARE_SIZE,
           SQUARE_SIZE,
           LCD_COLOR_BLACK);
   if(board[0][2] == 1){ // draw an X
       if(xPos == 0 & yPos == 2){
           lcd_draw_rectangle(
                      LEFT_COL,
                      LOWER_ROW ,
                      SQUARE_SIZE,
                      SQUARE_SIZE,
                      LCD_COLOR_RED);
      lcd_draw_image(LEFT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(LEFT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
       }
   }
   else if(board[0][2] == 2) {//draw an O
       if(xPos == 0 & yPos == 2){
           lcd_draw_rectangle(
                      LEFT_COL,
                      LOWER_ROW ,
                      SQUARE_SIZE,
                      SQUARE_SIZE,
                      LCD_COLOR_RED);
      lcd_draw_image(LEFT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(LEFT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
       }
   }
   else if(xPos == 0 & yPos == 2){
       lcd_draw_rectangle(
                                 LEFT_COL,
                                 LOWER_ROW ,
                                 SQUARE_SIZE,
                                 SQUARE_SIZE,
                                 LCD_COLOR_GREEN);
         if(xPlaying){
            lcd_draw_image(LEFT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
         }
         else {
            lcd_draw_image(LEFT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
         }
     }

   lcd_draw_rectangle(
             CENTER_COL,
             LOWER_ROW ,
             SQUARE_SIZE,
             SQUARE_SIZE,
             LCD_COLOR_BLACK);
   if(board[1][2] == 1) {// draw an X
       if(xPos == 1 & yPos == 2){
           lcd_draw_rectangle(
                        CENTER_COL,
                        LOWER_ROW ,
                        SQUARE_SIZE,
                        SQUARE_SIZE,
                        LCD_COLOR_RED);
           lcd_draw_image(CENTER_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(CENTER_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
       }
   }
   else if(board[1][2] == 2) {//draw an O
       if(xPos == 1 & yPos == 2){
           lcd_draw_rectangle(
                              CENTER_COL,
                              LOWER_ROW ,
                              SQUARE_SIZE,
                              SQUARE_SIZE,
                              LCD_COLOR_RED);
     lcd_draw_image(CENTER_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(CENTER_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
       }
   }
   else if(xPos == 1 & yPos == 2){
       lcd_draw_rectangle(
                                 CENTER_COL,
                                 LOWER_ROW ,
                                 SQUARE_SIZE,
                                 SQUARE_SIZE,
                                 LCD_COLOR_GREEN);
     if(xPlaying){
        lcd_draw_image(CENTER_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
     }
     else {
         lcd_draw_image(CENTER_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
     }
   }

   lcd_draw_rectangle(
              RIGHT_COL,
              LOWER_ROW ,
              SQUARE_SIZE,
              SQUARE_SIZE,
              LCD_COLOR_BLACK);
   if(board[2][2] == 1){ // draw an X
       if(xPos == 2 & yPos == 2){
           lcd_draw_rectangle(
                         RIGHT_COL,
                         LOWER_ROW ,
                         SQUARE_SIZE,
                         SQUARE_SIZE,
                         LCD_COLOR_RED);
       lcd_draw_image(RIGHT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(RIGHT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_YELLOW,LCD_COLOR_BLACK);
       }
   }
   else if(board[2][2] == 2) {//draw an O
       if(xPos == 2 & yPos == 2){
           lcd_draw_rectangle(
                         RIGHT_COL,
                         LOWER_ROW ,
                         SQUARE_SIZE,
                         SQUARE_SIZE,
                         LCD_COLOR_RED);
       lcd_draw_image(RIGHT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_RED);
       }
       else{
           lcd_draw_image(RIGHT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_CYAN,LCD_COLOR_BLACK);
       }
   }
   else if(xPos == 2 & yPos == 2){
       lcd_draw_rectangle(
               RIGHT_COL,
               LOWER_ROW ,
               SQUARE_SIZE,
               SQUARE_SIZE,
               LCD_COLOR_GREEN);
      if(xPlaying){
         lcd_draw_image(RIGHT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_X,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
      else {
        lcd_draw_image(RIGHT_COL,LOWER_ROW,O_WIDTH,O_HEIGHT,Bitmaps_O,LCD_COLOR_BLACK,LCD_COLOR_GREEN);
      }
   }
}

void winDetection(void){
    bool win = false;
    //check row & col
    if(((board[xPos][0] == board[xPos][1]) & (board[xPos][0] == board[xPos][2])) | ((board[0][yPos] == board[1][yPos]) & (board[0][yPos] == board[2][yPos]))){
        //either the whole row or the whole column matches, check what was just placed to see who won
        if(board[xPos][yPos] == 1)
            lcd_X_wins();
        else
            lcd_O_wins();
        win = true;
    }//check diagonal
    else if( (((board[0][0] == board[1][1]) & (board[0][0] == board[2][2])) | ((board[0][2] == board[1][1]) & (board[0][2] == board[2][0]))) & (board[1][1] != 0)){
        if(board[1][1] == 1)
            lcd_X_wins();
        else
            lcd_O_wins();
        win = true;
    }
    else if(board_full()){
        lcd_tie();
        win = true;
    }
    while(win & !BUTTON_PRESSED){
        ; //infinite loop :)
    }
    if(win){
        BUTTON_PRESSED  = false;
        tic_tac_toe_play_game();
    }
    else
        return;
}

bool board_full(void){
    bool full = (board[0][0] != 0) &  (board[0][1] != 0) & (board[0][2] != 0) &
                (board[1][0] != 0) &  (board[1][1] != 0) & (board[1][2] != 0) &
                (board[2][0] != 0) & (board[2][1] != 0) & (board[2][2] != 0);
    return full;
}


