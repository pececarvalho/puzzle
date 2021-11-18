/***
*
* by Paulo Cesar de Carvalho
* Game desenvolvido com o intuito de aprendizado da linguagem xHarbour/FiveWin
*
*/
#include "FIVEWIN.ch"
#include "INKEY.ch"
#include "XBROWSE.ch"
#include "SQLLIB.ch"
#include "SQL.ch"
#include "ADORDD.ch"
//-------------------------------------------------------------------------------------------------------------------------
#define NEW_LINE    CHR(13) + CHR(10)
#define BUTTON_ROWS 4
#define BUTTON_COLS 4
//-------------------------------------------------------------------------------------------------------------------------
STATIC oDlg    ,;
       oBtn[18],;
       oSay    ,;
       oTmr    ,;
       lStart  ,;
       nTime
//-------------------------------------------------------------------------------------------------------------------------
INIT PROCEDURE Init()

   Set EPOCH TO 1963
   Set CENTURY ON
   Set Date BRITISH
   Set Deleted ON

RETURN
//-------------------------------------------------------------------------------------------------------------------------
FUNCTION Main()
LOCAL oBmp[2],;
      oSay

   MyPuzzle()

RETURN nil
//-------------------------------------------------------------------------------------------------------------------------
STATIC FUNCTION MyPuzzle()
LOCAL oFont

   DEFINE FONT oFont NAME 'Arial' SIZE 14,12 BOLD

   lStart := .F.
   nTime  := 0

   DEFINE DIALOG oDlg RESOURCE "DIALOG_01" FONT oFont COLOR "B/W"

   REDEFINE BUTTON oBtn[ 1] ID 4001 OF oDlg  ACTION CliqueBotao(4001, {2,5} )
   REDEFINE BUTTON oBtn[ 2] ID 4002 OF oDlg  ACTION CliqueBotao(4002, {1, 3, 6} )
   REDEFINE BUTTON oBtn[ 3] ID 4003 OF oDlg  ACTION CliqueBotao(4003, {2, 4, 7} )
   REDEFINE BUTTON oBtn[ 4] ID 4004 OF oDlg  ACTION CliqueBotao(4004, {3, 8} )

   REDEFINE BUTTON oBtn[ 5] ID 4005 OF oDlg  ACTION CliqueBotao(4005, {1, 6, 9} )
   REDEFINE BUTTON oBtn[ 6] ID 4006 OF oDlg  ACTION CliqueBotao(4006, {2, 5, 7, 10} )
   REDEFINE BUTTON oBtn[ 7] ID 4007 OF oDlg  ACTION CliqueBotao(4007, {3, 6, 8, 11} )
   REDEFINE BUTTON oBtn[ 8] ID 4008 OF oDlg  ACTION CliqueBotao(4008, {4, 7, 12 } )

   REDEFINE BUTTON oBtn[ 9] ID 4009 OF oDlg  ACTION CliqueBotao(4009, {5, 10, 13 } )
   REDEFINE BUTTON oBtn[10] ID 4010 OF oDlg  ACTION CliqueBotao(4010, {6, 9, 11, 14} )
   REDEFINE BUTTON oBtn[11] ID 4011 OF oDlg  ACTION CliqueBotao(4011, {7, 10, 12, 15}  )
   REDEFINE BUTTON oBtn[12] ID 4012 OF oDlg  ACTION CliqueBotao(4012, {8, 11, 16} )

   REDEFINE BUTTON oBtn[13] ID 4013 OF oDlg  ACTION CliqueBotao(4013, {9, 14} )
   REDEFINE BUTTON oBtn[14] ID 4014 OF oDlg  ACTION CliqueBotao(4014, {10, 13, 15} )
   REDEFINE BUTTON oBtn[15] ID 4015 OF oDlg  ACTION CliqueBotao(4015, {11, 14, 16} )
   REDEFINE BUTTON oBtn[16] ID 4016 OF oDlg  ACTION CliqueBotao(4016, {12, 15} )


   REDEFINE BUTTON oBtn[17] ID 4017 OF oDlg ACTION Embaralha() WHEN !lStart     FONT oFont
   REDEFINE BUTTON oBtn[18] ID 4018 OF oDlg ACTION oDlg:End()        FONT oFont

   REDEFINE SAY oSay VAR Transform(StrZero(nTime,5),'99:99') ID 4020 OF oDlg

   SetKey(VK_F2, {|| MyStuff() } )

   SetKey(VK_F10, {|| Resolve() })

   ACTIVATE DIALOG oDlg ON INIT (oDlg:lHelpIcon := .F.) CENTERED


