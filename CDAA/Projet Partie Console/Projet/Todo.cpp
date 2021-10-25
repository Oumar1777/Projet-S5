/**
    *@file Todo.cpp
    *@brief Fichier CPP de la classe Todo
    *@author
*/

#include "Todo.h"
/**
    *@brief Constructeur par défaut de la classe Todo
    *@details Ce constructeur initialise à la date courante un Todo avec un contenu vide n'étant relié à aucune interaction;
*/
Todo::Todo()
{
    time_t n = time(0);
    date = new tm();
    this->setDate(*localtime(&n));
    this->contenu = "";
}

/**
    *@brief Constructeur avec paramètres de la classe Todo
    *@details Ce constructeur initialise à une date donnée un Todo avec un contenu vide n'étainteraction;
*/
Todo::Todo(const Interaction& i, const std::string& c, const tm& t)
{
    if(date != nullptr)
        date = new tm();
    this->setDate(t);
    this->setInteraction(i);
    this->setContenu(c);
}

/// Accesseurs

/**
    *@brief Pour récuperer l'intéraction à laquelle apppartient le Todo.
    *@details Ce fontion renvoie l'instance Intéraction à laquelle appartient le Todo.
*/
Interaction Todo::getInteraction() const
{
    return *lienInteraction;
}

/**
    *@brief Pour récupérer la date.
    *@details Cette fonction renvoie l'instance pointée par date.
*/
tm Todo::getDate() const
{
    return *date;
}

/**
    *@brief Pour recupérer le contenu de l'interaction.
    *@details Cette fonction renvoie la chaine contenu de l'interaction.
*/
std::string Todo::getContenu() const
{
    return this->contenu;
}

/// Mutateurs

/**
    *@brief Pour lier une intéraction à la classe Todo.
    *@param inter : l'intéraction à lier au Todo.
*/
void Todo::setInteraction(const Interaction& inter)
{
    *lienInteraction = inter;
}

/**
    *@brief Pour affecter une date à l'interaction.
    *@param t : structure tm représentant la date à affecter.
    *@details La structure tm t passée en paramètre est copié dans l'instance pointée par date.
*/
void Todo::setDate(const tm & t)
{
    *date= t;
}

/**
    *@brief Pour affecter un contenu à l'interaction.
    *@param c : string à affecter au contenu.
*/
void Todo::setContenu(const std:: string & c)
{
    contenu= c;
}

/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param td: de type Todo qui represente le Todo à afficher.
    *@details Pour afficher un Todo, on affiche son contenu suivie de sa date.
*/
std::ostream& operator<<(std::ostream& os, const Todo& td)
{
    tm* t= new tm(td.getDate());
    char* d= asctime(t);
    os<<"@todo " << td.getContenu() << d;

    delete t;
    return os;
}
