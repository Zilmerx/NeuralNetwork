#pragma once

#include <initializer_list>

using namespace std;


class NeuralNetworkSimple
{
public:

	using pourcentage = double;
	using value_type = int;

private:

	// Crit�res de s�lection, qui se modifient au f�r et � mesure que le programme "apprends".
	int min;
	int max;

	// Retourne true si la valeur est jug�e acceptable / se trouve entre le minimum et le maximum.
	inline bool is_acceptable_value(const value_type& value) const
	{
		return (value >= min && value <= max);
	}

public:

	NeuralNetworkSimple() :
		min{ 0 },
		max{ 0 }
	{
	}

	// Ajuste les crit�res de s�lection d'apr�s les valeurs re�ues en param�tre.
	void learn_from(initializer_list<value_type>&& values)
	{
		for (const auto& value : values)
		{
			if (value < min)
			{
				min = value;
			}
			
			if (value > max)
			{
				max = value;
			}
		}
	}

	// Retourne la probabilit� que "values" soit de la m�me sorte que ce qu'il a appris auparavant, en se fiant aux crit�res.
	pourcentage prob_ok(initializer_list<value_type>&& values) const
	{
		int nombreMauvais = 0;

		for (const auto& value : values)
		{
			if (!is_acceptable_value(value))
			{
				nombreMauvais++;
			}
		}

		if (nombreMauvais == 0)
			return 1;

		return (pourcentage)(values.size()-nombreMauvais) / (pourcentage)values.size();
	}
};