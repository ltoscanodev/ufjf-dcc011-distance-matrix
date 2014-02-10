#ifndef TNO_H_INCLUDED
#define TNO_H_INCLUDED

class TNo
{
    private:
        int index; // Guarda o índice j da matriz
        float info; // Guarda a distância
        TNo *next; // Guarda o próximo nó
    public:
        TNo(int j); // Construtor do TAD
        ~TNo(); // Destrutor do TAD
        int getIndex(); // Consulta o índice armazenado
        float getInfo(); // Consulta a distância armazenada
        void setInfo(float val); // Altera a distância armazenada
        TNo* getNext(); // Consulta o próximo nó
        void setNext(TNo *p); // Altera o próximo nó
};

#endif // TNO_H_INCLUDED
