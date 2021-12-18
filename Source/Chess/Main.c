#include <Chess/ChessGrid.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Window.h>
#include <stdio.h>

int main(void)
{
    sfContextSettings contextSettings = {
        .antialiasingLevel = 8,
        .attributeFlags = sfContextDefault,
        .depthBits = 24,
        .majorVersion = 3,
        .minorVersion = 3,
        .sRgbCapable = sfFalse,
    };
    sfRenderWindow* window = sfRenderWindow_create(
        (sfVideoMode){
            .bitsPerPixel = 32,
            .width = 800,
            .height = 800,
        },
        "Chess", sfResize | sfClose, &contextSettings);
    sfView* view = sfView_createFromRect((sfFloatRect){
        .left = 0,
        .top = 0,
        .width = 800,
        .height = 800,
    });
    sfRenderWindow_setView(window, view);
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
                sfView_reset(view, (sfFloatRect){
                                       .left = 0,
                                       .top = 0,
                                       .width = event.size.width,
                                       .height = event.size.height,
                                   });
                sfRenderWindow_setView(window, view);
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
    sfView_destroy(view);
    sfRenderWindow_destroy(window);
    return 0;
}