RETURN NIL
//-------------------------------------------------------------------------------------------------------------------------
STATIC FUNCTION BuildTimer()

   DEFINE TIMER oTmr OF oDlg ;
      ACTION ( nTime++, oSay:Refresh() ) INTERVAL 1000
   ACTIVATE TIMER oTmr

RETURN nil
//-------------------------------------------------------------------------------------------------------------------------
STATIC FUNCTION Embaralha()
LOCAL aRnds := {}
LOCAL cGerados, cRandom
LOCAL nRandom
LOCAL i, f

   cGerados:=''
   i:=1
   DO WHILE i<=16
      nRandom := HB_Random(0,18)
      IF nRandom>=1 .AND. nRandom<=16
         cRandom:=IF(nRandom=16,Space(2), Str(nRandom,2))
         IF At(cRandom,cGerados)=0
            cGerados+=cRandom
            AAdd(aRnds, cRandom)
            i++
         ENDIF
      ENDIF
   ENDDO

   FOR i=1 TO 16
      oBtn[i]:SetText( IF(aRnds[i]='16',Space(2),aRnds[i]) )
      oBtn[i]:Refresh()
   NEXT

   lStart := .T.
   TRY
      BuildTimer()
   CATCH oErr
      oTmr:Deactivate()
   FINALLY
   END

RETURN nil
//-------------------------------------------------------------------------------------------------------------------------
STATIC FUNCTION CliqueBotao( Id, aValidos )
LOCAL i, nPos
LOCAL lOk := .F.

   IF !lStart
      MsgAlert ("Clique em 'Iniciar' para começar...","ATENÇÃO")
      RETURN NIL
   ENDIF

   FOR i:=1 TO Len(aValidos)
       nPos := aValidos[i]
       IF oBtn[nPos]:GetText() = Space(2)
          lOk := .T.
          EXIT
       ENDIF
   NEXT

   IF !lOk
      MsgAlert ("Movimento inválido... Tente outra vez!","ATENÇÃO")
      RETURN .F.
   ENDIF

   // Troca o caption dos botões
   oBtn[nPos]:SetText( oBtn[Id-4000]:GetText() )
   oBtn[nPos]:Refresh()

   oBtn[Id-4000]:SetText( Space(2) )
   oBtn[Id-4000]:Refresh()

   IF FimDeJogo()
      MsgAlert ("PUZZLE no tempo de " + Transform(nTime,"@R 99:99"),"PARABÉNS")

      oTmr:Deactivate()
      lStart := .F.

      VeRecord()
      nTime :=0

   ENDIF

