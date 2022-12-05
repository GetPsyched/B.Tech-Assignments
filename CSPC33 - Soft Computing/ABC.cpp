#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>
#include <random>

/* constant values */
const double PI_VALUE = 3.14159265358979323846;
const double E_VALUE = 2.7182818284590452354;

using namespace std;

/* bee structure */
struct Bee {
	vector<double> pos;
	double cost = 0.0f;
};


/* class that holds the optimizable functions ready for use */
class OptimizableFunction {
private:
	/* variable that determines the used function */
	int m_choice;
public:
	/* bounds for the used function */
	double m_lowerBound;
	double m_upperBound;

	/* constructor */
	OptimizableFunction(int choice) {
		m_choice = choice;
		setBounds();
	}

	/* set the bounds depending on the function */
	void setBounds() {
		if (m_choice == 1) {
			m_lowerBound = -600;
			m_upperBound = 600;
		}
		else if (m_choice == 2) {
			m_lowerBound = -15;
			m_upperBound = 15;
		}
		else if (m_choice == 3) {
			m_lowerBound = -15;
			m_upperBound = 15;
		}
		else if (m_choice == 4) {
			m_lowerBound = -32768;
			m_upperBound = 32768;
		}
		else if (m_choice == 5) {
			m_lowerBound = -500;
			m_upperBound = 500;
		}
	}

	/* return function value for a vector of positions */
	double getResult(vector<double> numbers) {
		/* griewank function */
		if (m_choice == 1) {
			double sumResult = 0;
			double prodResult = 1;
			for (int i = 0; i < numbers.size(); i++) {
				sumResult += pow(numbers[i], 2);
				prodResult *= cos(numbers[i] / sqrt(i + 1));
			}
			return 1.0f / 4000.0f * sumResult - prodResult + 1.0f;
		}
		/* rastrigin function */
		else if (m_choice == 2) {
			double sumResult = 0;
			for (int i = 0; i < numbers.size(); i++) {
				sumResult += (pow(numbers[i], 2) - 10.0f * cos(2 * PI_VALUE * numbers[i]) + 10.0f);
			}
			return sumResult;
		}
		/* rosenbrock function */
		else if (m_choice == 3) {
			double sumResult = 0;
			for (int i = 0; i < numbers.size() - 1; i++) {
				sumResult += (100.0f * pow(pow(numbers[i], 2) - numbers[i + 1], 2) + pow(1 - numbers[i], 2));
			}
			return sumResult;
		}
		/* ackley function */
		else if (m_choice == 4) {
			double sumResult1 = 0;
			double sumResult2 = 0;
			for (int i = 0; i < numbers.size(); i++) {
				sumResult1 += pow(numbers[i], 2);
				sumResult2 += cos(2 * PI_VALUE * numbers[i]);
			}
			return 20.0f + E_VALUE - 20.0f * pow(E_VALUE, -0.2 * sqrt(1 / double(numbers.size()) * sumResult1)) - pow(E_VALUE, 1 / double(numbers.size()) * sumResult2);
		}
		/* schwefel function */
		else if (m_choice == 5) {
			double sumResult = 0;
			for (int i = 0; i < numbers.size(); i++) {
				sumResult += (-numbers[i] * sin(sqrt(fabs(numbers[i]))));
			}
			double finalResult = numbers.size() * 418.9829 + sumResult;
			if (finalResult < 0) {
				return 1.0f / -finalResult;
			}
			else {
				return finalResult;
			}
		}
		else return NULL;
	}
};

/* returns the cumulative sum of a vector of numbers */
vector<double> cumSum(vector<double> P) {
	double partialSum = 0;
	for (int i = 0; i < P.size(); i++) {
		partialSum += P[i];
		P[i] = partialSum;
	}
	return P;
}

/* returns index of potentially useful solution */
int fitnessProportionateSelection(vector<double> P) {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> randDist(0, 1);
	double randNumber = randDist(gen);
	vector<double> cumVector = cumSum(P);
	for (int i = 0; i < cumVector.size(); i++) {
		if (randNumber <= cumVector[i]) {
			return i;
		}
	}
	return NULL;
}

