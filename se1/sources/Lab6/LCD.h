#ifndef LCD_H
#define LCD_H

/* Faz a iniciação do sistema para permitir o acesso ao periférico
utilizando 2 linhas com 16 colunas e comunicação a 4 bits. */
void LCD_Init(void);

/* Escreve um carácter na posição corrente do cursor. */
void LCD_WriteChar(char ch);

/* Escreve uma string na posição corrente do cursor. */
void LCD_WriteString(char *str);

/* Posiciona o cursor na linha x e coluna y do mostrador. */
void LCD_Goto(int x, int y);

/* Limpa o visor, usando o comando disponível na API do periférico. */
void LCD_Clear(void);

#endif
