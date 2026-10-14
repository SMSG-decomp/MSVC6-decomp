uint __cdecl debug_field_stmember(int pass,c1_symbol *member,ushort *out)

{
  c1_u32 cVar1;
  int iVar2;
  
  if (pass == 1) {
    cVar1 = debug_type_index(member->type);
    return cVar1 & 0xffff0000;
  }
  *out = 0x1406;
  *(c1_u32 *)(out + 2) = member->type->debug_index;
  out[1] = (ushort)g_cv_zero_attributes;
  out[1] = (ushort)(member->flags2 & 3) | (ushort)g_cv_zero_attributes & 0xfffc;
  iVar2 = debug_identifier_length((byte *)(out + 4),member->name->text);
  return iVar2 + 8;
}

