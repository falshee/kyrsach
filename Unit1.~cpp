//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <cstring.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool isClear = true;
int temp;
int num;
AnsiString stemp;
class Delete_StringGrid
: public TStringGrid {
public:
using TStringGrid::DeleteRow;
};
THintWindow;//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
StringGrid1->Cells[0][0]="№";
StringGrid1->Cells[1][0]="ПІБ працівника";
StringGrid1->Cells[2][0]="Зарплата, грн";
StringGrid1->Cells[3][0]="Стаж роботи, років";
PageControl1->Pages[0]->Brush->Color=clGradientInactiveCaption;
PageControl1->Pages[1]->Brush->Color=clGradientInactiveCaption;
PageControl1->Pages[2]->Brush->Color=clGradientInactiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{//Вихід з БД
exit(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{  //Відкриття  БД
for (int i=StringGrid1->FixedCols; i<StringGrid1->ColCount; i++)
OpenDialog1->Title="Відкрити";
OpenDialog1->InitialDir=Application->ExeName;
if (OpenDialog1->Execute())
{
AnsiString name;
name=OpenDialog1->FileName;
{
ifstream input(name.c_str());
if(input.is_open()) {
int i=1;
StringGrid1->RowCount=i+1;
while(!input.eof()){
for (int i=1;i<=StringGrid1->RowCount;i++)
StringGrid1->Cells[0][i] = i;
for(int j=1; j< StringGrid1->ColCount;j++){
input.getline(stemp.c_str(), 999, '\n');
StringGrid1->Cells[j][i] = stemp.c_str();
}
i++;
StringGrid1->RowCount++;
}
StringGrid1->RowCount--;
i--;
} else {
MessageBox ( NULL, "Помилка при відкритті файлу", "Попередження", MB_OK+MB_ICONEXCLAMATION );
} }}
StringGrid1->Options =Form1-> StringGrid1->Options >> goEditing >>goTabs;;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{ //Збереження БД
TStringList *List = new TStringList();
for (int i=1; i<StringGrid1->RowCount; i++)
{
for (int j=1; j<StringGrid1->ColCount; j++)
{
List->Add(StringGrid1->Cells[j][i]);
List->SaveToFile("dani_pracivnykiv.txt");
}}
delete List;
List=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
if(SaveDialog1->Execute())
{
SaveDialog1->Execute();
TStringList *List = new TStringList(); 
for (int i=1; i<StringGrid1->RowCount; i++) 
{ 
for (int j=1; j<StringGrid1->ColCount; j++) 
{ 
List->Add(StringGrid1->Cells[j][i]); 
List->SaveToFile(SaveDialog1->FileName);
} }
delete List;
List=NULL;}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{ //Очищення БД
for (int i=0; i<StringGrid1->RowCount; i++)
{
for (int j=0; j<StringGrid1->ColCount; j++)
{
StringGrid1->Cells[j+1][i+1]="";
StringGrid1->Cells[0][i+1]=i+1;
}}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{  //Створення БД
Form2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{ //Додавання запису
for (int i=1; i<StringGrid1->RowCount; i++) {
for (int j=1; j<StringGrid1->ColCount; j++){
if(StringGrid1->Cells[j][i]==""){
isClear=true;
} else {
isClear=false;
}
}}
if (!isClear){
if(LabeledEdit1->Text=="" || LabeledEdit2->Text=="" || LabeledEdit3->Text=="" )
{MessageBox(NULL,"Залишились пусті поля", "Попередження", MB_OK+MB_ICONEXCLAMATION);}
else {
StringGrid1->RowCount=StringGrid1->RowCount+1;
num= StringGrid1->RowCount-1;
StringGrid1->Cells[0][num]=IntToStr(num);
StringGrid1->Cells[1][StringGrid1->RowCount - 1] = LabeledEdit1->Text;
StringGrid1->Cells[2][StringGrid1->RowCount - 1] = LabeledEdit2->Text;
StringGrid1->Cells[3][StringGrid1->RowCount - 1] = LabeledEdit3->Text;
}
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
LabeledEdit1->Text="";
LabeledEdit2->Text="";
LabeledEdit3->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{ //Редагування запису
isClear = true;
AnsiString EditIndex=InputBox("Редагування","Введіть номер запису для редагування","");
if (EditIndex=="") return;
if(isClear) {
if(StrToInt(EditIndex)<StringGrid1->RowCount && StrToInt(EditIndex)!=0) {
LabeledEdit4->Text = StringGrid1->Cells[0][StrToInt(EditIndex)];
LabeledEdit5->Text = StringGrid1->Cells[1][StrToInt(EditIndex)];
LabeledEdit6->Text = StringGrid1->Cells[2][StrToInt(EditIndex)];
LabeledEdit7->Text = StringGrid1->Cells[3][StrToInt(EditIndex)];
} else {
MessageBox ( NULL, "Такого запису не існує", "Попередження", MB_OK+MB_ICONEXCLAMATION);
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{ //Збереження редагування
if(LabeledEdit4->Text=="" || LabeledEdit5->Text=="" || LabeledEdit6->Text=="" || LabeledEdit7->Text=="")
MessageBox(NULL,"Залишились пусті поля", "Попередження", MB_OK+MB_ICONEXCLAMATION);
else {
StringGrid1->Cells[0][StrToInt(LabeledEdit4->Text)]=LabeledEdit4->Text;
StringGrid1->Cells[1][StrToInt(LabeledEdit4->Text)]=LabeledEdit5->Text;
StringGrid1->Cells[2][StrToInt(LabeledEdit4->Text)]=LabeledEdit6->Text;
StringGrid1->Cells[3][StrToInt(LabeledEdit4->Text)]=LabeledEdit7->Text;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
LabeledEdit4->Text="";
LabeledEdit5->Text="";
LabeledEdit6->Text="";
LabeledEdit7->Text="";

}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{ //Видалення запису
num=StrToInt(LabeledEdit8->Text);
if(num>=StringGrid1->RowCount) {
MessageBox ( NULL, "Такого запису не існує", "Попередження", MB_OK+MB_ICONEXCLAMATION );
} else {

for(int i=1;i<StringGrid1->RowCount;i++) {
if(StringGrid1->Cells[0][i]==num) {
for(int j=0;j<StringGrid1->ColCount;j++) {
StringGrid1->Cells[j][i]="";
}
for(int i=num;i<StringGrid1->RowCount;i++) {
for(int j=0;j<StringGrid1->ColCount;j++) {
StringGrid1->Cells[j][i]=StringGrid1->Cells[j][i+1];
}
}
StringGrid1->RowCount--;
num= StringGrid1->RowCount;
for(int i=1;i<StringGrid1->RowCount;i++) {
StringGrid1->Cells[0][i]=IntToStr(i);
}
}
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{ //Упорядкування БД
Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{float x[1000];
for(int i=1;i<StringGrid1->RowCount;i++){
if(StrToInt(StringGrid1->Cells[3][i])>10)
{
x[i]=StrToFloat(StringGrid1->Cells[2][i]);
x[i]=x[i]*1.1;  }
else x[i]=StrToFloat(StringGrid1->Cells[2][i]);}
for(int i=1;i<StringGrid1->RowCount;i++)
{StringGrid1->Cells[2][i]=FloatToStrF(x[i], ffFixed,7,2);
}
MessageBox ( NULL, "Збільшено на 10% заробітну плату працівникам, що мають стаж роботи більше 10 років", "Розрахунок", MB_OK+MB_ICONINFORMATION);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N15Click(TObject *Sender)
{
 //Запит
int i;
AnsiString  EditZarplata=InputBox("Пошук","Введіть необхідну заробітну плату","");
if (EditZarplata=="") return;
for(int i=1;i<=StringGrid1->RowCount;i++)
{if(StringGrid1->Cells[2][i]==EditZarplata){
StringGrid1->Cells[0][i] =StringGrid1->Cells[0][i];
StringGrid1->Cells[1][i] =StringGrid1->Cells[1][i];
StringGrid1->Cells[2][i] =StringGrid1->Cells[2][i];
StringGrid1->Cells[3][i] =StringGrid1->Cells[3][i];}
else {StringGrid1->Rows[i]->Clear();}
}
{for (size_t i=StringGrid1->FixedRows, end=StringGrid1->RowCount; i<end; i++)
{if (StringGrid1->Rows[i]->Text.Trim().IsEmpty())
{((Delete_StringGrid*)StringGrid1)->DeleteRow(i--);
--end;}}
StringGrid1->RowCount=i;}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
 //Запит
int i;
AnsiString  EditZarplata=InputBox("Пошук","Введіть стаж роботи","");
if (EditZarplata=="") return;
for(int i=1;i<StringGrid1->RowCount;i++)
{if(StringGrid1->Cells[3][i]==EditZarplata)
{
StringGrid1->Cells[0][i] =StringGrid1->Cells[0][i];
StringGrid1->Cells[1][i] =StringGrid1->Cells[1][i];
StringGrid1->Cells[2][i] =StringGrid1->Cells[2][i];
StringGrid1->Cells[3][i] =StringGrid1->Cells[3][i];}
else {StringGrid1->Rows[i]->Clear();} }
{for (size_t i=StringGrid1->FixedRows, end=StringGrid1->RowCount; i<end; i++)
{if (StringGrid1->Rows[i]->Text.Trim().IsEmpty())
{((Delete_StringGrid*)StringGrid1)->DeleteRow(i--);
--end;}}
StringGrid1->RowCount=21;}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N14Click(TObject *Sender)
{ifstream input("dani_pracivnykiv.txt");
if(input.is_open()) {
int i=1;
StringGrid1->RowCount=i+1;
while(!input.eof()){
for (int i=1;i<=StringGrid1->RowCount;i++)
StringGrid1->Cells[0][i] = i;
for(int j=1; j< StringGrid1->ColCount;j++){
input.getline(stemp.c_str(), 999, '\n');
StringGrid1->Cells[j][i] = stemp.c_str();
}
i++;
StringGrid1->RowCount++;
}
StringGrid1->RowCount--;
i--;
} else {
MessageBox ( NULL, "Помилка при відкритті файлу", "Попередження", MB_OK+MB_ICONEXCLAMATION);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
PasswordDlg->ShowModal();
}
//---------------------------------------------------------------------------


