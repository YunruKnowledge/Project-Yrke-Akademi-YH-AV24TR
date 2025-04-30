#include <assert.h>
#include "terminal.h"

void app_main(void)
{
    assert(terminal_init());

    while (1)
    {
        assert(terminal_run());
    }
}
