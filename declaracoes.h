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

struct Cenario
{
    int MapaColuna;
	int MapaTam;
	int BlocoTam;
};
// Mensagem de erro
void error_msg(char *mensagem);
// Inicialização do Programa
int inicializar();
// Função responsável por animar
void animacao(struct Sprite* mulher, struct Personagem* principal, int coluna_acao, int coluna_atual2, int linha_acao, int linha_atual2);
// Inicialização do Personagem Principal
void init_mulher(struct Sprite* mulher, struct Personagem* principal);
//Inicializa mapas
void InitCenario(struct Cenario* mapa);
