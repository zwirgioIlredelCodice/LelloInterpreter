#pragma once
#include "vm.h" //for esegui function
#include "comandi.h" //for enum comandi
#include <stdio.h>
#include "zwdata.h"

void test_vm()
{
	inizzializza_memoria(50);
	
	int test_carica[] = {
						carica, 666, 0, 0,
						fine, 0, 0, 0
						};
	esegui(test_carica);
	printf("carica expected 666 output ");
	SCRIVI(0);
	printf("\n");
	
	
	int test_copy[] = {
						copy, 0, 1, 0,
						fine, 0, 0, 0
					};
	esegui(test_copy);
	printf("copy expected 666 output ");
	SCRIVI(1);
	printf("\n");

	int test_somma[] = {
						somma, 0, 1, 2,
						fine, 0, 0, 0
						};
	esegui(test_somma);
	printf("somma expected 1332 output ");
	SCRIVI(2);
	printf("\n"); 
	
	int test_sottrai[] = {
						sottrai, 2, 0, 3,
						fine, 0, 0, 0
						};
	esegui(test_sottrai);
	printf("sottrai expected 666 output ");
	SCRIVI(3);
	printf("\n");
	
	int test_moltiplica[] = {
						moltiplica, 0, 1, 4,
						fine, 0, 0, 0
						};
	esegui(test_moltiplica);
	printf("moltiplica expected 443556 output ");
	SCRIVI(4);
	printf("\n");
	
	int test_dividi[] = {
						dividi, 0, 2, 5,
						fine, 0, 0, 0
						};
	esegui(test_dividi);
	printf("dividi expected 2 output ");
	SCRIVI(5);
	printf("\n");
	
	int test_e[] = 		{
						carica, 1, 0, 0,
						carica, 1, 1, 0,
						e, 0, 1, 6,
						fine, 0, 0, 0
						};
	esegui(test_e);
	printf("e expected 1 output ");
	SCRIVI(6);
	printf("\n");
	
	int test_o[] = 		{
						carica, 1, 0, 0,
						carica, 0, 1, 0,
						o, 0, 1, 7,
						fine, 0, 0, 0
						};
	esegui(test_o);
	printf("o expected 1 output ");
	SCRIVI(7);
	printf("\n");
	
	int test_non[] = 		{
						carica, 1, 0, 0,
						non, 0, 8, 0,
						fine, 0, 0, 0
						};
	esegui(test_non);
	printf("non expected 0 output ");
	SCRIVI(8);
	printf("\n");
	
	int test_uguale[] = 		{
						carica, 1, 0, 0,
						carica, 1, 1, 0,
						uguale, 0, 1, 9,
						fine, 0, 0, 0
						};
	esegui(test_uguale);
	printf("uguale expected 1 output ");
	SCRIVI(9);
	printf("\n");
	
	int test_nonuguale[] = 		{
						carica, 1, 0, 0,
						carica, 1, 1, 0,
						nonuguale, 0, 1, 10,
						fine, 0, 0, 0
						};
	esegui(test_nonuguale);
	printf("nonuguale expected 0 output ");
	SCRIVI(10);
	printf("\n");
	
	int test_minore[] = 		{
						carica, 2, 0, 0,
						carica, 1, 1, 0,
						minore, 0, 1, 11,
						fine, 0, 0, 0
						};
	esegui(test_minore);
	printf("minore expected 0 output ");
	SCRIVI(11);
	printf("\n");
	
	int test_maggiore[] = 		{
						carica, 2, 0, 0,
						carica, 1, 1, 0,
						maggiore, 0, 1, 12,
						fine, 0, 0, 0
						};
	esegui(test_maggiore);
	printf("maggiore expected 1 output ");
	SCRIVI(12);
	printf("\n");
	
	int test_minoreuguale[] = 		{
						carica, 2, 0, 0,
						carica, 2, 1, 0,
						minoreuguale, 0, 1, 12,
						fine, 0, 0, 0
						};
	esegui(test_minoreuguale);
	printf("minoreuguale expected 1 output ");
	SCRIVI(13);
	printf("\n");
	
	int test_maggioreuguale[] = 		{
						carica, 2, 0, 0,
						carica, 2, 1, 0,
						maggioreuguale, 0, 1, 13,
						fine, 0, 0, 0
						};
	esegui(test_maggioreuguale);
	printf("maggioreuguale expected 1 output ");
	SCRIVI(13);
	printf("\n");
	
	
	int test_vai[] = 		{
						vai, 3 , 0, 0,
						fine, 0, 0, 0,
						carica, 8, 14, 0,
						fine, 0, 0, 0
						};
	esegui(test_vai);
	printf("vai expected 8 output ");
	SCRIVI(14);
	printf("\n");
	
	int test_vai_vero[] = 		{
						carica, 1, 0, 0,
						vai_vero, 0 , 4, 0,
						fine, 0, 0, 0,
						carica, 8, 15, 0,
						fine, 0, 0, 0
						};
	esegui(test_vai_vero);
	printf("vai_vero expected 8 output ");
	SCRIVI(15);
	printf("\n");
	
	int test_vai_falso[] = 		{
						carica, 0, 0, 0,
						vai_falso, 0 , 4, 0,
						fine, 0, 0, 0,
						carica, 8, 16, 0,
						fine, 0, 0, 0
						};
	esegui(test_vai_falso);
	printf("vai_falso expected 8 output ");
	SCRIVI(16);
	printf("\n");
	
	int test_scrivi[] = 		{
						carica, 11, 0, 0,
						scrivi, 0, 0, 0,
						fine, 0, 0, 0
						};
	esegui(test_scrivi);
	printf("scrivi expected 11 output ");
	printf("\n");
	
	printf("immetti quello che vuoi\n");
	int test_immetti[] = 		{
						immetti, 0, 0, 0,
						fine, 0, 0, 0
						};
	esegui(test_immetti);
	printf("immetti expected cosa ai messo? output ");
	SCRIVI(0);
	printf("\n");
	
}