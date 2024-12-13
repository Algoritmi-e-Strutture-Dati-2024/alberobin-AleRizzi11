#include <iostream>

template <typename T>
class AlberoBinario {
private:
    T nodi[100];
    bool esistenti[100];

public:
    AlberoBinario(){
    for (int i = 0; i < 100; ++i) {
        esistenti[i] = false;
    }
	}
	
    bool alberoVuoto() const{
    return !esistenti[0];
	}
	
    void insRadice(const T& value){
    if (esistenti[0]) {
        std::cout << "Errore: La radice esiste gia'." << std::endl;
        return;
    }
    nodi[0] = value;
    esistenti[0] = true;
	}
	
    T radice() const{
    if (alberoVuoto()) {
        std::cout << "Errore: L'albero e' vuoto." << std::endl;
        return T();
    }
    return nodi[0];
	}
	
    bool isFoglia(int indice) const{
    if (!esistenti[indice]) {
        std::cout << "Errore: Indice non valido." << std::endl;
        return false;
    }
	return !esistenti[figlioSinistro(indice)] && !esistenti[figlioDestro(indice)];
	}
    
    int figlioSinistro(int indice) const{
    return 2 * indice + 1;
	}

    int figlioDestro(int indice) const{
    return 2 * indice + 2;
	}

    void insFiglioSinistro(int indice, const T& value){
    int figlio = figlioSinistro(indice);
    if (!esistenti[indice]) {
        std::cout << "Errore: Indice del genitore non valido." << std::endl;
        return;
    }
    if (esistenti[figlio]) {
        std::cout << "Errore: Figlio sinistro gia' presente." << std::endl;
        return;
    }
    nodi[figlio] = value;
    esistenti[figlio] = true;
	}
	
    void insFiglioDestro(int indice, const T& value){
    int figlio = figlioDestro(indice);
    if (!esistenti[indice]) {
        std::cout << "Errore: Indice del genitore non valido." << std::endl;
        return;
    }
    if (esistenti[figlio]) {
        std::cout << "Errore: Figlio destro gia' presente." << std::endl;
        return;
    }
    nodi[figlio] = value;
    esistenti[figlio] = true;
	}
	
    void rimuovi(int indice){
    if (!esistenti[indice]) {
        std::cout << "Errore: Indice non valido." << std::endl;
        return;
    }
    if (!isFoglia(indice)) {
        std::cout << "Errore: Il nodo non e' una foglia." << std::endl;
        return;
    }
    esistenti[indice] = false;
	}

    void stampa() const{
    for (int i = 0; i < 100; ++i) {
        if (esistenti[i]) {
            std::cout << "Pos " << i << ", Valore: " << nodi[i] << std::endl;
        }
    }
	}
};
