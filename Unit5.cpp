//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TPasswordDlg *PasswordDlg;
//---------------------------------------------------------------------
__fastcall TPasswordDlg::TPasswordDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TPasswordDlg::OKBtnClick(TObject *Sender)
{
AnsiString p="datapracivnykiv";
AnsiString n= Password->Text;
int i;
if(n==p)
{PasswordDlg->Close();
Form1->Show();
}
for (i=0; i<5; i++)
{if(n!=p)
{MessageBox ( NULL, "Невірний пароль! Спробуйте ще раз", "Попередження", MB_OK+MB_ICONEXCLAMATION);
PasswordDlg->Show();
Form1->Close();  } return;}
}
//---------------------------------------------------------------------------

void __fastcall TPasswordDlg::CancelBtnClick(TObject *Sender)
{
Form1->Close();
PasswordDlg->Close();
}
//---------------------------------------------------------------------------




