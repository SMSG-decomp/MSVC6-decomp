c1_symbol * __cdecl sym_new_object(void *name,char local)

{
  byte bVar1;
  c1_symbol *pcVar2;
  c1_u8 *pcVar3;
  uint uVar4;
  
  if (local == '\0') {
    pcVar2 = sym_take_free_record(10,name,0);
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = arena_alloc(g_arenas,g_symbol_size_table[10] + 3 & 0xfffffffc);
      if (pcVar2 != (c1_symbol *)0x0) {
        pcVar2 = sym_init_kind(pcVar2,'\n',name,0);
        pcVar3 = &pcVar2->storage;
        *pcVar3 = pcVar2->storage & 0xf8 ^ 1;
        goto LAB_1044819c;
      }
      pcVar2 = (c1_symbol *)0x0;
    }
    pcVar3 = &pcVar2->storage;
    *pcVar3 = pcVar2->storage & 0xf8 ^ 1;
  }
  else {
    pcVar2 = sym_take_free_record(10,name,4);
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = arena_alloc(g_arenas + 4,g_symbol_size_table[10] + 3 & 0xfffffffc);
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar2 = (c1_symbol *)0x0;
      }
      else {
        pcVar2 = sym_init_kind(pcVar2,'\n',name,4);
      }
    }
    pcVar3 = &pcVar2->storage;
    *pcVar3 = pcVar2->storage & 0xf8 ^ 4;
    if (local == '\x01') {
      local = '\0';
    }
  }
LAB_1044819c:
  bVar1 = *pcVar3;
  *(undefined4 *)pcVar3 = 0;
  *pcVar3 = (*pcVar3 ^ bVar1 & 7) & 7 ^ *pcVar3;
  if (0x7ffffffe < g_next_entity_id) {
    diag_fatal_simple(0x37);
  }
  uVar4 = pcVar2->entity ^ g_next_entity_id;
  g_next_entity_id = g_next_entity_id + 1;
  pcVar2->entity = uVar4 & 0xffffff ^ pcVar2->entity;
  pcVar2->key_ref = pcVar2->key_ref & 0xfffffff8;
  pcVar2->type = g_type_int;
  g_symbol_scope_level = local;
  if (local == '\0') {
    (*g_current_scope->global_scope->vtbl->insert)(pcVar2);
    return pcVar2;
  }
  (*g_current_scope->current->vtbl->insert)(pcVar2);
  return pcVar2;
}

