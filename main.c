#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void TesterVerbe(char Reponse[][10], char MotAuPresent[][10], int *NombreDeVie, char suivant[][5], char entree[10], int NumeroDeCase)

{
     while(strcmp(entree, Reponse[NumeroDeCase]) != 0 && *NombreDeVie >0)
            {
                printf("\nNombre de vie : %d", *NombreDeVie);
                printf("\nQuel est le verbe au passe de %s : ", MotAuPresent[NumeroDeCase]);
                scanf(" %s", entree);

                if(strcmp(entree, Reponse[NumeroDeCase]) == 0)
                {
                    printf("\nBravo c'est juste");
                    break;
                }
                else if(strcmp(entree, Reponse[NumeroDeCase]) != 0 && *NombreDeVie >0)
                {
                    printf("\nCe n'est pas juste !");
                    (*NombreDeVie)--;
                }

                else if (*NombreDeVie == 0)
                    break;

                else if (strcasecmp(entree, suivant[0]) == 0)
                    break;
            }
            ++NumeroDeCase;
}

int main ()
{
    char Reponse [50][10] =
    {
        "been", "become", "begun", "brought", "bought",
        "chosen", "come", "done", "drunk", "driven",
        "eaten", "fallen", "felt", "found", "flown", "forgotten",
        "gotten", "given", "gone", "had", "heard", "kept", "known",
        "left", "lent", "let", "lost", "made", "met",
        "paid", "put", "read", "run", "said", "seen", "sold",
        "sent", "sung", "sat", "slept", "spoken", "stood",
        "swum", "taken", "taught", "told", "thought", "understood",
        "worn", "written"
    };
    char MotAuPresent [50][10] =
    {
        "be", "become", "begin", "bring", "buy",
        "choose", "come", "do", "drink", "drive",
        "eat", "fall", "feel", "find", "fly", "forget",
        "get", "give", "go", "have", "hear", "keep", "know",
        "leave", "lend", "let", "lose", "make", "meet",
        "pay", "put", "read", "run", "say", "see", "sell",
        "send", "sing", "sit", "sleep", "speak", "stand",
        "swim", "take", "teach", "tell", "think", "understand",
        "wear", "write"
    };


    char suivant[1][5] = {"next"};
    char entree [10];
    char choix [5];
    int NombreDeVie = 5;
    int NumeroDeCase =0;
    char Recommencer [1];

    printf("Simulateur de Verbe irregulier version Participe Passee");
    printf("\nRepondez correctement ou ecrivez le mot NEXT pour passer au suivant");

    debut:
        NombreDeVie =5;
        NumeroDeCase = 0;

    while (NumeroDeCase < 50 && NombreDeVie >0)

    {
        TesterVerbe(Reponse, MotAuPresent, &NombreDeVie, suivant, entree, NumeroDeCase);
        ++NumeroDeCase;

        if (NombreDeVie == 0)
        {
            break;
        }

    }

    printf("\nGAME OVER...");
    printf("\nVoulez vous recommencer ? (oui ou non)");
    scanf("%s", Recommencer);

    if (Recommencer[0] == 'o')
    goto debut;

    else
        printf("\nMerci et aurevoir...\n");

    return 0;
}
