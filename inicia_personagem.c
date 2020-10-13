#include "declaracoes.h"

void init_elisabeth(struct Personagem* elisabeth)
{
	elisabeth->vivo = 1;
	elisabeth->vidas_1 = 3;
	elisabeth->altura_sprite = 32;
	elisabeth->largura_sprite = 32;
	elisabeth->altura_sprite_tela = 112;
	elisabeth->largura_sprite_tela = 112;
	elisabeth->pos_x_sprite = 0;
	elisabeth->pos_y_sprite = 0;
	elisabeth->inicio_x = 50;
	elisabeth->inicio_y = height - 180;
	elisabeth->vel_x_sprite = 5;
	elisabeth->vel_y_sprite = 30;
	elisabeth->x_folha = 0;
	elisabeth->y_folha = 0;

	// IDLE
	elisabeth->animacao[0].col_atual = 0;
	elisabeth->animacao[0].lin_atual = 0;
	elisabeth->animacao[0].col_folha = 5;
	elisabeth->animacao[0].frames_min = 0;
	elisabeth->animacao[0].frames_max = 9;

	// Andar
	elisabeth->animacao[1].col_atual = 0;
	elisabeth->animacao[1].lin_atual = 1;
	elisabeth->animacao[1].col_folha = 7;
	elisabeth->animacao[1].lin_folha = 0;
	elisabeth->animacao[1].frames_min = 0;
	elisabeth->animacao[1].frames_max = 9;

	// Ataque
	elisabeth->animacao[2].col_atual = 0;
	elisabeth->animacao[2].lin_atual = 5;
	elisabeth->animacao[2].col_folha = 8;
	elisabeth->animacao[2].lin_folha = 0;
	elisabeth->animacao[2].frames_min = 0;
	elisabeth->animacao[2].frames_max = 5;

	// Morte
	elisabeth->animacao[3].col_atual = 0;
	elisabeth->animacao[3].lin_atual = 4;
	elisabeth->animacao[3].col_folha = 6;
	elisabeth->animacao[3].lin_folha = 0;
	elisabeth->animacao[3].frames_min = 0;
	elisabeth->animacao[3].frames_max = 9;

}

void init_jack(struct Personagem* jack)
{
	jack->altura_sprite = 32;
	jack->largura_sprite = 32;
	jack->x_folha = 0;
	jack->y_folha = 0;

	// IDLE
	jack->animacao[0].col_atual = 0;
	jack->animacao[0].lin_atual = 0;
	jack->animacao[0].col_folha = 12;
	jack->animacao[0].lin_folha = 0;
	jack->animacao[0].frames_min = 0;
	jack->animacao[0].frames_max = 9;

	// Caido
	jack->animacao[1].col_atual_old = 5;
	jack->animacao[1].col_atual = 5;
	jack->animacao[1].lin_atual = 7;
	jack->animacao[1].col_folha = 6;
	jack->animacao[1].lin_folha = 0;
	jack->animacao[1].frames_min = 0;
	jack->animacao[1].frames_max = 9;
}