RETURN nil
//-------------------------------------------------------------------------------------------------------------------------
STATIC PROCEDURE VeRecord()
LOCAL cn := CreateObject("ADODB.Connection")
LOCAL rs := CreateObject("ADODB.Recordset")
LOCAL cSql, cNome, cNick
LOCAL vRecords := {}, i


   cNome := cNick := Space(20)
   IF !MsgGet("Informe seu nome:", cNome, @cNick)
      RETURN NIL
   ENDIF
   //Access --> ODBC nativo no Windows
   cn:Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\Sistemas\Puzzle\Puzzle.mdb")
   cSql  :="SELECT Data, Nome, Tempo FROM Registros ORDER BY tempo"
   rs:Open(cSql, cn, 2, 3)

   IF rs:Eof()
      MsgInfo('Novo record!','Parabéns')
      rs:AddNew()

      rs:Fields("Data"):Value  := Date()
      rs:Fields("Nome"):Value  := cNick
      rs:Fields("Tempo"):Value := TimeToStr(nTime)
      rs:Update()
   ELSE
      vRecords := {}
      DO WHILE !rs:Eof()
         AAdd( vRecords, { rs:Fields["Data"]:Value()   ,;
                           rs:Fields["Nome"]:Value()   ,;
                           rs:Fields["Tempo"]:Value() } )
         rs:MoveNext()
      ENDDO
   ENDIF

   IF !Empty(vRecords)
      rs:AddNew()

      rs:Fields("Data"):Value  := Date()
      rs:Fields("Nome"):Value  := cNick
      rs:Fields("Tempo"):Value := TimeToStr(nTime)
      rs:Update()
      rs:Close()

      cSql  :="SELECT Data, Nome, Tempo FROM Registros ORDER BY tempo"
      rs:Open(cSql, cn, 2, 3)

      xBrowse( vRecords )
   ENDIF

   rs:Close()
   cn:Close()

RETURN
//-------------------------------------------------------------------------------------------------------------------------
STATIC FUNCTION Resolve()
LOCAL i

   FOR i := 1 TO 15
       oBtn[i]:SetText(Str(i,2))
       oBtn[i]:Refresh()
   NEXT
   oBtn[16]:SetText(' ')
   oBtn[16]:Refresh()
   MsgAlert ("PUZZLE no tempo de " + TimeToStr(nTime),"PARABÉNS")

   oTmr:Deactivate()
   lStart := .F.

   VeRecord()
   nTime :=0


RETURN nil
//-------------------------------------------------------------------------------------------------------------------------
STATIC FUNCTION FimDeJogo()
LOCAL i
LOCAL lResult := .T.

   FOR i := 1 TO 15
      IF oBtn[i]:GetText() != Str(i,2)
         lResult := .F.
         EXIT
      ENDIF
   NEXT

RETURN lResult
//-------------------------------------------------------------------------------------------------------------------------
EXIT PROCEDURE Halt()

   oDlg:End()

   FreeResources() // Set Resources To
   Release All

   SysRefresh()

   /*limpia arreglo y llama al colecor de basura de xharbour*/ //-> Lixeira
   HB_GCALL( .T. )

   PostQuitMessage( 0 )  // use sempre na saida do seu programa

   QUIT              // must be QUIT !!!

RETURN
//-------------------------------------------------------------------------------------------------------------------------
STATIC FUNCTION TimeToStr(t)
LOCAL nSegundos, nMinutos, nHoras
LOCAL cResult

   nMinutos  := 0
   nHoras    := 0
   nSegundos := t
   cResult   := ''

   DO WHILE nSegundos>59
      nMinutos++
      nSegundos-=60
   ENDDO

   DO WHILE nMinutos>59
      nHoras++
      nMinutos-=60
   ENDDO

   IF nHoras > 0
      cResult := Str(nHoras,2)+':'+Strzero(nMinutos,2)+':'+StrZero(nSegundos,2)
   ELSE
      IF nMinutos > 0
         cResult := Str(nMinutos,2)+':'+StrZero(nSegundos,2)
      ELSE
         cResult := '00:'+StrZero(nSegundos,2)
      ENDIF
   ENDIF

RETURN cResult


STATIC FUNCTION MyStuff()
LOCAL cSql := 'SELECT * FROM tabela WHERE id = :pId AND num = :pNum AND data = :pDt'
LOCAL nPos := At(':pId',cSql)

cSql := Stuff(cSql,nPos,Len(':pId'),'x')
nPos := At(':pNum',cSql)
cSql := Stuff(cSql,nPos,Len(':pNum'),'y')


RETURN nil

STATIC FUNCTION CriaBotao(nId)
RETURN


