int __cdecl debug_type_record_member(int pass,c1_symbol *member,ushort *out)

{
  c1_u32 cVar1;
  uint uVar2;
  int iVar3;
  
  if (pass != 1) {
    *out = 0x1405;
    out[1] = (ushort)g_cv_zero_attributes;
    out[1] = (ushort)g_cv_zero_attributes | 3;
    if ((member->kind & 0x1f) == 2) {
      uVar2 = *g_debug_index_queue;
      g_debug_index_queue = g_debug_index_queue + 1;
    }
    else {
      uVar2 = member->type->debug_index;
    }
    *(uint *)(out + 2) = uVar2;
    uVar2 = pdb_numeric_leaf(out + 4,(uint)member->detail,(int)member->detail >> 0x1f);
    iVar3 = debug_identifier_length((char *)((uVar2 & 0xffff) + 8 + (int)out),member->name->text);
    return iVar3 + 8 + (uVar2 & 0xffff);
  }
  if ((member->kind & 0x1f) != 2) {
    cVar1 = debug_type_index(member->type);
    return cVar1 & 0xffff0000;
  }
  uVar2 = debug_type_record_bitfield(member);
  *g_debug_index_queue = uVar2;
  g_debug_index_queue = g_debug_index_queue + 1;
  return (uint)g_debug_index_queue & 0xffff0000;
}

