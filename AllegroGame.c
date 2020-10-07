#include "declaracoes.h"

const int width = 800;
const int height = 400;
const int FPS = 60;
enum keys { PULO, ESQUERDA, DIREITA, ESPACO};
bool keys[6] = { false ,false , false, false };

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP* folha_sprites = NULL;
ALLEGRO_BITMAP* fundo = NULL;

int main()
{
	bool redraw = true;
	bool done = false;
	

	struct Sprite mulher;
	struct Personagem principal;
	init_mulher(&mulher, &principal);

	if (inicializar() != 1)
	{
		error_msg("Falha ao inicializar o jogo");
		return -1;
	}

	while (!done)
	{
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_eventos, &evento);

		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			sprites(&mulher, &principal);

			if (keys[PULO])
				printf("oi");
			if (keys[ESQUERDA])
				printf("oi");
			if (keys[DIREITA])
			{
				principal.pos_x_sprite += principal.vel_x_sprite;
			}
				
			if (keys[ESPACO])
				printf("oi");
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[PULO] = true;
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

			al_draw_bitmap_region(fundo, 0, 0, width, height, 0, 0, 0);


			if (principal.vel_x_sprite > 0)
			{
				al_draw_scaled_bitmap(folha_sprites,
					mulher.regiao_x_folha, mulher.regiao_y_folha,
					principal.largura_sprite, principal.altura_sprite,
					principal.pos_x_sprite + principal.largura_sprite, principal.pos_y_sprite,
					principal.largura_sprite + 80, principal.altura_sprite + 80, 0);
			}
			else
			{
				al_draw_scaled_bitmap(folha_sprites,
					mulher.regiao_x_folha, mulher.regiao_y_folha,
					principal.largura_sprite, principal.altura_sprite,
					principal.pos_x_sprite + principal.largura_sprite, principal.pos_y_sprite,
					-principal.largura_sprite - 80, principal.altura_sprite + 80, 0);
			}
			al_flip_display();
			redraw = 0;

		}



	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_bitmap(folha_sprites);
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

	folha_sprites = al_load_bitmap("sprites/Mulher-aventureira.png"); // Carregando a folha de sprites
	if (!folha_sprites)
	{
		error_msg("Falha ao carregar a folha de sprites");
		return -1;
	}

	fundo = al_load_bitmap("sprites/background.png"); //Carregando o background do jogo
	if (!fundo)
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



