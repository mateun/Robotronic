//
// Created by mgrus on 04/07/2021.
//
#include <string>
#include "filesutils.h"
#include <SDL.h>

std::string f_read_file(const std::string& fileName)
{
    std::string result = "";
    FILE* f;
    fopen_s(&f, fileName.c_str(), "rb");
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    rewind(f);

    char* buf = new char[size+1];
    memset(buf, 0, sizeof(buf));
    int read = fread_s(buf, size, 1, size, f);
    if (read != size) {
    SDL_Log("error reading file\n.");
    exit(1);
    }
    buf[size] = '\0';

    result = buf;
    fclose(f);
    return result;

}

