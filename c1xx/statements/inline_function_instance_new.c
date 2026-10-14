void __cdecl inline_function_instance_new(c1_symbol *sym)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_symbol *pcVar4;
  fe_name *pfVar5;
  int iVar6;
  c1_symbol *value;
  byte bVar7;
  uint uVar8;
  
  if ((sym->kind & 0x1f) == 10) {
    if (g_c9il_mode == '\0') {
      if ((sym->storage & 7) != 3) {
        return;
      }
      iVar6 = func_wants_inline(g_current_function);
      if (((char)iVar6 == '\0') &&
         (pcVar4 = sym_class_needing_init(sym), pcVar4 == (c1_symbol *)0x0)) {
        return;
      }
    }
    else if ((sym->storage & 7) != 3) {
      return;
    }
    pcVar4 = arena_alloc(g_arenas,g_symbol_size_table[sym->kind & 0x1f] + 3 & 0xfffffffc);
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      pcVar4 = sym_copy_unlinked(pcVar4,sym,0);
    }
    (sym->x28).block_number = g_block_number;
    (pcVar4->x28).block_number = g_block_number;
    pcVar4->flags1 = pcVar4->flags1 & 0xfc;
    pfVar5 = name_intern_symbol_decorated(pcVar4);
    pcVar4->name = pfVar5;
    pcVar4->flags1 = pcVar4->flags1 & 0xfe | 2;
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar8 = pcVar4->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar4->entity = uVar8 & 0xffffff ^ pcVar4->entity;
    if ((sym->flags23 & 1) != 0) {
      value = sym_segment_record(sym);
      if (value == (c1_symbol *)0x0) {
        pcVar4->flags23 = pcVar4->flags23 & 0xfe;
      }
      else {
        sym_set_segment(pcVar4,value);
      }
    }
    pcVar4->flags2 = pcVar4->flags2 | 4;
    sym->flags4 = sym->flags4 | 0x40;
    symtab_21f4_insert(sym,pcVar4);
    (*g_current_scope->global_scope->vtbl->insert)(pcVar4);
    if (((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags21 & 1) != 0)) &&
       (((g_current_function->storage & 7) != 3 || ((g_current_function->flags1 & 4) != 0)))) {
      if ((g_current_function->flags22 & 0xc) != 0) {
        bVar7 = (pcVar4->flags22 ^ g_current_function->flags22) & 4 ^ pcVar4->flags22;
        pcVar4->flags22 = bVar7;
        pcVar4->flags22 = (g_current_function->flags22 ^ bVar7) & 8 ^ bVar7;
        cVar1 = pcVar4->flags21;
        cVar2 = pcVar4->flags22;
        cVar3 = pcVar4->flags23;
        sym->storage = pcVar4->storage;
        sym->flags21 = cVar1;
        sym->flags22 = cVar2;
        sym->flags23 = cVar3;
      }
      bVar7 = pcVar4->storage & 0xf8 ^ 2;
      pcVar4->storage = bVar7;
      pcVar4->storage = bVar7 | 0x40;
    }
  }
  return;
}

