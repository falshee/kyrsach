//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
int zapys=StrToInt(Edit1->Text)+1;
Form1->StringGrid1->RowCount=zapys ;
for (int i=1; i<Form1->StringGrid1->RowCount; i++)
for(int j=1; j<Form1->StringGrid1->ColCount; j++){
Form1->StringGrid1->Cells[0][i] = i;
Form1->StringGrid1->Cells[j][i]=" ";
Form1->StringGrid1->Options =Form1-> StringGrid1->Options << goEditing;
}

Form2->Close();
        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown1ChangingEx(TObject *Sender,
      bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
AllowChange = false;
if(Direction == updUp)
Edit1->Text = IntToStr(StrToInt(Edit1->Text)+1);
if(Direction == updDown)
Edit1->Text = IntToStr(StrToInt(Edit1->Text)-1);

}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{
Form2->Close();
Form1->Show();

}
//---------------------------------------------------------------------------
