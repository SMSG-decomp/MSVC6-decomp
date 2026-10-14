void __thiscall decl_append_derived_check_case80_fragment(c1_type *tail,int *rec,c1_type *layer)

{
  c1_type *pcVar1;
  
  tail->code = (c1_u16)CONCAT31((byte)(layer->code >> 8) & 0xe0,0x84);
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

