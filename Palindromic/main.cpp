#include <QCoreApplication>
#include <QDebug>

int isPali(char *s, char *e)
{
    int pali_len = 0;

    return pali_len;
}

char* longestPalindrome(char* s) {
    char *head, *tail, *ch, *ct, *p;
    int pali_len = 0;
    int check_len = 0;
    char *ret = NULL;

    ch = head;
    p = ch + 1;
    while (*(ch + 1) != '\0') {
        while (*p != '\0' &&
               *ch != *p) {
            p++;
        }

        if (*p == '\0') {
            return ret;
        }

        check_len = isPali(ch, p);
        if (pali_len < check_len) {
            head = ch;
            pali_len = check_len;
        }

        ch++;
        p = ch + 1;
    }

    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char str[] = "aba";

    char *pali = longestPalindrome(str);
    qDebug() << pali;

    return a.exec();
}

