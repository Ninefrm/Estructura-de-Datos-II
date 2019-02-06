#include "Menu.h"

void Menu::DATE(){
  char *strDate;
  string str;
  while(true){
      cout << "Fecha: ";
      getline(cin, str);
      strDate = new char[str.length()];
      strcpy(strDate, str.c_str());
      cout << strlen(strDate) << endl;
      if(isValidDate(strDate)){
          strcpy(p.DATE,strDate);
          break;
      }
      else{
          cout << endl;
          cout << "Fecha no valida, intente de nuevo." << endl;
      }
  }
}

void Menu::ADD(){
    cout<<"\t \t FISHBOWL"<<endl<<endl;
    cout<<"AQUARIUS CODE: ";
    cin>>p.CODE;
    cin.ignore();

    DATE();

    cout<<"PH LVL: ";
    cin>>p.PH;

    cout<<"SALINITY LVL:";
    cin>>p.SALINITY;

    cout<<"NITRITES LVL: ";
    cin>>p.NITRITES;

    cout<<"NITRATES LVL: ";
    cin>>p.NITRATES;

    cout<<"AMMONUIM LVL: ";
    cin>>p.AMMONUIM;

    p.STATUS=1;

    ofstream escribir("peceras.txt",ios::app);
    escribir.write((char*)&p,sizeof(p));
    escribir.close();
}

void Menu::SHOW(){
    ifstream leer("peceras.txt");
    if(!leer.is_open())
        cout<<"No records found"<<endl;
    else
    {
        while(!leer.eof())
        {
            leer.read((char*)&p,sizeof(p));

            if(leer.eof())
                break;
            if(p.STATUS==1)
            {
                cout<<"FISHBOWL CODE: #"<<p.CODE<<endl
                    <<"DATE: "<<p.DATE<<endl
                    <<"PH: "<<p.PH<<"\t\tSALINITY: "<<p.SALINITY<<endl
                    <<"NITRITES: "<<p.NITRITES<<"\tNITRATES: "<<p.NITRATES<<endl
                    <<"Ammonium: "<<p.AMMONUIM<<"\tSTATUS: "<<p.STATUS<<endl<<endl;
            }
        }
        leer.close();
    }
}

void Menu::SEARCH(){
    int sch;
    ifstream srch("peceras.txt");
    if(!srch.is_open())
        cout<<"No records found...";
    else
    {

        cout<<"AQUARIUS CODE: ";
        cin>>sch;
        cin.ignore();
        for(int i=0;!srch.eof();i=i+sizeof(p))
        {
            srch.seekg(i,srch.beg);
            srch.read((char*)&p,sizeof(p));
            if(p.CODE==sch&&p.STATUS==1)
            {
                cout<<"FISHBOWL CODE: #"<<p.CODE<<endl
                    <<"DATE: "<<p.DATE<<endl
                    <<"PH: "<<p.PH<<"\t\tSALINITY: "<<p.SALINITY<<endl
                    <<"NITRITES: "<<p.NITRITES<<"\tNITRATES: "<<p.NITRATES<<endl
                    <<"Ammonium: "<<p.AMMONUIM<<endl<<endl;
                    break;
            }
            else if(p.CODE==sch&&p.STATUS==0)
            {
                cout<<"LOGIC DELATED";
                break;
            }
            else
                continue;
        }
    }
}

void Menu::EDIT(){
    int edt;
    fstream EDIT("peceras.txt");

    if(!EDIT.is_open())
        cout<<"NO FILE.";
    else
    {
        cout<<"AQUARIUS CODE: ";
        cin>>edt;
        cin.ignore();

        for(int i=0;!EDIT.eof();i=i+sizeof(p))
        {
            EDIT.seekp(i,EDIT.beg);
            EDIT.read((char*)&p,sizeof(p));
            if(p.CODE==edt&&p.STATUS==1)
            {
                EDIT.seekp(i,EDIT.beg);
                //cout<<"N"<<endl<<endl;
                //cout<<"AQUARIUS CODE: ";
                //cin>>p.CODE;
                //p.CODE = edt;
                //cin.ignore();
                DATE();
                cout<<"PH LVL: ";
                cin>>p.PH;
                cout<<"SALINITY LVL: ";
                cin>>p.SALINITY;
                cout<<"NITRITES LVL: ";
                cin>>p.NITRITES;
                cout<<"NITRATES LVL: ";
                cin>>p.NITRATES;
                cout<<"AMMONUIM LVL: ";
                cin>>p.AMMONUIM;

                EDIT.write((char*)&p,sizeof(p));
                EDIT.close();
                break;
            }
            else if(p.CODE==edt&&p.STATUS==0)
            {
                cout<<"LOGIC DELETED";
                break;
            }
            else
                continue;
        }
    }
}

void Menu::DELETE(){
    int del;

    cout<<"AQUARIUS CODE: ";
    cin>>del;
    cin.ignore();

    ifstream orig("peceras.txt");
    ofstream temp("temp.txt");

    if(!orig.is_open())
        cout<<"NO FILE."<<endl;
    else
    {
        while(!orig.eof())
        {
            orig.read((char*)&p,sizeof(p));
            if(del==p.CODE&&p.STATUS==1)
                cout<<"DELETED."<<endl;
            else
            {
                if(orig.eof())
                    break;
                if(del==p.CODE&&p.STATUS==0)
                    cout<<"LOGIC DELETED.";
                temp.write((char*)&p,sizeof(p));
            }
        }
        orig.close();
        temp.close();
    }
    remove("peceras.txt");
    rename("temp.txt","peceras.txt");
}


