c1_symbol * __cdecl sym_new_kind12(void)

{
  fe_name *name;
  c1_symbol *pcVar1;
  byte bVar2;
  uint uVar3;
  
  name = g_name_formal;
  pcVar1 = sym_take_free_record(0xc,g_name_formal,0);
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = arena_alloc(g_arenas,g_symbol_size_table[0xc] + 3 & 0xfffffffc);
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = (c1_symbol *)0x0;
    }
    else {
      pcVar1 = sym_init_kind(pcVar1,'\f',name,0);
    }
  }
  bVar2 = pcVar1->storage & 0xf8 ^ 4;
  pcVar1->storage = bVar2;
  pcVar1->storage = '\0';
  pcVar1->flags21 = '\0';
  pcVar1->flags22 = '\0';
  pcVar1->flags23 = '\0';
  pcVar1->storage = (pcVar1->storage ^ bVar2 & 7) & 7 ^ pcVar1->storage;
  if (g_next_entity_id < 0x7fffffff) {
    uVar3 = pcVar1->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar1->entity = uVar3 & 0xffffff ^ pcVar1->entity;
    pcVar1->flags3 = pcVar1->flags3 | 8;
    pcVar1->type = g_type_void;
    return pcVar1;
  }
  diag_fatal_simple(0x37);
}

