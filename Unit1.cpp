//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPPong *PPong;

int x = -4;
int y = -4;
int leftPoints = 0, rightPoints = 0;
int bouncesIterator;

//---------------------------------------------------------------------------
__fastcall TPPong::TPPong(TComponent* Owner)
        : TForm(Owner)
{
verdict-> Left = bg->Width/2 - verdict->Width/2;
nextGame->Left = bg->Width/2 - nextGame->Width/2;
newGame->Left = bg->Width/2 - newGame->Width/2;
leftScore->Left = bg->Left + 10;
leftScore->Top = bg->Height/2 - leftScore->Height/2;
rightScore->Left = bg->Width - 10 - rightScore->Width;
rightScore->Top = bg->Height/2 - leftScore->Height/2;
bounces->Left = bg->Width/2 - bounces->Width/2;
startGame->Left = bg->Width/2 - startGame->Width/2;
b->Top = bg->Height/2;
b->Left = bg->Width/2;
}
//---------------------------------------------------------------------------

void __fastcall TPPong::Timer_ballTimer(TObject *Sender)
{
b->Left += x;
b->Top += y;

leftP -> Left = 100;
rightP->Left = bg->Width - rightP->Width - 100;

if(b->Top -10 <= bg-> Top) y=-y;
if(b->Top + b->Height + 10 >= bg->Height) y=-y;


//skucha lewa
if(b->Left < leftP->Left + leftP->Width - 80)
{
        Timer_ball -> Enabled = false;
        rightPoints++;
        rightScore -> Caption = rightPoints;
        verdict -> Caption = "Punkt dla gracza prawego >";
        verdict -> Left = bg -> Width/2 - verdict -> Width/2;
        verdict -> Visible = true;
        nextGame -> Visible = true;
        newGame -> Visible = true;

}
else if((b->Top + b->Height/2 >= leftP->Top ) && (b->Top + b->Height/2 <= leftP->Top + leftP->Height)
        && (b->Left <= leftP->Left + leftP->Width))
        {
                if((b->Top > leftP->Top + 60) && (b->Top < leftP->Top + 140))
                {
                        leftSound->Play();
                        x = x*1.25;
                        x = -x;
                        bouncesIterator++;
                        bounces -> Caption = bouncesIterator;
                }
                else
                {
                        leftSound->Play();
                        x = -x;
                        bouncesIterator++;
                        bounces -> Caption = bouncesIterator;
                }
        }

        
//skucha prawa
if(b->Left + b->Width >= rightP->Left + 80)
{
        Timer_ball -> Enabled = false;
        leftPoints++;
        leftScore -> Caption = leftPoints;
        verdict -> Caption = "< Punkt dla gracza lewego";
        verdict -> Left = bg -> Width/2 - verdict -> Width/2;
        verdict -> Visible = true;
        nextGame -> Visible = true;
        newGame -> Visible = true;
}

else if ((b->Top + b->Height/2 >= rightP->Top) && (b->Top + b->Height/2 <= rightP->Top + rightP->Height)
        && (b->Left + b->Width >= rightP->Left))
        {
                if((b->Top + b->Width > rightP->Top + 60) && (b->Top + b->Width < rightP->Top + 140))
                {
                        rightSound->Play();
                        x = x*1.25;
                        x = -x;
                        bouncesIterator++;
                        bounces -> Caption = bouncesIterator;
                }
                else
                {
                        rightSound->Play();
                        x = -x;
                        bouncesIterator++;
                        bounces -> Caption = bouncesIterator;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TPPong::leftUpTimer(TObject *Sender)
{
if (leftP->Top > 15) leftP->Top -= 10;        
}
//---------------------------------------------------------------------------
void __fastcall TPPong::leftDownTimer(TObject *Sender)
{
if (leftP->Top + leftP->Height < bg->Height -15 ) leftP->Top += 10;        
}
//---------------------------------------------------------------------------
void __fastcall TPPong::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == 0x41) leftUp ->Enabled = true ;
if(Key == 0x5A) leftDown ->Enabled = true ;

if(Key == VK_UP) rightUp ->Enabled = true ;
if(Key == VK_DOWN) rightDown ->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TPPong::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == 0x41) leftUp -> Enabled = false ;
if(Key == 0x5A) leftDown -> Enabled = false ;
if(Key == VK_UP) rightUp -> Enabled = false ;
if(Key == VK_DOWN) rightDown -> Enabled = false ;        
}
//---------------------------------------------------------------------------
void __fastcall TPPong::rightUpTimer(TObject *Sender)
{
 if (rightP->Top > 15) rightP->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TPPong::rightDownTimer(TObject *Sender)
{
if (rightP->Top + rightP->Height <= bg->Height -15) rightP->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TPPong::FormCreate(TObject *Sender)
{
ShowMessage("Witaj w grze Ping-Pong!!!\nLewy gracz steruje klawiszami A i Z.\nPrawy gracz steruje strza³kami GÓRA i DÓ£. \nOdbicie pi³ki na srodku paletki przyspieszy ruch pi³ki oraz zwiêkszy k¹t odbicia wzglêdem p³aszczyzny paletki.");
leftSound->FileName = "wav/left.wav";
leftSound->Open();
rightSound->FileName = "wav/right.wav";
rightSound->Open();
}
//---------------------------------------------------------------------------
void __fastcall TPPong::nextGameClick(TObject *Sender)
{
bouncesIterator = 0;
verdict -> Visible = false;
nextGame -> Visible = false;
newGame -> Visible = false;
b -> Top = bg -> Height/2;
b -> Left = bg -> Width/2;
x = -4;
x = x * -1;
Timer_ball -> Enabled = true;
bounces -> Caption = 0;
}
//---------------------------------------------------------------------------
void __fastcall TPPong::newGameClick(TObject *Sender)
{
if(Application->MessageBox(
"Czy rozpocz¹c grê od nowa? \nWyniki zostan¹ utracone","Nowa gra",
MB_YESNO | MB_ICONQUESTION) == IDYES)
{
bouncesIterator = 0;
x = -4;
verdict -> Visible = false;
nextGame -> Visible = false;
newGame -> Visible = false;
b -> Top = bg -> Height/2;
b -> Left = bg -> Width/2;
Timer_ball -> Enabled = true;
leftPoints = 0;
rightPoints = 0;
leftScore -> Caption = 0;
rightScore -> Caption = 0;
bounces -> Caption = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TPPong::startGameClick(TObject *Sender)
{
b->Visible = True;
Timer_ball->Enabled=True;
leftScore->Visible = True;
rightScore->Visible = True;
bounces->Visible = True;
startGame->Visible = False;
leftP->Visible = True;
rightP->Visible = True;
verdict->Visible = False;
}
//---------------------------------------------------------------------------


void __fastcall TPPong::FormClose(TObject *Sender, TCloseAction &Action)
{
rightSound->Close();
leftSound->Close();
}
//---------------------------------------------------------------------------

