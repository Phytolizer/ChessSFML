#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>

int main(void)
{
    sfRenderWindow* window = sfRenderWindow_create(
        (sfVideoMode){
            .bitsPerPixel = 32,
            .width = 800,
            .height = 600,
        },
        "Chess", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            switch (event.type)
            {
            case sfEvtClosed:
                sfRenderWindow_close(window);
                break;
            case sfEvtResized:
                sfRenderWindow_setSize(window, (sfVector2u){.x = event.size.width, .y = event.size.height});
                break;
            default:
                break;
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}