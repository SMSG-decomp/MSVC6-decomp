uint __cdecl il_symbol_key_assign(c1_symbol *sym)

{
  c1_pdb_namemap *pThis;
  c1_symbol *sym_00;
  byte bVar1;
  uint uVar2;
  char *sz;
  int iVar3;
  
  sym_00 = sym;
  if (((sym->flags3 & 8) != 0) &&
     ((((bVar1 = sym->kind & 0x1f, bVar1 == 0 || (0xe < bVar1)) || (bVar1 == 5)) ||
      ((bVar1 = sym->storage & 7, bVar1 != 1 && (bVar1 != 2)))))) {
    if (g_c9il_mode == '\0') {
      if (g_next_local_key < 0x3f0000) {
        diag_error(0x143,g_current_function);
        local_keys_reset();
        uVar2 = 0;
      }
      else {
        uVar2 = g_next_local_key;
        g_next_local_key = g_next_local_key - 1;
      }
    }
    else {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar2 = g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
    }
    sym_00->key_ref = sym_00->key_ref & 7 | uVar2 * 8;
    return uVar2 & 0x1fffffff;
  }
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 != 4) &&
     (((bVar1 == 0 || (0xe < bVar1)) || ((bVar1 == 5 || ((sym->storage & 7) != 7)))))) {
    if ((sym->name != (fe_name *)0x0) && (sym->name != g_name_unnamed)) {
      pThis = g_pdb_gi->namemap;
      if ((sym->scope_index == 0) ||
         ((g_scope_vector->entries[(short)sym->scope_index]->kind & 0x1f) != 0x19)) {
LAB_1047dc26:
        sz = decorate_name(sym_00,(c1_symbol *)0x0);
      }
      else {
        uVar2 = decorate_symbol_codes(sym);
        if (uVar2 != 0) goto LAB_1047dc26;
        sz = sym_format_scope_key_name(sym_00,g_scope_vector->entries[(short)sym_00->scope_index]);
        if (sz == (char *)0x0) goto LAB_1047dc26;
      }
      sym = (c1_symbol *)0x0;
      iVar3 = (*pThis->vtbl->get_ni)(pThis,sz,(ulong *)&sym);
      if (iVar3 == 0) {
LAB_1047dc7e:
        diag_fatal_simple(0x37);
      }
      uVar2 = (int)sym * 8 + 0xa8;
      sym_00->key_ref = uVar2 ^ sym_00->key_ref & 7;
      uVar2 = uVar2 >> 3;
      if (g_max_namemap_key <= uVar2) {
        g_max_namemap_key = uVar2;
      }
      if (g_next_global_key < g_max_namemap_key) goto LAB_1047dc7e;
      goto LAB_1047dca1;
    }
    sym->key_ref = sym->key_ref & 7 | g_next_global_key * 8;
    g_next_global_key = g_next_global_key - 1;
  }
  if (g_next_global_key < g_max_namemap_key) {
    diag_fatal_simple(0x37);
  }
LAB_1047dca1:
  return sym_00->key_ref >> 3;
}

