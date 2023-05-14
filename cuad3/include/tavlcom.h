#ifndef _TAVL_H_
#define _TAVL_H_

#include <iostream>
#include "tcomplejo.h"
#include "tvectorcom.h"
#include <vector>
#include <queue>

using namespace std;

class TAVLCom;

class TNodoAVL
{
    private:
        TComplejo item;
        TAVLCom iz, de;
        int fe;
    public:
        TNodoAVL();
        TNodoAVL(TNodoAVL&);
        ~TNodoAVL();
        TNodoAVL& operator=(TNodoAVL&);
        
        friend class TNodoAVL;
};

class TAVLCom
{
    private:
        TNodoAVL *raiz;
        void InordenAux(TVectorCom&, int&);
        void PreordenAux(TVectorCom&, int&);
        void PostordenAux(TVectorCom&, int&);
    public:
        TAVLCom();
        TAVLCom(TAVLCom&);
        ~TAVLCom();
        TAVLCom& operator=(TAVLCom&);

        bool operator==(TAVLCom&);
        bool operator!=(TAVLCom&);
        bool EsVacio();
        bool Insertar(TComplejo&);
        bool Buscar(TComplejo&);
        bool Borrar(TComplejo&);
        int Altura();
        TComplejo Raiz();
        int Nodos();
        int NodosHoja();
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();

        friend ostream& operator<<(ostream&, TAVLCom&);

        friend class TNodoAVL;
    

};

#endif