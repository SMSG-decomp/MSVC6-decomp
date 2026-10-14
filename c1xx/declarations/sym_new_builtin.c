c1_symbol * __cdecl sym_new_builtin(void *name,void *seg_class,uint id,c1_u8 cls)

{
  c1_scope_stack *pcVar1;
  c1_u32 cVar2;
  c1_symbol *pcVar3;
  uint uVar4;
  c1_symbol *pcVar5;
  int *free_cell;
  
  free_cell = (int *)g_symbol_free_lists[g_symbol_size_class_table[0xe]];
  if (free_cell != (int *)0x0) {
    g_symbol_free_lists[g_symbol_size_class_table[0xe]] = (uint *)free_cell[1];
    pcVar3 = (c1_symbol *)(free_cell + -2);
    *free_cell = 0;
    free_cell[1] = 0;
    cVar2 = g_symbol_size_table[0xe];
    pcVar5 = pcVar3;
    for (uVar4 = g_symbol_size_table[0xe] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      pcVar5->kind = '\0';
      pcVar5->flags1 = '\0';
      pcVar5->flags2 = '\0';
      pcVar5->flags3 = '\0';
      pcVar5 = (c1_symbol *)&pcVar5->flags4;
    }
    for (uVar4 = cVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      pcVar5->kind = '\0';
      pcVar5 = (c1_symbol *)&pcVar5->flags1;
    }
    *free_cell = (int)name;
    pcVar3->kind = pcVar3->kind & 0xee | 0xe;
    if (pcVar3 != (c1_symbol *)0x0) goto LAB_1044bc3e;
  }
  pcVar3 = arena_alloc(g_arenas,g_symbol_size_table[0xe] + 3 & 0xfffffffc);
  if (pcVar3 == (c1_symbol *)0x0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = sym_init_kind(pcVar3,'\x0e',name,0);
  }
LAB_1044bc3e:
  pcVar3->entity = (pcVar3->entity ^ id) & 0xffffff ^ pcVar3->entity;
  if (id < 0x15) {
    pcVar3->key_ref = id << 3 | pcVar3->key_ref & 7;
  }
  (pcVar3->x28).bytes.bit_position = cls;
  pcVar3->type = g_type_segment;
  (pcVar3->detail).ptr = seg_class;
  pcVar1 = g_current_scope;
  if ((name != (void *)0x0) && (name != g_name_unnamed)) {
    if (g_current_scope->segments != (c1_symbol *)0x0) {
      pcVar3->next = g_current_scope->segments;
    }
    pcVar1->segments = &pcVar3->name;
  }
  return pcVar3;
}