void init_dwarf(struct Personagem dwarf[])
{
	dwarf[0].vivo = 1;
	dwarf[0].vidas_1 = 1;
	dwarf[0].altura_sprite = 32;
	dwarf[0].largura_sprite = 38;
	dwarf[0].altura_sprite_tela = 112;
	dwarf[0].largura_sprite_tela = 112;
	dwarf[0].vel_x_sprite = 5;
	dwarf[0].vel_y_sprite = 8;
	dwarf[0].x_folha = 0;
	dwarf[0].y_folha = 0;

	// IDLE
	dwarf[0].animacao[0].col_atual_old = 0;
	dwarf[0].animacao[0].col_atual = 0;
	dwarf[0].animacao[0].lin_atual = 0;
	dwarf[0].animacao[0].col_folha = 3;
	dwarf[0].animacao[0].lin_folha = 0;
	dwarf[0].animacao[0].frames_min = 0;
	dwarf[0].animacao[0].frames_max = 10;

	// Andar
	dwarf[0].animacao[1].col_atual_old = 0;
	dwarf[0].animacao[1].col_atual = 0;
	dwarf[0].animacao[1].lin_atual = 1;
	dwarf[0].animacao[1].col_folha = 7;
	dwarf[0].animacao[1].lin_folha = 0;
	dwarf[0].animacao[1].frames_min = 0;
	dwarf[0].animacao[1].frames_max = 8;

	// Ataque
	dwarf[0].animacao[2].col_atual_old = 0;
	dwarf[0].animacao[2].col_atual = 0;
	dwarf[0].animacao[2].lin_atual = 3;
	dwarf[0].animacao[2].col_folha = 5;
	dwarf[0].animacao[2].lin_folha = 0;
	dwarf[0].animacao[2].frames_min = 0;
	dwarf[0].animacao[2].frames_max = 8;

	// Morte
	dwarf[0].animacao[3].col_atual_old = 0;
	dwarf[0].animacao[3].col_atual = 0;
	dwarf[0].animacao[3].lin_atual = 7;
	dwarf[0].animacao[3].col_folha = 6;
	dwarf[0].animacao[3].lin_folha = 0;
	dwarf[0].animacao[3].frames_min = 0;
	dwarf[0].animacao[3].frames_max = 8;
	
}
void init_minotauro(struct Personagem minotauro[])
{
	minotauro[1].vivo = 1;
	minotauro[1].vidas_1 = 1;
	minotauro[1].altura_sprite = 96;
	minotauro[1].largura_sprite = 96;
	minotauro[1].altura_sprite_tela = 396;
	minotauro[1].largura_sprite_tela = 396;
	minotauro[1].vel_x_sprite = 5;
	minotauro[1].vel_y_sprite = 8;

	// IDLE
	minotauro[1].animacao[0].col_atual_old = 0;
	minotauro[1].animacao[0].col_atual = 0;
	minotauro[1].animacao[0].lin_atual = 0;
	minotauro[1].animacao[0].col_folha = 4;
	minotauro[1].animacao[0].lin_folha = 0;
	minotauro[1].animacao[0].frames_min = 0;
	minotauro[1].animacao[0].frames_max = 8;

	// Andar
	minotauro[1].animacao[1].col_atual_old = 0;
	minotauro[1].animacao[1].col_atual = 0;
	minotauro[1].animacao[1].lin_atual = 1;
	minotauro[1].animacao[1].col_folha = 7;
	minotauro[1].animacao[1].lin_folha = 0;
	minotauro[1].animacao[1].frames_min = 0;
	minotauro[1].animacao[1].frames_max = 8;

	// Ataque
	minotauro[1].animacao[2].col_atual_old = 0;
	minotauro[1].animacao[2].col_atual = 0;
	minotauro[1].animacao[2].lin_atual = 3;
	minotauro[1].animacao[2].col_folha = 8;
	minotauro[1].animacao[2].lin_folha = 0;
	minotauro[1].animacao[2].frames_min = 0;
	minotauro[1].animacao[2].frames_max = 8;

	// Morte
	minotauro[1].animacao[3].col_atual_old = 0;
	minotauro[1].animacao[3].col_atual = 0;
	minotauro[1].animacao[3].lin_atual = 19	;
	minotauro[1].animacao[3].col_folha = 5;
	minotauro[1].animacao[3].lin_folha = 0;
	minotauro[1].animacao[3].frames_min = 0;
	minotauro[1].animacao[3].frames_max = 8;
}

void init_esqueleto(struct Personagem esqueleto[])
{
	esqueleto[2].vivo = 1;
	esqueleto[2].vidas_1 = 1;
	esqueleto[2].altura_sprite = 150;
	esqueleto[2].largura_sprite = 150;
	esqueleto[2].altura_sprite_tela = 230;
	esqueleto[2].largura_sprite_tela = 230;
	esqueleto[2].vel_x_sprite = 5;
	esqueleto[2].vel_y_sprite = 8;
	esqueleto[2].x_folha = 0;
	esqueleto[2].y_folha = 0;

	// IDLE
	esqueleto[2].animacao[0].esqueleto = true;
	esqueleto[2].animacao[0].col_atual_old = 0;
	esqueleto[2].animacao[0].col_atual = 0;
	esqueleto[2].animacao[0].lin_atual = 0;
	esqueleto[2].animacao[0].col_folha = 3;
	esqueleto[2].animacao[0].lin_folha = 0;
	esqueleto[2].animacao[0].frames_min = 0;
	esqueleto[2].animacao[0].frames_max = 8;

	// Andar
	esqueleto[2].animacao[1].esqueleto = true;
	esqueleto[2].animacao[1].col_atual_old = 3;
	esqueleto[2].animacao[1].col_atual = 3;
	esqueleto[2].animacao[1].lin_atual = 0;
	esqueleto[2].animacao[1].col_folha = 7;
	esqueleto[2].animacao[1].lin_folha = 0;
	esqueleto[2].animacao[1].frames_min = 0;
	esqueleto[2].animacao[1].frames_max = 8;

	// Ataque
	esqueleto[2].animacao[2].esqueleto = true;
	esqueleto[2].animacao[2].col_atual_old = 9;
	esqueleto[2].animacao[2].col_atual = 9;
	esqueleto[2].animacao[2].lin_atual = 0;
	esqueleto[2].animacao[2].col_folha = 15;
	esqueleto[2].animacao[2].lin_folha = 0;
	esqueleto[2].animacao[2].frames_min = 0;
	esqueleto[2].animacao[2].frames_max = 8;

	// Morte
	esqueleto[2].animacao[3].esqueleto = true;
	esqueleto[2].animacao[3].col_atual_old = 15;
	esqueleto[2].animacao[3].col_atual = 15;
	esqueleto[2].animacao[3].lin_atual = 0;
	esqueleto[2].animacao[3].col_folha = 23;
	esqueleto[2].animacao[3].lin_folha = 0;
	esqueleto[2].animacao[3].frames_min = 0;
	esqueleto[2].animacao[3].frames_max = 8;
}