void Menu::LOGICDELETE(){
    int ldl;
    fstream LOGICDELETE("peceras.txt");

    if(!LOGICDELETE.is_open())
        cout<<"NO FILE.";
    else
    {
        cout<<"AQUARIUS CODE: ";
        cin>>ldl;
        cin.ignore();
        for(int i=0;!LOGICDELETE.eof();i=i+sizeof(p))
        {
            LOGICDELETE.seekp(i,LOGICDELETE.beg);
            LOGICDELETE.read((char*)&p,sizeof(p));
            if(p.CODE==ldl&&p.STATUS==1)
            {
                LOGICDELETE.seekp(i,LOGICDELETE.beg);
                p.STATUS=0;
                cout<<"LOGIC DELETE";
                LOGICDELETE.write((char*)&p,sizeof(p));
                break;
            }
            else if(p.CODE==ldl&&p.STATUS==0)
            {
                cout<<"LOGIC DELETED";
                break;
            }
            else
                continue;
        }
        LOGICDELETE.close();
    }
}

void Menu::LOGICRES(){
    int lrs;
    fstream LOGICRES("peceras.txt");

    if(!LOGICRES.is_open())
        cout<<"NO FILE";
    else
    {
        cout<<"AQUARIUS CODE:";
        cin>>lrs;
        cin.ignore();
        for(int i=0;!LOGICRES.eof();i=i+sizeof(p))
        {
            LOGICRES.seekp(i,LOGICRES.beg);
            LOGICRES.read((char*)&p,sizeof(p));
            if(p.CODE==lrs&&p.STATUS==0)
            {
                LOGICRES.seekp(i,LOGICRES.beg);
                p.STATUS=1;
                cout<<"ACTIVATED";
                LOGICRES.write((char*)&p,sizeof(p));
                break;
            }
            else if(p.CODE==lrs&&p.STATUS==0)
            {
                cout<<"ACTIVO";
                break;
            }
            else
                continue;
        }
        LOGICRES.close();
    }
}

void Menu::MENU()
{
    size_t opc;

    do
    {
        system("cls");
        cout<<"1.- NEW FISHBOWL"<<endl
            <<"2.- SHOW"<<endl
            <<"3.- SEARCH"<<endl
            <<"4.- EDIT"<<endl
            <<"5.- DELETE"<<endl
            <<"6.- LOGIC ELIMINATION"<<endl
            <<"7.- LOGIC RESTORE"<<endl
            <<"8.- EXIT"<<endl<<endl;
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc)
        {
        case 1:
            ADD();
            break;
        case 2:
            SHOW();
            break;
        case 3:
            SEARCH();
            break;
        case 4:
            EDIT();
            break;
        case 5:
            DELETE();
            break;
        case 6:
            LOGICDELETE();
            break;
        case 7:
            LOGICRES();
            break;
        case 8:
            cout << "PRESS ENTER TO EXIT" << '\n';
            break;
        default:
            cout<<""<<endl;
        }
        cin.ignore();
    }
    while (opc!=8);
}

bool Menu::isValidDate(char* date){
    ///Arreglar lo de los espacios en blanco
    int c = 0, ct = 0;

    if(strlen(date) == 10){
        for(int i=0; i<10; i++){
            if(date[i] >= 48 && date[i] <= 57){
                c++; ///Cuenta que hayan 8 números
            }
        }

        if(date[2] == '/' && date[5] == '/'){
            ct = 1; ///Bandera que detecta las diagonales en dichos índices
        }

        if(c == 8 && ct == 1){
            ///Formato correcto
            string day, month, year;
            int d = 0, m = 0, y = 0;

            for(int i=0; i<=1; i++){
                day+=date[i];
            }

            for(int i=3; i<=4; i++){
                month+=date[i];
            }

            for(int i = 6; i <= 9; i++){
                year+=date[i];
            }

            d = stoi(day);
            m = stoi(month);
            y = stoi(year);

            if(m >= 1 && m <= 12){
                ///Son meses válidos
                if(m == 1 || m == 3 || m == 5 || m == 7 ||
                   m == 8 || m == 10 || m == 12){
                    ///Meses que tienen 31 días
                    if(d >= 1 && d <= 31){
                        return true; ///Días válidos para estos meses
                    }
                    else{
                        return false;
                    }
                }
                else if(m == 2){
                    ///Verificando febrero
                    if(y % 4 == 0){
                        ///Si es año bisiesto
                        if(d >= 1 && d <= 29){
                            return true; ///Días válidos para febrero en año bisiesto
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        ///Si no es año bisiesto
                        if(d >= 1 && d <= 28){
                            return true; ///Días válidos para febrero en año no bisiesto
                        }
                        else{
                            return false;
                        }
                    }
                }
                else{
                    ///Meses que tienen 30 días
                    if(d >= 1 && d <= 30){
                        return true; ///Días válidos para esos meses
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                return false; ///Mes inválido
            }
        }
        else{
            return false; ///Formato incorrecto
        }
    }
    else{
        return false; ///La cadena es mayor o menor a 10 caracteres
    }
}
