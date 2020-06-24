//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TPPong : public TForm
{
__published:	// IDE-managed Components
        TShape *bg;
        TImage *b;
        TImage *leftP;
        TImage *rightP;
        TTimer *leftDown;
        TTimer *leftUp;
        TTimer *rightUp;
        TTimer *rightDown;
        TTimer *Timer_ball;
        TLabel *bounces;
        TLabel *leftScore;
        TLabel *rightScore;
        TLabel *verdict;
        TButton *nextGame;
        TButton *newGame;
        TButton *startGame;
        TMediaPlayer *leftSound;
        TMediaPlayer *rightSound;
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall leftUpTimer(TObject *Sender);
        void __fastcall leftDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall rightUpTimer(TObject *Sender);
        void __fastcall rightDownTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall nextGameClick(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall startGameClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TPPong(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPPong *PPong;
//---------------------------------------------------------------------------
#endif
 