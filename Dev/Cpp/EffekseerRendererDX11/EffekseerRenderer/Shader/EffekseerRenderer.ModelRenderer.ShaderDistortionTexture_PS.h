#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /EPS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.ModelRenderer.ShaderDistortionTexture_PS.h
//    Shader/model_renderer_distortion_texture_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 g_scale;                    // Offset:    0 Size:    16
//   float4 mUVInversedBack;            // Offset:   16 Size:    16
//   float4 fFlipbookParameter;         // Offset:   32 Size:    16
//   float4 fUVDistortionParameter;     // Offset:   48 Size:    16
//   float4 fBlendTextureParameter;     // Offset:   64 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_sampler                         sampler      NA          NA    0        1
// g_backSampler                     sampler      NA          NA    1        1
// g_alphaSampler                    sampler      NA          NA    2        1
// g_uvDistortionSampler             sampler      NA          NA    3        1
// g_blendSampler                    sampler      NA          NA    4        1
// g_texture                         texture  float4          2d    0        1
// g_backTexture                     texture  float4          2d    1        1
// g_alphaTexture                    texture  float4          2d    2        1
// g_uvDistortionTexture             texture  float4          2d    3        1
// g_blendTexture                    texture  float4          2d    4        1
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
// TEXCOORD                 5     zw        1     NONE  float     zw
// TEXCOORD                 1   xyzw        2     NONE  float       
// TEXCOORD                 2   xyzw        3     NONE  float   xy w
// TEXCOORD                 3   xyzw        4     NONE  float   xy w
// TEXCOORD                 4   xyzw        5     NONE  float   xy w
// COLOR                    0   xyzw        6     NONE  float   xy w
// TEXCOORD                 6   xy          7     NONE  float   xy  
// TEXCOORD                 7     zw        7     NONE  float     zw
// TEXCOORD                 8   x           8     NONE  float   x   
// TEXCOORD                 9    yz         8     NONE  float    yz 
// TEXCOORD                10      w        8     NONE  float      w
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb0[5], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_sampler s3, mode_default
dcl_sampler s4, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_resource_texture2d (float,float,float,float) t4
dcl_input_ps linear v1.xy
dcl_input_ps linear v1.zw
dcl_input_ps linear v3.xyw
dcl_input_ps linear v4.xyw
dcl_input_ps linear v5.xyw
dcl_input_ps linear v6.xyw
dcl_input_ps linear v7.xy
dcl_input_ps linear v7.zw
dcl_input_ps linear v8.x
dcl_input_ps linear v8.yz
dcl_input_ps linear v8.w
dcl_output o0.xyzw
dcl_temps 5
sample r0.xyzw, v7.xyxx, t3.xyzw, s3
mad r0.xy, r0.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r1.xyzw, r0.xyxy, cb0[3].xxxx, v1.xyzw
sample r2.xyzw, r1.xyxx, t0.xyzw, s0
mul r2.z, r2.w, v6.w
lt r0.z, l(0.000000), cb0[2].x
if_nz r0.z
  mad r0.xy, r0.xyxx, cb0[3].xxxx, v8.yzyy
  sample r0.xyzw, r0.xyxx, t0.xyzw, s0
  eq r0.z, cb0[2].y, l(1.000000)
  mad r0.xyw, r0.xyxw, v6.xyxw, -r2.xyxz
  mad r0.xyw, v8.xxxx, r0.xyxw, r2.xyxz
  movc r2.xyz, r0.zzzz, r0.xywx, r2.xyzx
