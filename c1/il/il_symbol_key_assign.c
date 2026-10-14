uint __cdecl il_symbol_key_assign(c1_symbol *sym)

{
  NameMap *this;
  c1_symbol *pcVar1;
  byte bVar2;
  char *sz;
  int iVar3;
  uint uVar4;
  
  pcVar1 = sym;
  if (((sym->flags2 & 2) != 0) &&
     ((((bVar2 = sym->kind & 0x1f, bVar2 == 0 || (0xe < bVar2)) || (bVar2 == 5)) ||
      ((bVar2 = sym->storage & 7, bVar2 != 1 && (bVar2 != 2)))))) {
    if (g_c9il_mode == '\0') {
      if (g_next_local_key < 0x3f0000) {
        diag_error(0x143,g_current_function);
        il_symbol_key_counter_reset();
        uVar4 = 0;
      }
      else {
        uVar4 = g_next_local_key;
        g_next_local_key = g_next_local_key - 1;
      }
    }
    else {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar4 = g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
    }
    pcVar1->key_ref = pcVar1->key_ref & 7 | uVar4 * 8;
    return uVar4 & 0x1fffffff;
  }
  bVar2 = sym->kind & 0x1f;
  if ((bVar2 != 4) &&
     (((bVar2 == 0 || (0xe < bVar2)) || ((bVar2 == 5 || ((sym->storage & 7) != 7)))))) {
    if ((sym->name != (fe_name *)0x0) && (sym->name != g_name_unnamed)) {
      this = g_pdb_gi->name_map;
      sz = decorate_warn_name_truncated(sym);
      sym = (c1_symbol *)0x0;
      iVar3 = (*this->vtbl->getNi)(this,sz,(NI *)&sym);
      if (iVar3 == 0) {
LAB_10639de5:
        diag_fatal_simple(0x37);
      }
      uVar4 = (int)sym * 8 + 0xa8;
      pcVar1->key_ref = uVar4 ^ pcVar1->key_ref & 7;
      uVar4 = uVar4 >> 3;
      if (g_max_namemap_key <= uVar4) {
        g_max_namemap_key = uVar4;
      }
      if (g_next_global_key < g_max_namemap_key) goto LAB_10639de5;
      goto LAB_10639e08;
    }
    sym->key_ref = sym->key_ref & 7 | g_next_global_key * 8;
    g_next_global_key = g_next_global_key - 1;
  }
  if (g_next_global_key < g_max_namemap_key) {
    diag_fatal_simple(0x37);
  }
LAB_10639e08:
  return pcVar1->key_ref >> 3;
}

