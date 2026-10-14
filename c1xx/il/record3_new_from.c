void * __cdecl record3_new_from(int *src,int arena)

{
  c1_u8 *pcVar1;
  
  pcVar1 = record3_new(*src,src[1],src[2],arena);
  return pcVar1;
}

