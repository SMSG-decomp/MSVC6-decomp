c1_symbol * __cdecl expr_uuidof_guid_symbol(fe_name *name,c1_guid *guid)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  c1_symbol *pcVar2;
  c1_type *type;
  c1_u8 *item;
  c1_u32 *spec;
  c1_decl_record cStack_4c;
  
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar1 != (c1_lookup_entry *)0x0) {
      return pcVar1->sym;
    }
  }
  pcVar2 = sym_new_object(name,'\0');
  spec = g_default_decl_specifiers;
  pcVar2->flags1 = pcVar2->flags1 & 0xfe | 2;
  pcVar2->storage = pcVar2->storage | 0x40;
  pcVar2->flags3 = pcVar2->flags3 | 1;
  type = expr_guid_object_type();
  decl_record_init(&cStack_4c,type,spec);
  decl_finish_declarator(&cStack_4c);
  pcVar2->type = cStack_4c.type;
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0xc;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (item == (c1_u8 *)0x0) {
    item = (c1_u8 *)0x0;
  }
  else {
    *(c1_symbol **)item = pcVar2;
    *(c1_guid **)(item + 4) = guid;
    item[8] = '\0';
  }
  if (PTR_104d1b4c == (c1_vector *)0x0) {
    PTR_104d1b4c = vector_new(0,0);
  }
  vector_push(PTR_104d1b4c,item);
  return pcVar2;
}

