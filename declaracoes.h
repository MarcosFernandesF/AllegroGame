#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#define width 1000
#define height 750

struct Acao
{
	bool esqueleto; // Controle para saber se a animacao e do Esqueleto (animação diferente das demais)
	int col_atual; // Coluna atual da folha de sprite
	int col_atual_old; // Coluna atual antiga utilizado para animação do Esqueleto
	int lin_atual; // Linha atual da folha de sprite
	int col_folha; // Colunas totais da folha de sprite
	int lin_folha; // Linhas totais da folha de sprite
	int frames_min; // Frame minimo da animação
	int frames_max; // Frame maximo da animação
};

struct Personagem
{
	struct Acao animacao[5];
	int vivo; // Vivo ou morto
	int vidas_1; // Vidas
	int vidas_2; // Vida do segundo inimigo
	int altura_sprite; // Na folha
	int largura_sprite;  // Na folha
	int altura_sprite_tela; // Na tela
	int largura_sprite_tela; // Na tela
	int pos_x_sprite; // Posição X para incremento da movimentação
	int pos_y_sprite; // Posição Y para incremento da movimentação
	int inicio_x; // Inicio da posiçao X
	int inicio_y; // Inicio da posiçao Y
	int pos_x_sprite_2; // Posição X para movimentar segundo inimigo
	int pos_y_sprite_2; // Posição Y para movimentar segundo inimigo
	int vel_x_sprite; // Velocidade eixo X
	int vel_y_sprite; // Velocidade eixo Y
	int x_folha; // X da folha de sprite
	int y_folha; // Y da folha de sprite
};

struct Cenario
{
    int MapaColuna; // Numero de colunas
	int MapaTam; // Tamanho do vetor
	int BlocoTam; // Tamanho original do bloco
};

// Mensagem de erro
void error_msg(char *mensagem);
// Inicialização do Programa
int inicializar();
// Função responsável por animar
void animacao_beth_jack(struct Personagem* beth_jack, int acao, bool jack);
void animacao_inimigos(struct Personagem inimigos[], int acao, int indice);
// Inicialização do Personagem Principal
void init_elisabeth(struct Personagem* elisabeth);
void init_jack(struct Personagem* jack);
// Inicializando dos inimigos
void init_dwarf(struct Personagem dwarf[]);
void init_minotauro(struct Personagem minotauro[]);
void init_esqueleto(struct Personagem esqueleto[]);
// Tirando os inimigos do mapa
//void morte_inimigo(struct Sprite monstro[], struct Personagem secundario[], int indice);
// Inicializa mapas
void init_cenario(struct Cenario* mapa);
// Desenha os inimigos em posições do mapa e o jack tambem
void desenha_inimigos(ALLEGRO_BITMAP* monstro_png [], ALLEGRO_BITMAP* jack_png, struct Personagem inimigos[], struct Personagem* jack, int level);
// Desenha Elisabeth
void desenha_elisabeth(ALLEGRO_BITMAP* elisabeth_png, struct Personagem* elisabeth, bool keys[], int DIRECAO);
// Colisao de personagens
void colisao_personagens(struct Personagem* elisabeth, struct Personagem inimigos[], int indice);
//Colisao com os blocos
int colisao_blocos(struct Personagem* elisabeth, int caindo, int level);
