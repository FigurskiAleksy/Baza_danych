#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <list>

using namespace std;

struct Pojazd
{
  public:
  Pojazd(){}
  virtual void wyswietl_pojazd() const=0;
  virtual void zapisz_pojazd(fstream &plik) const=0;

  ~Pojazd()=default;

  protected:
  string marka;
  string model;
  int przebieg;
  int moc;

};

struct Samochod: Pojazd
{
  public:
  Samochod(string a, string b, int c, int d, int e, int f, string g, string h, string i)
  {
      marka    = a;
      model = b;
      przebieg   = c;
      moc = d;
      liczba_miejsc = e;
      liczba_drzwi = f;
      polozenie_silnika = g;
      orientacja_silnika =h;
      naped = i;
  }

  static void nowy_samochod(vector<Pojazd*>&pojazdy)
  {
    string marka_1;
    string model_1;
    int moc_1;
    int przebieg_1;
    int liczba_miejsc_1;
    int liczba_drzwi_1;
    string naped_1;
    string polozenie_silnika_1;
    string orientacja_silnika_1;

    cin.ignore();
    cout<<"Podaj marke pojazdu \n";
    getline(cin,marka_1);

    cout<<"Podaj model pojazdu \n";
    getline(cin,model_1);

    cout<<"Podaj moc pojazdu \n";
    cin>>moc_1;

    cout<<"Podaj przebieg pojazdu \n";
    cin>>przebieg_1;

    cout<<"Podaj liczbe miejsc \n";
    cin>>liczba_miejsc_1;
    while(liczba_miejsc_1>50)
    {
      cout<<"Oj chyba troche za duzo \n";
      cin>>liczba_miejsc_1;
    }

    cout<<"Podaj liczbe drzwi \n";
    cin>>liczba_drzwi_1;
    while(liczba_drzwi_1>50)
    {
      cout<<"Oj chyba troche za duzo \n";
      cin>>liczba_drzwi_1;
    }

    cout<<"Polozenie silnika (przod/tyl/centralnie) \n";
    cin.ignore();
    getline(cin,polozenie_silnika_1);
    while(polozenie_silnika_1!="przod" && polozenie_silnika_1!="tyl" && polozenie_silnika_1!="centralnie")
    {
    cout << " Powtorz \n";
    getline(cin,polozenie_silnika_1);
    }

    cout<<"Orientacja silnika (wzdluznie/poprzecznie) \n";
    getline(cin,orientacja_silnika_1);
    while(orientacja_silnika_1!="wzdluznie" && orientacja_silnika_1!="poprzecznie")
    {
    cout << " Powtorz \n";
    getline(cin,orientacja_silnika_1);
    } 

    cout<<"Uklad napedowy pojazdu (RWD/FWD/AWD)\n";
    getline(cin,naped_1);
    while(naped_1!="RWD" && naped_1!="FWD" && naped_1!="AWD")
    {
    cout << " Powtorz \n";
    cin.ignore();
    getline(cin,naped_1);
    }
    
    pojazdy.push_back(new Samochod(marka_1, model_1, przebieg_1, moc_1, liczba_miejsc_1, liczba_drzwi_1, polozenie_silnika_1, orientacja_silnika_1, naped_1));


  }
  
  virtual void wyswietl_pojazd() const override
  {
    cout<<"Marka: "<<marka<<"\n";
    cout<<"Model: "<<model<<"\n";
    cout<<"Przebieg: "<<przebieg<<"\n";
    cout<<"Moc: "<<moc<<"\n";
    cout<<"Liczba miejsc: "<<liczba_miejsc<<"\n";
    cout<<"Liczba drzwi: "<<liczba_drzwi<<"\n";
    cout<<"Polozenie silnika: "<<polozenie_silnika<<"\n";
    cout<<"orientacja_silnika: "<<orientacja_silnika<<"\n";
    cout<<"Uklad napedowy: "<<naped<<"\n";
  }

  virtual void zapisz_pojazd(fstream &plik) const override
  {
      int temp=1;
      plik.write((const char*)&temp, sizeof(int));
      plik<<marka<<'\0';
      plik<<model<<'\0';
      plik<<polozenie_silnika<<'\0';
      plik<<orientacja_silnika<<'\0';
      plik<<naped<<'\0';
      plik.write((const char*)&przebieg, sizeof(int));
      plik.write((const char*)&moc, sizeof(int));
      plik.write((const char*)&liczba_miejsc, sizeof(int));
      plik.write((const char*)&liczba_drzwi, sizeof(int));
  }

