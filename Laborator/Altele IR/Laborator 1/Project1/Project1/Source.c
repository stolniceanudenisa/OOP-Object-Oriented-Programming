/*Determina intersectia a doua segmente plane (date prin coordonatele lor carteziene).

*/

#include <stdio.h>
#include <assert.h>



typedef struct 
{
	float x, y;
}punct;

typedef struct 
{
	punct extr1,extr2;
}segment;


void meniu()
{	/*
	Functia afiseaza meniul aplicatiei. 
	Comanda 1 determina executia aplicatiei.
	Comanda x determina inchiderea aplicatiei.
	*/
	printf("__________________________________________________\n");
	printf("|Comenzi                                          |\n");
	printf("|_________________________________________________|\n");
	printf("|1: Intersectia segmentelor                       |\n");
	printf("|2: Intersectia dreptelor determinate de segmente |\n");
	printf("|0: Exit                                          |\n");
	printf("|_________________________________________________|\n");
}

segment citire(char nume[2],char pct1, char pct2, segment seg)
{	/*
	Functia citeste datele pentru structura segment definita in program.
	:param nume: char(sir de caractere) (reprezninta denumirea segmentului)
	:param pct1: char(caracter) (repreninta denumirea unui punct din plan)
	:param pct2: char(caracter) (repreninta denumirea unui punct din plan)
	:param seg: segment
	:return: segment
	*/
	printf("Segmentul %s: \n",nume);
	printf("Coordonatele punctului %c: \n",pct1);
	printf("x=");
	scanf("%f", &seg.extr1.x);
	printf("y=");
	scanf("%f", &seg.extr1.y);
	printf("Coordonatele punctului %c: \n", pct2);
	printf("x=");
	scanf("%f", &seg.extr2.x);
	printf("y=");
	scanf("%f", &seg.extr2.y);
	return seg;
}

int minim(int a, int b)
{	/*
	Determina minimul dintre doua numere a si b.
	:param a: nr intreg
	:param b: nr intreg
	:return: min(a,b)
	*/
	if (a < b)
		return a;
	else return b;
}

int maxim(int a, int b)
{
	/*
	Determina maximul dintre doua numere a si b.
	:param a: nr intreg
	:param b: nr intreg
	:return: max(a,b)
	*/
	if (a > b)
		return a;
	else return b;
}

float panta(segment AB)
{
	/*
	Functia determina panta unei drepte.
	:param AB: segment
	:return: float
	*/
	return (AB.extr1.y - AB.extr2.y) / (AB.extr1.x - AB.extr2.x);
}
punct punctComun(punct A, punct B, punct C, punct D)
{
	/*
	Functia determina punctele egale. (in ipoteza ca exista)
	:param A,B,C,D: punct
	return: punct
	*/
	if ((A.x == B.x) && (A.y == B.y) || (A.x == C.x) && (A.y == C.y) || (A.x == D.x) && (A.y == D.y))
		return A;
	if ((B.x == C.x) && (B.y == C.y) || (B.x == D.x) && (B.y == D.y))
		return B;
	if ((D.x == C.x) && (D.y == C.y))
		return C;
}
punct intersection(segment AB, segment CD)
{
	/*
	Functia determina punctul de intersectie dintre doua drepte
	:param AB: segment
	:param CD: segment
	:return: punct
	*/
	punct I;
	I.x = -1;
	I.y = -1;

	if ((AB.extr1.x == AB.extr2.x) && (CD.extr1.x != CD.extr2.x))
	{
		I.x = AB.extr1.x;
		I.y = (I.x*(CD.extr2.y - CD.extr1.y) + CD.extr2.x*CD.extr1.y - CD.extr1.x*CD.extr2.y) / (CD.extr2.x - CD.extr1.x);
	}

	if ((AB.extr1.x != AB.extr2.x) && (CD.extr1.x != CD.extr2.x))
	{
		if (panta(AB) == panta(CD)) //Dreptele sunt paralele
		{
			if ((maxim(AB.extr1.x, AB.extr2.x) == minim(CD.extr1.x, CD.extr2.x)) || (minim(AB.extr1.x, AB.extr2.x) == maxim(CD.extr1.x, CD.extr2.x)))
			{
				I = punctComun(AB.extr1, AB.extr2, CD.extr1, CD.extr2);
			}
		}
		if (panta(AB) != panta(CD)) 
		{
			I.x = (panta(AB)*AB.extr1.x - panta(CD) * CD.extr1.x - AB.extr1.y + CD.extr1.y) / (panta(AB) - panta(CD));
			I.y = panta(AB) * (I.x - AB.extr1.x) + AB.extr1.y;
		}
	}
	return I;
}



