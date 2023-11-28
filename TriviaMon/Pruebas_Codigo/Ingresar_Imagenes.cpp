#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

int main()
{
    // Initialize Allegro
    if (!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    // Initialize the image addon
    if (!al_init_image_addon())
    {
        fprintf(stderr, "failed to initialize image addon!\n");
        return -1;
    }

    // Create a display
    ALLEGRO_DISPLAY *display = al_create_display(640, 480);
    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    // Load a font (you need to load a font before using it)
    ALLEGRO_FONT *font = al_create_builtin_font();
    if (!font)
    {
        fprintf(stderr, "failed to create font!\n");
        al_destroy_display(display);
        return -1;
    }

    // Load the bitmap
    ALLEGRO_BITMAP *mysha = al_load_bitmap("mysha.png");
    if (!mysha)
    {
        fprintf(stderr, "failed to load mysha.png!\n");
        al_destroy_display(display);
        al_destroy_font(font);
        return -1;
    }

    // Clear the display to black
    al_clear_to_color(al_map_rgb(0, 0, 0));

    // Draw text on the display
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");

    // Draw the bitmap on the display
    al_draw_bitmap(mysha, 100, 100, 0);

    // Flip the display
    al_flip_display();

    // Pause for a while (you may want to use a timer or event handling for better control)
    al_rest(5.0);

    // Destroy resources
    al_destroy_bitmap(mysha);
    al_destroy_font(font);
    al_destroy_display(display);

    return 0;
}
