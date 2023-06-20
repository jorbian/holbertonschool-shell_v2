#include "shellv2.h"

void free_shell()
{
    if (symbol_table != NULL)
        delete_hash_table(symbol_table);

    if (builtins != NULL)
        delete_hash_table(builtins);
}
