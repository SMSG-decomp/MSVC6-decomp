void __thiscall decl_apply_declspec_based_fragment(c1_type *layer,int *rec,int zero)

{
  c1_type *pcVar1;
  
  pcVar1 = type_this_pointer(*(c1_symbol **)(rec[2] + 8),0x20,(ushort)zero);
  type_function_with_return(layer,pcVar1);
  *(byte *)&layer->code = (byte)layer->code | 0x85;
  pcVar1 = (c1_type *)rec[2];
  if ((pcVar1->code & 0x8f) == 0x83) {
    pcVar1 = type_skip_arrays(pcVar1->base);
  }
  if ((pcVar1->flags & 8) != 0) {
    diag_error(0xd4);
    *(byte *)(rec + 0xf) = *(byte *)(rec + 0xf) | 1;
    *(ushort *)(rec[2] + 2) = *(ushort *)(rec[2] + 2) & 0xffe7;
  }
  return;
}

