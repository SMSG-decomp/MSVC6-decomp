c1_symbol * __cdecl sym_new_builtin(void *name,void *seg_class,uint id,c1_u8 cls)

{
  uint *puVar1;
  c1_scope_stack *pcVar2;
  c1_symbol *pcVar3;
  uint uVar4;
  uint uVar5;
  c1_symbol *pcVar6;
  
  puVar1 = g_symbol_free_lists[g_symbol_size_class_table[0xe]];
  if (puVar1 != (uint *)0x0) {
    g_symbol_free_lists[g_symbol_size_class_table[0xe]] = (uint *)puVar1[1];
    pcVar3 = (c1_symbol *)(puVar1 + -2);
    *puVar1 = 0;
    puVar1[1] = 0;
    uVar5 = g_symbol_size_table[0xe];
    pcVar6 = pcVar3;
    for (uVar4 = g_symbol_size_table[0xe] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      pcVar6->kind = '\0';
      pcVar6->flags1 = '\0';
      pcVar6->flags2 = '\0';
      pcVar6->flags3 = '\0';
      pcVar6 = (c1_symbol *)&pcVar6->flags4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      pcVar6->kind = '\0';
      pcVar6 = (c1_symbol *)&pcVar6->flags1;
    }
    *puVar1 = (uint)name;
    pcVar3->kind = pcVar3->kind & 0xee | 0xe;
    if (pcVar3 != (c1_symbol *)0x0) goto LAB_10611f04;
  }
  pcVar3 = arena_alloc(g_arenas,g_symbol_size_table[0xe] + 3 & 0xfffffffc);
  if (pcVar3 == (c1_symbol *)0x0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = sym_init_kind(pcVar3,'\x0e',name,0);
  }
LAB_10611f04:
  pcVar3->entity = (pcVar3->entity ^ id) & 0xffffff ^ pcVar3->entity;
  if (id < 0x15) {
    pcVar3->key_ref = id << 3 | pcVar3->key_ref & 7;
  }
  (pcVar3->x28).bytes.bit_position = cls;
  pcVar3->type = g_type_segment;
  pcVar3->detail = seg_class;
  pcVar2 = g_current_scope;
  if ((name != (void *)0x0) && (name != g_name_unnamed)) {
    if ((c1_sym_link *)g_current_scope->unk210 != (c1_sym_link *)0x0) {
      pcVar3->next = (c1_sym_link *)g_current_scope->unk210;
    }
    pcVar2->unk210 = (c1_u32)&pcVar3->name;
  }
  return pcVar3;
}