void afisare(segment AB,segment CD)
{
	/*
	Functia afiseaza un mesaj corespunzator datelor de intrare.
	:param AB: segment
	:param CD: segment
	*/
	punct I;
	I.x = -1;
	I.y = -1;
	
	//Se trateaza cazul in care dreptele determinate de [AB], [CD] sunt paralele cu dreapta 0y. 
	//(Panta dreptelor nu se poate calcula.)
	if ((AB.extr1.x == AB.extr2.x) && (CD.extr1.x == CD.extr2.x))
	{
		printf("Segmentele sunt paralele cu axa Oy.\n");
	}

	//Se trateaza cazul in care dreapta determinata de [AB] este paralela cu Oy.
	if ((AB.extr1.x == AB.extr2.x) && (CD.extr1.x != CD.extr2.x))
	{
		I = intersection(AB, CD);
		printf("Punctul de intersectie este I(%.1f,%.1f)\n", I.x, I.y);
	}

	//Se trateaza cazul in care dreapta determinata de [CD] este paralela cu Oy.
	if ((AB.extr1.x != AB.extr2.x) && (CD.extr1.x == CD.extr2.x))
	{
		I = intersection(CD, AB);
		printf("Punctul de intersectie este I(%.1f,%.1f)\n", I.x, I.y);
	}

	//Se trateaza cazul in care dreaptele determinate de [AB],[CD] nu sunt paralele cu Oy.
	//(Se poate calcula panta dreptelor.)
	if ((AB.extr1.x != AB.extr2.x) && (CD.extr1.x != CD.extr2.x))
	{

		if (panta(AB) == panta(CD)) //Dreptele sunt paralele
		{
			if ((maxim(AB.extr1.x, AB.extr2.x) == minim(CD.extr1.x, CD.extr2.x)) || (minim(AB.extr1.x, AB.extr2.x) == maxim(CD.extr1.x, CD.extr2.x)))
			{
				I = punctComun(AB.extr1, AB.extr2, CD.extr1, CD.extr2);
				printf("Punctul de intersectie este I(%.1f,%.1f)\n", I.x, I.y);
			}
			else printf("Segmentele sunt paralele. (Pante egale)\n");
		}
		else //Dreptele se intersecteaza
		{
			I = intersection(AB,CD);
			printf("Punctul de intersectie este I(%.1f,%.1f)\n", I.x, I.y);
		}
	}
}

int validare(segment AB, segment CD) 
{
	/*
	Determina daca segmentele AB, CD se intersecteaza.
	:param AB: segment
	:param CD: segment
	:return: 0 (nu se intersecteaza), 1 (se intersecteaza)
	*/
	if ((AB.extr1.x == AB.extr2.x) && (CD.extr1.x == CD.extr2.x))
		return 0;
	if (panta(AB)==panta(CD))
	{
		if ((maxim(AB.extr1.x, AB.extr2.x) == minim(CD.extr1.x, CD.extr2.x)) || (minim(AB.extr1.x, AB.extr2.x) == maxim(CD.extr1.x, CD.extr2.x)))
			return 1; 
		else return 0;
	}
	punct I = intersection(AB, CD);
	if (I.x < minim(AB.extr1.x, AB.extr2.x) || I.x > maxim(AB.extr1.x, AB.extr2.x))
		return 0;
	if (I.x < minim(CD.extr1.x, CD.extr2.x) || I.x > maxim(CD.extr1.x, CD.extr2.x))
		return 0;
	return 1;
}

void afisare2(segment AB, segment CD)
{
	/*
	Functia afiseaza un mesaj corespunzator datelor de intrare.
	:param AB: segment
	:param CD: segment
	*/
	if (validare(AB, CD) == 1)
		afisare(AB, CD);
	else printf("Segmentele nu se intersecteaza.\n");
}

