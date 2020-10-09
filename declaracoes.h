#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#define width 1000
#define height 750



struct Sprite
{
	int colunas_folha;
	int coluna_atual;
	int linhas_folha;
	int linha_atual;
	int regiao_x_folha;
	int regiao_y_folha;
};

struct Personagem
{
	int altura_sprite;
	int largura_sprite;
	int pos_x_sprite;
	int pos_y_sprite;
	int vel_x_sprite;
	int vel_y_sprite;
	int frames_sprite;
	int cont_frames;
};
// Mensagem de erro
void error_msg(char *mensagem);
// Inicialização do Programa
int inicializar();
// Função responsável por animar
void animacao(struct Sprite* sprite, struct Personagem* beth_jack, int coluna_max, int linha_atual_2); // Struct Ponteiros
void animacao2(struct Sprite sprite[], struct Personagem inimigo[], int coluna_max, int linha_atual_2, int indice); // Struct vetor
// Inicialização do Personagem Principal
void init_elisabeth(struct Sprite* elisabeth, struct Personagem* principal);
// Inicializando inimigos no mapa
void init_inimigos(struct Sprite monstro[], struct Personagem secundario[], int indice);
// Tirando os inimigos do mapa
void reset_inimigos(struct Sprite monstro[], struct Personagem secundario[]);


