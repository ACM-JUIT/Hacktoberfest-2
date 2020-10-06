#include<iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <iomanip.h>

int i,j,li,lp,rec,valid;
void help();
char ch,choice;
class FEE
{
	private :
			int  Class ;
			float tuition, ac, science, computer, activity ;
			void DISPLAY(int) ;
			void MODIFY_RECORD(int, float, float, float, float, float) ;

	public :
			void ADDITION(void) ;
			void MODIFICATION(void) ;
			void FEE_SLIP(void) ;
			void LIST(void) ;
			void HELP(void);
}fee ;



void mainmenu()
{	clrscr();

	gotoxy(15,10);
	cout<<"\      nPress the corresponding Keys for the desired action";
	gotoxy(35,13);

	cprintf("\n F: FEE SLIP");
	gotoxy(35,16);

	cprintf("\n M: MODIFY");
	gotoxy(35,19);
	cprintf("\n Q: QUIT");
	choice=getch();
	ch=toupper(choice);
	switch(ch)
	{
		case'F':fee.FEE_SLIP();
			break;
		case'M':fee.MODIFICATION();
			break;
			case'Q':exit(0);
			break;
		default:gotoxy(33,40);
			cout<<"\nIllegal Choice Press any key to return to Main Menu";
			getch();
			mainmenu();
	}
}

//**********************************************************
// FUNCTION TO ADD FEE STRUCTURE IN FEE FILE
//**********************************************************

void FEE :: ADDITION(void)
{
	fstream file ;
	file.open("FEE.DAT", ios::in) ;
	if (!file.fail())
		return ;
	file.close() ;
	file.open("FEE.DAT", ios::app) ;
	for (int i=1; i<=12; i++)
	{
		Class   = i ;
		tuition  = 0.0 ;
		ac      = 0.0 ;
		science = 0.0 ;
		computer= 0.0 ;
		activity= 0.0 ;
		file.write((char *) this, sizeof(FEE)) ;
	}
	file.close() ;
	MODIFY_RECORD(12,450,50,60,60,50) ;
	MODIFY_RECORD(11,450,50,60,60,50) ;
	MODIFY_RECORD(10,350,50,30,60,50) ;
	MODIFY_RECORD(9,350,50,20,60,50) ;
	MODIFY_RECORD(8,300,50,20,40,50) ;
	MODIFY_RECORD(7,300,50,20,40,50) ;
	MODIFY_RECORD(6,300,50,20,40,50) ;
	MODIFY_RECORD(5,250,50,0,40,40) ;
	MODIFY_RECORD(4,250,50,0,40,40) ;
	MODIFY_RECORD(3,250,50,0,40,40) ;
	MODIFY_RECORD(2,250,50,0,40,40) ;
	MODIFY_RECORD(1,250,50,0,40,40) ;
}




//**********************************************************
// FUNCTION TO DISPLAY THE RECORD FOR THE GIVEN CLASS
//**********************************************************

