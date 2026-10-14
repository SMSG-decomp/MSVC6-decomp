void __cdecl pragma_alloc_text_name(fe_name *name)

{
  byte bVar1;
  c1_scope_lookup *pcVar2;
  void *pvVar3;
  c1_symbol *sym;
  short n;
  
  pcVar2 = (*g_current_scope->file_scope->vtbl->lookup)(g_current_scope->file_scope,(int)name);
  if (pcVar2 == (c1_scope_lookup *)0x0) {
    sym = (c1_symbol *)0x0;
  }
  else {
    sym = pcVar2->sym;
  }
  if (sym == (c1_symbol *)0x0) {
    diag_error(0x9d,name);
  }
  else {
    if ((sym->flags23 & 1) == 0) {
      if ((g_compile_flags_c4 & 0x10000) == 0) {
        if ((sym->kind & 0x1f) != 10) {
          sym->flags2 = sym->flags2 | 1;
          diag_error(0x9e,sym);
          return;
        }
        if ((sym->storage & 7) != 1) {
          sym->flags2 = sym->flags2 | 1;
          diag_error(0xb2,sym);
          return;
        }
      }
      else {
        bVar1 = sym->kind & 0x1f;
        if ((bVar1 == 7) || (bVar1 == 8)) {
          if ((sym->flags1 & 1) == 0) goto LAB_106383bf;
          n = 200;
        }
        else {
          n = 0x3f;
        }
        diag_error(n,sym);
      }
LAB_106383bf:
      sym_set_segment_checked(sym,g_alloc_text_segment);
      return;
    }
    pvVar3 = sym_segment_record(sym);
    if (pvVar3 != g_alloc_text_segment) {
      diag_error(0xc1,sym);
      return;
    }
  }
  return;
}

