#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /Emain /D __INST__=40 /Fh ShaderHeader/model_unlit_ps.h
//    Shader/model_unlit_ps.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 fLightDirection;            // Offset:    0 Size:    16 [unused]
//   float4 fLightColor;                // Offset:   16 Size:    16 [unused]
//   float4 fLightAmbient;              // Offset:   32 Size:    16 [unused]
//   float4 fFlipbookParameter;         // Offset:   48 Size:    16 [unused]
//   float4 fUVDistortionParameter;     // Offset:   64 Size:    16 [unused]
//   float4 fBlendTextureParameter;     // Offset:   80 Size:    16 [unused]
//   float4 fCameraFrontDirection;      // Offset:   96 Size:    16 [unused]
//   
//   struct
//   {
//       
//       float4 Param;                  // Offset:  112
//       float4 BeginColor;             // Offset:  128
//       float4 EndColor;               // Offset:  144
//
//   } fFalloffParam;                   // Offset:  112 Size:    48 [unused]
//   float4 fEmissiveScaling;           // Offset:  160 Size:    16 [unused]
//   float4 fEdgeColor;                 // Offset:  176 Size:    16 [unused]
//   float4 fEdgeParameter;             // Offset:  192 Size:    16 [unused]
//   float4 softParticleAndReconstructionParam1;// Offset:  208 Size:    16
//   float4 reconstructionParam2;       // Offset:  224 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// sampler_colorTex                  sampler      NA          NA    0        1
// sampler_depthTex                  sampler      NA          NA    1        1
// _colorTex                         texture  float4          2d    0        1
// _depthTex                         texture  float4          2d    1        1
// PS_ConstanBuffer                  cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// TEXCOORD                 0   xy          1     NONE  float   xy  
// COLOR                    0   xyzw        2     NONE  float   xyzw
// TEXCOORD                 4   xyzw        3     NONE  float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb0[15], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_input_ps linear centroid v1.xy
dcl_input_ps linear centroid v2.xyzw
dcl_input_ps linear v3.xyzw
dcl_output o0.xyzw
dcl_temps 3
sample r0.xyzw, v1.xyxx, t0.xyzw, s0
mul r0.xyzw, r0.xyzw, v2.xyzw
div r1.yzw, v3.xxyz, v3.wwww
add r1.yz, r1.yyzy, l(0.000000, 1.000000, 1.000000, 0.000000)
mul r2.x, r1.y, l(0.500000)
mad r2.z, -r1.z, l(0.500000), l(1.000000)
sample r2.xyzw, r2.xzxx, t1.xyzw, s1
ne r1.y, cb0[13].x, l(0.000000)
mad r1.x, r2.x, cb0[13].y, cb0[13].z
mad r2.xy, r1.xwxx, cb0[14].wwww, -cb0[14].yyyy
mad r1.xz, -r1.xxwx, cb0[14].zzzz, cb0[14].xxxx
div r1.xz, r2.xxyx, r1.xxzx
add r1.x, -r1.x, r1.z
div_sat r1.x, r1.x, cb0[13].x
mul r1.x, r0.w, r1.x
movc r0.w, r1.y, r1.x, r0.w
eq r1.x, r0.w, l(0.000000)
discard r1.x
mov o0.xyzw, r0.xyzw
ret 
// Approximately 20 instruction slots used
#endif

