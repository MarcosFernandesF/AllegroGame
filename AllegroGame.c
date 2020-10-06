#include "declaracoes.h"

const int width = 800;
const int height = 400;
const int FPS = 60;
enum KEYS { CIMA, BAIXO, ESQUERDA, DIREITA, ESPAÇO, CLICK};
bool keys[6] = { false, false, false ,false , false, false };

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP* folha_sprites = NULL;
ALLEGRO_BITMAP* fundo = NULL;

int altura_sprite = 32, largura_sprite = 32;
int colunas_folha = 4, coluna_atual = 0;
int linhas_folha = 1, linha_atual = 0;
int regiao_x_folha = 0, regiao_y_folha = 0;
int frames_sprite = 200000, cont_frames = 0;
int pos_x_sprite = 50, pos_y_sprite = 150;
int vel_x_sprite = 4, vel_y_sprite = 0;

int main()
{

	bool redraw = true;
	bool done = false;
	



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

			sprite();

			if (keys[CIMA])
				al_clear_to_color(al_map_rgb(255, 0, 0));
			if (keys[BAIXO])
				al_clear_to_color(al_map_rgb(0, 255, 0));
			if (keys[ESQUERDA])
				printf("ESQUERDA");
			if (keys[DIREITA])
				printf("DIREITA");
			if (keys[ESPAÇO])
				printf("ESPAÇO");
			if (keys[CLICK])
				printf("CLICK");
		}

		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_W:
				keys[CIMA] = true;
				break;
			case ALLEGRO_KEY_S:
				keys[BAIXO] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[ESQUERDA] = true;
				break;
			case ALLEGRO_KEY_D:
				keys[DIREITA] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPAÇO] = true;
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
			case ALLEGRO_KEY_W:
				keys[CIMA] = false;
				break;
			case ALLEGRO_KEY_S:
				keys[BAIXO] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[ESQUERDA] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[DIREITA] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPAÇO] = false;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				keys[CLICK] = true;
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				keys[CLICK] = false;
		}
			
		if (redraw && al_is_event_queue_empty(fila_eventos)) 
		{
			redraw = false;

			al_draw_bitmap_region(fundo, 0, 0, width, height, 0, 0, 0);


			if (vel_x_sprite > 0)
			{
				al_draw_bitmap_region(folha_sprites, regiao_x_folha,
					regiao_y_folha, largura_sprite, altura_sprite, pos_x_sprite, pos_y_sprite, 0);
			}
			else
			{
				al_draw_scaled_bitmap(folha_sprites,
					regiao_x_folha, regiao_y_folha,
					largura_sprite, altura_sprite,
					pos_x_sprite + largura_sprite, pos_y_sprite,
					-largura_sprite, altura_sprite, 0);
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


	timer = al_create_timer(1 / FPS); // Criando o timer
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

	folha_sprites = al_load_bitmap("Owlet_Monster_Attack1_4.png"); // Carregando a folha de sprites
	if (!folha_sprites)
	{
		error_msg("Falha ao carregar a folha de sprites");
		return -1;
	}

	fundo = al_load_bitmap("background.png"); //Carregando o backgrounde do jogo
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

void sprite() 
{
	cont_frames++;
	if (cont_frames >= frames_sprite)
	{
		cont_frames = 0;

		coluna_atual++;

		if (coluna_atual >= colunas_folha)
		{
			coluna_atual = 0;

			linha_atual = (linha_atual + 1) % linhas_folha;

			regiao_y_folha = linha_atual * altura_sprite;
		}

		regiao_x_folha = coluna_atual * largura_sprite;
	}
	if (pos_x_sprite + largura_sprite > width - 20 || pos_x_sprite < 20)
	{
		vel_x_sprite = -vel_x_sprite;
	}
}

