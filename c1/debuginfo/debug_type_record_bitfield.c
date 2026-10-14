int __cdecl debug_type_record_bitfield(c1_symbol *sym)

{
  ushort *puVar1;
  c1_u32 cVar2;
  int iVar3;
  
  puVar1 = g_cv_record_body;
  cVar2 = debug_type_index(sym->type);
  *puVar1 = 0x1205;
  *(c1_u8 *)(puVar1 + 3) = (sym->x28).bytes.depth;
  *(c1_u8 *)((int)puVar1 + 7) = (sym->x28).bytes.bit_position;
  *(c1_u32 *)(puVar1 + 1) = cVar2;
  iVar3 = cvserver_emit_type(8);
  return iVar3;
}

