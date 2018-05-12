#include <iostream>
#include <list>         /* list is better for removing at any given location than vector ! see: http://www.cplusplus.com/reference/list/list/ */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>    /* sleep */
#include "bunny.h"

using namespace std;


int main()
{
    srand (time(NULL));    // call random seed, otherwise you always get the same distribution !!!

    const unsigned short maxRounds = 1000;

    //vector<Bunny*> vecBunnies(initialPopulation);    // ERROR: segfaults!!!!! WHY ?
    list<Bunny *> listBunnyPopulation;

    for( int i = 0; i < Bunny::INITIAL_POPULATION; ++i )
        listBunnyPopulation.push_back(new Bunny());

//~ The program should print a list of all the bunnies in the colony each turn along w/ all the bunnies details, sorted by age.
//~ When all the bunnies have died the program terminates.
//~ If the bunny population exceeds 1000 a food shortage must occur killing exactly half of the bunnies (randomly chosen)

    //for( int i=0; i<=maxRounds; ++i)
    unsigned int nrRounds = 0;
    while(Bunny::nrTotalBunnies && nrRounds <= maxRounds)
    {
        cerr << "\n--> ROUND: " << nrRounds++ << endl;
        //Bunny::printStatistic();
        Bunny::reproducePopulation(listBunnyPopulation);
        Bunny::radioactivatePopulation(listBunnyPopulation);
        Bunny::agePopulation(listBunnyPopulation);
        if (Bunny::nrTotalBunnies > Bunny::MAX_POPULATION)
            Bunny::skullPopulation(listBunnyPopulation);

        Bunny::printStatistic();
        sleep(3);
    }

    for (list<Bunny *>::iterator itBunny = listBunnyPopulation.begin(); itBunny != listBunnyPopulation.end(); ++itBunny )
        delete (*itBunny);

    return 0;
}
