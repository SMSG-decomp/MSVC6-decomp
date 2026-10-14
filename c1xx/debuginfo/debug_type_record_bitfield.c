int __cdecl debug_type_record_bitfield(c1_symbol *member)

{
  ushort *puVar1;
  uint type_index;
  int iVar2;
  
  puVar1 = g_cv_record_body;
  type_index = debug_type_index(member->type);
  *puVar1 = 0x1205;
  *(c1_u8 *)(puVar1 + 3) = (member->x28).bytes.depth;
  *(c1_u8 *)((int)puVar1 + 7) = (member->x28).bytes.bit_position;
  *(uint *)(puVar1 + 1) = type_index;
  iVar2 = cvserver_emit_type(8);
  return iVar2;
}

