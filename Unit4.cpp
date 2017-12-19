//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm4::RadioButton1Click(TObject *Sender)
{
AnsiString rab[5];
for (int i=1;i<Form1->StringGrid1->RowCount;i++)
{
for (int k=1;k<=Form1->StringGrid1->ColCount;k++)
rab[k]=Form1->StringGrid1->Cells[k][i];
int j=i;
while(j>1 && rab[3].ToInt()<Form1->StringGrid1->Cells[3][j-1].ToInt())
{
for (int k=1;k<=Form1->StringGrid1->ColCount;k++)
Form1->StringGrid1->Cells[k][j]=Form1->StringGrid1->Cells[k][j-1];
j--;
}
for (int k=1;k<=Form1->StringGrid1->ColCount;k++)
Form1->StringGrid1->Cells[k][j]=rab[k];
}

}
//---------------------------------------------------------------------------
void __fastcall TForm4::RadioButton2Click(TObject *Sender)
{
AnsiString p;
int k,nmin;
for(int i=1; i<Form1->StringGrid1->RowCount-1; i++){
nmin=i;
for (int j=i+1; j<Form1->StringGrid1->RowCount; j++)
if (StrToInt(Form1->StringGrid1->Cells[3][j])>StrToInt(Form1->StringGrid1->Cells[3][nmin]))
nmin=j;
for (k=1; k<=Form1->StringGrid1->ColCount;k++) {
p=Form1->StringGrid1->Cells[k][i];
Form1->StringGrid1->Cells[k][i]=Form1->StringGrid1->Cells[k][nmin];
Form1->StringGrid1->Cells[k][nmin]=p;}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::RadioButton3Click(TObject *Sender)
{
AnsiString p;
int k,nmin;
for(int i=1; i<Form1->StringGrid1->RowCount-1; i++){
nmin=i;
for (int j=i+1; j<Form1->StringGrid1->RowCount; j++)
if (StrToFloat(Form1->StringGrid1->Cells[2][j])<StrToFloat(Form1->StringGrid1->Cells[2][nmin]))
nmin=j;
for (k=1; k<=Form1->StringGrid1->ColCount;k++) {
p=Form1->StringGrid1->Cells[k][i];
Form1->StringGrid1->Cells[k][i]=Form1->StringGrid1->Cells[k][nmin];
Form1->StringGrid1->Cells[k][nmin]=p;}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::RadioButton4Click(TObject *Sender)
{
AnsiString p;
int k,nmin;
for(int i=1; i<Form1->StringGrid1->RowCount-1; i++){
nmin=i;
for (int j=i+1; j<Form1->StringGrid1->RowCount; j++)
if (StrToFloat(Form1->StringGrid1->Cells[2][j])>StrToFloat(Form1->StringGrid1->Cells[2][nmin]))
nmin=j;
for (k=1; k<=Form1->StringGrid1->ColCount;k++) {
p=Form1->StringGrid1->Cells[k][i];
Form1->StringGrid1->Cells[k][i]=Form1->StringGrid1->Cells[k][nmin];
Form1->StringGrid1->Cells[k][nmin]=p;}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
RadioButton1->Checked = false;
RadioButton2->Checked = false;
RadioButton3->Checked = false;
RadioButton4->Checked = false;
Form4->Close();
}
//---------------------------------------------------------------------------