void testPunctComun()
{
	//test pentru functia punct comun;
	punct A, B, C, D, I;
	A.x = A.y = 1;
	B.x = B.y = C.x = C.y = 2;
	D.x = D.y = 3;
	I = punctComun(A, B, C, D);
	assert(I.x == B.x);
	assert(I.y == B.y);
}

void testPanta()
{
	//test pentru functia panta
	segment AB;
	AB.extr1.x = 1;
	AB.extr1.y = 1;
	AB.extr2.x = 2;
	AB.extr2.y = 2;
	assert(panta(AB) == 1);
}

void testIntersection()
{
	//test pentru funtia intersection
	segment AB,CD;
	punct I;
	AB.extr1.x = 1;
	AB.extr1.y = 1;
	AB.extr2.x = 2;
	AB.extr2.y = 2;
	CD.extr1.x = 3;
	CD.extr1.y = 3;
	CD.extr2.x = 2;
	CD.extr2.y = 2;
	I = intersection(AB, CD);
	assert(I.x == 2);
	assert(I.y == 2);

	AB.extr1.x = 1;
	AB.extr1.y = 1;
	AB.extr2.x = 3;
	AB.extr2.y = 3;
	CD.extr1.x = 2;
	CD.extr1.y = 1;
	CD.extr2.x = 4;
	CD.extr2.y = 1;
	I = intersection(AB, CD);
	assert(I.x == 1);
	assert(I.y == 1);

	AB.extr1.x = 1;
	AB.extr1.y = 1;
	AB.extr2.x = 3;
	AB.extr2.y = 3;
	CD.extr1.x = 3;
	CD.extr1.y = 1;
	CD.extr2.x = 1;
	CD.extr2.y = 3;
	I = intersection(AB, CD);
	assert(I.x == 2);
	assert(I.y == 2);

}

void testValidare()
{
	//test pentru functia de validare intersectie segmente
	segment AB, CD;
	punct I;
	AB.extr1.x = 1;
	AB.extr1.y = 1;
	AB.extr2.x = 2;
	AB.extr2.y = 2;
	CD.extr1.x = 3;
	CD.extr1.y = 3;
	CD.extr2.x = 2;
	CD.extr2.y = 2;
	assert(validare(AB, CD) == 1);

	AB.extr1.x = 1;
	AB.extr1.y = 1;
	AB.extr2.x = 3;
	AB.extr2.y = 3;
	CD.extr1.x = 2;
	CD.extr1.y = 1;
	CD.extr2.x = 4;
	CD.extr2.y = 1;
	assert(validare(AB, CD) == 0);

	AB.extr1.x = 1;
	AB.extr1.y = 1;
	AB.extr2.x = 1;
	AB.extr2.y = 3;
	CD.extr1.x = 3;
	CD.extr1.y = 1;
	CD.extr2.x = 3;
	CD.extr2.y = 3;
	assert(validare(AB, CD) == 0);
}

void teste()
{
	testPunctComun();
	testPanta();
	testIntersection();
	testValidare();
}

int main()
{
	/*
	Punctul de intrare in aplicatie. 
	*/
	segment AB, CD;
	int cmd = 0;

	AB.extr1.x = 0; AB.extr1.y = 0; AB.extr2.x = 0; AB.extr2.y = 0;
	CD.extr1.x = 0; CD.extr1.y = 0; CD.extr2.x = 0; CD.extr2.y = 0;
	
	while (1)
	{
		teste();
		meniu();
		printf("Comanda: ");
		scanf("%d", &cmd);

		if (cmd==0)
		{	
			printf("Multumim ca ati utilizat aplicatia!\n");
			break;
		}
	
		if (cmd==2)
		{
			AB = citire("AB", 'A', 'B', AB);
			CD = citire("CD", 'C', 'D', CD);
			afisare(AB,CD);
			continue;
		}

		if (cmd == 1)
		{
			AB = citire("AB", 'A', 'B', AB);
			CD = citire("CD", 'C', 'D', CD);
			afisare2(AB,CD);
			continue;
		}
		
		if (cmd!=0 || cmd!=1 || cmd!=2)
		{
			printf("Comanda gresita!\n");
			continue;
		}
	}
	return 0;
}