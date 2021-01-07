#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct entry_node_struct{
	float entry;
	struct entry_node_struct *next;
}entryNode;

//Coordinate vector that has a linked list of entries
typedef struct coordinate_node_struct{
	int row_size;
	entryNode *vector;
	struct coordinate_node_struct *next;
}coordinateNode;

typedef struct Matrix_struct{
	int col_size;
	int row_size;
	coordinateNode *col_vectors;
}Matrix;



entryNode *create_new_entryNode(float entry){
	entryNode* newNode = NULL;
	newNode = (entryNode *)calloc(1, sizeof(entryNode));
	if(newNode != NULL){
		newNode -> entry = entry;
		newNode -> next = NULL;
	}
	return newNode;
}



bool correct_vector_column_size(int dimension, entryNode *vector){
	int size = 0;
	while(vector != NULL){
		vector = vector -> next;
		size++;
	}
	return dimension == size;
}

coordinateNode *create_new_coordinateNode(int row_size, entryNode *vector){
	if (!correct_vector_column_size(row_size, vector)){
		printf("Incorrect dimension");
		return NULL;
	}
	coordinateNode *newNode = NULL;
	newNode = (coordinateNode *)calloc(1, sizeof(coordinateNode));

	if(newNode != NULL){
		newNode -> row_size = row_size;
		newNode -> vector = vector;
		newNode -> next = NULL;
	}
	return newNode;
}



bool correct_row_size(int dimension, coordinateNode* col_vectors){
	int size = 0;
	while(col_vectors != NULL){
		col_vectors = col_vectors -> next;
		size++;
	}

	return dimension == size;
}

bool correct_matrix_column_size(int dimension, coordinateNode* col_vectors){
	while(col_vectors != NULL){
		int size = 0;
		if(!correct_vector_column_size(dimension, col_vectors->vector))
			return false;
		col_vectors = col_vectors -> next;
	}
	return true;
}

Matrix create_new_Matrix(int col_size, int row_size, coordinateNode* col_vectors){

}

int main(){
	return 0;
}
