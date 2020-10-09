#include "declaracoes.h"

const int FPS = 60;		
const int num_inimigos = 2;
enum keys { PULO, ESQUERDA, DIREITA, ESPACO, DIRECAO, GRAVIDADE};
bool keys[6] = { false ,false , false, false, true, false };

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP* Elisabeth_png = NULL;
ALLEGRO_BITMAP* fundo_png = NULL;
ALLEGRO_BITMAP* inimigos_png[2] = { NULL, NULL };
int main()
{
	bool redraw = true;
	bool done = false;
	bool parado = true;
	int i;
	int col_max, lin_atual_2;

	struct Sprite elisabeth; // Sprite da elisabeth
	struct Sprite inimigo[2]; // Sprite dos inimigos no geral
	struct Personagem principal;  // Personagem Principal
	struct Personagem secundario[2]; // Personagem secundario

	init_elisabeth(&elisabeth, &principal); //Inicialização da elisabeth
	
	for (i = 0; i < num_inimigos; i++)
	{
		init_inimigos(inimigo, secundario, i); // Inicializando inimigo no mapa
	}

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
			redraw = true;
			
			
			int zero;
			for (zero = 0; zero < num_inimigos; zero++)
			{
				switch (zero)
				{
				case 0:
					 col_max = 5, lin_atual_2 = 0;
					animacao2(inimigo, secundario, col_max, lin_atual_2, zero);
					break;
				case 1:
					 col_max = 8, lin_atual_2 = 3;
					animacao2(inimigo, secundario, col_max, lin_atual_2, zero);
					break;
				}
			}
			if (parado) // Parado realiza animação padrão
			{
				 col_max = 5, lin_atual_2 = 0;
				animacao(&elisabeth, &principal, col_max, lin_atual_2);
			}

			if (keys[ESQUERDA]) // Vai para a esquerda
			{
				 col_max = 7, lin_atual_2 = 1;
				
				keys[DIRECAO]= false;
				animacao(&elisabeth, &principal, col_max, lin_atual_2);
				principal.pos_x_sprite -= principal.vel_x_sprite;
			}			
			if (keys[DIREITA]) // Vai para a direita
			{
				 col_max = 7, lin_atual_2 = 1;
				
				keys[DIRECAO] = true;
				animacao(&elisabeth, &principal, col_max, lin_atual_2);
				principal.pos_x_sprite += principal.vel_x_sprite;
			}
				
			if (keys[ESPACO]) // Comando para bater
			{
				 col_max = 9, lin_atual_2 = 5;
				
				animacao(&elisabeth, &principal, col_max, lin_atual_2);
			}
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				// Precisa consertar ainda
				int col_max = 7, lin_atual_2 = 1;
				parado = false;
				animacao(&elisabeth, &principal, col_max, lin_atual_2);
				pos_y_anterior = principal.pos_y_sprite;
				principal.pos_y_sprite -= principal.vel_y_sprite;
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
		else if (evento.type == ALLEGRO_EVENT_KEY_UP)
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
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DIREITA] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPACO] = false;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				printf("click");
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				printf("click");
		}

		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
			
		if (redraw && al_is_event_queue_empty(fila_eventos)) 
		{
			redraw = false;
			int indice;
			int pos_x, pos_y;

			// Desenhando o fundo
			al_draw_scaled_bitmap(fundo_png, 0, 0, 1024, 383, 0, 0,width,height, 0);

			
			/* Infelizmente al_draw_scaled_bitmap nao funciona dentro de outra função void
			   Entao tive que fazer o desenho dos inimigos diretamente na main */
			for (indice = 0; indice < num_inimigos; indice++)
			{
				switch (indice)
				{
				case 0: // Inimigo 1
					pos_x = 30, pos_y = height/2;
					al_draw_scaled_bitmap(inimigos_png[indice],
						inimigo[indice].regiao_x_folha, inimigo[indice].regiao_y_folha,
						secundario[indice].largura_sprite, secundario[indice].altura_sprite,
						pos_x + secundario[indice].largura_sprite, pos_y,
					secundario[indice].largura_sprite + 80, secundario[indice].altura_sprite + 80, 0);
					break;
				case 1: // Inimigo 2
					pos_x = 60, pos_y = 60;
					al_draw_scaled_bitmap(inimigos_png[indice],
						inimigo[indice].regiao_x_folha, inimigo[indice].regiao_y_folha,
						secundario[indice].largura_sprite, secundario[indice].altura_sprite,
						pos_x + secundario[indice].largura_sprite, pos_y,
						secundario[indice].largura_sprite + 80, secundario[indice].altura_sprite + 80, 0);
					break;
				}
			}

			if (keys[DIRECAO])
			{
				// Boneco para um lado
				al_draw_scaled_bitmap(Elisabeth_png,
					elisabeth.regiao_x_folha, elisabeth.regiao_y_folha,
					principal.largura_sprite, principal.altura_sprite,
					principal.pos_x_sprite + principal.largura_sprite, principal.pos_y_sprite,
					principal.largura_sprite + 80, principal.altura_sprite + 80, 0);
			}
			else
			{
				// Boneco ao contrario
				al_draw_scaled_bitmap(Elisabeth_png,
					elisabeth.regiao_x_folha, elisabeth.regiao_y_folha,
					principal.largura_sprite, principal.altura_sprite,
					principal.pos_x_sprite + principal.largura_sprite, principal.pos_y_sprite,
					principal.largura_sprite + 80 , principal.altura_sprite + 80, ALLEGRO_FLIP_HORIZONTAL);
			}
			al_flip_display();
			redraw = 0;

		}



	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_bitmap(Elisabeth_png);
	al_destroy_bitmap(inimigos_png[0]);
	al_destroy_bitmap(inimigos_png[1]);
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

	inimigos_png[0] = al_load_bitmap("sprites/Inimigos/Dwarf.png"); // Carregando ciclope
	inimigos_png[1] = al_load_bitmap("sprites/Inimigos/Minotauro.png"); // Carregando minotauro

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



