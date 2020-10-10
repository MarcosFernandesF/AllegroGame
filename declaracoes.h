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


struct Acao
{
	bool esqueleto;
	int col_atual;
	int col_atual_old;
	int lin_atual;
	int col_folha;
	int lin_folha;
	int frames_min;
	int frames_max;
};

struct Personagem
{
	struct Acao animacao[5];
	int altura_sprite;
	int largura_sprite;
	int pos_x_sprite;
	int pos_y_sprite;
	int vel_x_sprite;
	int vel_y_sprite;
	int x_folha;
	int y_folha;
};

// Mensagem de erro
void error_msg(char *mensagem);
// Inicializa��o do Programa
int inicializar();
// Fun��o respons�vel por animar
void animacao_elisabeth1(struct Personagem* beth_jack, int acao);
void animacao_inimigos(struct Personagem inimigos[], int acao, int indice);
// Inicializa��o do Personagem Principal
void init_elisabeth(struct Personagem* elisabeth);
// Inicializando inimigos
void init_dwarf(struct Personagem dwarf[]);
void init_minotauro(struct Personagem minotauro[]);
void init_esqueleto(struct Personagem esqueleto[]);
// Tirando os inimigos do mapa
void morte_inimigo(struct Sprite monstro[], struct Personagem secundario[], int indice);
