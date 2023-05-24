#include "../interpreter/htmltags.h"
#include "../networking/processer.h"
#include "../utils/utils.h"

typedef struct {
    char* title;
    char* css;
    char* js;
} webctx;

typedef struct {
    char* element_name;
    char* element_id;
    char* element_arguments;
} elementctx;

typedef struct {

} contentctx;


/**
 * @brief gets head from raw html, and writes it to head
 * @param html pointer pointing at the raw html
 * @param head pointer to write head to
 * @return has head or not
**/
bool gethead(char *html, char *head);