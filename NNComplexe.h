#pragma once


/*

�bauche de ce � quoi un neural network un peu plus compliqu� pourrait ressembler.

class NeuralNetworkComplexe
{

private:

	// Crit�res de s�lection. Chaque classe ( NoseFinder etc.. ) poss�de ses propres crit�res de s�lection.
	// Cela veut aussi dire que chaque classe a besoin d'informations sp�cifiques pour apprendre.

	class HeadFinder	{...} headfinder;	// Trouves le contour du visage dans l'image.

	class NoseFinder	{...} nosefinder;	// Objet prenant un contour de visage, et tentant de trouver un nez dans l'image.
	class EyeFinder		{...} eyefinder;	// Objet prenant un contour de visage, et tentant de trouver deux yeux dans l'image.
	class MouthFinder	{...} mouthfinder;	// Objet prenant un contour de visage, et tentant de trouver une bouche dans l'image.


	// Retourne true si la valeur est jug�e acceptable.
	inline bool is_acceptable_value(const Image& image) const
	{
		if(is_ok(image) > 0.8)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:

	// Ajuste les crit�res de s�lection d'apr�s les valeurs re�ues en param�tre.
	void learn_from(const Head& head)
	{
		headfinder::learn_from(head);

		nosefinder::learn_from(head);
		eyefinder::learn_from(head);
		mouthfinder::learn_from(head);
	}

	// Retourne la probabilit� que l'image soit un visage;
	pourcentage prob_ok(const Image& image) const
	{
		Head head = headfinder::trouver(image);

		double probabilite = ( NoseFinder::trouver(head) + EyeFinder::trouver(head) + MouthFinder::trouver(head) ) / 3;

		return probabilite;
	}
};



*/