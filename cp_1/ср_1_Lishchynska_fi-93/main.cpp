#include <iostream>
#include <fstream>
#include "cmath"
#include <locale.h>
#include "string.h"
#include <cstring>
using namespace std;

float freq_letters_without_space[33] = {};
float freq_letters_with_space[34] = {};

float number_of_letters[33] = {};

float** num_of_crossed_biagrams = new float *[33];
float** num_of_n_crossed_biagrams = new float *[33];

float** num_of_crossed_biagrams_space = new float *[34];
float ** num_of_n_crossed_biagrams_space = new float *[34];



void text_without_space(char *output_text_without_space);
void text_with_space(char *output_text_with_space);
void entropia ();

void text_without_space(char *output_text_without_space){
    int k,l;
    int size = 1341322;

    //рахунок символів
    for(int num_letter=-64,k=0; num_letter<=-33; num_letter++,k++)
    {
        for(int count=0;  output_text_without_space[count]!=NULL;count++)
        {
            if((int)output_text_without_space[count]==num_letter+32){
                freq_letters_without_space[k]++;
            }
            if(( int)output_text_without_space[count]==-72){
                freq_letters_without_space[32]++;
            }
        }
    }

    for (int i=0; i<33; i++){
        number_of_letters[i] = freq_letters_without_space[i];
    }

    int how_many_letters_without_space=0;

    for (int i=0; i<size; i++){
        if (output_text_without_space[i]!=NULL){
            how_many_letters_without_space++;
        }
    }

    for(int i=0; i<33; i++){
        freq_letters_without_space[i] = freq_letters_without_space[i]/how_many_letters_without_space;
    }

    //-------------------------------------------------------------------------
    //підрахунок біаграм

    for(int i=0; i<33; i++) {
        num_of_crossed_biagrams[i] = new float [33];
    }

    for(int i=0; i<33; i++)
    {
        for(int j=0; j<33; j++)
        {
            num_of_crossed_biagrams[i][j]=0;
        }
    }
    for(int i=0;  output_text_without_space[i]!=NULL&&i<1341322;i++)
    {
        if((int)output_text_without_space[i]==-72)
        {
            l=((int)output_text_without_space[i+1]+(char)32);
            num_of_crossed_biagrams[32][l]++;
        }
        else{
            if(( int)output_text_without_space[i+1]==-72)
            {
                k=((int)output_text_without_space[i]+(char)32);
                num_of_crossed_biagrams[k][32]++;
            }
            else{
                k=((int)output_text_without_space[i]+(char)32);
                l=((int)output_text_without_space[i+1]+(char)32);
                num_of_crossed_biagrams[k][l]++;
            }
        }
    }

    for(int i=0; i<33; i++){
        for(int j=0; j<33; j++){
            num_of_crossed_biagrams[i][j]=num_of_crossed_biagrams[i][j]/(how_many_letters_without_space-1);
        }

    }

    //нот крос біграми

    for(int i=0; i<33; i++) {
        num_of_n_crossed_biagrams[i] = new float [33];
    }

    for(int i=0;  output_text_without_space[i]!=NULL&&i<1341322;i+=2)
    {
        if(( int)output_text_without_space[i]==-72)
        {
            l=((int)output_text_without_space[i]+(char)32);
            num_of_n_crossed_biagrams[32][l]++;
        }
        else{
            if((int)output_text_without_space[i+1]==-72)
            {
                k=((int)output_text_without_space[i]+(char)32);
                num_of_n_crossed_biagrams[k][32]++;
            }
            else{
                k=((int)output_text_without_space[i]+(char)32);
                l=((int)output_text_without_space[i+1]+(char)32);
                num_of_n_crossed_biagrams[k][l]++;
            }
        }
    }

    for(int i=0; i<33; i++){
        for(int j=0; j<33; j++){
            num_of_n_crossed_biagrams[i][j]=num_of_n_crossed_biagrams[i][j]/(how_many_letters_without_space/2);
        }
    }
}



