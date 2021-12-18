#include <Chess/ChessGrid.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <stdio.h>

int main(void)
{
    sfRenderWindow* window = sfRenderWindow_create(
        (sfVideoMode){
            .bitsPerPixel = 32,
            .width = 600,
            .height = 600,
        },
        "Chess", sfResize | sfClose, NULL);
    ChessGrid grid;
    ChessGrid_init(&grid, window);
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
                ChessGrid_scaleToFit(&grid, (sfVector2f){.x = event.size.width, .y = event.size.height});
                break;
            case sfEvtMouseMoved:
                printf("Mouse moved: %d, %d\n", event.mouseMove.x, event.mouseMove.y);
                break;
            default:
                break;
            }
        }
        sfRenderWindow_clear(window, (sfColor){.r = 0x28, .g = 0x27, .b = 0x29, .a = 0xFF});
        ChessGrid_render(&grid, window);
        sfRenderWindow_display(window);
    }
    ChessGrid_deinit(&grid);
    sfRenderWindow_destroy(window);
    return 0;
}