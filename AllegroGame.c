#include "declaracoes.h"

const int width = 800;
const int height = 400;
const int FPS = 60;

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP* folha_sprites = NULL;
ALLEGRO_BITMAP* fundo = NULL;

int main()
{

	bool redraw = true;
	bool done = false;
	int altura_sprite = 32, largura_sprite = 32;
	int colunas_folha = 4, coluna_atual = 0;
	int linha_atual = 0, linhas_folha = 1;
	int regiao_x_folha = 0, regiao_y_folha = 0;
	int frames_sprite = 200000, cont_frames = 0;
	int pos_x_sprite = 50, pos_y_sprite = 150;
	int vel_x_sprite = 4, vel_y_sprite = 0;



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
			

			redraw = 1;
		}
		if (redraw && al_is_event_queue_empty(fila_eventos)) 
		{
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
		error_msg("A addon de imagens não foi inicializada");
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

	folha_sprites = al_load_bitmap("Pink_Monster_Attack1_4.png"); // Carregando a folha de sprites
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
	al_start_timer(timer); // Iniciando o timer

	return 1;
}

