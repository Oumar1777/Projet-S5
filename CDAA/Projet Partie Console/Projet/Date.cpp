#include "Date.h"
/**
 *@namespace std: utilisation de std
*/
using namespace std;

Date:: Date()
{
    time_t n= time(0);
    d= localtime(&n);
}

/**
    *@brief Récupération du jour de la date
    *@return un entier qui représente le jour
*/
int Date::getJour()
{
    return this->d->tm_mday;
}

/**
    *@brief Récupération du mois de la date
    *@return un entier qui représente le mois
*/
int Date::getMois()
{
    return this->d->tm_mon+1;
}

/**
    *@brief Récupération de l'année de la date
    *@return un entier qui représente l'année
*/
int Date::getAnnee()
{
    return this->d->tm_year + 1900;
}

/**
    @brief Récupération en fonction des paramètres day, month et year d'une structure tm contenant la date définie
    @param day : le jour de la nouvelle date
    @param month : le mois de la nouvelle date
    @param year : l'année de la nouvelle date
*/
void Date::fromDate(const int day, const int month, const int year)
{
    time_t nt = time(NULL);
    struct tm* nd = localtime(&nt);

    nd -> tm_mday= day;
    nd -> tm_mon= month - 1;
    nd -> tm_year= year - 1900;

    nt = mktime(nd);
    d = localtime(&nt);
}

/**
    @brief Récupération de la date avec le format jj/mm/aaaa
    @return Chaine de caractère contenant la date
*/
string Date::toString()
{
    return std::to_string( getJour())+"/"+std::to_string(getMois())+"/"+to_string(getAnnee());
}
