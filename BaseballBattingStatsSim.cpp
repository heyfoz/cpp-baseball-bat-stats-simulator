// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
//
// https://docs.microsoft.com/en-us/troubleshoot/developer/visualstudio/cpp/libraries/stl-sqrt-pow-functions
// https://docs.microsoft.com/en-us/cpp/standard-library/iomanip-functions?view=msvc-170

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <ctime>    // Access random number generator
using namespace std;

// Constant Variable Initialization
const string TITLE = "Baseball Batting Stats Simulator";
const string AUTHOR_LINE = "By Forrest Moulin";

// Career stats based on 1000 at bats
const int OUTS_INT = 580;
const int WALKS_INT = 97;
const int SINGLES_INT = 220;
const int DOUBLES_INT = 61;
const int TRIPLES_INT = 25;
const int HOMERUNS_INT = 17;

// Use 1000 multiplier to facilitate calculations
const double ATBATS = 1000.0 * 1000;
const double OUTS = ATBATS * 1.0 / OUTS_INT;
const double WALKS = ATBATS * 1.0 / WALKS_INT;
const double SINGLES = ATBATS * 1.0 / SINGLES_INT;
const double DOUBLES = ATBATS * 1.0 / DOUBLES_INT;
const double TRIPLES = ATBATS * 1.0 / TRIPLES_INT;
const double HOMERUNS = ATBATS * 1.0 / HOMERUNS_INT;
const double CAREER_AVG = 0.358;

// Resulting integers to be used in rand function
const int OUTS_INT2 = OUTS;
const int WALKS_INT2 = WALKS;
const int SINGLES_INT2 = SINGLES;
const int DOUBLES_INT2 = DOUBLES;
const int TRIPLES_INT2 = TRIPLES;
const int HOMERUNS_INT2 = HOMERUNS;

int main()
{
	// Seed random number generator
	srand(time(NULL));

	// Dynamic Variable Initialization
	int outsInt, walksInt, singlesInt, doublesInt,
		triplesInt, homeRunsInt, batAvg;

	int outCount = 0, walkCount = 0, singleCount = 0, 
		doubleCount = 0,tripleCount = 0, homeRunCount = 0, 
		hitCount = 0, atBatCount = 0, simCount = 0;

	char continueChar = NULL;

	cout << fixed << setprecision(3) << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	while (continueChar != 'n'
		|| continueChar != toupper('n'))
	{
		simCount++; // Track # of simulations
		cout << "Simulation # " << simCount << endl;
		cout << "Simulating 1000 at-bats..." << endl << endl;

		while(atBatCount < 1000)
		{
			// Generate random values based on statistical averages
			outsInt = rand() % OUTS_INT2 + 1;
			singlesInt = rand() % SINGLES_INT2 + 1;
			doublesInt = rand() % DOUBLES_INT2 + 1;
			triplesInt = rand() % TRIPLES_INT2 + 1;
			homeRunsInt = rand() % HOMERUNS_INT2 + 1;
			walksInt = rand() % WALKS_INT2 + 1;
			// Since multiplier of 1000 used, check whether
			// random value is from 1 to 1000
			// Break in case 1000 is reached to avoid
			// going over limit during if bodies
			if (outsInt <= 1000)
			{
				outCount++;
				atBatCount++;
				if (atBatCount == 1000)
				{
					break;
				}
			}
			if (singlesInt <= 1000)
			{
				singleCount++;
				atBatCount++;
				if (atBatCount == 1000)
				{
					break;
				}
			}
			if (doublesInt <= 1000)
			{
				doubleCount++;
				atBatCount++;
				if (atBatCount == 1000)
				{
					break;
				}
			}
			if (triplesInt <= 1000)
			{
				tripleCount++;
				atBatCount++;
				if (atBatCount == 1000)
				{
					break;
				}
			}
			if (homeRunsInt <= 1000)
			{
				homeRunCount++;
				atBatCount++;
				if (atBatCount == 1000)
				{
					break;
				}
			}
			if (walksInt <= 1000)
			{
				walkCount++;
				atBatCount++;
				if (atBatCount == 1000)
				{
					break;
				}
			}
		}
		// Calculate the batting average in decimal form
		hitCount = singleCount + doubleCount + tripleCount + homeRunCount;
		batAvg = 1.0 * hitCount 
			/ (1000 - walkCount);

		// Print results in table format
		cout << left << setw(15) << "Outs:" << outCount << endl
			<< left << setw(15) << "Walks:" << walkCount << endl
			<< left << setw(15) << "Singles: " << singleCount << endl
			<< left << setw(15) << "Doubles:" << doubleCount << endl
			<< left << setw(15) << "Triples:" << tripleCount << endl
			<< left << setw(15) << "Home Runs:" << homeRunCount << endl << endl
			<< "Calculated batting average: " << batAvg
			<< endl << endl
			<< "Would you like to run another simulation?"
			<< endl << "(y for yes, n for no)" << endl << endl;

		// Get char input (Y/N)
		cin >> continueChar;

		if (continueChar == 'n'
			|| continueChar == toupper('n'))
		{
			cout << endl << "Exiting the simulator..."
				<< endl << "Until next time!" << endl;
			break;
		}
		else if (continueChar == 'y'
			|| continueChar == toupper('y'))
		{
			// Reset values for next simulation
			atBatCount = 0;
			outCount = 0;
			singleCount = 0;
			doubleCount = 0;
			tripleCount = 0;
			homeRunCount = 0;
			walkCount = 0;
			cout << endl;
			continue;
		}
		else
		{
			do
			{
				cout << "Invalid entry."
					<< "Would you like to run another simulation?"
					<< endl << "(y for yes, n for no)" << endl << endl;
				cin >> continueChar;
			} while (continueChar != 'n'
				|| continueChar != toupper('n')
				|| continueChar != 'y'
				|| continueChar != toupper('y'));
		}
	}
}
/*
* CONSOLE OUTPUT
* Baseball Batting Stats Simulator
* By Forrest Moulin
*
* Simulation # 1
* Simulating 1000 at-bats...
*
* Outs:          575
* Walks:         113
* Singles:       212
* Doubles:       60
* Triples:       20
* Home Runs:     20
*
* Calculated batting average: 0.352
*
* Would you like to run another simulation?
* (y for yes, n for no)
*
* y
*
* Simulation # 2
* Simulating 1000 at-bats...
*
* Outs:          536
* Walks:         126
* Singles:       220
* Doubles:       55
* Triples:       31
* Home Runs:     32
*
* Calculated batting average: 0.387
*
* Would you like to run another simulation?
* (y for yes, n for no)
*
* y
*
* Simulation # 3
* Simulating 1000 at-bats...
*
* Outs:          544
* Walks:         88
* Singles:       251
* Doubles:       61
* Triples:       26
* Home Runs:     30
*
* Calculated batting average: 0.404
*
* Would you like to run another simulation?
* (y for yes, n for no)
*
* y
*
* Simulation # 4
* Simulating 1000 at-bats...
*
* Outs:          557
* Walks:         115
* Singles:       220
* Doubles:       50
* Triples:       33
* Home Runs:     25
*
* Calculated batting average: 0.371
*
* Would you like to run another simulation?
* (y for yes, n for no)
*
* y
*
* Simulation # 5
* Simulating 1000 at-bats...
*
* Outs:          548
* Walks:         119
* Singles:       208
* Doubles:       62
* Triples:       28
* Home Runs:     35
*
* Calculated batting average: 0.378
*
* Would you like to run another simulation?
* (y for yes, n for no)
*
* n
*
* Exiting the simulator...
* Until next time!
*/
