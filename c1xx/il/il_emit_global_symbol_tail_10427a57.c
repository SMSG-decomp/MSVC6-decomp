void __cdecl il_emit_global_symbol_tail(char mode,c1_symbol *sym,int *symref)

{
  byte bVar1;
  c1_symbol *sym_00;
  c1_u32 position;
  void *pvVar2;
  c1_node *pcVar3;
  int iVar4;
  int n;
  
  if ((*(byte *)(symref + 4) & 3) != 0) goto LAB_10427e10;
  if (mode == '\0') {
    return;
  }
  sym_00 = sym_from_table_entry((int)symref);
  position = sym_decl_position(sym_00);
  diag_begin_global(position);
  bVar1 = sym->kind & 0x1f;
  if (bVar1 != 0xc) {
    if (bVar1 == 0xb) {
      n = 100;
      iVar4 = 4;
    }
    else {
      if (g_il_block_level == '\0') goto LAB_10427e0b;
      if ((*(byte *)(symref + -1) & 4) == 0) {
        n = 0x65;
        iVar4 = 3;
      }
      else {
        n = 0xbd;
        iVar4 = 4;
      }
    }
    diag_warning(iVar4,n,sym);
  }
LAB_10427e0b:
  diag_end_global();
LAB_10427e10:
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 == 7) || (bVar1 == 8)) || (bVar1 == 6)) {
    bVar1 = sym->kind & 0x1f;
    if (((bVar1 == 7) || (bVar1 == 8)) && ((*(byte *)((int)symref + 0x2d) & 2) != 0)) {
      pvVar2 = class_scalar_deleting_dtor_of(sym);
      if ((*(byte *)((int)pvVar2 + 2) & 8) == 0) {
        il_emit_global_symbol((int *)((int)pvVar2 + 8));
      }
      iVar4 = 0x10;
    }
    else {
      iVar4 = 4;
    }
  }
  else {
    bVar1 = sym->kind & 0x1f;
    if (((bVar1 == 0xb) || (bVar1 == 0xc)) && ((*(byte *)((int)symref + -3) & 4) != 0)) {
      pcVar3 = tree_new_symbol_ref(sym,'\0');
      symref[3] = (int)pcVar3->type;
    }
    iVar4 = 1;
  }
  if (g_opt_Zi != '\0') {
    il_emit_symbol_if_needed(symref);
  }
  il_emit_symbol_with_mode(iVar4,(int)symref,mode);
  sym->flags2 = sym->flags2 | 8;
  return;
}

