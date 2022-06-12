#ifndef FASTNOISE_C_H
#define FASTNOISE_C_H

#include "FastNoise_Export.h"

#ifdef __cplusplus
extern "C" {
#endif

 void* fnNewFromEncodedNodeTree( const char* encodedString, unsigned /*FastSIMD::eLevel*/ simdLevel /*0 = Auto*/ );

 void fnDeleteNodeRef( void* node );

 unsigned fnGetSIMDLevel( const void* node );
 int fnGetMetadataID( const void* node );

 void fnGenUniformGrid2D( const void* node, float* noiseOut,
                                       int xStart, int yStart,
                                       int xSize, int ySize,
                                       float frequency, int seed, float* outputMinMax /*nullptr or float[2]*/ );

 void fnGenUniformGrid3D( const void* node, float* noiseOut,
                                       int xStart, int yStart, int zStart,
                                       int xSize, int ySize, int zSize,
                                       float frequency, int seed, float* outputMinMax /*nullptr or float[2]*/ );

 void fnGenUniformGrid4D( const void* node, float* noiseOut,
                                       int xStart, int yStart, int zStart, int wStart,
                                       int xSize, int ySize, int zSize, int wSize,
                                       float frequency, int seed, float* outputMinMax /*nullptr or float[2]*/ );

 void fnGenPositionArray2D( const void* node, float* noiseOut, int count,
                                         const float* xPosArray, const float* yPosArray,
                                         float xOffset, float yOffset,
                                         int seed, float* outputMinMax /*nullptr or float[2]*/ );

 void fnGenPositionArray3D( const void* node, float* noiseOut, int count,
                                         const float* xPosArray, const float* yPosArray, const float* zPosArray,
                                         float xOffset, float yOffset, float zOffset,
                                         int seed, float* outputMinMax /*nullptr or float[2]*/ );

 void fnGenPositionArray4D( const void* node, float* noiseOut, int count,
                                         const float* xPosArray, const float* yPosArray, const float* zPosArray, const float* wPosArray,
                                         float xOffset, float yOffset, float zOffset, float wOffset,
                                         int seed, float* outputMinMax /*nullptr or float[2]*/ );

 void fnGenTileable2D( const void* node, float* noiseOut,
                                    int xSize, int ySize,
                                    float frequency, int seed, float* outputMinMax /*nullptr or float[2]*/ );

 float fnGenSingle2D( const void* node, float x, float y, int seed );
 float fnGenSingle3D( const void* node, float x, float y, float z, int seed );
 float fnGenSingle4D( const void* node, float x, float y, float z, float w, int seed );

 int fnGetMetadataCount();
 const char* fnGetMetadataName( int id ); // valid IDs up to `fnGetMetadataCount() - 1`
 void* fnNewFromMetadata( int id, unsigned /*FastSIMD::eLevel*/ simdLevel /*0 = Auto*/ );

 int fnGetMetadataVariableCount( int id );
 const char* fnGetMetadataVariableName( int id, int variableIndex );
 int fnGetMetadataVariableType( int id, int variableIndex );
 int fnGetMetadataVariableDimensionIdx( int id, int variableIndex );
 int fnGetMetadataEnumCount( int id, int variableIndex );
 const char* fnGetMetadataEnumName( int id, int variableIndex, int enumIndex );
 bool fnSetVariableFloat( void* node, int variableIndex, float value );
 bool fnSetVariableIntEnum( void* node, int variableIndex, int value );

 int fnGetMetadataNodeLookupCount( int id );
 const char* fnGetMetadataNodeLookupName( int id, int nodeLookupIndex );
 int fnGetMetadataNodeLookupDimensionIdx( int id, int nodeLookupIndex );
 bool fnSetNodeLookup( void* node, int nodeLookupIndex, const void* nodeLookup );

 int fnGetMetadataHybridCount( int id );
 const char* fnGetMetadataHybridName( int id, int hybridIndex );
 int fnGetMetadataHybridDimensionIdx( int id, int hybridIndex );
 bool fnSetHybridNodeLookup( void* node, int hybridIndex, const void* nodeLookup );
 bool fnSetHybridFloat( void* node, int hybridIndex, float value );

#ifdef __cplusplus
}
#endif

#endif
