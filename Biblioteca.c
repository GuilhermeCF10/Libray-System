#include <stdio.h>


//              Declarando Variáveis

// Data que a pessoa pegou o livro
int dia_inicial, mes_inicial, ano_inicial;

// Data que a pessoa devolveu o livro
int dia_final, mes_final, ano_final;

// Relacionadas ao Atraso
int dias_utilizados = 0, termina_mes, dias_totais_ano = 0, dias_do_mes = 0, _ano_inicial = 0, _mes_inicial = 0;

// Mostra a Situação de Atrasado
int situacao_atrasada = 0;

// Penalização
int penalizacao = 0;

// Retirada Permitida
int dia_permitido, mes_permitido, ano_permitido, _penalizacao;




// Função para Validação das Datas, tanto de retirada, quanto da devolução do livro
int EnviarLivro()
{
    printf("\tData de retirada: ");
    scanf("%i/%i/%i", &dia_inicial, &mes_inicial, &ano_inicial);

    // Primeira restrição   (   O dia não pode superar 31   )
    while ( (dia_inicial > 31) || (dia_inicial < 0) )
    {
        printf("\tVocê inseriu uma data inválida.");
        printf("\tData de retirada: ");
        scanf("%i/%i/%i", &dia_inicial, &mes_inicial, &ano_inicial);
    }

    // Segunda restrição    (   O Mês tem que estar entre 1 e 12  )      
    while ( (mes_inicial > 12) || (mes_inicial < 0) )
    {
        printf("\tVocê inseriu uma data inválida.");
        printf("\tData de retirada: ");
        scanf("%i/%i/%i", &dia_inicial, &mes_inicial, &ano_inicial);
    }
    
    // Terceira restrição   (   Mês 30 não possui dia 31    )  
    while ( (dia_inicial == 31) && ((mes_inicial == 4) || (mes_inicial==6) || (mes_inicial==9) || (mes_inicial==11)) )
    {
        printf("\tVocê inseriu uma data inválida.");
        printf("\tData de retirada: ");
        scanf("%i/%i/%i", &dia_inicial, &mes_inicial, &ano_inicial);       
    }
    
    return 0;
}

int ReceberLivro()
{
    printf("\tData de entrega: ");
    scanf("%i/%i/%i", &dia_final, &mes_final, &ano_final);

    // Primeira restrição   (   O dia não pode superar 31   )
    while ( (dia_final > 31) || (dia_final < 0))
    {
        printf("Você inseriu uma data inválida!\n");
        printf("\tData de entrega: ");
        scanf("%i/%i/%i", &dia_final, &mes_final, &ano_final);
    }

    // Segunda restrição    (   O Mês tem que estar entre 1 e 12  ) 
    while ( (mes_final > 12) || (mes_final < 0))
    {
        printf("Você inseriu uma data inválida!\n");
        printf("\tData de entrega: ");
        scanf("%i/%i/%i", &dia_final, &mes_final, &ano_final);
    }
    
    // Terceira restrição   (   Mês 30 não possui dia 31    )
    while ( (dia_final== 31) && ((mes_final == 4) || (mes_final==6) || (mes_final==9) || (mes_final==11)) )
    {
        printf("\tVocê inseriu uma data inválida.");
        printf("\tData de retirada: ");
        scanf("%i/%i/%i", &dia_final, &mes_final, &ano_final);       
    }
    
    // Quarta restrição    (    Para entregar: Não pode digitar qualquer data anterior a data de retirada  )
    while (ano_final < ano_inicial)
    {
        printf("\nVocê não é um viajante do tempo, digite uma data válida!\n");
        printf("\tData de entrega: ");
        scanf("%i/%i/%i", &dia_final, &mes_final, &ano_final);
    }

    // Quinta restrição    (    Para entregar: Não pode digitar qualquer data anterior a data de retirada  )
    while ((ano_final == ano_inicial) && (mes_final < mes_inicial) )
    {
        printf("\nVocê não é um viajante do tempo, digite uma data válida!\n");
        printf("\tData de entrega: ");
        scanf("%i/%i/%i", &dia_final, &mes_final, &ano_final);
    }

    // Sexta restrição     (    Para entregar: Não pode digitar qualquer data anterior a data de retirada  )
    while ((ano_final == ano_inicial) && (mes_final == mes_inicial) && (dia_final < dia_inicial))
    {
        printf("\nVocê não é um viajante do tempo, digite uma data válida!\n");
        printf("\tData de entrega: ");
        scanf("%i/%i/%i", &dia_final, &mes_final, &ano_final);
    }
    
    return 0;
}