endif 
sample r0.xyzw, r1.zwzz, t2.xyzw, s2
mul r0.x, r0.w, r2.z
ge r0.y, v8.w, r0.x
discard r0.y
eq r0.y, r0.x, l(0.000000)
discard r0.y
sample r1.xyzw, v7.zwzz, t4.xyzw, s4
mul r0.yz, r1.xxyx, r1.wwww
add r0.w, -r1.w, l(1.000000)
mad r2.zw, r0.wwww, r2.xxxy, r0.yyyz
mad r3.xy, r1.wwww, r1.xyxx, r2.xyxx
mad r1.xy, -r1.wwww, r1.xyxx, r2.xyxx
eq r4.xyzw, cb0[4].xxxx, l(0.000000, 1.000000, 2.000000, 3.000000)
mul r0.yz, r0.yyzy, r2.xxyx
movc r0.yz, r4.wwww, r0.yyzy, r2.xxyx
movc r0.yz, r4.zzzz, r1.xxyx, r0.yyzy
movc r0.yz, r4.yyyy, r3.xxyx, r0.yyzy
movc r0.yz, r4.xxxx, r2.zzwz, r0.yyzy
div r1.xy, v5.xyxx, v5.wwww
div r1.zw, v4.xxxy, v4.wwww
div r2.xy, v3.xyxx, v3.wwww
mad r0.yz, r0.yyzy, l(0.000000, 2.000000, 2.000000, 0.000000), l(0.000000, -1.000000, -1.000000, 0.000000)
mul r0.yz, r0.yyzy, v6.xxyx
mul r0.yz, r0.yyzy, cb0[0].xxxx
add r2.xy, -r1.xyxx, r2.xyxx
mad r0.yw, r2.xxxy, r0.yyyy, r1.xxxy
add r1.xy, -r1.xyxx, r1.zwzz
mad r0.yz, r1.xxyx, r0.zzzz, r0.yywy
add r0.yz, r0.yyzy, l(0.000000, 1.000000, 1.000000, 0.000000)
mul r1.x, r0.y, l(0.500000)
mad r0.y, -r0.z, l(0.500000), l(1.000000)
mad r1.z, cb0[1].y, r0.y, cb0[1].x
sample r1.xyzw, r1.xzxx, t1.xyzw, s1
mov o0.xyz, r1.xyzx
mov o0.w, r0.x
ret 
// Approximately 50 instruction slots used
#endif