int main() {

	/* define infinity */
	constexpr double inf = std::numeric_limits<double>::infinity();
	/* define random generator template */
	random_device rd;
	mt19937 gen(rd());
	/* define old random generator with current time as seed */
	srand((unsigned int)time(NULL));

	/* get through all functions */
	for (int functionNumber = 1; functionNumber <= 5; functionNumber++) {
		/*get through all distance sizes*/
		for (int distanceSize = 10; distanceSize <= 30; distanceSize += 10) {

			/* maximum number of experiments */
			int nrOfExperiments = 30;
			/* maximum number of iterations */
			int maxIterations = 1500;

			/* vector for holding the best cost of each experiment*/
			vector<double> bestCostExperiments(nrOfExperiments, 0);
			/* mean cost of all experiments */
			double allMeanCost = 0.0f;
			/* standard deviation cost of all experiments */
			double allSDCost = 0.0f;

			/* create a function object to be tested; parameter is used for choosing a certain function */
			OptimizableFunction optimizableFunction(functionNumber);
			/* get the bound values for the function */
			int distanceMin = optimizableFunction.m_lowerBound;
			int distanceMax = optimizableFunction.m_upperBound;

			/* colony size of bees (or population size) */
			int beesPopulation = 125;
			/* employed bees (sending them onto the food sources to measure their nectar amounts / fitness value) */
			int beesEmployed = int(50.0f / 100.0f * beesPopulation);
			/* onlooker bees (select the food sources using the nectar information / fitness value) */
			int beesOnlooker = beesEmployed;
			/* scout bees (sent to the selected food sources) */
			int beesScout = 1;
			/* limit used for determining the worth of finding a food source */
			int limit = int(round(0.6 * distanceSize * beesPopulation));
			/* acceleration parameter used for finding potential food sources faster */
			int accel = 1;

			cout << "For function " << functionNumber << ": " << nrOfExperiments << " experiments, " << maxIterations << " iterations for each experiment, " << distanceSize << " distances for each iteration." << endl << endl;

			/* loop through all experiments */
			for (int experiment = 0; experiment < nrOfExperiments; experiment++) {

				/* vector for the entire population of bees */
				vector<Bee> beesVector;
				/* initialize the vector with empty bees */
				for (int i = 0; i < beesPopulation; i++) {
					Bee initBee;
					beesVector.push_back(initBee);
				}
				/* initialize the best solution with the worst cost */
				Bee bestSolution;
				bestSolution.cost = inf;
				/* initializing distances for the bees vector with random values and calculating costs */
				for (int i = 0; i < beesPopulation; i++) {
					uniform_real_distribution<> distance(distanceMin, distanceMax);
					for (int j = 0; j < distanceSize; j++) {
						beesVector[i].pos.push_back(distance(gen));
					}
					beesVector[i].cost = optimizableFunction.getResult(beesVector[i].pos);
					if (beesVector[i].cost <= bestSolution.cost) {
						bestSolution = beesVector[i];
					}
				}
				/* vector for counting the abandoned bees */
				vector<double> abandonedBees(beesPopulation, 0);
				/* vector for keeping in memory the best cost for every iteration */
				vector<double> bestCost(maxIterations, 0);

				/* loop through all iterations */
				for (int it = 0; it < maxIterations; it++) {

					/* employeed bees phase */
					for (int i = 0; i < beesEmployed; i++) {

						/* choose a random bee that isn't the current one */
						vector<int> randomBees;
						for (int j = 0; j < beesEmployed; j++) {
							if (j != i) {
								randomBees.push_back(j);
							}
						}
						int randomBeesIndex = randomBees[rand() % randomBees.size()];

						/* calculate a different acceleration coefficient for every distance */
						vector<double> accelCoef;
						uniform_real_distribution<> acc(-1, +1);
						for (int j = 0; j < distanceSize; j++) {
							accelCoef.push_back(accel * acc(gen));
						}

						/* define a new bee */
						Bee newBee;
						/* get the new bee position */
						for (int j = 0; j < distanceSize; j++) {
							/* new bee position is equal to current bee's position + (current bee's position - random bee's position) * acceleration coefficient */
							newBee.pos.push_back(beesVector[i].pos[j] + (beesVector[i].pos[j] - beesVector[randomBeesIndex].pos[j]) * accelCoef[j]);
						}
						/* calculate the new cost */
						newBee.cost = optimizableFunction.getResult(newBee.pos);

						/* if the new cost is better */
						if (newBee.cost <= beesVector[i].cost) {
							/* replace the old cost with the better one */
							beesVector[i] = newBee;
						}
						/* else abandon it */
						else {
							abandonedBees[i] += 1;
						}
					}

					/* vector for calculating the fitness values */
					vector<double> fitnessValues(beesEmployed, 0);
					/* sum of fitness values */
					double fSum = 0;
					/* average cost of all the bees */
					double averageCost = 0;
					/* calculating the average cost */
					for (int i = 0; i < fitnessValues.size(); i++) {
						averageCost += beesVector[i].cost;
					}
					averageCost /= fitnessValues.size();
					/* calculating the fitness values */
					for (int i = 0; i < fitnessValues.size(); i++) {
						fitnessValues[i] = pow(E_VALUE, -beesVector[i].cost / averageCost);
						fSum += fitnessValues[i];
					}
					/* calculating probability of being selected */
					vector<double> prob(beesEmployed, 0);
					for (int i = 0; i < prob.size(); i++) {
						prob[i] = fitnessValues[i] / fSum;
					}

					/* onlooker bees phase */
					for (int m = 0; m < beesOnlooker; m++) {

						/* select a bee index based on the probability and make it the current one */
						int i = fitnessProportionateSelection(prob);

						/* choose a random bee that isn't the current one */
						vector<int> randomBees;
						for (int j = 0; j < beesEmployed; j++) {
							if (j != i) {
								randomBees.push_back(j);
							}
						}
						int randomBeesIndex = randomBees[rand() % randomBees.size()];

						/* calculate a different acceleration coefficient for every distance */
						vector<double> accelCoef;
						uniform_real_distribution<> acc(-1, +1);
						for (int j = 0; j < distanceSize; j++) {
							accelCoef.push_back(accel * acc(gen));
						}

						/* define a new bee */
						Bee newBee;
						/* get the new bee position */
						for (int j = 0; j < distanceSize; j++) {
							/* new bee position is equal to current bee's position + (current bee's position - random bee's position) * acceleration coefficient */
							newBee.pos.push_back(beesVector[i].pos[j] + (beesVector[i].pos[j] - beesVector[randomBeesIndex].pos[j]) * accelCoef[j]);
						}
						/* calculate the new cost */
						newBee.cost = optimizableFunction.getResult(newBee.pos);

						/* if the new cost is better */
						if (newBee.cost <= beesVector[i].cost) {
							/* replace the old cost with the better one */
							beesVector[i] = newBee;
						}
						/* else abandon it */
						else {
							abandonedBees[i] += 1;
						}
					}

					/* scout bees phase */
					for (int itScout = 0; itScout < beesScout; itScout++) {
						for (int i = 0; i < beesEmployed; i++) {
							/* if the abandoned bee is over the abandonment limit, make it search again */
							if (abandonedBees[i] >= limit) {
								uniform_real_distribution<> distance(distanceMin, distanceMax);
								for (int j = 0; j < distanceSize; j++) {
									beesVector[i].pos[j] = distance(gen);
								}
								beesVector[i].cost = optimizableFunction.getResult(beesVector[i].pos);
								abandonedBees[i] = 0;
							}
						}
					}

					/* calculating the best cost */
					for (int i = 0; i < beesEmployed; i++) {
						if (beesVector[i].cost <= bestSolution.cost) {
							bestSolution = beesVector[i];
						}
					}
					/* saving the best cost in a vector */
					bestCost[it] = bestSolution.cost;

					//cout << "Best cost for iteration " << it << ": " << bestCost[it] << endl;

					if (it == maxIterations - 1) {
						bestCostExperiments[experiment] = bestCost[it];
						cout << "Best cost for experiment " << experiment << ": " << bestCostExperiments[experiment] << endl;
					}

				}
			}

			cout << endl;

			/* calculate all mean cost */
			for (int i = 0; i < nrOfExperiments; i++) {
				allMeanCost += bestCostExperiments[i];
			}
			allMeanCost /= nrOfExperiments;

			/* calculate variance */
			double variance = 0.0f;
			for (int i = 0; i < nrOfExperiments; i++) {
				variance += pow(bestCostExperiments[i] - allMeanCost, 2);
			}
			variance /= nrOfExperiments;

			/* calculate all standard deviation cost */
			allSDCost = sqrt(variance);

			cout << "Mean cost: " << allMeanCost << endl;
			cout << "SD cost: " << allSDCost << endl;
			cout << endl << "-----------------------------------------------" << endl << endl;
		}
	}
	return 0;
}