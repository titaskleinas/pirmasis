#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char fd[]="gaminii.txt";
const char fr[]="rezultati.txt";

void ivedimas(int &n);
void gaminiai(int n, int &mil, int &cukr);
void spausdinimas(int mil, int cukr, int n);

struct gaminys{
	string pav;
	int a;
	int b;
};

gaminys mas[100];
string gam[100];

int main()
{
	int n;
	int mil=0, cukr=0;
	ivedimas(n);
	gaminiai(n, mil, cukr);
	spausdinimas(mil, cukr, n);
cout <<"   ___ ___         .__  .__                               .__       .___ "<<endl;
cout <<"  /   |   \   ____ |  | |  |   ____   __  _  _____________|  |    __| _/ "<<endl;
cout <<" /    ~    \_/ __ \|  | |  |  /  _ \  \ \/ \/ /  _ \_  __ \  |   / __ |  "<<endl;
cout <<" \    Y    /\  ___/|  |_|  |_(  <_> )  \     (  <_> )  | \/  |__/ /_/ |  "<<endl;
cout <<"  \___|_  /  \___  >____/____/\____/    \/\_/ \____/|__|  |____/\____ |  "<<endl;
cout <<"        \/       \/                                                  \/  "<<endl;

cout <<" _____.___.                              __    .__                   __              .___"<<endl;
cout <<" \__  |   | ____  __ __     ____   _____/  |_  |  |__ _____    ____ |  | __ ____   __| _/"<<endl;
cout <<"  /   |   |/  _ \|  |  \   / ___\ /  _ \   __\ |  |  \\__  \ _/ ___\|  |/ // __ \ / __ | "<<endl;
cout <<"  \____   (  <_> )  |  /  / /_/  >  <_> )  |   |   Y  \/ __ \\  \___|    <\  ___// /_/ | "<<endl;
cout <<"  / ______|\____/|____/   \___  / \____/|__|   |___|  (____  /\___  >__|_ \\___  >____ | "<<endl;
cout <<"  \/                     /_____/                    \/     \/     \/     \/    \/     \/ "<<endl;


	return 0;
}

void ivedimas(int &n)
{
	char kint;
	int x=1;
	string pav1;
	ifstream d(fd);
	d >> n;
	
	for (int i=0; i < n; i++)
	{
		
		d >> kint;
		while (x!=0)
	    {
			d >> pav1;
			mas[i].pav=mas[i].pav+pav1;
			if (pav1[pav1.length()-1] == '"')
			{
				x=1;
				mas[i].pav.erase(mas[i].pav.length()-1, 1);
			}
			else
			{
				mas[i].pav=mas[i].pav+" ";
			}
		}
		x=1;
		d >> mas[i].a;
		d >> mas[i].b;
		d.ignore();
	}
	
}

void gaminiai(int n, int &mil, int &cukr)
{
	string pav2;
	int kiek;
	kiek=3;
	for (int i = 0; i < kiek; i++)
	{
		cout << "iveskite gaminio pavadinima:" << endl;
		getline(cin, pav2);
		for (int j = 0; j < n; j++)
		{
			gam[i]=pav2;
			if (pav2 == mas[j].pav)
			{
				mil = mil + mas[j].a;
				cukr = cukr + mas[j].b;
			}
		}
	}
}

void spausdinimas(int mil, int cukr, int n)
{
	ofstream r(fr);

	for (int i=0; i<n; i++)
	{
		r << mas[i].pav << "  " << mas[i].a << "  " << mas[i].b << endl << endl;
	}

	r << "gaminiai:" << endl;
	for (int i=0; i<2; i++)
	{
		r << gam[i] << endl;
	}
	r << endl;

	r << "miltu reiks: " << mil << endl;
	r << "cukrus reiks: " << cukr << endl;


}