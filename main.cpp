int main() {
    AlberoBinario<int> albero;

    albero.insRadice(11);
    albero.insFiglioSinistro(0, 4);
    albero.insFiglioDestro(0, 12);
    
    std::cout << "Albero:\n";
    albero.stampa();
    
    albero.rimuovi(2);
    
    std::cout << "Albero dopo la rimozione:\n";
    albero.stampa();
    
    return 0;
}