void text_with_space(char *output_text_with_space){
    int k,l;
    int size = 1341322;
    char test_letter;
    int space = 0;

    int how_many_letters=0;
    for (int i=0; i<size; i++){
        if (output_text_with_space[i]!= NULL){
            how_many_letters++;
        }
    }


    for (int i=0; i<33; i++){
        freq_letters_with_space[i] = number_of_letters[i];
    }

    for (int i=0; i<size; i++){
        if (output_text_with_space[i] == ' ') space++;
    }

    freq_letters_with_space[33]=space;

    for (int i=0; i<34; i++){
        freq_letters_with_space[i] = freq_letters_with_space[i]/how_many_letters;
    }

    //-------------------------------------------------------------------------
    //підрахунок біграм з пробілом

    for(int i=0; i<34; i++) {
        num_of_crossed_biagrams_space[i] = new float [34];
    }

    for(int i=0; i<34; i++)
    {
        for(int j=0; j<34; j++)
        {
            num_of_crossed_biagrams_space[i][j]=NULL;
        }
    }
    for(int i=0;  output_text_with_space[i]!=NULL&&i<1341322;i++)
    {
        test_letter=output_text_with_space[i];
        if((int)output_text_with_space[i]==-72)
        {
            l=((int)output_text_with_space[i+1]+(char)32);
            num_of_crossed_biagrams_space[32][l]++;
        }
        else{
            if(( int)output_text_with_space[i+1]==-72){
                k=((int)output_text_with_space[i]+(char)32);
                num_of_crossed_biagrams_space[k][32]++;

            }
            else{
                if(( int)output_text_with_space[i]==32){
                    l=((int)output_text_with_space[i+1]+(char)32);
                    num_of_crossed_biagrams_space[33][l]++;
                }
                else{
                    if(( int)output_text_with_space[i+1]==32)
                    {
                        l=((int)output_text_with_space[i]+(char)32);
                        num_of_crossed_biagrams_space[l][33]++;
                    }
                    else
                    {
                        k=((int)output_text_with_space[i]+(char)32);
                        l=((int)output_text_with_space[i+1]+(char)32);
                        num_of_crossed_biagrams_space[k][l]++;
                    }
                }
            }
        }
    }

    for(int i=0; i<34; i++){
        for(int j=0; j<34; j++){
            num_of_crossed_biagrams_space[i][j]=num_of_crossed_biagrams_space[i][j]/(how_many_letters-1);
        }
    }

    //-------------------------------------------------------------------------
    //біграми без перехрещування

    for(int i=0; i<34; i++) {
        num_of_n_crossed_biagrams_space[i] = new float [34];
    }

    for(int i=0; i<34; i++)
    {
        for(int j=0; j<34; j++)
        {
            num_of_n_crossed_biagrams_space[i][j]=NULL;
        }
    }
    for(int i=0;  output_text_with_space[i]!=NULL&&i<1341322;i+=2)
    {
        test_letter=output_text_with_space[i];
        if((int)output_text_with_space[i]==-72)
        {
            l=((int)output_text_with_space[i+1]+(char)32);
            num_of_n_crossed_biagrams_space[32][l]++;
        }
        else{
            if(( int)output_text_with_space[i+1]==-72){
                k=((int)output_text_with_space[i]+(char)32);
                num_of_n_crossed_biagrams_space[k][32]++;

            }
            else{
                if(( int)output_text_with_space[i]==32){
                    l=((int)output_text_with_space[i+1]+(char)32);
                    num_of_n_crossed_biagrams_space[33][l]++;
                }
                else{
                    if(( int)output_text_with_space[i+1]==32)
                    {
                        l=((int)output_text_with_space[i]+(char)32);
                        num_of_n_crossed_biagrams_space[l][33]++;
                    }
                    else
                    {
                        k=((int)output_text_with_space[i]+(char)32);
                        l=((int)output_text_with_space[i+1]+(char)32);
                        num_of_n_crossed_biagrams_space[k][l]++;
                    }
                }
            }
        }
    }

    for(int i=0; i<34; i++){
        for(int j=0; j<34; j++){
            num_of_n_crossed_biagrams_space[i][j]=num_of_n_crossed_biagrams_space[i][j]/(how_many_letters/2);
        }
    }
}

