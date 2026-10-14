int __cdecl debug_emit_symbol_type_2(c1_symbol *sym)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  short sVar4;
  c1_u32 cVar5;
  
  puVar3 = g_cv_record_body;
  cVar5 = sym->type->debug_index;
  if (cVar5 == 0) {
    free_list_push_124c(sym);
    sym->flags2 = sym->flags2 & 0xf7;
    *puVar3 = 0x1007;
    puVar3[1] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[2] = (ushort)g_cv_zero_attributes;
    uVar1 = (ushort)g_cv_zero_attributes;
    puVar3[2] = uVar1 | 0x80;
    uVar2 = (ushort)(((sym->detail).cls)->layout_flags3b >> 1 & 1) << 3;
    puVar3[2] = uVar2 | uVar1 & 0xfff7 | 0x80;
    puVar3[2] = (ushort)(((sym->detail).cls)->flags3e >> 7) << 8 | uVar2 | uVar1 & 0xfef7 | 0x80;
    sVar4 = debug_identifier_length_of_type((byte *)(puVar3 + 7),sym);
    cVar5 = cvserver_emit_type(sVar4 + 0xe);
    sym->type->debug_index = cVar5;
    free_list_pop_124c();
  }
  return cVar5;
}