void FEE :: DISPLAY(int tclass)
{
	fstream file ;
	file.open("FEE.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(FEE)))
	{
		if (Class == tclass)
		{
			gotoxy(5,5) ;
			cout <<"Class : " <<Class ;
			gotoxy(5,7) ;
			cout <<"~~~~~~~~~~~~" ;
			gotoxy(5,8) ;
			cout <<"\nTution Fee  : " <<tuition ;
			gotoxy(5,9) ;
			cout <<"\nAnnual charges Fee  : " <<ac ;
			gotoxy(5,10) ;
			cout <<"\nScience Fee : " <<science ;
			gotoxy(5,11) ;
			cout <<"\nComputer Fee: " <<computer ;
			gotoxy(5,12) ;
			cout <<"\nActivity Fee : " <<activity ;
			break ;
		}
	}
	file.close() ;
}


//**********************************************************
// FUNCTION TO MODIFY THE FEE RECORD FOR THE GIVEN DATA
//**********************************************************

void FEE :: MODIFY_RECORD(int tclass, float ttution, float tac, float
tscience, float tcomputer, float tactivity)
{
	fstream file ;
	file.open("FEE.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while (!file.eof())
	{
		file.read((char *) this, sizeof(FEE)) ;
		if (file.eof())
			break ;
		if (tclass == Class)
		{
			Class   = tclass ;
			tuition  = ttution ;
			ac      = tac ;
			science = tscience ;
			computer= tcomputer ;
			activity= tactivity ;
			temp.write((char *) this, sizeof(FEE)) ;
		}
		else
			temp.write((char *) this, sizeof(FEE)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("FEE.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while (!temp.eof())
	{
		temp.read((char *) this, sizeof(FEE)) ;
		if (temp.eof())
			break ;
		file.write((char *) this, sizeof(FEE)) ;
	}
	file.close() ;
	temp.close() ;
}


//**********************************************************
// FUNCTION TO GIVE DATA TO MODIFY THE FEE RECORD
//**********************************************************

void FEE :: MODIFICATION(void)
{
	clrscr() ;

	char  ch, t1[10] ;
	int   valid=0, t=0, tclass=0 ;
	float t2=0 ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"\nPress <ENTER> for EXIT" ;
		gotoxy(5,5) ; clreol() ;
		cout <<"\nEnter Class for the Modification of the Fee Structure : " ;
		gets(t1) ;
		t = atoi(t1) ;
		tclass = t ;
		if (strlen(t1) == 0)
			return ;
		if (tclass < 1 || tclass > 12)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\n7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	clrscr() ;
	gotoxy(71,1) ;
	cout <<"\n<0>=Exit" ;
	DISPLAY(tclass) ;
	gotoxy(5,25) ; clreol() ;
	do
	{
		gotoxy(5,15) ; clreol() ;
		cout <<"\nDo you want to modify the fee structure (y/n) : " ;
		ch = getche() ;
		if (ch == '0')
			return ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		mainmenu();
	float ttution=0.0, tac=0.0, tscience=0.0, tcomputer=0.0, tactivity=0.0
;
	gotoxy(5,13) ; clreol() ;
	gotoxy(5,17) ;
	cout <<"\nTuition Fee : " ;
	gotoxy(5,18) ;
	cout <<"\nAnnual Charges Fee : " ;
	gotoxy(5,19) ;
	cout <<"\nScience Fee : " ;
	gotoxy(5,20) ;
	cout <<"\nComputer Fee : " ;
	gotoxy(5,21) ;
	cout <<"\nActivity Fee : " ;
	int modified = 5 ;
	fstream file ;
	file.open("FEE.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(FEE)))
		if (Class == tclass)
			break ;
	file.close() ;
	do
	{
		valid = 1 ;
		gotoxy(6,27) ; clreol() ;
		cout <<"\nEnter TUITION FEE or Press <ENTER> for no change  " ;
		gotoxy(19,18) ; clreol() ;
		gets(t1) ;
		t2 = atof(t1) ;
		ttution = t2 ;
		if (t1[0] == '0')
			return;
		if (strlen(t1) == 0)
			break ;
		if (ttution > 1000)
		{
			valid = 0 ;
			gotoxy(5,27) ; clreol() ;
			cout <<"7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t1) == 0)
	{
		modified-- ;
		ttution = tuition ;
		gotoxy(20,17) ;
		cout <<ttution ;
	}
	do
	{
		valid = 1 ;
		gotoxy(6,27) ; clreol() ;
		cout <<"\nEnter ANNUAL CHARGES fee or Press <ENTER> for no change  " ;
		gotoxy(26,18) ; clreol() ;
		gets(t1) ;
		t2 = atof(t1) ;
		tac = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
			break ;
		if (tac > 1000)
		{
			valid = 0 ;
			gotoxy(5,27) ; clreol() ;
			cout <<"\n7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t1) == 0)
	{
		modified-- ;
		tac = ac ;
		gotoxy(26,18) ;
		cout <<tac ;
	}
	do
	{
		valid = 1 ;
		gotoxy(5,27) ; clreol() ;
		cout <<"\nEnter SCIENCE FEES or Press <ENTER> for no change" ;
		gotoxy(19,19) ; clreol() ;
		gets(t1) ;
		t2 = atof(t1) ;
		tscience = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
			break ;
		if (tscience > 1000)
		{
			valid = 0 ;
			gotoxy(5,27) ; clreol() ;
			cout <<"\n7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t1) == 0)
	{
		modified-- ;
		tscience = science ;
		gotoxy(19,19) ;
		cout <<tscience ;
	}
	do
	{
		valid = 1 ;
		gotoxy(5,27) ; clreol() ;
		cout <<"\nEnter COMPUTER FEES or Press <ENTER> for no change" ;
		gotoxy(19,20) ; clreol() ;
		gets(t1) ;
		t2 = atof(t1) ;
		tcomputer = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
			break ;
		if (tcomputer > 1000)
		{
			valid = 0 ;
			gotoxy(5,27) ; clreol() ;
			cout <<"\n7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t1) == 0)
	{
		modified-- ;
		tcomputer = computer ;
		gotoxy(19,20) ;
		cout <<tcomputer ;
	}
	do
	{
		valid = 1 ;
		gotoxy(5,27) ; clreol() ;
		cout <<"\nEnter ACTIVITY FEES or Press <ENTER> for no change" ;
		gotoxy(19,21) ; clreol() ;
		gets(t1) ;
		t2 = atof(t1) ;
		tactivity = t2 ;
		if (t1[0] == '0')
			return;
		if (strlen(t1) == 0)
			break;
		if (tactivity > 1000)
		{
			valid = 0 ;
			gotoxy(5,27) ; clreol() ;
			cout <<"\n7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t1) == 0)
	{
		modified-- ;
		tactivity = activity ;
		gotoxy(19,21) ;
		cout <<tactivity ;
	}
	if (!modified)
		mainmenu();
	gotoxy(5,27) ; clreol() ;
	do
	{
		gotoxy(5,25) ; clreol() ;
		cout <<"\nDo you want to save (y/n) : " ;
		ch = getche() ;
		if (ch == '0')
			return ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	MODIFY_RECORD(tclass,ttution,tac,tscience,tcomputer,tactivity);
	gotoxy(5,27) ;
	cout <<"\n7Record Modified" ;
	gotoxy(5,29) ;
	cout <<"\nPress any key to continue..........." ;
	getch() ;
	mainmenu();
}


//**********************************************************
// FUNCTION TO DISPLAY THE FEE SLIP FOR THE CLASS
//**********************************************************

void FEE :: FEE_SLIP(void)
{
	clrscr() ;
	char  ch, t1[10] ;
	int   valid=0, t=0, tclass=0 ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"\nPress <ENTER> for EXIT" ;
		gotoxy(5,5) ; clreol() ;
		cout <<"\nEnter Class to see the Fee Structure : " ;
		gets(t1) ;
		t = atoi(t1) ;
		tclass = t ;
		if (strlen(t1) == 0)
			return ;
		if (tclass < 1 || tclass > 12)
		{

			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\n7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	char name[26] ;
	do
	{
		gotoxy(5,25) ; clreol() ;
		cout <<"\nENTER NAME OF THE STUDENT" ;
		valid = 1 ;
		gotoxy(5,7) ; clreol() ;
		cout <<"\nName : " ;
		gets(name) ;
		if (strlen(name) < 1 || strlen(name) > 25)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\nNAME SHOULD NOT BE GREATER THAN 25" ;
			getch() ;
		}
	} while (!valid) ;
	clrscr() ;
	cout <<"\n                          NAME OF INSTITUTE      " ;
	int d1, m1, y1 ;
	struct date dt;
	getdate(&dt);
	d1 = dt.da_day ;
	m1 = dt.da_mon ;
	y1 = dt.da_year ;
	cout <<"\n                Date: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	cout <<"\n                NAME  : " <<name ;
	cout <<"\n                CLASS : " <<tclass ;
	cout <<"\n                PARTICULARS               AMOUNT" ;
	fstream file ;
	file.open("FEE.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(FEE)))
		if (Class == tclass)
			break ;
	file.close() ;
	float total=0.0 ;
	cout <<"\n\n\n                Tuition fees               " <<setprecision(2) <<tuition ;
	total = total+tuition ;
	cout <<"\n                Annual charges fees       " <<setprecision(2) <<ac ;
	total = total+ac ;
	cout <<"\n                Science fees              " <<setprecision(2) <<science ;
	total = total+science ;
	cout <<"\n                Computer fees             " <<setprecision(2) <<computer ;
	total = total+computer ;
	cout <<"\n                Activity fees             " <<setprecision(2) <<activity ;
	total = total+activity ;
	char tt[15] ;
	sprintf(tt,"%f",total) ;
	cout <<"\n                Total                     " <<tt ;
	cout<<"\n                                          Cashier" ;
	cout<<"\n       Press any key to return to the main menu........";
	getch() ;
	mainmenu();
}


//**********************************************************
// MAIN FUNCTION TO CREATE MENU AND CALL OTHER FUNCTIONS
//**********************************************************

void main()
{
	FEE fee;
	fee.ADDITION();
	clrscr();

	cout<<"\n                          Welcome To Fee Structure System";
	cout<<"\n                                      Coded By";
	cout<<"\n                                    ARPIT AGRAWAL     ";
	cout<<"\n\n\n                             Press Any Key To Continue";
	getch();
	mainmenu();
}


