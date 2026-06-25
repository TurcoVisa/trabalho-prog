#include <stdio.h>
#include <string.h>

typedef struct {
int id; //identificador
char nome[50];
char artista[50];
char genero[30];
int duracao; // em segundos
int curtidas;
} Musica;


int buscarPorId(Musica playlist[], int qtd, int id) {
    for(int i = 0; i < qtd; i++) {
        if(playlist[i].id == id) {
            return i;
        }
    }
    return -1;
}


int cadastrarMusica(Musica playlist[], int qtd) {
    int idx;
    printf("insira o ID\n");
    scanf("%d", &idx);
    if(buscarPorId(playlist, qtd, idx) != -1) {
        return 0;
    } else {
        playlist[qtd].id = idx;
        printf("insira o nome\n");
        scanf("%s", playlist[qtd].nome);
        printf("insira o artista\n");
        scanf("%s", playlist[qtd].artista);
        printf("insira o genero\n");
        scanf("%s", playlist[qtd].genero);
        printf("insira a duracao\n");
        scanf("%d", &playlist[qtd].duracao);
        printf("insira a quantidade de curtidas\n");
        scanf("%d", &playlist[qtd].curtidas);
        return 1;
    }
}

void exibirPlaylist(Musica playlist[], int qtd) {
    for(int i = 0; i<qtd; i++) {
        printf("%s\n", playlist[i].nome);
    }
} 

void listarPorArtista(Musica playlist[], int qtd, char artista[]) {
    for(int i = 0; i<qtd; i++) {
        if(!strcmp(playlist[i].artista, artista)) {
            printf("%s\n", playlist[i].nome);
        }
    }
}

void curtirMusica(Musica playlist[], int qtd, int id) {
    if(buscarPorId(playlist, qtd, id) == -1) {
        printf("id não encontrado\n");
    } else {
        playlist[buscarPorId(playlist, qtd, id)].curtidas++;
    }
}

void musicaMaisCurtida(Musica playlist[], int qtd) {
    int maior = 0;
    for(int i = 0; i<qtd; i++) {
        if(playlist[i].curtidas>playlist[maior].curtidas) {
            maior = i;
        }
    }
    printf("%s\n", playlist[maior].nome);
}

int duracaoTotal(Musica playlist[], int qtd) {
    int totalSegundos = 0;
    for(int i = 0; i<qtd; i++) {
        totalSegundos = totalSegundos + playlist[i].duracao;
    }
    return totalSegundos;
}

void mostrarEstatisticas(Musica playlist[], int qtd) {
    printf("A playlist tem %d ", qtd);
    printf("musicas\n");
    int totalCurtidas = 0;
    for(int i = 0; i<qtd; i++) {
        totalCurtidas = totalCurtidas + playlist[i].curtidas;
    }
    printf("o total de curtidas e %d\n", totalCurtidas);
    printf("a média de curtidas por musica e de %d\n", totalCurtidas/qtd);
    printf("a duracao media das musicas e de %d ", duracaoTotal(playlist, qtd)/qtd);
    printf("segundos\n");
}
void ordernarPorNome(Musica playlist[],int qtd){
    int i,j,temp;
    for(i=0;i<qtd-1;i++){
        for(j=0;j<qtd-i-1;j++){
            if(playlist[j].nome>playlist[j+1].nome){
                temp=playlist[j].nome;
                playlist[j+1].nome=temp;
            }
        }
    }
}
void ordernarPorcurtidas(Musica playlist[],int qtd){
    int i,j,temp;
    for(i=0;i<qtd-1;i++){
        for(j=0;j<qtd-i-1;j++){
            if(playlist[j].curtidas>playlist[j+1].curtidas){
                temp=playlist[j].curtidas;
                playlist[j+1].curtidas=temp;
            }
        }
    }
}
int main(){

    int opcao;
    Musica playlist[100];
    int tamanho = 0;

    do {
        printf("Escolha uma opcao\n");
        printf("(1) Cadastrar musica\n");
        printf("(2) Exibir Playlist\n");
        printf("(3) Buscar Musica por ID\n");
        printf("(4) Listar musica por artista\n");
        printf("(5) Curtir uma musica\n");
        printf("(6) Exibir musica mais curtida\n");
        printf("(7) Calcular duracao total da Playlist\n");
        printf("(8) Ordenar Playlist por nome\n");
        printf("(9) Ordenar Playlist por curtidas\n");
        printf("(10) Mostrar estatisticas da Playlist \n");
        printf("(11) Encerrar programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if(cadastrarMusica(playlist, tamanho) == 1) {
                tamanho++;
            }
            break;
        
        case 2:
            exibirPlaylist(playlist, tamanho);
            break;
        case 3:
            int idx, indexID;
            printf("insira o ID que voce quer encontrar\n");
            scanf("%d", & idx);
            indexID = buscarPorId(playlist, tamanho, idx);
            if(indexID== -1) {
                printf("indice nao encontrado\n");
            } else {
                printf("nome: %s\n", playlist[indexID].nome);
                printf("artista: %s\n", playlist[indexID].artista);
                printf("genero: %s\n", playlist[indexID].genero);
                printf("duracao: %d\n", playlist[indexID].duracao);
                printf("curtidas: %d\n", playlist[indexID].curtidas);
            }
            break;
        case 4:
            char artista[50];
            printf("insira o artista que quer procurar\n");
            scanf("%s", artista);
            listarPorArtista(playlist, tamanho, artista);
            break;
        case 5:
            printf("escolha o id da musica para curtir\n");
            int idCurtida;
            scanf("%d", &idCurtida);
            curtirMusica(playlist, tamanho, idCurtida);
            break;
        case 6:
            musicaMaisCurtida(playlist, tamanho);
            break;
        case 7:
            printf("a duracao total da playlist e de: %d ", duracaoTotal(playlist, tamanho));
            printf("segundos\n");
            break;
        case 8:
            ordernarPorNome(playlist,tamanho); 
            break;
        case 9:
            ordernarPorcurtidas(playlist,tamanho);
            break;
        case 10:
            mostrarEstatisticas(playlist, tamanho);
            break;  
        case 11:
            
            break;
        default:
            printf("opcao invalida\n");
            break;
        }
        
    } while(opcao != 11);
    return 0;
}