void entropia (){
    double entr_letters_without_space=0;
    double entr_crossed_bigrams_without_space=0;
    double entr_n_crossed_bigrams_without_space=0;
    double entr_letters_with_space=0;
    double entr_crossed_bigrams_with_space=0;
    double entr_n_crossed_bigrams_with_space=0;

    //-----------------ентропія (літери без пробілу)
    for (int i=0; i<33; i++){
        entr_letters_without_space = entr_letters_without_space + (freq_letters_without_space[i]*log2(freq_letters_without_space[i]));
    }

    entr_letters_without_space = entr_letters_without_space*(-1);

    cout<<"entr_letters_without_space: "<<entr_letters_without_space<<"\n";

    //-----------------ентропія (біграми з перетином без пробілу)
    for (int i=0; i<33; i++){
        for (int j=0; j<33; j++){
            if (num_of_crossed_biagrams[i][j] != 0)
                entr_crossed_bigrams_without_space = entr_crossed_bigrams_without_space + (num_of_crossed_biagrams[i][j]*log2(num_of_crossed_biagrams[i][j]));
        }
    }

    entr_crossed_bigrams_without_space = entr_crossed_bigrams_without_space/(-2);

    cout<<"entr_crossed_bigrams_without_space: "<<entr_crossed_bigrams_without_space<<"\n";

    //-----------------ентропія (біграми без перетину без пробілу)
    for (int i=0; i<33; i++){
        for (int j=0; j<33; j++){
            if (num_of_n_crossed_biagrams[i][j] != 0)
                entr_n_crossed_bigrams_without_space = entr_n_crossed_bigrams_without_space + (num_of_n_crossed_biagrams[i][j]*log2(num_of_n_crossed_biagrams[i][j]));
        }
    }

    entr_n_crossed_bigrams_without_space = entr_n_crossed_bigrams_without_space/(-2);

    cout<<"entr_n_crossed_bigrams_without_space: "<<entr_n_crossed_bigrams_without_space<<"\n";

    //-----------------ентропія (літери з пробілом)
    for (int i=0; i<34; i++){
        entr_letters_with_space = entr_letters_with_space + (freq_letters_with_space[i]*log2(freq_letters_with_space[i]));
    }

    entr_letters_with_space = entr_letters_with_space*(-1);

    cout<<"entr_letters_with_space: "<<entr_letters_with_space<<"\n";

    //-----------------ентропія (біграми з перетином з пробілом)
    for (int i=0; i<34; i++){
        for (int j=0; j<34; j++){
            if (num_of_crossed_biagrams_space[i][j]!=0)
                entr_crossed_bigrams_with_space = entr_crossed_bigrams_with_space + (num_of_crossed_biagrams_space[i][j]*log2(num_of_crossed_biagrams_space[i][j]));
        }
    }

    entr_crossed_bigrams_with_space = entr_crossed_bigrams_with_space/(-2);

    cout<<"entr_crossed_bigrams_with_space: "<<entr_crossed_bigrams_with_space<<"\n";

    //-----------------ентропія (біграми без перетину з пробілом)
    for (int i=0; i<34; i++){
        for (int j=0; j<34; j++){
            if (num_of_n_crossed_biagrams_space[i][j]!=0)
                entr_n_crossed_bigrams_with_space = entr_n_crossed_bigrams_with_space + (num_of_n_crossed_biagrams_space[i][j]*log2(num_of_n_crossed_biagrams_space[i][j]));
        }
    }

    entr_n_crossed_bigrams_with_space = entr_n_crossed_bigrams_with_space/(-2);

    cout<<"entr_n_crossed_bigrams_with_space: "<<entr_n_crossed_bigrams_with_space<<"\n";
}


int main()
{


    setlocale (LC_ALL,"rus");
    int size = 1341322;
    string text1;
    char input_text[size];
    char *output_text_with_space= new char[size];
    char *output_text_without_space= new char[size];

    int k,l;
    for (int i=0; i<size; i++)
    {
        input_text[i]=0;
        output_text_with_space[i]=NULL;
        output_text_without_space[i]=NULL;
        if(i<33) freq_letters_without_space[i]=NULL;
    }


    ifstream in ("C:\\Users\\user\\Desktop\\input_text.txt");
    if (in.is_open()){
        string temp;
        while (getline(in, temp))
        {
            text1 += temp;
            if (!in.eof())
                text1 += '\n';
        }

    }
    in.close();

    for (int i=0; i<text1.length(); i++){

        if(text1[i]>=(char)192&&text1[i]<=(char)223)
        {

            input_text[i] = text1[i]+(char)32;
        }
        else
            input_text[i] = text1[i];
    }




    //-------------------------------------------------------------------------
    //текст без пробілів
    for (int i=0,k=0; i<size; i++){
        if((input_text[i]>=(char)192&&input_text[i]<=(char)255)/*||input_text[i]==(char)168*/||input_text[i]==(char)184)
        {
            output_text_without_space[k]=input_text[i];
            k++;
        }
    }

    text_without_space(output_text_without_space);

    //-------------------------------------------------------------------------
    //текст з пробілами
    for (int i=0,k=0; i<size; i++){
        if((input_text[i]>=(char)192&&input_text[i]<=(char)255)||input_text[i]==(char)168||input_text[i]==(char)184)
        {
            output_text_with_space[k]=input_text[i];
            k++;
        }
        else
            if((input_text[i-1]>=(char)192&&input_text[i-1]<=(char)255)||input_text[i-1]==(char)168||input_text[i-1]==(char)184)
            {
                output_text_with_space[k]=' ';
                k++;
            }

    }

    text_with_space(output_text_with_space);

    //-------------------------------------------
    //ентропія

    entropia();

    return 0;

}



