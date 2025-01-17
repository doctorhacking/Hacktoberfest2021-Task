#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void
main_menu();

void
oct_to_str();

void
str_to_oct();

int
main(void)          //Execution of every program in c language start from main() function.
{
    unsigned char choise = 0;

    main_menu();    //Calling main_menu() function.
    scanf("%d", &choise);
    switch (choise) {
        case 1:
            oct_to_str();
        case 2:
            str_to_oct();
        case 3:
            exit(0);
            
        default:
            printf("Invalid choice");
    }

    return 0;
}

void
main_menu()
{
    printf("1 - Convert octal permissions to string\n");
    printf("2 - Convert stirng permissions to octal\n");
    printf("3 - Exit\n");
}

void
oct_to_str()
{
    const char *s = "rwxrwxrwx";
    
    unsigned long long mask = 0400;
    unsigned long long user_mask = 0;
    char user_perm[3];

    printf("Enter your octal permissions: ");
    scanf("%s", user_perm);

    for (int i = 0; i < 3; i++) {
        char ch = user_perm[i] - '0';
        user_mask = (user_mask << 3) | ch;
    }

    int iter = 0;
    while (mask) {
        if (mask & user_mask) {
            printf("%c", s[iter]);
        } else {
            printf("%c", '-');
        }

        mask >>= 1;
        iter++;
    }

    printf("\n");
}

void
str_to_oct()
{
    char user_perm[9]; // declaration of char type array.
    unsigned long long user_mask = 0;
    unsigned long long mask = 400;

    printf("Enter your string permissions: ");
    scanf("%s", user_perm);

    for (int i = 0; i < 9; i += 3) {
        if (user_perm[i] != '-') {
            user_mask |= 1;
        }
        user_mask <<= 1;

        if (user_perm[i + 1] != '-') {
            user_mask |= 1;
        }
        user_mask <<= 1;

        if (user_perm[i + 2] != '-') {
            user_mask |= 1;
        }

        printf("%o", user_mask);
        user_mask = 0;
    }
    printf("\n");
}
