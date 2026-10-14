c1_u32 __cdecl debug_type_record_enum_forward(c1_symbol *sym)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  c1_u32 cVar4;
  
  puVar2 = g_cv_record_body;
  cVar4 = sym->type->debug_index;
  if (cVar4 == 0) {
    free_list_push_124c(sym);
    sym->flags1 = sym->flags1 & 0xfd;
    *puVar2 = 0x1007;
    puVar2[1] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[2] = (ushort)g_cv_zero_attributes;
    uVar1 = (ushort)g_cv_zero_attributes;
    puVar2[2] = uVar1 | 0x80;
    puVar2[2] = (ushort)((sym->tag_alignment & 0x200) >> 6) | uVar1 & 0xfff7 | 0x80;
    iVar3 = debug_put_symbol_name((char *)(puVar2 + 7),sym);
    cVar4 = cvserver_emit_type(iVar3 + 0xe);
    sym->type->debug_index = cVar4;
    free_list_pop_124c();
  }
  return cVar4;
}

