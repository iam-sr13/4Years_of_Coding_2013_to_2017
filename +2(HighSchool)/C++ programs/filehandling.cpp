#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#define sstream stringstream
using namespace std;
enum{in,out};
string stringify(int i)
{
	string n;
	sstream ss;
	ss<<i;
	ss>>n;
	ss.str("");
	return n;
}
class file:public fstream
{
	string fname;
	public:
	void getfname(string n)
	{
		fname=n;
	}
	void f_open(string n,int mode=0)
	{
		fname=n;
		switch(mode) {
			case 1: fstream::open(fname.c_str(),ios::in); break;
			case 2: fstream::open(fname.c_str(),ios::out); break;
			default: fstream::open(fname.c_str(),ios::in|ios::out);
		}		
	}		
	void create(string n,string s,int mode=0)
	{		
		f_open(n,mode);		
		fstream::operator<<(s.c_str());		
	}
	void display()
	{
		char s[80];
		while(this->getline(s,80)) {
			cout<<s<<endl;
		}
	}
};

main()
{
	fstream fout,fin;
	string s;
	//[]={"1.00794","4.0026","6.941","9.01218","10.811","12.0107","14.0067","15.9994","18.9984","20.1797","22.9898","24.305","26.9815","28.0855","30.9738","32.065","35.453","39.948","39.0983","40.078","44.9559","47.867","50.9415","51.961","54.938","55.845","58.9332","58.6934","63.546","65.38","69.723","72.63","74.9216","78.96","79.904","83.798","85.4678","87.62","88.9059","91.224","92.9064","95.96","98","101.07","102.906","106.42","107.868","112.411","114.818","118.71","121.76","127.6","126.904","131.293","132.905","137.327","138.905","140.116","140.908","144.242","145","150.36","151.964","157.25","158.925","162.5","164.93","167.259","168.934","173.054","174.967","178.49","180.948","183.84","186.207","190.23","192.217","195.084","196.967","200.59","204.383","207.2","208.98","210","210","222","223","226","227","232.038","231.036","238.029","237","244","243","247","247","251","252","257","258","259","262","267","268","269","270","269","278","281","281","285","286","289","288","293","294","294"};
	//string a[118]={"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Fluorine","Neon","Sodium","Magnesium","Aluminium","Silicon","Phosphorus","Sulfur","Chlorine","Argon","Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium","Tin","Antimony","Tellurium","Iodine","Xenon","Cesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium","Dysprosium","Holmium","Erbium","Thulium","Ytterbium","Lutetium","Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine","Radon","Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium","Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium","Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copernicium","Ununtrium","Flerovium","Ununpentium","Livermorium","Ununseptium","Ununoctium"};
	/*for(int i=1;i<=118;i++) {
		fout.open(("D:\\C++ programs\\QPT\\test prog\\elements\\"+stringify(i)+".txt").c_str(),ios::out|ios::app);
		fout<<endl<<a[i-1];
		fout.close();
	}*/
	
	/*fout.open("filetest\\f1.txt",ios::out);
	for(int i=0;i<=256;i++)	fout<<i<<" "<<char(i)<<endl;
	fout.close();*/
	
	/*fin.open("filetest\\f1.txt",ios::in);
	for(int i=0;i<=256;i++) {
		getline(fin,s);
		cout<<s;
	}
	fin.close();*/
	
	/*for(int i=1;i<=118;i++) {
		
		fin.open(("D:\\C++ programs\\QPT\\test prog\\elements\\"+stringify(i)+".txt").c_str(),ios::in);
		getline(fin,s);
		cout<<s<<" ";
		getline(fin,s);
		cout<<s<<" "<<i<<endl;
		fin.close();
	}*/
}