const BYTE g_main[] =
{
     68,  88,  66,  67, 141, 199, 
     41,   3, 155, 205, 251,  99, 
    129, 217,   5,  31, 186,  69, 
    174, 103,   1,   0,   0,   0, 
    104,   8,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     40,   4,   0,   0, 180,   4, 
      0,   0, 232,   4,   0,   0, 
    236,   7,   0,   0,  82,  68, 
     69,  70, 236,   3,   0,   0, 
      1,   0,   0,   0,   4,   1, 
      0,   0,   5,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    184,   3,   0,   0, 188,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    205,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 222,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 232,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    242,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 115,  97, 109, 112, 
    108, 101, 114,  95,  99, 111, 
    108, 111, 114,  84, 101, 120, 
      0, 115,  97, 109, 112, 108, 
    101, 114,  95, 100, 101, 112, 
    116, 104,  84, 101, 120,   0, 
     95,  99, 111, 108, 111, 114, 
     84, 101, 120,   0,  95, 100, 
    101, 112, 116, 104,  84, 101, 
    120,   0,  80,  83,  95,  67, 
    111, 110, 115, 116,  97, 110, 
     66, 117, 102, 102, 101, 114, 
      0, 171, 242,   0,   0,   0, 
     13,   0,   0,   0,  28,   1, 
      0,   0, 240,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  84,   2,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 116,   2,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 128,   2,   0,   0, 
     32,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 142,   2,   0,   0, 
     48,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 161,   2,   0,   0, 
     64,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 184,   2,   0,   0, 
     80,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 207,   2,   0,   0, 
     96,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 229,   2,   0,   0, 
    112,   0,   0,   0,  48,   0, 
      0,   0,   0,   0,   0,   0, 
     68,   3,   0,   0,   0,   0, 
      0,   0,  84,   3,   0,   0, 
    160,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 101,   3,   0,   0, 
    176,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 112,   3,   0,   0, 
    192,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 127,   3,   0,   0, 
    208,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 163,   3,   0,   0, 
    224,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 102,  76, 105, 103, 
    104, 116,  68, 105, 114, 101, 
     99, 116, 105, 111, 110,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 102,  76, 
    105, 103, 104, 116,  67, 111, 
    108, 111, 114,   0, 102,  76, 
    105, 103, 104, 116,  65, 109, 
     98, 105, 101, 110, 116,   0, 
    102,  70, 108, 105, 112,  98, 
    111, 111, 107,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0, 102,  85,  86,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  80,  97, 114,  97, 
    109, 101, 116, 101, 114,   0, 
    102,  66, 108, 101, 110, 100, 
     84, 101, 120, 116, 117, 114, 
    101,  80,  97, 114,  97, 109, 
    101, 116, 101, 114,   0, 102, 
     67,  97, 109, 101, 114,  97, 
     70, 114, 111, 110, 116,  68, 
    105, 114, 101,  99, 116, 105, 
    111, 110,   0, 102,  70,  97, 
    108, 108, 111, 102, 102,  80, 
     97, 114,  97, 109,   0,  80, 
     97, 114,  97, 109,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     66, 101, 103, 105, 110,  67, 
    111, 108, 111, 114,   0,  69, 
    110, 100,  67, 111, 108, 111, 
    114,   0, 243,   2,   0,   0, 
    252,   2,   0,   0,   0,   0, 
      0,   0,  12,   3,   0,   0, 
    252,   2,   0,   0,  16,   0, 
      0,   0,  23,   3,   0,   0, 
    252,   2,   0,   0,  32,   0, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  12,   0,   0,   0, 
      3,   0,  32,   3,   0,   0, 
    102,  69, 109, 105, 115, 115, 
    105, 118, 101,  83,  99,  97, 
    108, 105, 110, 103,   0, 102, 
     69, 100, 103, 101,  67, 111, 
    108, 111, 114,   0, 102,  69, 
    100, 103, 101,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0, 115, 111, 102, 116,  80, 
     97, 114, 116, 105,  99, 108, 
    101,  65, 110, 100,  82, 101, 
     99, 111, 110, 115, 116, 114, 
    117,  99, 116, 105, 111, 110, 
     80,  97, 114,  97, 109,  49, 
      0, 114, 101,  99, 111, 110, 
    115, 116, 114, 117,  99, 116, 
    105, 111, 110,  80,  97, 114, 
     97, 109,  50,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  57,  46,  50, 
     57,  46,  57,  53,  50,  46, 
     51,  49,  49,  49,   0, 171, 
    171, 171,  73,  83,  71,  78, 
    132,   0,   0,   0,   4,   0, 
      0,   0,   8,   0,   0,   0, 
    104,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
    116,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   3,   3,   0,   0, 
    125,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,  15,  15,   0,   0, 
    116,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,  15,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0,  67,  79,  76, 
     79,  82,   0, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171,  83,  72,  68,  82, 
    252,   2,   0,   0,  64,   0, 
      0,   0, 191,   0,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      0,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      1,   0,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   1,   0, 
      0,   0,  85,  85,   0,   0, 
     98,  24,   0,   3,  50,  16, 
     16,   0,   1,   0,   0,   0, 
     98,  24,   0,   3, 242,  16, 
     16,   0,   2,   0,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   3,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   3,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  16,  16,   0, 
      1,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  30, 
     16,   0,   2,   0,   0,   0, 
     14,   0,   0,   7, 226,   0, 
     16,   0,   1,   0,   0,   0, 
      6,  25,  16,   0,   3,   0, 
      0,   0, 246,  31,  16,   0, 
      3,   0,   0,   0,   0,   0, 
      0,  10,  98,   0,  16,   0, 
      1,   0,   0,   0,  86,   6, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
     50,   0,   0,  10,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,  63,   1,  64,   0,   0, 
      0,   0, 128,  63,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0, 134,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 126,  16,   0,   1,   0, 
      0,   0,   0,  96,  16,   0, 
      1,   0,   0,   0,  57,   0, 
      0,   8,  34,   0,  16,   0, 
      1,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     13,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  11,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,  13,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,  13,   0, 
      0,   0,  50,   0,   0,  12, 
     50,   0,  16,   0,   2,   0, 
      0,   0, 198,   0,  16,   0, 
      1,   0,   0,   0, 246, 143, 
     32,   0,   0,   0,   0,   0, 
     14,   0,   0,   0,  86, 133, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,  50,   0,   0,  12, 
     82,   0,  16,   0,   1,   0, 
      0,   0,   6,   3,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0, 166, 138,  32,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,  14,   0,   0,   7, 
     82,   0,  16,   0,   1,   0, 
      0,   0,   6,   1,  16,   0, 
      2,   0,   0,   0,   6,   2, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  14,  32,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     13,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     13,   0,   4,   3,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 116,   0, 
      0,   0,  20,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     10,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
