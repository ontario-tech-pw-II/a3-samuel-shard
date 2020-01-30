//Week 4 Activity 2
//January 30, 2020
//Author: Samuel Shard, Student Number: 100745640
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void freadnames(ifstream &, char * []);
void fwritenames_reverse(ofstream &,char * []);
void freenames(char * []);


int main(int argc, char *argv[])
{
	char *list[100];
    
    if(argc != 3){
    	cerr << "Number of argument is not correct!" << endl;
    	return 1;
    }

	ifstream fin(argv[1]);
	if(fin.fail()){
		cerr << "Cannot open the input file!" << endl;
		return 1;
	}

	ofstream fout(argv[2]);
	if(fin.fail()){
		cerr << "Cannot open the output file!" << endl;
		return 1;
	}

	freadnames(fin,list);
	fwritenames_reverse(fout,list);
	freenames(list);
	
	fin.close();
	fout.close();
	
	return 0; 
}

void freadnames(ifstream &f,char *list [])
{
	char x[200];

	int i = 0;

	// write a while loop to read one string from the input file 
	// and put it in x till the end of the file
		// inside the loop, allocate the dynamic array for list[i]
		// copy string stored in x to list[i] array using strcpy
		// increment i 
	while(f >> x){
		list[i] = new char[strlen(x)+1]; //first step
		strcpy(list[i], x);
		i++;
	}
	
	// IMPORTANT: we put the null to the last pointer in list 
	// to mark the last element in list
	list[i] = nullptr;  
}
void fwritenames_reverse(ofstream &f,char *list [])
{
	int i;
	for(i = 0; list[i] != nullptr ; i++)
	;//list i points to nullptr (one past the end of the array)

	//starting at the end of the array, go in reverse
	for(int j = i-1; j >= 0 ; j--)
	{	
		//write names starting from bottom to top of list to outfile
		f << list[j] << "\n";
		cout << list[j] << " ";
	}
}
void freenames(char *list [])
{
	for (int i = 0; list[i] != nullptr; i++)
	{
		delete [] list[i];
	}
}