
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    //char filename[] = "org.gnome.Vino.gschema.xml";
    char filename[] = "org.gnome.Vino.gschema.xml";
    char string_to_input[] = "<key name='enabled' type='b'>\
<summary> Enable remote access to the desktop</summary>\
<description>\
If true, allows remote access to the desktop via the RFB\
protocol.Users on remote machines may then connect to the\
desktop using a VNC viewer.\
</description>\
<default>true</default>\
</key>";

    FILE* fr = fopen(filename, "a+");

    if (fr == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }

    int count = 0;
    while ((ch = fgetc(fr)) != EOF)
    {
        fputc(ch, stdout);
        count++;
    }

    printf("count : %d\n", count);

    /* SEEK_END */
    fseek(fr, -27L, SEEK_END);
    ch = fgetc(fr);
    printf("%d %c\n", ch, ch);
    fprintf(fr, "%s", string_to_input);

    return 0;
}
