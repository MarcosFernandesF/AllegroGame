#include "declaracoes.h"

const int FPS = 60;
const int num_inimigos = 3;

enum keys { PULO, ESQUERDA, DIREITA, ESPACO, DIRECAO, GRAVIDADE };
bool keys[6] = { false ,false , false, false, true, false };

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP* Elisabeth_png = NULL; 
ALLEGRO_BITMAP* fundo_png = NULL;
ALLEGRO_BITMAP* inimigos_png[3] = { NULL, NULL };

int main()
{
	bool redesenhar = true; // Variavel de controle para redesenhar algo
	bool done = false;  // Variavel de controle para o laço principal
	bool parado = true; // Variavel para saber se esta parado ou nao
	int level;
	int indice, indice2, indice3;  // Indices para acessar os vetores de inimigos
	int acao; // Utilizado para saber qual a ação necessaria do personagem

	//struct Sprite elisabeth; // Sprite da elisabeth
	//struct Sprite inimigo[3]; // Sprite dos inimigos no geral
	struct Personagem elisabeth;  // Personagem elisabeth
	struct Personagem inimigos[3]; // Personagem secundario

	init_elisabeth(&elisabeth);	//Inicialização da Elisabeth
	init_dwarf(inimigos); // Inicialização do Dwarf
	init_minotauro(inimigos); // Inicialização do Minotauro
	init_esqueleto(inimigos); // Inicialização do Esqueleto
	/*for (indice = 0; indice < num_inimigos; indice++)
	{
		init_inimigos(inimigo, inimigos, indice); // Inicializando inimigo no mapa
	}*/

	if (inicializar() != 1)
	{
		error_msg("Falha ao inicializar o jogo");
		return -1;
	}

	while (!done)
	{
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_eventos, &evento);

		int pos_y_anterior = 0;

		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			redesenhar = true;

			for (indice2 = 0; indice2 < num_inimigos; indice2++)
			{
				switch (indice2)
				{
				case 0:
					animacao_inimigos(inimigos, 0, indice2);
					break;
				case 1:
					animacao_inimigos(inimigos, 1, indice2);
					break;
				case 2:
					animacao_inimigos(inimigos, 2, indice2);
					break;
				}
			}
			if (parado) // Parado realiza animação padrão
			{
				acao = 0;
				animacao_elisabeth1(&elisabeth, acao);
			}

			if (keys[ESQUERDA]) // Vai para a esquerda
			{
				acao = 1;
				parado = false;
				keys[DIRECAO] = false;

				animacao_elisabeth1(&elisabeth, acao);
				elisabeth.pos_x_sprite -= elisabeth.vel_x_sprite;

			}
			if (keys[DIREITA]) // Vai para a direita
			{
				acao = 1;
				parado = false;
				keys[DIRECAO] = true;

				animacao_elisabeth1(&elisabeth, acao);
				elisabeth.pos_x_sprite += elisabeth.vel_x_sprite;

			}

			if (keys[ESPACO]) // Comando para bater
			{
				acao = 2;
				parado = false;
				animacao_elisabeth1(&elisabeth, acao);
			}
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) // Se a tecla for pressionada
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				// Precisa consertar ainda
				acao = 1;
				parado = false;
				animacao_elisabeth1(&elisabeth, acao);
				pos_y_anterior = elisabeth.pos_y_sprite;
				elisabeth.pos_y_sprite -= elisabeth.vel_y_sprite;
				keys[GRAVIDADE] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[ESQUERDA] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DIREITA] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPACO] = true;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_UP) // Se a tecla for solta
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[PULO] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[ESQUERDA] = false;
				parado = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DIREITA] = false;
				parado = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPACO] = false;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) // Se houver um clique do mouse
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				printf("click");
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) // Se desfizer o clique
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				printf("click");
		}

		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		if (redesenhar && al_is_event_queue_empty(fila_eventos))
		{
			redesenhar = false;
			int pos_x, pos_y;

			// Desenhando o fundo
			al_draw_scaled_bitmap(fundo_png, 0, 0, 1024, 383, 0, 0, width, height, 0);


			/* Infelizmente al_draw_scaled_bitmap nao funciona dentro de outra função void
			   Entao tive que fazer o desenho dos inimigos diretamente na main */
			for (indice3 = 0; indice3 < num_inimigos; indice3++)
			{
				switch (indice3)
				{
				case 0: // Inimigo 1
					pos_x = 30, pos_y = height / 2;
					acao = 0;
					al_draw_scaled_bitmap(inimigos_png[indice3],
						inimigos[indice3].x_folha, inimigos[indice3].y_folha,
						inimigos[indice3].largura_sprite, inimigos[indice3].altura_sprite,
						pos_x + inimigos[indice3].largura_sprite, pos_y,
						inimigos[indice3].largura_sprite + 80, inimigos[indice3].altura_sprite + 80, 0);
					break;
				case 1: // Inimigo 2
					pos_x = 60, pos_y = 60;
					acao = 1;
					al_draw_scaled_bitmap(inimigos_png[indice3],
						inimigos[indice3].x_folha, inimigos[indice3].y_folha,
						inimigos[indice3].largura_sprite, inimigos[indice3].altura_sprite,
						pos_x + inimigos[indice3].largura_sprite, pos_y,
						inimigos[indice3].largura_sprite + 80, inimigos[indice3].altura_sprite + 80, 0);
					break;
				case 2: // Inimigo 3
					pos_x = 400, pos_y = 400;
					acao = 2;
					al_draw_scaled_bitmap(inimigos_png[indice3],
						inimigos[indice3].x_folha, inimigos[indice3].y_folha,
						inimigos[indice3].largura_sprite, inimigos[indice3].altura_sprite,
						pos_x + inimigos[indice3].largura_sprite, pos_y,
						inimigos[indice3].largura_sprite + 80, inimigos[indice3].altura_sprite + 80, 0);
					break;
				}
			}

			if (keys[DIRECAO])
			{
				// Boneco para um lado
				acao = 1;
				al_draw_scaled_bitmap(Elisabeth_png,
					elisabeth.x_folha, elisabeth.y_folha,
					elisabeth.largura_sprite, elisabeth.altura_sprite,
					elisabeth.pos_x_sprite + elisabeth.largura_sprite, elisabeth.pos_y_sprite,
					elisabeth.largura_sprite + 80, elisabeth.altura_sprite + 80, 0);
			}
			else
			{
				acao = 1;
				// Boneco ao contrario
				al_draw_scaled_bitmap(Elisabeth_png,
					elisabeth.x_folha, elisabeth.y_folha,
					elisabeth.largura_sprite, elisabeth.altura_sprite,
					elisabeth.pos_x_sprite + elisabeth.largura_sprite, elisabeth.pos_y_sprite,
					elisabeth.largura_sprite + 80, elisabeth.altura_sprite + 80, ALLEGRO_FLIP_HORIZONTAL);
			}
			al_flip_display();
			redesenhar = 0;

		}



	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_bitmap(Elisabeth_png);
	al_destroy_bitmap(inimigos_png[0]);
	al_destroy_bitmap(inimigos_png[1]);
	al_destroy_bitmap(inimigos_png[2]);
	al_destroy_event_queue(fila_eventos);

	return 0;
}

