/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   A_jpg;
    const int            A_jpgSize = 189488;

    extern const char*   B_jpg;
    const int            B_jpgSize = 262144;

    extern const char*   C_jpg;
    const int            C_jpgSize = 214248;

    extern const char*   D_jpg;
    const int            D_jpgSize = 262144;

    extern const char*   E_jpg;
    const int            E_jpgSize = 134520;

    extern const char*   F_jpg;
    const int            F_jpgSize = 150071;

    extern const char*   G_jpg;
    const int            G_jpgSize = 65536;

    extern const char*   H_jpg;
    const int            H_jpgSize = 80552;

    extern const char*   Cat_obj;
    const int            Cat_objSize = 216547;

    extern const char*   Cow_obj;
    const int            Cow_objSize = 71840;

    extern const char*   Deer_obj;
    const int            Deer_objSize = 153706;

    extern const char*   Face_obj;
    const int            Face_objSize = 488414;

    extern const char*   Goat_obj;
    const int            Goat_objSize = 74629;

    extern const char*   Human_obj;
    const int            Human_objSize = 393707;

    extern const char*   Rat_obj;
    const int            Rat_objSize = 85911;

    extern const char*   Tiger_obj;
    const int            Tiger_objSize = 259127;

    extern const char*   Wolf_obj;
    const int            Wolf_objSize = 199819;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 17;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