const BYTE g_PS[] =
{
     68,  88,  66,  67, 220,  10, 
    241,  92, 220,   3, 157, 164, 
     15, 146, 113,  14,  27, 103, 
    166,   1,   1,   0,   0,   0, 
     48,  13,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    144,   3,   0,   0, 244,   4, 
      0,   0,  40,   5,   0,   0, 
    180,  12,   0,   0,  82,  68, 
     69,  70,  84,   3,   0,   0, 
      1,   0,   0,   0,  40,   2, 
      0,   0,  11,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
     33,   3,   0,   0, 124,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    134,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 148,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 163,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    185,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 200,   1,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 210,   1, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    224,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   2,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 239,   1,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,   5,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      4,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
     20,   2,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 103,  95, 115,  97, 
    109, 112, 108, 101, 114,   0, 
    103,  95,  98,  97,  99, 107, 
     83,  97, 109, 112, 108, 101, 
    114,   0, 103,  95,  97, 108, 
    112, 104,  97,  83,  97, 109, 
    112, 108, 101, 114,   0, 103, 
     95, 117, 118,  68, 105, 115, 
    116, 111, 114, 116, 105, 111, 
    110,  83,  97, 109, 112, 108, 
    101, 114,   0, 103,  95,  98, 
    108, 101, 110, 100,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    103,  95, 116, 101, 120, 116, 
    117, 114, 101,   0, 103,  95, 
     98,  97,  99, 107,  84, 101, 
    120, 116, 117, 114, 101,   0, 
    103,  95,  97, 108, 112, 104, 
     97,  84, 101, 120, 116, 117, 
    114, 101,   0, 103,  95, 117, 
    118,  68, 105, 115, 116, 111, 
    114, 116, 105, 111, 110,  84, 
    101, 120, 116, 117, 114, 101, 
      0, 103,  95,  98, 108, 101, 
    110, 100,  84, 101, 120, 116, 
    117, 114, 101,   0,  80,  83, 
     95,  67, 111, 110, 115, 116, 
     97, 110,  66, 117, 102, 102, 
    101, 114,   0, 171, 171, 171, 
     20,   2,   0,   0,   5,   0, 
      0,   0,  64,   2,   0,   0, 
     80,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    184,   2,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0, 192,   2, 
      0,   0,   0,   0,   0,   0, 
    208,   2,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0, 192,   2, 
      0,   0,   0,   0,   0,   0, 
    224,   2,   0,   0,  32,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0, 192,   2, 
      0,   0,   0,   0,   0,   0, 
    243,   2,   0,   0,  48,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0, 192,   2, 
      0,   0,   0,   0,   0,   0, 
     10,   3,   0,   0,  64,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0, 192,   2, 
      0,   0,   0,   0,   0,   0, 
    103,  95, 115,  99,  97, 108, 
    101,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    109,  85,  86,  73, 110, 118, 
    101, 114, 115, 101, 100,  66, 
     97,  99, 107,   0, 102,  70, 
    108, 105, 112,  98, 111, 111, 
    107,  80,  97, 114,  97, 109, 
    101, 116, 101, 114,   0, 102, 
     85,  86,  68, 105, 115, 116, 
    111, 114, 116, 105, 111, 110, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0, 102,  66, 
    108, 101, 110, 100,  84, 101, 
    120, 116, 117, 114, 101,  80, 
     97, 114,  97, 109, 101, 116, 
    101, 114,   0,  77, 105,  99, 
    114, 111, 115, 111, 102, 116, 
     32,  40,  82,  41,  32,  72, 
     76,  83,  76,  32,  83, 104, 
     97, 100, 101, 114,  32,  67, 
    111, 109, 112, 105, 108, 101, 
    114,  32,  57,  46,  50,  57, 
     46,  57,  53,  50,  46,  51, 
     49,  49,  49,   0, 171, 171, 
     73,  83,  71,  78,  92,   1, 
      0,   0,  13,   0,   0,   0, 
      8,   0,   0,   0,  64,   1, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  76,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   3,   0,   0,  76,   1, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     12,  12,   0,   0,  76,   1, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     15,   0,   0,   0,  76,   1, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,  11,   0,   0,  76,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
     15,  11,   0,   0,  76,   1, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
     15,  11,   0,   0,  85,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,  11,   0,   0,  76,   1, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
      3,   3,   0,   0,  76,   1, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
     12,  12,   0,   0,  76,   1, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   1,   0,   0,  76,   1, 
      0,   0,   9,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
      6,   6,   0,   0,  76,   1, 
      0,   0,  10,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   8,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  67,  79,  76,  79,  82, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171, 
     83,  72,  68,  82, 132,   7, 
      0,   0,  64,   0,   0,   0, 
    225,   1,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   1,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   2,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   3,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   4,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   1,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      2,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   3,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   4,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3, 178,  16,  16,   0, 
      3,   0,   0,   0,  98,  16, 
      0,   3, 178,  16,  16,   0, 
      4,   0,   0,   0,  98,  16, 
      0,   3, 178,  16,  16,   0, 
      5,   0,   0,   0,  98,  16, 
      0,   3, 178,  16,  16,   0, 
      6,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      7,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      7,   0,   0,   0,  98,  16, 
      0,   3,  18,  16,  16,   0, 
      8,   0,   0,   0,  98,  16, 
      0,   3,  98,  16,  16,   0, 
      8,   0,   0,   0,  98,  16, 
      0,   3, 130,  16,  16,   0, 
      8,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   5,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   7,   0, 
      0,   0,  70, 126,  16,   0, 
      3,   0,   0,   0,   0,  96, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   4,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7,  66,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     58,  16,  16,   0,   6,   0, 
      0,   0,  49,   0,   0,   8, 
     66,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  31,   0, 
      4,   3,  42,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
    150,  21,  16,   0,   8,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   8, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  50,   0, 
      0,  10, 178,   0,  16,   0, 
      0,   0,   0,   0,  70,  12, 
     16,   0,   0,   0,   0,   0, 
     70,  28,  16,   0,   6,   0, 
      0,   0,  70,   8,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
    178,   0,  16,   0,   0,   0, 
      0,   0,   6,  16,  16,   0, 
      8,   0,   0,   0,  70,  12, 
     16,   0,   0,   0,   0,   0, 
     70,   8,  16,   0,   2,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   2,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70,   3, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  21,   0,   0,   1, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
    230,  10,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      2,   0,   0,   0,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  29,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16,   0,   8,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  13,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     13,   0,   4,   3,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
    230,  26,  16,   0,   7,   0, 
      0,   0,  70, 126,  16,   0, 
      4,   0,   0,   0,   0,  96, 
     16,   0,   4,   0,   0,   0, 
     56,   0,   0,   7,  98,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   1,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   8, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     50,   0,   0,   9, 194,   0, 
     16,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,   6,   4,  16,   0, 
      2,   0,   0,   0,  86,   9, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,   9,  50,   0, 
     16,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10,  50,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      2,   0,   0,   0,  24,   0, 
      0,  11, 242,   0,  16,   0, 
      4,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,  64,   0,   0,  64,  64, 
     56,   0,   0,   7,  98,   0, 
     16,   0,   0,   0,   0,   0, 
     86,   6,  16,   0,   0,   0, 
      0,   0,   6,   1,  16,   0, 
      2,   0,   0,   0,  55,   0, 
      0,   9,  98,   0,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   4,   0,   0,   0, 
     86,   6,  16,   0,   0,   0, 
      0,   0,   6,   1,  16,   0, 
      2,   0,   0,   0,  55,   0, 
      0,   9,  98,   0,  16,   0, 
      0,   0,   0,   0, 166,  10, 
     16,   0,   4,   0,   0,   0, 
      6,   1,  16,   0,   1,   0, 
      0,   0,  86,   6,  16,   0, 
      0,   0,   0,   0,  55,   0, 
      0,   9,  98,   0,  16,   0, 
      0,   0,   0,   0,  86,   5, 
     16,   0,   4,   0,   0,   0, 
      6,   1,  16,   0,   3,   0, 
      0,   0,  86,   6,  16,   0, 
      0,   0,   0,   0,  55,   0, 
      0,   9,  98,   0,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   4,   0,   0,   0, 
    166,  11,  16,   0,   2,   0, 
      0,   0,  86,   6,  16,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   7,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,  16, 
     16,   0,   5,   0,   0,   0, 
    246,  31,  16,   0,   5,   0, 
      0,   0,  14,   0,   0,   7, 
    194,   0,  16,   0,   1,   0, 
      0,   0,   6,  20,  16,   0, 
      4,   0,   0,   0, 246,  31, 
     16,   0,   4,   0,   0,   0, 
     14,   0,   0,   7,  50,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  16,  16,   0,   3,   0, 
      0,   0, 246,  31,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  15,  98,   0,  16,   0, 
      0,   0,   0,   0,  86,   6, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  64,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0,   0,   0,  56,   0, 
      0,   7,  98,   0,  16,   0, 
      0,   0,   0,   0,  86,   6, 
     16,   0,   0,   0,   0,   0, 
      6,  17,  16,   0,   6,   0, 
      0,   0,  56,   0,   0,   8, 
     98,   0,  16,   0,   0,   0, 
      0,   0,  86,   6,  16,   0, 
      0,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   8,  50,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9, 162,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   4,  16,   0,   2,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,   6,   4, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8,  50,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
    230,  10,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,   9, 
     98,   0,  16,   0,   0,   0, 
      0,   0,   6,   1,  16,   0, 
      1,   0,   0,   0, 166,  10, 
     16,   0,   0,   0,   0,   0, 
     86,   7,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
     98,   0,  16,   0,   0,   0, 
      0,   0,  86,   6,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,  50,   0, 
      0,  10,  34,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,  11, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0, 134,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   1,   0, 
      0,   0,   0,  96,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   5, 114,  32,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 130,  32, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 116,   0, 
      0,   0,  50,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,  12,   0,   0,   0, 
     19,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
