#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define BLANC al_map_rgb(255,255,255)
#define NR rand()%600

int main() {
    srand(time(NULL));
    // Declarations
    ALLEGRO_DISPLAY * game_display = NULL;
    ALLEGRO_COLOR rouge= {0};
    ALLEGRO_TIMER * game_timer= NULL;
    ALLEGRO_EVENT_QUEUE* fifo = NULL;

    //Initialisation
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());

    // Creation des éléments
    game_display = al_create_display(800, 600);
    game_timer = al_create_timer(1.0/1.0);
    fifo = al_create_event_queue();

    // Sources
    al_register_event_source(fifo, al_get_display_event_source(game_display));
    al_register_event_source(fifo, al_get_keyboard_event_source());
    al_register_event_source(fifo, al_get_timer_event_source(game_timer));

    // premier affichage
    al_clear_to_color(BLANC);
    al_flip_display();

    bool fini = false;
    ALLEGRO_EVENT event;
    al_start_timer(game_timer);
    while (!fini){
        al_wait_for_event(fifo, &event);

        switch (event.type) {
            case ALLEGRO_EVENT_TIMER:
                al_clear_to_color(al_map_rgb(rand()%256, rand()%256, rand()%256));
                al_flip_display();
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fini=true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_T:
                        al_draw_filled_triangle(1,1, 100, 120, 200, 300, BLANC);
                        break;
                    case ALLEGRO_KEY_C:
                        al_draw_filled_circle(rand()%500; 300, BLANC);
                        break;
                }
                break;
        }

    }



    // Liberation memoire
    al_destroy_display(game_display);
    al_destroy_timer(game_timer);
    al_destroy_event_queue(fifo);
    return 0;
}
