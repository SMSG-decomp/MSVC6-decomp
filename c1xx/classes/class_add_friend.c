void __cdecl class_add_friend(c1_symbol *cls,c1xx_decl_specifiers *spec,c1_symbol *friend_sym)

{
  uint uVar1;
  c1_symbol *pcVar2;
  c1_u8 *rec;
  byte bVar3;
  c1_u16 cVar4;
  c1_line_map_row *pcVar5;
  c1_symbol *sym;
  c1_symbol *sym_00;
  
  if (friend_sym == (c1_symbol *)0x0) {
    if ((spec->type->code & 0x200) == 0) {
      return;
    }
    sym = (spec->type->extra).cls;
  }
  else {
    func_parse_definition_or_skip(friend_sym,'\x01');
    sym = friend_sym;
  }
  if (((((sym->kind & 0x1f) != 4) || (spec->insert_fn == (void *)0x0)) || (sym->scope_index == 0))
     || (((g_scope_vector->entries[(short)sym->scope_index]->kind & 0x1f) != 4 ||
         (pcVar2 = g_class_def_stack[g_class_depth].cls,
         g_scope_vector->entries[(short)sym->scope_index] != pcVar2)))) goto LAB_1041da2b;
  if (pcVar2->scope_index == 0) {
    sym->scope_index = 0;
    goto LAB_1041da2b;
  }
  sym_00 = g_scope_vector->entries[(short)pcVar2->scope_index];
  bVar3 = sym_00->kind & 0x1f;
  if (bVar3 == 4) {
    cVar4 = pcVar2->scope_index;
    do {
      pcVar2 = g_scope_vector->entries[(short)cVar4];
      cVar4 = pcVar2->scope_index;
      if (cVar4 == 0) break;
    } while ((g_scope_vector->entries[(short)cVar4]->kind & 0x1f) == 4);
    if (pcVar2->scope_index == 0) {
      sym_00 = pcVar2;
    }
    else {
LAB_1046d3ab:
      friend_sym._0_1_ = '\a';
    }
  }
  else {
    if (bVar3 != 0x19) goto LAB_1046d3ab;
    friend_sym._0_1_ = '\x19';
  }
  if (sym_00 != (c1_symbol *)0x0) {
    if ((char)friend_sym == '\x1c') {
      sym_inherit_scope_index(sym,&sym_00->kind);
    }
    else if ((char)friend_sym == '\x04') {
      sym->scope_index = ((sym_00->detail).cls)->scope_index;
    }
    else if ((char)friend_sym == '\x19') {
      sym->scope_index = *(c1_u16 *)&sym_00->type->base;
    }
    else if (((char)friend_sym == '\a') || ((char)friend_sym == '\b')) {
      if ((sym_00->x28).block_number == 0) {
        scope_vector_add(sym_00,'\a');
      }
      sym->scope_index = (sym_00->x28).block_number;
      if ((sym->kind & 0x1f) == 4) {
        ((sym->detail).cls)->unk38 = g_block_number;
      }
    }
  }
LAB_1041da2b:
  ((cls->detail).cls)->layout_flags3b = ((cls->detail).cls)->layout_flags3b | 0x40;
  rec = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0xc;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  uVar1 = cls->entity;
  rec[8] = '\0';
  rec[9] = '\0';
  rec[10] = '\0';
  rec[0xb] = '\0';
  *(c1_symbol **)(rec + 4) = sym;
  *(uint *)rec = uVar1 & 0xffffff;
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar5 = &g_line_map_cached_row;
  }
  else {
    pcVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  (*g_idb->vtbl->idb_scope_kind2_to_3)
            (g_idb,CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                            (short)pcVar5->line - (short)pcVar5->position) + g_token_position,
             g_macro_expansion_depth);
  class_friend_table_add(rec);
  return;
}

