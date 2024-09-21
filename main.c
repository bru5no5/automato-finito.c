// Membros do grupo:
// Bruno Rocha - 10400926
// Lucas Braga - 10403286
// Roberto Silveira - 10403243
// Xuan Zhu - 10401714

#include <stdio.h>

#define _INTEIRO_ 1
#define _INTEIRO_NEGATIVO_ 2
#define _P_FLUTUANTE_ 3
#define _P_FLUTUANTE_NEGATIVO_ 4
#define _ERRO_ 0

// Função para ler uma string
int scanner(const char *palavra) {
  const char *p = palavra;
  char c;
  goto inicial;

// Estado inicial
inicial:
  c = *p++;
  if (c == '-') goto sinal_neg;
  else if (c >= '0' && c <= '9') goto final_int;
  else goto erro;

// Estado extra que permite classificar como número negativo
sinal_neg:
  c = *p++;
  if (c >= '0' && c <= '9') goto final_int_neg;
  else goto erro;

// Estado final de classificação como número inteiro positivo
final_int:
  c = *p++;
  if (c == '\0') return _INTEIRO_;
  else if (c >= '0' && c <= '9') goto final_int;
  else if (c == '.') goto pfloat;
  else goto erro;

// Estado final de classificação como número inteiro negativo
final_int_neg: 
  c = *p++;
  if (c == '\0') return _INTEIRO_NEGATIVO_;
  else if (c >= '0' && c <= '9') goto final_int_neg;
  else if (c == '.') goto pfloat_neg;
  else goto erro;

// Estado que classifica como número float positivo
pfloat:
  c = *p++;
  if (c >= '0' && c <= '9') goto final_pfloat;
  else goto erro;

// Estado que classifica como número float negativo
pfloat_neg:
  c = *p++;
  if (c >= '0' && c <= '9') goto final_pfloat_neg;
  else goto erro;

// Estado final de classificação como número float positivo 
final_pfloat:
  c = *p++;
  if (c == '\0') return _P_FLUTUANTE_;
  else if (c >= '0' && c <= '9') goto final_pfloat;
  else goto erro;

// Estado final de classificação como número float negativo
final_pfloat_neg:
  c = *p++;
  if (c == '\0') return _P_FLUTUANTE_NEGATIVO_;
  else if (c >= '0' && c <= '9') goto final_pfloat_neg;
  else goto erro;

// Estado de erro
erro:
  return _ERRO_;
}

// Recebe as palavras como strings
int main() {
  const char *test_cases[] = {
    "21", "-21", "021", "2,1", "2.1", "+0.34", "05,567", "05.567", "-2.1"
  };
  int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

  // Testa cada palavra e imprime o tipo correspondente
  for (int i = 0; i < num_cases; ++i) {
    int result = scanner(test_cases[i]);
    printf("\"%s\" é ", test_cases[i]);
    switch (result) {
      case _INTEIRO_:
        printf("<INTEIRO>\n");
        break;
      case _INTEIRO_NEGATIVO_:
        printf("<INTEIRO NEGATIVO>\n");
        break;
      case _P_FLUTUANTE_:
        printf("<P.FLUTUANTE>\n");
        break;
      case _P_FLUTUANTE_NEGATIVO_:
        printf("<P.FLUTUANTE NEGATIVO>\n");
        break;
      case _ERRO_:
        printf("<ERRO>\n");
        break;
      default:
        printf("<IN &#8203;``【oaicite:0】``&#8203;)>\n");
    }
  } 
  return 0;
}
