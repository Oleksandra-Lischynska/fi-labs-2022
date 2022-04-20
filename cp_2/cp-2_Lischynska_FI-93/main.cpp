#define TEXT_SIZE 6385
#define A 65504
#define YA 65535
#define ATOI unsigned short int
#include <iostream>
#include <fstream>
#include "cmath"
#include <locale.h>
#include "string.h"
#include <cstring>
#include <iomanip>

using namespace std;
char* find_keyword_2variant(char* text,int key_length);
char* code_text(char *text, char key_for_text[], int size_key);
void endline();
int find_key(char* text);
char *find_keyword(char* text,int key_length);
char*find_keyletter(int iteration, char* text, int key_length, int key_letter);
void cout_arr(int arr[], int size);
void cout_arr_double(const double arr[], int size);
int find_max(int arr[], int size);
double find_max_double(double arr[], int size);
const double freq_alphabet[32]{0.07998,0.01592,0.04533,0.01687,0.02977,0.08483,0.0094 ,0.01641,0.07367,0.01208,0.03486,0.04343,0.03203,0.067  ,0.10983,0.02804,
                               0.04746,0.05473,0.06318,0.02615,0.00267,0.00966,0.00486,0.0145 ,0.00718,0.00361,0.00037,0.01898,0.01735,0.00331,0.00639,0.02001
                              };

int main()
{
    int key_length=0;
    setlocale (LC_ALL,"rus");
    char *decoded_text= new char [TEXT_SIZE];
    char *key;
    //    cout_arr_double(freq_alphabet,32);
    //    for(int i=0; i<=255; i++){
    //        cout<<"i = "<<i<<" "<<(char)i<<endl;
    //    }
    char *input_text="�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
    key_length=find_key(input_text);
//    for(int k=2; k<60; k++)
//    {
        find_keyword(input_text,key_length);
        key=find_keyword_2variant(input_text,key_length);
        cout<<"\n";
//    }
        for(int i=0,k=0; i<TEXT_SIZE; i++,k++)
        {
            if(k>=17)k=0;

            decoded_text[i]=input_text[i]-key[k]+(char)65504;
            if((ATOI)decoded_text[i]<=65503)decoded_text[i]+=char(32);
          //cout<<input_text[i]<<"-"<<key[k]<<"="<<decoded_text[i]<<(ATOI)decoded_text[i]<<endl;
            cout<<decoded_text[i];
        }

}



char* find_keyword_2variant(char* text,int key_length)
{

    cout<<"k="<<key_length<<endl;
    char* result=new char[key_length];
    int id=0;
    double summ[32]{};
    int freq_counter[32]{};


    for(int b=0; b<key_length; b++){
        for(int zero=0; zero<32; zero++)freq_counter[zero]=0;
        for(int i=b; i<TEXT_SIZE; i+=key_length)
        {
            if(i+key_length<TEXT_SIZE)
            {
                freq_counter[(ATOI)text[i]-65504]++;
                //cout<<(ATOI)text[i]-65504<<text[i]<<"\t";
            }
        }
        //cout_arr(freq_counter,32);
        for(int i=0; i<32; i++) summ[i]=0;
        for(int i=0, ig=0; i<32; i++)
        {
            for(int j=0; j<32; j++)
            {
                ig=i+j;
                if(ig>=32)ig-=32;
                summ[i]+=freq_alphabet[j]*freq_counter[ig];
            }
        }

//                for(int i=0; i<32; i++)
//                {
//                    cout<<summ[i]<<"\t";
//                }
//cout<<endl;
        result[b]=(char)(find_max_double(summ,32)+224);
        cout<<(char)(find_max_double(summ,32)+224);
    }
    return result;
}




char *find_keyword(char* text,int key_length)
{
    char* result=new char[17];
    for(int key_letter=1; key_letter<33; key_letter++){
        //cout<<"----------------\nkeyletter="<<key_letter<<endl;
        for(int i=0; i<key_length; i++)
        {
            find_keyletter(i,text,key_length, key_letter);

        }
        cout<<setw(20)<<(char)(key_letter+223)<<endl;                    //uncomment
        //cout<<endl;
    }

    return result;
}



char*find_keyletter(int iteration, char* text,int key_length,int key_letter)
{

    char* letter;
    int freq_counter[32]={};
    int test;
    for(int i=0; i<TEXT_SIZE; i+=key_length)
    {
        if(i+iteration>=TEXT_SIZE)break;
        test =(ATOI)text[i+iteration]-65504;
        freq_counter[(ATOI)text[i+iteration]-65504]++;
        //cout<<i<<"\t"<<(ATOI)text[i]-65504<<endl;
    }
    //cout_arr(freq_counter,32);
    int max_id=find_max(freq_counter,32);

    int result_letter=max_id;

    result_letter-=key_letter;
    if(result_letter<0)result_letter+=32;

    cout<<(char)(result_letter+224);
    //cout<<max_id<<(char)(max_id+224)<<"\tresult letter="<<result_letter<<(char)(result_letter+224)<<endl;
}


double find_max_double(double arr[], int size)
{
    double max=0;
    int id_max=0;
    for(int i=0; i<size; i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            id_max=i;
        }
    }
    // cout<<endl<<"max="<<arr[id_max]<<endl;
    return id_max;

}



int find_max(int arr[], int size)
{
    int max=0;
    int id_max=0;
    for(int i=0; i<size; i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            id_max=i;
        }
    }
    // cout<<endl<<"max="<<arr[id_max]<<endl;
    return id_max;

}

void cout_arr(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<setw(2)<<arr[i]<<" ";
    }
    cout<<endl;
}
void cout_arr_double(const double arr[], int size){
    for(int i=0; i<size; i++)
    {
        cout<<setw(5)<<arr[i]<<" ";
    }
    cout<<endl;
}


int find_key(char* text)
{
    int size=25;
    int count[25]={};
    int max=0,id_counter=0;
    int result=0;
    for(int j=1; j<size; j++){
            for(int i=0; i<TEXT_SIZE;i++)
            {
                if(text[i]==text[i+j])count[j]++;

            }
        }

    for(int i=0; i<size;i++)
    {
        if(max<count[i])
        {
            id_counter=i;
            max=count[i];
        }
    }
    result =id_counter;
    //    cout<<"max_id ="<<result<<endl<<id_counter<<endl;
            for(int i=0; i<size;i++)
            {
                cout<<i<<"\t"<<count[i]<<endl;
            }

            cout<<"\n\n";
    return result;
}

