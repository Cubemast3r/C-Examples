#include "bunny.h"
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;


// static members
const unsigned short Bunny::MAX_POPULATION = 1000;
const unsigned short Bunny::INITIAL_POPULATION = 5;
const unsigned short Bunny::MAX_AGE = 10;
const unsigned short Bunny::MAX_RADIOACTIVE_AGE = 4;
const unsigned short Bunny::SEXUALLY_MATURE = 2;
const unsigned short Bunny::RADIOA_PROBABILITY=1;
unsigned int Bunny::idCounter = 0;
unsigned int Bunny::nrTotalBunnies = 0;
unsigned int Bunny::nrRadioactiveBunnies = 0;
unsigned int Bunny::nrMale = 0;
unsigned int Bunny::nrFemale = 0;
unsigned int Bunny::nrMatureFemale = 0;
unsigned int Bunny::nrMatureMale = 0;

// static methods
void Bunny::reproducePopulation( list<Bunny*>& listBunnies )
{
//~ So long as there is at least one male age 2 or older, for each female bunny in the list age 2 or older;
//~ a new bunny is created each turn. (i.e. if there was 1 adult male and 3  adult female bunnies, three new bunnies would be born each turn)
//~ New bunnies born should be the same color as their mother.

    if (Bunny::nrMatureMale > 0 && Bunny::nrFemale > 0)
    {
        vector<Bunny *> vecBabyBunnies;
        vecBabyBunnies.reserve(Bunny::nrFemale);
        // create new babies
        for (list<Bunny *>::iterator itBunny = listBunnies.begin(); itBunny != listBunnies.end(); ++itBunny )
        {
            if ((*itBunny)->sex() == Sex::female && (*itBunny)->age() >= Bunny::SEXUALLY_MATURE )
            {
                vecBabyBunnies.push_back( new Bunny( (*itBunny)->color() ) );
                //(*itBunny)->print("#Mother: ");
            }
        }
        // and put them to the population
        for (vector<Bunny *>::iterator itBabies = vecBabyBunnies.begin(); itBabies != vecBabyBunnies.end(); ++itBabies )
        {
            listBunnies.push_back( (*itBabies) );
            //(*itBabies)->print("#Baby: ");
        }
    }
}

void Bunny::radioactivatePopulation( list<Bunny *>& listBunnies )
{
//~ If a radioactive mutant vampire bunny is born then each turn it will  change exactly one non radioactive bunny into a radioactive vampire  bunny.
//~ (if there are two radioactive mutant vampire bunnies two bunnies will be changed each turn and so on...)
//~ Radioactive vampire bunnies are excluded from regular breeding and do not count as adult bunnies.
    unsigned int nrViralRadioactives = Bunny::nrRadioactiveBunnies;
    while (nrViralRadioactives && Bunny::nrRadioactiveBunnies < Bunny::nrTotalBunnies)
    {
        list<Bunny *>::iterator itBunny = listBunnies.begin();
        advance(itBunny, rand() % listBunnies.size());
        if (!(*itBunny)->isRadioactive())
        {
            (*itBunny)->setRadioactive();
            --nrViralRadioactives;
        }
    }
}

void Bunny::agePopulation( list<Bunny*>& listBunnies )
{
//~ If a bunny becomes older than 10 years old, it dies.
//~ Radioactive vampire bunnies do not die until they reach age 50.

    unsigned short age = 0;
    // increase age:
    for (list<Bunny *>::iterator itBunny = listBunnies.begin(); itBunny != listBunnies.end(); ++itBunny )
    {
        age = (*itBunny)->increaseAge();
        // if bunny too old: delete it
        if ( ( !(*itBunny)->isRadioactive() && age >= Bunny::MAX_AGE ) || ( (*itBunny)->isRadioactive() && age >= Bunny::MAX_RADIOACTIVE_AGE )  )
        {
            delete (*itBunny);
            itBunny = listBunnies.erase(itBunny);
        }
    }
}


