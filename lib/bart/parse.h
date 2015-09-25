/* File:    parse.h
 * Purpose: simple parser for data files, includeing args parsing
 */

#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include "Definition.h"
#include <Scene.h>

bool viParseArgs(int argc, char *argv[], char **filename);
bool viParseFile(FILE *f, Scene* scenePtr);

#endif
