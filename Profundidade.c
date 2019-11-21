#include "Profundidade.h"

void VisitaDfs(TipoValorVertice u, TipoGrafo ∗Grafo, TipoValorTempo ∗Tempo, TipoValorTempo ∗d, TipoValorTempo ∗t , TipoCor ∗Cor, short ∗Antecessor){
    char FimListaAdj ; TipoValorAresta Peso; TipoApontador Aux;
    TipoValorVertice v; Cor[u] = cinza; (∗Tempo)++; d[u] = (∗Tempo);
    printf ( "Visita%2d Tempo descoberta:%2d cinza\n" , u, d[u]) ; getchar ();
    if ( ! ListaAdjVazia(&u, Grafo)){
        Aux = PrimeiroListaAdj(&u, Grafo) ; FimListaAdj = FALSE;
        while ( ! FimListaAdj){
            ProxAdj(&u, &v, &Peso, &Aux, &FimListaAdj);
            if (Cor[v] == branco){
                Antecessor[v] = u; VisitaDfs(v, Grafo, Tempo, d, t , Cor, Antecessor);
            }
        }
    }
    Cor[u] = preto ; (∗Tempo)++; t [u] = (∗Tempo);
    printf ( "Visita%2d Tempo termino:%2d preto\n" , u, t [u] ) ; getchar ();
}

void BuscaEmProfundidade(TipoGrafo ∗Grafo){
    TipoValorVertice x;
    TipoValorTempo Tempo;
    TipoValorTempo d[MAXNUMVERTICES + 1] , t [MAXNUMVERTICES + 1];
    TipoCor Cor[MAXNUMVERTICES+1];
    short Antecessor[MAXNUMVERTICES+1];
    Tempo = 0;
    for (x = 0; x <= Grafo−>NumVertices− 1; x++){
        Cor[x] = branco;
        Antecessor[x] = −1;
    }
    for (x = 0; x <= Grafo−>NumVertices− 1; x++){
        if (Cor[x] == branco){
            VisitaDfs(x, Grafo, &Tempo, d, t , Cor, Antecessor);
        }
    }
}

