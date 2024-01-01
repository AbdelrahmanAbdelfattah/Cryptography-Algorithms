
#include "CeaserCipher.h"
#include "languageDetector.h"
#include <iostream>
#include<string>
using namespace std;


int main() {

	string englishText = "Hi , i am abdelrahman , i am a student at faculty of engineering at al azhar university in cairo deaprtment of computer and system engineering";
	string spanichText = "Hoy hace mucho frío. Es invierno y todas las calles están cubiertas de nieve. Dentro de poco vendrá la primavera y con ella el sol y el tiempo cálido. La semana pasada estuvo de lluvia y tormenta. Incluso un rayo cayó encima de la campana de la catedral, pero no ocurrió nada. Los truenos siempre me han dado miedo y mucho respeto. Pero tenemos suerte... pues la previsión del tiempo para mañana es muy buena. Dicen que hoy habrá heladas y por la tarde granizo, pero mañana el día será soleado. A ver si tengo suerte y veo algún arcoíris . Tengo amigos que ahora mismo están en Brasil.Allí el tiempo es muy diferente.La atmósfera está más caliente porque están en verano.Aunque dicen que ayer hizo mucho viento.Sin embargo, aquí todo está cubierto de nubes, ¡incluso ayer la niebla cubría las casas!No se veía nada.También tenemos que tener cuidado con el hielo, se resbala fácilmente en él.A poca gente le gusta la lluvia, ¡pero es muy necesaria para vivir!Pero pronto vendrá el sol y cesará el mal tiempo.";


	string path = "words_alpha.txt";
	languageDetector* ld = new languageDetector();
	cout << ld->isEnglishText(path, englishText) << endl;
	cout << ld->isEnglishText(path, spanichText) << endl;


}