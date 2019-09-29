#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLENGTH 100

const char keywords[][MAXLENGTH] = {
    "begin",
    "end",
    "if",
    "else",
    "fi",
    "then",
    "case",
    "esac",
    "do",
    "od",
    "proc",
    "int",
    "real",
    "long",
    "string",
    "char",
    "local",
    "mode",
    "op",
    "prio",
    "flex",
    "heap",
    "loc",
    "ref",
    "short",
    "bits",
    "bool",
    "bytes",
    "compl",
    "sema",
    "void",
    "channel",
    "file",
    "format",
    "struct",
    "union",
    "at",
    "either",
    "is",
    "isnt",
    "is not",
    "of",
    "true",
    "false",
    "empty",
    "nil",
    "skip",
    "co",
    "comment",
    "pr",
    "pragmat",
    "in",
    "out",
    "for",
    "from",
    "to",
    "by",
    "while",
    "elif",
    "par",
    "go to",
    "goto",
    "exit"
};

size_t keywords_count(void)
{
    return sizeof(keywords) / sizeof(keywords[0]);
}

int search_keyword(const char *str)
{
    int i;
    for (i = 0; i < keywords_count(); i++) {
        if (strcmp(keywords[i], str) == 0) return i;
    }

    return -1;
}

void replace_keyword(int index, char *token)
{
    const char *key;
    size_t len = 0;
    size_t i;

    if (index < 0) {
        printf("%s", token);
    }
    else {
        key = keywords[index];
    
        while (*key) {
            putchar(*key++ - ('a' - 'A'));
        }
    }
}

void search_replace_keyword(char *token)
{
    int kindex = search_keyword(token);
    replace_keyword(kindex, token);
}

int main()
{
    char token[MAXLENGTH];
    char *ptr = token;
    int ch;
    int kindex;

    while ((ch = getchar()) != EOF) {
        if (ptr - token >= MAXLENGTH - 1) {
            ptr = token;
            memset(token, 0, MAXLENGTH);
        } 

        if (!isalpha(ch)) {
            *ptr = 0;
            search_replace_keyword(token);    
            ptr = token;
            memset(token, 0, MAXLENGTH);
            putchar(ch);
        }
        else {
            *ptr++ = ch;
        }
    }

    return 0;
}
