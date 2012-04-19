/*
Header für das ganze DIR
*/
#ifndef database_h
#define database_h


  /*-------------------------------*/
 /*------- Return-Values ---------*/
/*-------------------------------*/
//TODO: Values in Abstimmung mit datastruct.h
#define TABLE_ERROR_ATTR_NOT_FOUND -1
#define TABLE_ERROR_ATTR_NO_INDEX -1
#define DATABASE_SUCCESS 1
#define ATTR_TUPEL_NOT_FOUND -1

#include "attribut.h"
#include "table.h"
#include "db.h"
#endif
