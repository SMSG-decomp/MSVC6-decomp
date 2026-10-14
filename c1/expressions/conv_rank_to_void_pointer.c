int __cdecl conv_rank_to_void_pointer(int rank,c1_type *to_layer,c1_type *from_layer)

{
  int iVar1;
  
  if (((from_layer == (c1_type *)0x0) || ((to_layer->code & 0x8f) != 0x82)) ||
     (iVar1 = 0x100, (char)to_layer->base->code < '\0')) {
    iVar1 = rank;
  }
  return iVar1;
}