// Verifica caso ocorra alguma atraso
int VerificaAtraso()
{
    // Analisa mesmo mês e mesmo Ano 
    if ( (mes_final == mes_inicial) && (ano_inicial == ano_final) )
    {
        dias_utilizados = dia_final - dia_inicial;
    } 

    // Analisa mês diferentes e mesmo Ano
    else if ( (mes_inicial < mes_final) && (ano_inicial == ano_final) )
    {
        // Analisa se o dia termina em 31, 30, 29 ou 28

         // Caso for um mês que termina em 31
        if ( (mes_inicial == 1) || (mes_inicial == 3) || (mes_inicial == 5) || (mes_inicial == 7) || (mes_inicial == 8) || (mes_inicial == 10) || (mes_inicial == 12) )
        {
            dias_utilizados = dia_final + dia_inicial - 31;
        }

        // Caso for um mês que termina em 30
        if ( (mes_inicial == 4) || (mes_inicial == 6) || (mes_inicial == 9) || (mes_inicial == 11) )
        {
            dias_utilizados = dia_inicial + dia_final - 30;
        }  

        /*  Caso for fevereiro em ano bissexto 
            Caso for fevereiro em ano não bissexto   */
        if (mes_inicial == 2)
        {
            if ( ( ( ano_inicial % 4 == 0) &&  (ano_inicial % 100) != 0)  ||  (ano_inicial % 400) == 0 )
            {
                if (dia_inicial >= 29)
                {
                    dias_utilizados = dia_inicial + dia_final - 29;
                }
            }
            else
            {
                if (dia_inicial >= 28)
                {
                    dias_utilizados = dia_inicial + dia_final - 28;
                }
            }
        } 
           
    }

    // Analisa caso o ano de devolução for maior e o mês de devolução for maior ou igual ao mês de retirada
     _ano_inicial = ano_inicial;
    while  (_ano_inicial < ano_final)
    {
        if (((_ano_inicial % 4) == 0) && ((_ano_inicial % 100) != 0 || ((_ano_inicial % 400) == 0)))
        {
            dias_totais_ano = dias_totais_ano + 366;
            _ano_inicial++;
        }
        else
        {
            _ano_inicial++;
            dias_totais_ano = dias_totais_ano + 365;
        }
    }

    // Analisa e converte meses em dias se o mes de devolução for maior que o mes de retirada
    _mes_inicial = mes_inicial;
    while(_mes_inicial > mes_final)
    {
        if(_mes_inicial==1||_mes_inicial==3||_mes_inicial==5||_mes_inicial==7||_mes_inicial==8||_mes_inicial==10||_mes_inicial==12)
        {
            dias_do_mes = dias_do_mes - 31;   
            _mes_inicial--;
        }
     else if(_mes_inicial==4||_mes_inicial==6||_mes_inicial==9||_mes_inicial==11)
        {
             dias_do_mes = dias_do_mes - 30;
             _mes_inicial--;
        }
     else if(_mes_inicial == 2)
        {
         if(ano_inicial % 4 == 0 && (ano_inicial % 100 != 0 || ano_inicial % 400 == 0))
            {
             dias_do_mes = dias_do_mes - 29;
             _mes_inicial--;
            }
         else
            {
             dias_do_mes = dias_do_mes - 28;
             _mes_inicial--;
            }
        }
    }

    // Analisa e converte meses em dias se o mes de devolução for menor que o mes de retirada
    _mes_inicial = mes_inicial;
    while (_mes_inicial < mes_final)
    {
        if(_mes_inicial==1||_mes_inicial==3||_mes_inicial==5||_mes_inicial==7||_mes_inicial==8||_mes_inicial==10||_mes_inicial==12)
        {
            dias_do_mes = dias_do_mes + 31;   
            _mes_inicial++;
        }
     else if(_mes_inicial==4||_mes_inicial==6||_mes_inicial==9||_mes_inicial==11)
        {
             dias_do_mes = dias_do_mes + 30;
             _mes_inicial++;
        }
     else if(_mes_inicial == 2)
        {
         if(ano_inicial % 4 == 0 && (ano_inicial % 100 != 0 || ano_inicial % 400 == 0))
            {
             dias_do_mes = dias_do_mes + 29;
             _mes_inicial++;
            }
         else
            {
             dias_do_mes = dias_do_mes + 28;
             _mes_inicial++;
            }
        }
    }
    
    
    // Faz a união dos dias, convertidas de meses e anos

    // Caso se os anos iniciais e finais forem diferentes
    if (dias_utilizados == 0)
    {
        dias_utilizados = dia_final - dia_inicial + dias_totais_ano + dias_do_mes;
    }
    // Caso se os anos iniciais e finais forem iguais
    else
    {
        dias_utilizados = dias_utilizados + dias_totais_ano + dias_do_mes;
    }

    return 0;
}


