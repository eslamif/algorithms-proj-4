//cs325, Projec 4, Group 2 (Kevin To, Matthew Walz, Frank Eslami)
//Source code for main program 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//HARD-KEYED DATA UNTIL MATT'S FUNCTION PROVIDES DATA


//CREATE DUMMY DATA UNTIL MATT'S PROVIDES DATA
struct city {
	int id;
	int x;
	int y;
};

struct edge {
	int i_id;
	int j_id;
	double weight;
};

//FUNCTION DECLARATIONS
void find_distance(struct city cities[], int num_of_cities, struct edge *city_edge, int num_of_edges);
double find_MST(int num_of_cities, struct edge *city_edge, int num_of_edges);
int cmp_weights(const void *a, const void *b);

int main() {
	int num_of_cities = 4;
	int num_of_edges = num_of_cities * (num_of_cities) / 2;

	//INITIALIZE DUMMY DATA UNTIL MATT'S PROVIDES DATA
	struct city cities[num_of_cities];
	cities[0].id = 0;
	cities[0].x = 200;
	cities[0].y = 800;
	
	cities[1].id = 1;
	cities[1].x = 3600;
	cities[1].y = 2300;
	
	cities[2].id = 2;
	cities[2].x = 3100;
	cities[2].y = 3300;
	
	cities[3].id = 3;
	cities[3].x = 4700;
	cities[3].y = 5750;

	
	//Struct that stores 2 cities and the weight of their edge
	struct edge *city_edge;
	city_edge = malloc(sizeof(struct edge) * num_of_edges);

	//Find distance between each city & store in struct
	find_distance(cities, num_of_cities, city_edge, num_of_edges);
 
	//Find MST by using Prim's algorithm
	double total_weight = find_MST(num_of_cities, city_edge, num_of_edges);
	printf("MST weight = %.0f\n", total_weight);	

	return 0;
}


//Find distance between each city and stored in struct
//
void find_distance(struct city cities[], int num_of_cities, struct edge *city_edge, int num_of_edges) {
//	struct edge city_edge[num_of_edges];
	int i, j, h = 0;
	double weight;
	for (i = 0; i < num_of_cities; i++) {
		for (j = i + 1; j < num_of_cities; j++) {
			weight = sqrt( pow((cities[i].x - cities[j].x), 2) + pow((cities[i].y - cities[j].y), 2) );
			city_edge[h].i_id = cities[i].id;
			city_edge[h].j_id = cities[j].id;
			city_edge[h].weight = weight; 

			//TEST weights were stored correctly
//			printf("%.0f\n", city_edge[h].weight);

			h++;
		}	
	}

	//qsort the edges by weight. Note that cmp_weights is a function
	qsort(city_edge, num_of_edges, sizeof(struct edge), cmp_weights);

	/*  TEST SORT WORKED
	for (i = 0; i < num_of_edges; i++) {
			printf("%.0f\n", city_edge[i].weight);
	} */
}


//Find MST using Prim's Algorithm
double find_MST(int num_of_cities, struct edge *city_edge, int num_of_edges) {
	int *comps, i, j, k, cj, l;
	int total_distance = 0;
	comps = malloc(sizeof(int) * num_of_cities);
	for (i = 0; i < num_of_cities; i++) {
		comps[i] = i;
	}

	for (k = 0; k < num_of_edges; k++) {
		i = city_edge[k].i_id;
		j = city_edge[k].j_id;	
		
		if (comps[i] != comps[j]) {
			total_distance += city_edge[k].weight;
			cj = comps[j];
	
			for (l = 0; l < num_of_cities; l++) {
				if (comps[l] == cj)
					comps[l] = comps[i];
			}
		}
	}	
	free(comps);
	free(city_edge);
	return total_distance;
}


//qsort weight comparison function - required for qsort, which is part of the stdlib.h
int cmp_weights(const void *a, const void *b) {
	double w1, w2;

	w1 = ((struct edge*)a)->weight;
	w2 = ((struct edge*)b)->weight;
	
	if (w1 < w2)
		return -1;
	else if (w1 == w2)
		return 0;
	else
		return 1;
}








