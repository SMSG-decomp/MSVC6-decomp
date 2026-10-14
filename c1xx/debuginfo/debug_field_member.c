uint __cdecl debug_field_member(int pass,byte *member,ushort *out)

{
  ushort uVar1;
  c1_u32 cVar2;
  uint uVar3;
  int iVar4;
  
  if (pass != 1) {
    *out = 0x1405;
    out[1] = (ushort)g_cv_zero_attributes;
    out[1] = member[2] & 0xff03 | (ushort)g_cv_zero_attributes & 0xfffc;
    if ((*member & 0x1f) == 2) {
      uVar3 = *g_debug_index_queue;
      g_debug_index_queue = g_debug_index_queue + 1;
    }
    else {
      uVar3 = *(uint *)(*(int *)(member + 0x14) + 0xc);
    }
    *(uint *)(out + 2) = uVar3;
    uVar1 = pdb_numeric_leaf(out + 4,*(uint *)(member + 0x24),(int)*(uint *)(member + 0x24) >> 0x1f)
    ;
    iVar4 = debug_identifier_length
                      ((byte *)(uVar1 + 8 + (int)out),*(char **)(*(int *)(member + 8) + 4));
    return iVar4 + 8 + (uint)uVar1;
  }
  if ((*member & 0x1f) != 2) {
    cVar2 = debug_type_index(*(c1_type **)(member + 0x14));
    return cVar2 & 0xffff0000;
  }
  uVar3 = debug_type_record_bitfield((c1_symbol *)member);
  *g_debug_index_queue = uVar3;
  g_debug_index_queue = g_debug_index_queue + 1;
  return (uint)g_debug_index_queue & 0xffff0000;
}

