#pragma once

#include <initializer_list>

using namespace std;


class NeuralNetworkSimple
{
public:

	using pourcentage = double;
	using value_type = int;

private:

	// Critères de sélection, qui se modifient au fûr et à mesure que le programme "apprends".
	int min;
	int max;

	// Retourne true si la valeur est jugée acceptable / se trouve entre le minimum et le maximum.
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

	// Ajuste les critères de sélection d'après les valeurs reçues en paramètre.
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

	// Retourne la probabilité que "values" soit de la même sorte que ce qu'il a appris auparavant, en se fiant aux critères.
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