ushort __cdecl debug_field_vbclass_body(int pass,ushort *out,c1_symbol *base,c1_type *type)

{
  char cVar1;
  c1_type *pcVar2;
  c1_symbol *pcVar3;
  ushort uVar4;
  ushort uVar5;
  int local_4;
  
  pcVar3 = base;
  class_virtual_base_info(base,(c1_symbol *)type,(int *)&base,&local_4,&type);
  if (pass != 1) {
    uVar4 = pdb_numeric_leaf(out + 6,(uint)base,(int)base >> 0x1f);
    *(c1_u32 *)(out + 2) = pcVar3->type->debug_index;
    *(c1_u32 *)(out + 4) = type->debug_index;
    cVar1 = (char)type->code;
    pcVar2 = type;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    uVar5 = debug_cv_unsigned_numeric_leaf
                      ((ushort *)(uVar4 + 0xc + (int)out),
                       local_4 / (int)(char)(&g_type_rank_table)[(byte)pcVar2->code & 0xf],
                       local_4 / (int)(char)(&g_type_rank_table)[(byte)pcVar2->code & 0xf] >> 0x1f);
    return uVar5 + 0xc + uVar4;
  }
  debug_type_index(pcVar3->type);
  debug_type_index(type);
  return 0;
}

