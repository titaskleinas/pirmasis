#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char fd[]="gaminiai.txt";
const char fr[]="rezultatai.txt";

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
				x=0;
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
	kiek=2;
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
	r << "cukraus reiks: " << cukr << endl;


}