int inicializar()
{

	if (!al_init()) //Inicializando o Allegro
	{
		error_msg("O Allegro nao foi inicializado");
		return -1;
	}

	if (!al_init_image_addon())  // Inicializando a biblioteca de imagem
	{
		error_msg("A addon de imagens nao foi inicializada");
		return -1;
	}

	if (!al_install_keyboard())  // Instalando o teclado
	{
		error_msg("O teclado nao foi instalado");
		return -1;
	}

	if (!al_install_mouse()) // Instalando o mouse
	{
		error_msg("O mouse nao foi instalado");
		return -1;
	}

	display = al_create_display(width, height);  // Criando o display
	if (!display)
	{
		error_msg("Falha ao criar a janela");
		return -1;
	}


	timer = al_create_timer(1.0 / FPS); // Criando o timer
	if (!timer)
	{
		error_msg("Falha ao criar o timer");
		return -1;
	}

	fila_eventos = al_create_event_queue(); // Criando a fila de eventos
	if (!fila_eventos)
	{
		error_msg("Falha ao criar a fila de eventos");
		return -1;
	}

	Elisabeth_png = al_load_bitmap("sprites/Principais/Elisabeth.png"); // Carregando a folha de sprites
	if (!Elisabeth_png)
	{
		error_msg("Falha ao carregar a folha de sprites");
		return -1;
	}

	inimigos_png[0] = al_load_bitmap("sprites/Inimigos/Dwarf.png"); // Carregando Dwarf
	inimigos_png[1] = al_load_bitmap("sprites/Inimigos/Minotauro.png"); // Carregando Minotauro
	inimigos_png[2] = al_load_bitmap("sprites/Inimigos/Esqueleto.png"); // Carregando Esqueleto

	if (!inimigos_png[0])
	{
		error_msg("Falha ao carregar um ou mais inimigos");
		return -1;
	}

	if (!inimigos_png[1])
	{
		error_msg("Falha ao carregar um ou mais inimigos");
		return -1;
	}

	if (!inimigos_png[2])
	{
		error_msg("Falha ao carregar um ou mais inimigos");
		return -1;
	}

	fundo_png = al_load_bitmap("sprites/Fundo/background.png"); //Carregando o background do jogo
	if (!fundo_png)
	{
		error_msg("Falha ao carregar o fundo do jogo");
		return -1;
	}

	al_register_event_source(fila_eventos, al_get_timer_event_source(timer)); // Registrando uma fonte de eventos do timer
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); // Registrando fonte de eventos do teclado
	al_register_event_source(fila_eventos, al_get_mouse_event_source()); // Registrando fonte de eventos do mouse
	al_start_timer(timer); // Iniciando o timer


	return 1;
}