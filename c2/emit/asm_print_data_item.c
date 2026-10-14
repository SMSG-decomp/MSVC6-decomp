void __fastcall asm_print_data_item(void *rec)

{
  c2_init *pcVar1;
  c2_init *rec_00;
  c2_fe_symbol *sec;
  int iVar2;
  int iVar3;
  c2_fe_symbol *local_8;
  
  local_8 = fe_symbol_lookup_id(*(uint32_t *)((int)rec + 0x10));
  if (((local_8->cls == '\x04') || (local_8->cls == '\x01')) && ((local_8->storage & 0x1000) != 0))
  {
    local_8 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)local_8);
  }
  sec = fe_symbol_lookup_id(local_8->section_id);
  asm_print_data_label(local_8,*(int *)((int)rec + 0xc),sec);
  pcVar1 = *(c2_init **)((int)rec + 4);
  for (rec_00 = pcVar1; rec_00 != (c2_init *)0x0; rec_00 = rec_00->next) {
    if (rec_00->kind == 0) {
      iVar2 = sec->refcount;
      iVar3 = ((rec_00->u08).header.offset + local_8->offset) - iVar2;
      if (iVar3 != 0) {
        asm_printf("\tORG $%+ld",iVar3);
        g_asm_column = 0;
        asm_printf(g_asm_newline);
        sec->refcount = iVar2 + iVar3;
      }
    }
    else {
      iVar2 = asm_print_init_record(rec_00);
      if (((rec_00 == pcVar1) && (local_8->name != (char *)0x0)) && (*local_8->name == '?')) {
        asm_print_symbol_operand(local_8,1);
      }
      g_asm_column = 0;
      asm_printf(g_asm_newline);
      sec->refcount = sec->refcount + iVar2;
    }
  }
  return;
}

