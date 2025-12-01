# pragma once 

#include "Point2D.hpp"
#include <vector>

template <typename T>
class Polygone {
    
    private : 
//----------------------------------------------------------------------------------------------------
// Attribut
//----------------------------------------------------------------------------------------------------
        std::vector <Point2D <T> > sommets;

    public : 

//----------------------------------------------------------------------------------------------------
// Constructeurs 
//----------------------------------------------------------------------------------------------------
        Polygone ()                                                         {}
        Polygone (std::vector <Point2D <T> > sommets) : sommets (sommets)   {}
        Polygone (Polygone<T> & const p) : sommets (p.sommets)              {}

//----------------------------------------------------------------------------------------------------
// Destructeur 
//----------------------------------------------------------------------------------------------------
        ~Polygone()                                                         default;

//----------------------------------------------------------------------------------------------------
// Accesseurs 
//----------------------------------------------------------------------------------------------------
        std::vector <Point2D <T> > getSommets ()                            {return this->sommets};
        void setSommets (std::vector <Point2D <T> > inSommets)              {this->sommets = inSommets};

//----------------------------------------------------------------------------------------------------
// Methodes 
//----------------------------------------------------------------------------------------------------
        void addPoints (Point2D <T> p) {
            std::vector<Point2D <T> > newSommets = this->sommets;
            newSommets.push_back(p);

            setSommets (newSommets);
        }
        
        void translater (T x, T y) {
            std::vector<Point2D <T> > sommetsTranslates = this->sommets;

            for (Point2D <T> p : sommetsTranslates) {
                p.translater(x, y);
            }
            setSommets (sommetsTranslates);
        }
};
