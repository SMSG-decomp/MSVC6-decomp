uint __cdecl debug_field_nesttype(int pass,c1_symbol *member,ushort *out)

{
  c1_u32 cVar1;
  int iVar2;
  
  if (pass == 1) {
    cVar1 = debug_type_index(member->type);
    return cVar1 & 0xffff0000;
  }
  *out = 0x1408;
  out[1] = 0;
  *(c1_u32 *)(out + 2) = member->type->debug_index;
  iVar2 = debug_identifier_length((byte *)(out + 4),member->name->text);
  return iVar2 + 8;
}

