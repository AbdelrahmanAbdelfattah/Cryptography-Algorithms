
#include "CeaserCipher.h"
#include "languageDetector.h"
#include <iostream>
#include<string>
using namespace std;


int main() {

	string englishText = "Hi , i am abdelrahman , i am a student at faculty of engineering at al azhar university in cairo deaprtment of computer and system engineering";
	string spanichText = "Hoy hace mucho fr�o. Es invierno y todas las calles est�n cubiertas de nieve. Dentro de poco vendr� la primavera y con ella el sol y el tiempo c�lido. La semana pasada estuvo de lluvia y tormenta. Incluso un rayo cay� encima de la campana de la catedral, pero no ocurri� nada. Los truenos siempre me han dado miedo y mucho respeto. Pero tenemos suerte... pues la previsi�n del tiempo para ma�ana es muy buena. Dicen que hoy habr� heladas y por la tarde granizo, pero ma�ana el d�a ser� soleado. A ver si tengo suerte y veo alg�n arco�ris . Tengo amigos que ahora mismo est�n en Brasil.All� el tiempo es muy diferente.La atm�sfera est� m�s caliente porque est�n en verano.Aunque dicen que ayer hizo mucho viento.Sin embargo, aqu� todo est� cubierto de nubes, �incluso ayer la niebla cubr�a las casas!No se ve�a nada.Tambi�n tenemos que tener cuidado con el hielo, se resbala f�cilmente en �l.A poca gente le gusta la lluvia, �pero es muy necesaria para vivir!Pero pronto vendr� el sol y cesar� el mal tiempo.";


	string path = "words_alpha.txt";
	languageDetector* ld = new languageDetector();
	cout << ld->isEnglishText(path, englishText) << endl;
	cout << ld->isEnglishText(path, spanichText) << endl;


}