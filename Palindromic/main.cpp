#include <QCoreApplication>
#include <QDebug>

int isPali(char *s, char *e)
{
    char *is, *ie;
    int pali_len = 0;

    is = s;
    ie = e;

    while (is < ie) {
        if (*is != *ie) {
            break;
        }

        is++;
        ie--;
    }

    if (is >= ie) {
        pali_len = e - s + 1;
    }

    return pali_len;
}

char* longestPalindrome(char* s) {
    char *head, *ch, *p;
    int pali_len = 0;
    int check_len = 0;
    char *ret = NULL;

    if (!s) {
        return ret;
    }

    if (strlen(s) == 1) {
        return s;
    }

    ch = head = s;
    p = ch;
    while (*(ch + 1) != '\0') {
        while (*p != '\0') {
            if (*ch == *p) {
                check_len = p - ch + 1;
                if (pali_len < check_len) {
                    check_len = isPali(ch, p);
                    if (check_len) {
                        head = ch;
                        pali_len = check_len;
                    }
                }
            }

            p++;
        }

        ch++;
        p = ch;
    }

    if (pali_len > 0) {
        ret = (char *)calloc(1, pali_len + 1);
        memcpy(ret, head, pali_len);
    }

    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char str[] = "ccccc";

    char *pali = longestPalindrome(str);
    printf("pali str:%s\n", pali);

    return a.exec();
}

