void putInMemory(int segment, int address, char character);
void printLine(int line, char * txt, color, int asteriks);
int calculateMidlePosition(char * string);
int getStringSize(char * string);

int main()
{
    char *  text[25];
    int i = 0;
    int colorCount = 0;
    text[0] =  "                            Sistemas Operativos I";
    text[1] =  "               Universidad Tecnologica Centroamericana (UNITEC)";
    text[2] =  "                            21241123 - Gabriel Paz";
    text[3] =  "                          Mi Primer Sistema Operativo";
    text[4] =  "-------------------------------------------------------------------------------";
    text[5] =  "******************************** Hola Mundo! **********************************";
    text[6] =  "******************************** Hello World! *********************************";
    text[7] =  "******************************** Hallo Welt! **********************************";
    text[8] =  "****************************** Bonjour le Monde! ******************************";
    text[9] =  "******************************** Ola Mundo! ***********************************";
    text[10] = "******************************* Cia Mondo! ************************************";
    text[11] = "******************************* Hej varlden! **********************************";
    text[12] = "****************************** Hallo Wereld! **********************************";
    text[13] = "****************************** Gruezi Waelt! **********************************";
    text[14] = "******************************* Salve Mundi! **********************************";
    text[15] = "******************************* Hello Vilag! **********************************";
    text[16] = "******************************* Hello Dunia! **********************************";
    text[17] = "******************************** Moien Welt! **********************************";
    text[18] = "******************************** Salut Lume! **********************************";
    text[19] = "****************************** Witaj Swiecie! *********************************";
    text[20] = "******************************* Hei Maailma! **********************************";
    text[21] = "******************************* Privet Mir! ***********************************";
    text[22] = "******************************* Ahoj Svete! ***********************************";
    text[23] = "******************************** Hola mon! ************************************";
    text[24] = "****************************** Geia sou Kosme! ********************************";
    
    
    for(i = 0; i < 25; i++)
    {
            printLine(i,text[i], 0x0 + colorCount + 1); 
            colorCount++;
            if(colorCount == 14){
                colorCount = 0;
            } 
    }
}

void printLine(int line, char * txt, int color)
{
    int i = 0;
    int offset = 0;
    while(txt[i] != '\0'){
        int address = 0x8000 + 160 * (line);
        putInMemory(0xB000, address + (i * 2) , txt[i]);
        if(txt[i] != '*')
            putInMemory(0xB000, address + (i * 2) + 1, color);
        else
            putInMemory(0xB000, address + (i * 2) + 1, 7);
        i++;
    }
}
