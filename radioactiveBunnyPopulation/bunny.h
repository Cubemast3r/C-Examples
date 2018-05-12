#ifndef BUNNY_H_
#define BUNNY_H_

#include <iostream>
#include <list>

using namespace std;

enum Sex
{
    male, female
};

enum Color
{
    white, brown, black, spotted, NR_COLORS
};


class Bunny
{
public:
    // constructor + destructor
    Bunny();
    Bunny( Color color );
    ~Bunny();
    // static members
    static const unsigned short MAX_POPULATION;
    static const unsigned short INITIAL_POPULATION;
    static const unsigned short MAX_AGE;
    static const unsigned short MAX_RADIOACTIVE_AGE;
    static const unsigned short SEXUALLY_MATURE;
    static const unsigned short RADIOA_PROBABILITY;
    static unsigned int idCounter;
    static unsigned int nrTotalBunnies;
    static unsigned int nrRadioactiveBunnies;
    static unsigned int nrMale;
    static unsigned int nrFemale;
    static unsigned int nrMatureFemale;
    static unsigned int nrMatureMale;
    // static methods
    static string enum2color( Color color );
    static string enum2sex( Sex sex );
    static void printStatistic();
    static void reproducePopulation( list<Bunny*>& listBunnies );
    static void agePopulation( list<Bunny*>& listBunnies );
    static void radioactivatePopulation( list<Bunny*>& listBunnies );
    static void skullPopulation(  list<Bunny*>& listPopulation );

    // getters
    inline unsigned int id() const
    {
        return id_;
    }
    inline unsigned short age() const
    {
        return age_;
    }
    inline Sex sex() const
    {
        return sex_;
    }
    inline Color color() const
    {
        return color_;
    }
    inline bool isRadioactive() const
    {
        return radioactive_;
    }
    // setters
    const unsigned short increaseAge();
    void setRadioactive();
    void print(const string& prefix="" ) const;

private:
    // private members
    const unsigned int id_;
    unsigned short age_;
    const Sex sex_;
    const Color color_;
    bool radioactive_;
};
#endif
