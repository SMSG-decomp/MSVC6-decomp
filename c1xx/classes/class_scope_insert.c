void __thiscall class_scope_insert(c1xx_class_scope *class_scope,c1_symbol *sym2)

{
  c1_type *pcVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  c1_symbol *sym;
  c1xx_scope *pcVar5;
  c1_symbol *pcVar6;
  int iVar7;
  
  sym = sym_insert_check_alias(sym2);
  if (sym != (c1_symbol *)0x0) {
    if ((class_scope->kind == 0) || (0xf8 < class_scope->kind)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    sym->flags3 = cVar3 << 3 | sym->flags3 & 0xf7;
    if (g_class_depth < 0) {
      pcVar5 = scope_innermost_declaration_record(g_current_scope,'\x01');
      (*pcVar5->vtbl->insert)(sym);
      return;
    }
    if ((sym->flags21 & 4) == 0) {
      pcVar1 = sym->type;
      cVar3 = (char)pcVar1->code;
      while (cVar3 < '\0') {
        pcVar1 = pcVar1->base;
        cVar3 = (char)pcVar1->code;
      }
      if ((pcVar1->code & 0x300) == 0) {
        pcVar6 = (c1_symbol *)0x0;
      }
      else {
        pcVar6 = (pcVar1->extra).cls;
      }
      bVar4 = (pcVar6->flags3 ^ sym->flags3) & 8 ^ sym->flags3;
      sym->flags3 = bVar4;
      if (((bVar4 & 8) == 0) && (g_il_block_level != '\0')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if ((g_c9il_mode == '\0') && (bVar2)) {
        cVar3 = '\x01';
      }
      else {
        cVar3 = '\0';
      }
      sym->flags3 = cVar3 << 4 | bVar4 & 0xef;
      if ((cVar3 != '\0') && (iVar7 = (*g_idb->vtbl->idb_note_global_il_record)(g_idb), iVar7 == 0))
      {
        diag_fatal(0x49,"p1inl.inl",0x2ee);
      }
      class_append_member(sym);
    }
  }
  return;
}

