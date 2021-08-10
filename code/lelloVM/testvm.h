#pragma once
#include "vm.h" //for esegui function
#include "comandi.h" //for enum comandi
#include <stdio.h>
#include "zwdata.h"

void test_vm()
{
	int test_carica[] = {
						carica, 666, 0, 0,
						fine, 0, 0, 0
						};
	esegui(test_carica);
	printf("carica expected 666 output ");
	SCRIVI(0);
	printf("/n");
	
	
	int test_copy[] = {
						copy, 0, 1, 0,
						fine, 0, 0, 0
					};
	esegui(test_copy);
	printf("copy expected 666 output ");
	SCRIVI(1);
	printf("/n");
	
	int test_somma[] = {
						somma, 0, 1, 2,
						fine, 0, 0, 0
						};
	esegui(test_somma);
	printf("somma expected 1332 output ");
	SCRIVI(2);
	printf("/n"); 
	
	int test_sottrai[] = {
						sottrai, 2, 0, 3,
						fine, 0, 0, 0
						};
	esegui(test_sottrai);
	printf("sottrai expected 666 output ");
	SCRIVI(3);
	printf("/n");
	
	int test_moltiplica[] = {
						moltiplica, 0, 1, 4,
						fine, 0, 0, 0
						};
	esegui(test_moltiplica);
	printf("moltiplica expected 443556 output ");
	SCRIVI(4);
	printf("/n");
	
	int test_dividi[] = {
						dividi, 0, 2, 5,
						fine, 0, 0, 0
						};
	esegui(test_dividi);
	printf("dividi expected 2 output ");
	SCRIVI(5);
	printf("/n");
}