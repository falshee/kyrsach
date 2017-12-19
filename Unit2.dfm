object Form2: TForm2
  Left = 615
  Top = 295
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1057#1090#1074#1086#1088#1077#1085#1085#1103' '#1041#1044
  ClientHeight = 151
  ClientWidth = 266
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 249
    Height = 129
    Caption = #1056#1086#1079#1084#1110#1088' '#1041#1044
    Color = clGradientInactiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 40
      Width = 111
      Height = 20
      Caption = #1063#1080#1089#1083#1086' '#1079#1072#1087#1080#1089#1110#1074':'
    end
    object Edit1: TEdit
      Left = 136
      Top = 40
      Width = 89
      Height = 28
      TabOrder = 0
      Text = '0'
    end
    object UpDown1: TUpDown
      Left = 225
      Top = 40
      Width = 16
      Height = 28
      Associate = Edit1
      Min = 0
      Position = 0
      TabOrder = 1
      Wrap = False
      OnChangingEx = UpDown1ChangingEx
    end
    object BitBtn1: TBitBtn
      Left = 16
      Top = 80
      Width = 73
      Height = 33
      Caption = #1054#1050
      TabOrder = 2
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 144
      Top = 80
      Width = 89
      Height = 33
      Caption = 'Cancel'
      TabOrder = 3
      OnClick = BitBtn2Click
    end
  end
end