// Analisa a situação de atrasado
int Situacao()
{
    if (dias_utilizados > 10)
    {
        situacao_atrasada = dias_utilizados - 10;
    }
    
    return 0;
}


// Analisa a penalização de 3 dias uteis por cada dia de atraso
int Penalizacao()
{
    if (situacao_atrasada > 0)
    {
        penalizacao = (situacao_atrasada * 3);
    }
    return 0;
}


// Próxima retirada permitida
int RetiradaPermitida()
{
    /* 5 dias úteis correspondem a 7 dias corridos
        Converte dias úteis para dias corridos      */
    _penalizacao = (7 * (penalizacao / 5)) + ((penalizacao)%5);
    dia_permitido = dia_final;
    mes_permitido = mes_final;
    ano_permitido = ano_final;

    // Adiciona 1 dia ao dia para sair do castigo e decresce 1 dia da penalidade
    while(_penalizacao > 0)
    {

        // Vai adicionando dia até a penalização zerar 
        dia_permitido++;
        _penalizacao--;
        
        /* Se o mês terminar em dia 31, irá substituir o que seria o dia 32 pelo dia 1 do próximo mes,
            se for em dezembro, ele troca o ano             */
        if((mes_permitido==1||mes_permitido==3||mes_permitido==5||mes_permitido==7||mes_permitido==8||mes_permitido==10||mes_permitido==12)&&dia_permitido==32)
        {
            dia_permitido = 1;
            mes_permitido = (mes_permitido % 12) + 1;
            if(mes_permitido == 1)
            {
                ano_permitido++;
            }
        }

        // Se o mês terminar em dia 30, irá substituir o que seria o dia 31 pelo dia 1 do próximo mes,
        if((mes_permitido==4||mes_permitido==6||mes_permitido==9||mes_permitido==11)&&dia_permitido==31)
        {
            dia_permitido = 1;
            mes_permitido++;
        }

        // Se o mês for fevereiro, irá substituir o dia e passará para o proximo mês e o ano não for bissexto
        if(mes_permitido == 2 && dia_permitido == 29)
        {
            if(ano_permitido % 4 == 0 && (ano_permitido % 100 != 0 || ano_permitido % 400 == 0))
            {
                dia_permitido = 29;
            }
            else
            {
                dia_permitido = 1;
                mes_permitido = 3;
            } 
        }

        // Se o mês for fevereiro, irá substituir o dia e passará para o proximo mês e o ano for bissexto
        if(mes_permitido == 2 && dia_permitido == 30)
        {
            dia_permitido = 1;
            mes_permitido = 3;
        }
    }

    return 0;
}


// Gera a continuação do relatorio da Biblioteca.
int GeraRelatorio ()
{
    printf("\tSituação: atrasado(a) por %i dias.\n", situacao_atrasada);
    printf("\tPenalização: %i dias úteis\n", penalizacao);
    printf("\tRetirada permitida a partir de: %i/%i/%i\n\n", dia_permitido, mes_permitido, ano_permitido);
    printf("**********************************************************************");
    return 0;
}


// Main
int main ()
{
    printf("\n");
    printf("***************** Sistema de Empréstimo de Livros **********************\n\n");    

    // Função para Validação das Datas
    EnviarLivro();
    ReceberLivro();

    // Verifica Atraso
    VerificaAtraso();
    Situacao();
    Penalizacao();
    RetiradaPermitida();

    // Relatório
    GeraRelatorio();


    return 0;
}