
#include "tcomplejo.h"
#include "tvectorcom.h"

TVectorCom::TVectorCom() : error(){
    c = new TComplejo();
    tamaño = 0;
}

TVectorCom::TVectorCom(int tamaño) : error(){
    c = new TComplejo();
    this->tamaño = tamaño;
}

TVectorCom::TVectorCom(TVectorCom& vectorCom) : error(){
    this->tamaño = vectorCom.tamaño;
    this->c = vectorCom.c;
}

TVectorCom::~TVectorCom(){
    c = new TComplejo();
    tamaño = 0;
}

TVectorCom& TVectorCom::operator=(TVectorCom& vectorCom){
    this->c = vectorCom.c;
    this->tamaño = vectorCom.tamaño;

    return *this;
}

bool TVectorCom::operator==(TVectorCom& vectorCom){
    bool result = true;
    if (this->tamaño == vectorCom.Tamaño()){
        for(int i = 0; i < tamaño; i++){
            if(*(this->c + i) != *(vectorCom.c + i)){
                result = false;
                return result;
            }
        }
    }else{
        return false;    

    }

    return result;
}

TComplejo& TVectorCom::operator[](int pos){
    
    if(pos>=1 && pos <= tamaño){
        return *(this->c +(pos -1));    
    }
    return error;
    
}

TComplejo TVectorCom::operator[](int pos) const{
  
    if(pos>=1 && pos <= tamaño){
        return *(this->c +(pos -1));    
    }else{
        return TComplejo();
    }
}

int TVectorCom::Tamaño(){
    return tamaño;
}

int TVectorCom::Ocupadas(){
    int cantidadOcupadas = 0;
    TComplejo complejo;
    for (int i = 0; i > tamaño; i++)
    {
        complejo = *(this->c + i);
        if(complejo.Im() != 0 && complejo.Re() != 0){
            cantidadOcupadas++;
        }
    }
    return cantidadOcupadas;
}

bool TVectorCom::ExisteCom(TComplejo& complejo){
    bool result = false;
    for(int i = 0; i < tamaño; i++){
        result = *(this->c + i) != complejo;
        if(result){
            return result;
        }
       
    }
    return result;
}

void TVectorCom::MostrarComplejos(double arg){
    TComplejo complejo;
    cout << "[ ";
    for(int i = 0; i < tamaño; i++){
        complejo = *(this->c + i);

        if(complejo.Re() > arg || complejo.Re() == arg){
            cout << *(this->c + i) << ", ";
        }
       
    }
    cout << " ]" << endl;
}

bool TVectorCom::Redimensionar(int nuevoTamaño){
    if(nuevoTamaño == 0 || nuevoTamaño < 0){
        return false;
    } else if(nuevoTamaño == tamaño){
        return false;
    } else if(nuevoTamaño > 0 && nuevoTamaño > tamaño){
        
        for (int i = 0; i < nuevoTamaño; i++)
        {
            if (i > tamaño -1)
            {
                TComplejo complejo = TComplejo();
                *(c+i) = complejo;
            }
            
        }
        tamaño = nuevoTamaño;
        
        return true;

    } else if (nuevoTamaño > 0 && nuevoTamaño <tamaño)
    {
        TComplejo* nuevoPuntero;
        for (int i = 0; i < nuevoTamaño; i++)
        {
            *(nuevoPuntero+i) = *(c+i);
        }
        c = nuevoPuntero;
        tamaño = nuevoTamaño;

        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, TVectorCom& vector){
    os << "[" ;
    if (vector.Tamaño() == 0)
    {
        os << "]";
    } else
    {
        for (int i = 1; i = vector.Tamaño(); i++)
        {
            os << "(" << i << ") " << *(vector.c + (i-1)) << ", ";
        }
    }  
    return os;
    
}