
#include <iostream>

#include "NNSimple.h"






int main()
{
	NeuralNetworkSimple neural;


	cout << "CHANCES QUE LA LISTE CORRESPONDE AUX CRITERES DU NN" << endl;
	cout << "---------------------------------------------------" << endl;

	// Test avant qu'il aie appris quoi que ce soit.
	double prob = neural.prob_ok({ 5,6,7 });

	cout << "Aucun apprentissage   : " << prob * 100 << "%" << endl;



	// Test après avoir appris quelques informations (insuffisantes)
	neural.learn_from({ 1,1,2,2,3,3 });

	prob = neural.prob_ok({ 5,6,7 });

	cout << "Apprentissage insuff. : " << prob * 100 << "%" << endl;


	// Test après avoir appris assez d'informations pour accepter.
	neural.learn_from({ 4,5,6 });

	prob = neural.prob_ok({ 5,6,7 });

	cout << "Apprentissage partiel : " << prob * 100 << "%" << endl;


	// Test après avoir appris assez d'informations pour reconnaître parfaitement.
	neural.learn_from({ 5,6,7 });

	prob = neural.prob_ok({ 5,6,7 });

	cout << "Apprentissage complet : " << prob * 100 << "%" << endl;

	system("pause");

}