void Bunny::skullPopulation( list<Bunny*>& listPopulation )
{
    assert(Bunny::nrTotalBunnies >= Bunny::MAX_POPULATION/2);
    for ( unsigned short i = 0; i < Bunny::MAX_POPULATION/2; ++i )
    {
        list<Bunny *>::iterator itBunny = listPopulation.begin();
        advance(itBunny, rand() % listPopulation.size());
        delete (*itBunny);
        itBunny = listPopulation.erase(itBunny);
    }
}

string Bunny::enum2color( Color color )
{
    switch( color )
    {
    case white:
        return "white";
    case brown:
        return "brown";
    case black:
        return "black";
    case spotted:
        return "spotted";
    default:
        return "undefined";
    }
}

string Bunny::enum2sex( Sex sex )
{
    switch( sex )
    {
    case male:
        return "male";
    case female:
        return "female";
    default:
        return "undefined";
    }
}

void Bunny::printStatistic()
{
    cerr << "TOTAL:         " << Bunny::nrTotalBunnies << '\n';
    cerr << "MALE:          " << Bunny::nrMale << '\n';
    cerr << "FEMALE:        " << Bunny::nrFemale << '\n';
    cerr << "RADIOACTIVE:   " << Bunny::nrRadioactiveBunnies << '\n';
    cerr << "MATURE-MALE:   " << Bunny::nrMatureMale << '\n';
    cerr << "MATURE-FEMALE: " << Bunny::nrMatureFemale << '\n';
}

// constructor + destructor
Bunny::Bunny()
    : id_(Bunny::idCounter++), age_(0),
      sex_((rand() % 100 + 1) < 50 ? Sex::male : Sex::female),
      color_(Color(rand() % NR_COLORS)),
      radioactive_( (rand() % 100 + 1) <= Bunny::RADIOA_PROBABILITY ? true : false )
{
    ++Bunny::nrTotalBunnies;
    this->radioactive_ ? (++Bunny::nrRadioactiveBunnies) : (this->sex_ == Sex::male ? ++Bunny::nrMale : ++Bunny::nrFemale);
    print("* Born: ");
}

Bunny::Bunny( Color color )
    : id_(Bunny::idCounter++), age_(0),
      sex_((rand() % 100 + 1) < 50 ? Sex::male : Sex::female),
      color_(color),
      radioactive_( (rand() % 100 + 1) <= Bunny::RADIOA_PROBABILITY ? true : false )
{
    ++Bunny::nrTotalBunnies;
    this->radioactive_ ? (++Bunny::nrRadioactiveBunnies) : (this->sex_ == Sex::male ? ++Bunny::nrMale : ++Bunny::nrFemale);
    print("* Born: ");
}

Bunny::~Bunny()
{
    --Bunny::nrTotalBunnies;
    if ( radioactive_ )
        --Bunny::nrRadioactiveBunnies;
    else
    {
        if (sex_ == Sex::male)
        {
            --Bunny::nrMale;
            if (age_>=Bunny::SEXUALLY_MATURE) --Bunny::nrMatureMale;
        }
        else
        {
            --Bunny::nrFemale;
            if (age_>=Bunny::SEXUALLY_MATURE) --Bunny::nrMatureFemale;
        }
    }
    print("~ Died: ");
}

void Bunny::print( const string& prefix ) const
{
    cerr << prefix << "ID: " << id_ << " | AGE: " << age_ <<  " | SEX: " << Bunny::enum2sex(sex_) << " | COLOR: " << Bunny::enum2color(color_) << " | RADIOACTIVE: " << radioactive_ << endl;
}

const unsigned short Bunny::increaseAge()
{
    ++age_;
    if ( (age_ == Bunny::SEXUALLY_MATURE) && (!radioactive_) )
    {
        if(sex_ == Sex::male) ++Bunny::nrMatureMale;
        else ++Bunny::nrMatureFemale;
    }

    return age_;
};

void Bunny::setRadioactive()
{
    assert(radioactive_!= true);
    radioactive_=true;
    ++Bunny::nrRadioactiveBunnies;

    if (sex_ == Sex::male)
    {
        --Bunny::nrMale;
        if (age_ >= Bunny::SEXUALLY_MATURE) --Bunny::nrMatureMale;
    }
    else
    {
        --Bunny::nrFemale;
        if (age_ >= Bunny::SEXUALLY_MATURE) --Bunny::nrMatureFemale;
    }
};