  static void odczytaj(vector<Pojazd*>&flota, fstream &plik)
  {
      string marka_1;
      string model_1;
      string ps_1;
      string os_1;
      string naped_1;
      int przebieg_1;
      int moc_1;
      int lm_1;
      int ld_1;

      getline(plik,marka_1,'\0');
      getline(plik,model_1,'\0');
      getline(plik,ps_1,'\0');
      getline(plik,os_1,'\0');
      getline(plik,naped_1,'\0');
      plik.read((char*)&przebieg_1, sizeof(int));
      plik.read((char*)&moc_1, sizeof(int));
      plik.read((char*)&lm_1, sizeof(int));
      plik.read((char*)&ld_1, sizeof(int));
      flota.push_back(new Samochod(marka_1, model_1, przebieg_1, moc_1, lm_1, ld_1, ps_1, os_1, naped_1));
  }

  protected:
  int liczba_miejsc;
  int liczba_drzwi;
  string polozenie_silnika;
  string orientacja_silnika;
  string naped;

};

struct Motocykl: Pojazd
{
  public:
  Motocykl(string a, string b, int c, int d, int e, int f, string g)
  {
      marka    = a;
      model = b;
      przebieg   = c;
      moc = d;
      liczba_kol = e;
      liczba_cylindrow = f;
      przeniesienie_napedu = g;
  }
  
  static void nowy_motocykl(vector<Pojazd*>&pojazdy)
  {
    string marka_1;
    string model_1;
    int moc_1;
    int przebieg_1;
    int liczba_kol_1;
    int liczba_cylindrow_1;
    string przeniesienie_napedu_1;

    cin.ignore();
    cout<<"Podaj marke pojazdu \n";
    getline(cin,marka_1);

    cout<<"Podaj model pojazdu \n";
    getline(cin,model_1);

    cout<<"Podaj moc pojazdu \n";
    cin>>moc_1;

    cout<<"Podaj przebieg pojazdu \n";
    cin>>przebieg_1;

    cout<<"Podaj liczbe kol \n";
    cin>>liczba_kol_1;
    while(liczba_kol_1>5)
    {
      cout<<"Oj chyba troche za duzo \n";
      cin>>liczba_kol_1;
    }

    cout<<"Podaj liczbe cylindrow \n";
    cin>>liczba_cylindrow_1;
    while(liczba_cylindrow_1>16)
    {
      cout<<"Oj chyba troche za duzo \n";
      cin>>liczba_cylindrow_1;
    }

    cout<<"Przeniesienie napedu (lancuch/pasek/wal) \n";
    cin.ignore();
    getline(cin,przeniesienie_napedu_1);
    while(przeniesienie_napedu_1!="lancuch" && przeniesienie_napedu_1!="pasek" && przeniesienie_napedu_1!="wal")
    {
    cout << " Powtorz \n";
    getline(cin,przeniesienie_napedu_1);
    }

    pojazdy.push_back(new Motocykl(marka_1, model_1, przebieg_1, moc_1, liczba_kol_1, liczba_cylindrow_1, przeniesienie_napedu_1));

  }

  virtual void wyswietl_pojazd() const override
  {
    cout<<"Marka: "<<marka<<"\n";
    cout<<"Model: "<<model<<"\n";
    cout<<"Przebieg: "<<przebieg<<"\n";
    cout<<"Moc: "<<moc<<"\n";
    cout<<"Liczba kol: "<<liczba_kol<<"\n";
    cout<<"Liczba cylindrow: "<<liczba_cylindrow<<"\n";
    cout<<"Przeniesienie napedu: "<<przeniesienie_napedu<<"\n";
  }

  virtual void zapisz_pojazd(fstream &plik) const override
  {
    int temp=0;
    plik.write((const char*)&temp, sizeof(int));
    plik<<marka<<'\0';
    plik<<model<<'\0';
    plik<<przeniesienie_napedu<<'\0';
    plik.write((const char*)&przebieg, sizeof(int));
    plik.write((const char*)&moc, sizeof(int));
    plik.write((const char*)&liczba_kol, sizeof(int));
    plik.write((const char*)&liczba_cylindrow, sizeof(int));  
  }

