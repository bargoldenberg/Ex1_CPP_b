#include<string.h>
#include<iostream>
#include"mat.hpp"
#include<vector>
#include<ctype.h>
constexpr auto A  = 33;
constexpr auto B = 126;
using namespace std;

/* AUTHOR: BAR GOLDENBERG 209894286 */
/**
 * @brief This function loops a 2d array and fills it with a character.
 * 
 * @param arr 
 * @param l 
 * @param w 
 * @param minwidth 
 * @param minlength 
 * @param c 
 */
/*
Draws a rectangle in a matrix given a set of bounds and a character.
*/
vector<vector<char>> ariel::loop(vector<vector<char>> mat,int originalwidth, int originallength,int minwidth,int minlength,char c){
    for(int i=minwidth;i<originallength;i++){
        mat[minlength][i]=c;
        mat[originalwidth-1][i]=c;
    }
    for(int i=minlength;i<originalwidth;i++){
        mat[i][minwidth]=c;
        mat[i][originallength-1]=c;
    }
  return mat;
}
/**
 * @brief this function uses the loop function to create a carpet type string.
 * question from: https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
 * 
 * @param w 
 * @param l 
 * @param c 
 * @param spacing 
 * @return string 
 */
string ariel::mat(int w,int l,char c,char spacing){
    string ans;
    /*
    Throw Exceptions if input is illegal.
    */
  
    if(l%2==0||w%2==0){
        throw invalid_argument("Mat size is always odd");
    }
    if(l<0||w<0){
        string word;
        word+="l= ";
        word+=to_string(l);
        word+=" ,w=";
        word+=to_string(w);
        throw invalid_argument(word+"Mat size is always positive");
    }
    if(c<A||spacing<A){
        throw invalid_argument("illegal char not on ascii table");
    }
    if(c>B||spacing>B){
        throw invalid_argument("illegal char not on ascii table");
    }
    /*
    Continue building carpet if input is legal.
    */
    vector<vector<char>> mat;
    mat.resize(l);
    for(int i=0;i<l;i++){
        mat[i].resize(w);
    }

    int newwidth=w;
    int newlength=l;
    int k=0;
    /*
    Create carpets by using loop to draw smaller and smaller rectangles, untill we receive the desiered carpet.
    */
    while(k<=w/2&&k<=l/2){
        if(k%2==0){
            mat = ariel::loop(mat,newlength,newwidth,k,k,c);
        }else{
            mat = ariel::loop(mat,newlength,newwidth,k,k,spacing);
        }
        newwidth--;
        newlength--;
        k++;
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            ans.push_back(mat[i][j]);
        }
        ans+="\n";
    }
    /*
    Return answer.
    */
    return ans;
    
}