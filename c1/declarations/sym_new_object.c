c1_symbol * __cdecl sym_new_object(void *name,char level)

{
  c1_symbol *pcVar1;
  c1_u8 *pcVar2;
  byte bVar3;
  uint uVar4;
  
  if (level == '\0') {
    pcVar1 = sym_take_free_record(10,name,0);
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = arena_alloc(g_arenas,g_symbol_size_table[10] + 3 & 0xfffffffc);
      if (pcVar1 != (c1_symbol *)0x0) {
        pcVar1 = sym_init_kind(pcVar1,'\n',name,0);
        pcVar2 = &pcVar1->storage;
        bVar3 = pcVar1->storage & 0xf8 ^ 1;
        goto LAB_10634a7e;
      }
      pcVar1 = (c1_symbol *)0x0;
    }
    pcVar2 = &pcVar1->storage;
    bVar3 = pcVar1->storage & 0xf8 ^ 1;
  }
  else {
    pcVar1 = sym_take_free_record(10,name,2);
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = arena_alloc(g_arenas + 2,g_symbol_size_table[10] + 3 & 0xfffffffc);
      if (pcVar1 == (c1_symbol *)0x0) {
        pcVar1 = (c1_symbol *)0x0;
      }
      else {
        pcVar1 = sym_init_kind(pcVar1,'\n',name,2);
      }
    }
    pcVar2 = &pcVar1->storage;
    bVar3 = pcVar1->storage & 0xf8 ^ 4;
  }
LAB_10634a7e:
  *pcVar2 = bVar3;
  *(undefined4 *)pcVar2 = 0;
  *pcVar2 = (*pcVar2 ^ bVar3 & 7) & 7 ^ *pcVar2;
  if (0x7ffffffe < g_next_entity_id) {
    diag_fatal_simple(0x37);
  }
  uVar4 = pcVar1->entity ^ g_next_entity_id;
  g_next_entity_id = g_next_entity_id + 1;
  pcVar1->entity = uVar4 & 0xffffff ^ pcVar1->entity;
  pcVar1->key_ref = pcVar1->key_ref & 0xfffffff8;
  pcVar1->type = g_type_int;
  g_symbol_scope_level = level;
  if (level == '\0') {
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,pcVar1);
    return pcVar1;
  }
  (*g_current_scope->current->vtbl->insert)(g_current_scope->current,pcVar1);
  return pcVar1;
}

