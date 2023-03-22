/** gif2bmp
 * This program converts gif into a series of bmp files in a folder
 * with the same name as the gif file.
 * It is a very simple program and was made to try the nobuild.h header
 * file provided by tsoding.
 *
 * # Dependencies
 * - imagemagick
 *
 * This program uses imagemagick as its backbone so if its
 * not installed on your system or is not in your PATH enviroment
 * variable, then the program will fail with the error;
 * [ERROR] command was not found.
 * ...probably, didn't test it.
**/

#define NOBUILD_IMPLEMENTATION
#include "nobuild.h" // THANK YOU TSODING
                     // reference: https://youtu.be/ldefArsm3x0
                     // And the original .h file is here:
                     // https://github.com/tsoding/nobuild

int main(int argc, char **argv)
{
    argc -= 1; // Ignore argument[0]

    // Print Usage if no arguments are supplied
    if (argc == 0 || argc > 1) INFO("usage: gif2bmp [filename (no ext)]");

    char *filename = argv[1]; // get filename
    MKDIRS(filename);         // Make a directory with the same name

    // Copy gif into that Directory
    CP(CONCAT(filename,".gif"), CONCAT(filename, "/", filename, ".gif"));

    // Use the convert command in the imagemagick package to convert the gif into multiple
    // bmp fotos.
    CMD("convert", "-coalesce", CONCAT(filename, "/", filename, ".gif"), CONCAT(filename, "/out.bmp"));

#ifdef RMGIF // If the program is built with the -DRMGIF flag then remove the gif after the conversion
    CMD("rm", CONCAT(filename, ".gif"));
#endif // otherwise just ignore that line and exit
    return 0;
}