  static void odczytaj(vector<Pojazd*>&flota, fstream &plik)
  {
      string marka_1;
      string model_1;
      string pn_1;
      int przebieg_1;
      int moc_1;
      int lk_1;
      int lc_1;

      getline(plik,marka_1,'\0');
      getline(plik,model_1,'\0');
      getline(plik,pn_1,'\0');
      plik.read((char*)&przebieg_1, sizeof(int));
      plik.read((char*)&moc_1, sizeof(int));
      plik.read((char*)&lk_1, sizeof(int));
      plik.read((char*)&lc_1, sizeof(int));
      flota.push_back(new Motocykl(marka_1, model_1, przebieg_1, moc_1, lk_1, lc_1, pn_1));
  }


  protected:
  int liczba_kol;
  int liczba_cylindrow;
  string przeniesienie_napedu;
};

void zapisz_pojazd(vector<Pojazd*>&flota)
{

  fstream plik;
  plik.open("Baza.bin", ios::out | ios::binary);
  const int temp=flota.size();

  if (plik.good())
  {
    plik.write((const char*)&temp, sizeof(int));
    for(int i=0; i<temp; i++)
    {
      flota[i]->zapisz_pojazd(plik);
    }
    plik.close();
  }
};

void odczytaj_pojazd(vector<Pojazd*>&flota)
{
  fstream plik;
  int temp;
  int temp2;
  plik.open("Baza.bin", ios::in | ios::binary);
  if (plik.good())
  {
    flota.clear();
    plik.read((char*)&temp, sizeof(int));
    for(int i=0; i<temp; i++)
    {
      plik.read((char*)&temp2, sizeof(int));
      if(temp2==1)
      {
        Samochod::odczytaj(flota,plik);
      }
      else if(temp2==0)
      {
        Motocykl::odczytaj(flota,plik);
      }
      else
      {
        cout<<"Blad pliku\n";
      }
    }
    
    plik.close();
  }  
}

int main()
{
  int rozmiar=0;
  int a;
  int b;
  string komenda;

  vector<Pojazd*>Korpo_flota; 
  odczytaj_pojazd(Korpo_flota);

  cout << "Witaj w bazie danych samochodow i motocykli. Wybierz komende \n";
  cout << "ds - dodaj samochod \n";
  cout << "dm - dodaj motocykl \n";
  cout << "listuj - wypisz wszystkie pojazdy \n";
  cout << "del - usuń wybrany pojazd \n";
  cout << "zapisz - zapisz baze danych do pliku \n";
  cout << "odczyt - odczytaj baze danych z pliku \n";
  cout << "help - wypisz dostepne komendy \n";
  cout << "koniec - zakoncz dzialanie programu i zapisz baze danych \n";

 for (int i=0;i!=1;) //petla komend
  {
    cout << "Podaj komende \n";
    cin >> komenda;
    
    if (komenda=="ds")
    {
      Samochod::nowy_samochod(Korpo_flota);
    }
    else if (komenda=="dm")
    {
      Motocykl::nowy_motocykl(Korpo_flota);
    }
    else if (komenda=="listuj")
    {
      rozmiar=Korpo_flota.size();

      for (int j=0; j<rozmiar; j++)
      {
        cout<<j+1<<"\n";
        Korpo_flota[j]->wyswietl_pojazd();
        cout<<"\n";
      }
    }
    else if (komenda =="del")
    {
      cout<<"Podaj numer porzadkowy pojazdu do usunięcia \n";
      cin>>a;
      a=a-1;
      Korpo_flota.erase(Korpo_flota.begin()+a);
    }
    else if (komenda =="zapisz")
    {
      zapisz_pojazd(Korpo_flota);
    }
    else if (komenda =="odczyt")
    {
      odczytaj_pojazd(Korpo_flota);
    }
    else if (komenda == "koniec")
    {
      zapisz_pojazd(Korpo_flota);
      i=1;
    }
    else if (komenda == "help")
    {
      cout << "ds - dodaj samochod \n";
      cout << "dm - dodaj motocykl \n";
      cout << "listuj - wypisz wszystkie pojazdy \n";
      cout << "del - usuń wybrany pojazd \n";
      cout << "zapisz - zapisz baze danych do pliku \n";
      cout << "odczyt - odczytaj baze danych z pliku \n";
      cout << "help - wypisz dostepne komendy \n";
      cout << "koniec - zakoncz dzialanie programu \n";
    }
  }

}