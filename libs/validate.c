#include <ctype.h>
#include <string.h>


int validTelephone(char *telephone) {
    if (strlen(telephone) != 13) {
        return 0;
    }

    // Verifica cada caractere com base no padrão XX X XXXXXXXX
    return isdigit(telephone[0]) && isdigit(telephone[1]) &&
        telephone[2] == ' ' &&
        isdigit(telephone[3]) && telephone[4] == ' ' &&
        isdigit(telephone[5]) && isdigit(telephone[6]) &&
        isdigit(telephone[7]) && isdigit(telephone[8]) &&
        isdigit(telephone[9]) && isdigit(telephone[10]) &&
        isdigit(telephone[11]);
}