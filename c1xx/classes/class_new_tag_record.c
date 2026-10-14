c1_symbol * __cdecl class_new_tag_record(void *name,c1_u16 type_code)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1_type_extra sym;
  c1_symbol *sym_00;
  c1_type *pcVar3;
  uint uVar4;
  c1_type local_10;
  
  sym.cls = sym_take_free_record(4,(void *)0x0,0);
  if (sym.cls == (c1_symbol *)0x0) {
    sym_00 = arena_alloc(g_arenas,g_symbol_size_table[4] + 3 & 0xfffffffc);
    if (sym_00 == (c1_symbol *)0x0) {
      sym.cls = (c1_symbol *)0x0;
    }
    else {
      sym.cls = sym_init_kind(sym_00,'\x04',(void *)0x0,0);
    }
  }
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x48;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  ((sym.cls)->detail).cls = (c1_class_record *)pcVar1;
  if (((g_compile_flags_c4 & 0x20000) == 0) && (g_pch_precomp_types == 0)) {
    bVar2 = (sym.cls)->flags2 | 8;
  }
  else {
    bVar2 = (sym.cls)->flags2 & 0xf7;
  }
  (sym.cls)->flags2 = bVar2;
  if (0x7ffffffe < g_next_entity_id) {
    diag_fatal_simple(0x37);
  }
  uVar4 = (sym.cls)->entity ^ g_next_entity_id;
  g_next_entity_id = g_next_entity_id + 1;
  (sym.cls)->entity = uVar4 & 0xffffff ^ (sym.cls)->entity;
  (sym.cls)->flags2 = (sym.cls)->flags2 | 0x10;
  (sym.cls)->flags3 = (sym.cls)->flags3 & 0xf7;
  (sym.cls)->flags1 = (sym.cls)->flags1 & 0xfc;
  (((sym.cls)->detail).cls)->flags3e = (((sym.cls)->detail).cls)->flags3e | 1;
  scope_vector_add(sym.cls,'\x04');
  local_10.base = (c1_type *)0x0;
  (((sym.cls)->detail).cls)->gm_name_index = 0;
  local_10.debug_index = 0;
  local_10.flags = 0;
  (((sym.cls)->detail).cls)->pm_model = (((sym.cls)->detail).cls)->pm_model & 0xf8;
  local_10.code = type_code;
  local_10.extra = sym;
  pcVar3 = type_intern(&local_10);
  (sym.cls)->type = pcVar3;
  (sym.cls)->name = name;
  class_check_member_pointer_representation(sym.cls);
  if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym.cls);
    (*g_il_emitter->vtbl->mark_definition)(1,(int)name);
    (*g_il_emitter->vtbl->reference_symbol)(sym.count);
  }
  return sym.cls;
}

