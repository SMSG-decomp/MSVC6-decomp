void __cdecl c1xx_new_builtin_labels(void)

{
  void *name;
  c1_u32 cVar1;
  c1_symbol *pcVar2;
  uint uVar3;
  c1_symbol *pcVar4;
  int *free_cell;
  
  pcVar2 = sym_take_free_record(9,(void *)0x0,0);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = arena_alloc(g_arenas,g_symbol_size_table[9] + 3 & 0xfffffffc);
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = (c1_symbol *)0x0;
    }
    else {
      pcVar2 = sym_init_kind(pcVar2,'\t',(void *)0x0,0);
    }
  }
  g_builtin_label_1 = pcVar2;
  (pcVar2->detail).cls = (c1_class_record *)0x0;
  g_builtin_label_1->type = g_type_none;
  g_builtin_label_1->flags4 = g_builtin_label_1->flags4 | 0x20;
  g_builtin_label_1->flags2 = g_builtin_label_1->flags2 | 4;
  g_builtin_label_1->entity = g_builtin_label_1->entity & 0xff000001 | 1;
  g_builtin_label_1->key_ref = g_builtin_label_1->key_ref & 7 | 8;
  name = g_name_local_size;
  free_cell = (int *)g_symbol_free_lists[g_symbol_size_class_table[9]];
  if (free_cell != (int *)0x0) {
    g_symbol_free_lists[g_symbol_size_class_table[9]] = (uint *)free_cell[1];
    pcVar2 = (c1_symbol *)(free_cell + -2);
    *free_cell = 0;
    free_cell[1] = 0;
    cVar1 = g_symbol_size_table[9];
    pcVar4 = pcVar2;
    for (uVar3 = g_symbol_size_table[9] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar4->kind = '\0';
      pcVar4->flags1 = '\0';
      pcVar4->flags2 = '\0';
      pcVar4->flags3 = '\0';
      pcVar4 = (c1_symbol *)&pcVar4->flags4;
    }
    for (uVar3 = cVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar4->kind = '\0';
      pcVar4 = (c1_symbol *)&pcVar4->flags1;
    }
    *free_cell = (int)name;
    pcVar2->kind = pcVar2->kind & 0xe9 | 9;
    if (pcVar2 != (c1_symbol *)0x0) goto LAB_1044740b;
  }
  pcVar2 = arena_alloc(g_arenas,g_symbol_size_table[9] + 3 & 0xfffffffc);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = sym_init_kind(pcVar2,'\t',name,0);
  }
LAB_1044740b:
  g_builtin_label_10 = pcVar2;
  pcVar2->type = g_type_none;
  g_builtin_label_10->entity = g_builtin_label_10->entity & 0xff00000a | 10;
  g_builtin_label_10->key_ref = g_builtin_label_10->key_ref & 7 | 0x50;
  g_builtin_label_10->flags4 = g_builtin_label_10->flags4 | 0x20;
  g_builtin_label_10->flags2 = g_builtin_label_10->flags2 | 4;
  g_builtin_label_10->kind = g_builtin_label_10->kind | 0x20;
  g_dynamic_initializer_functions = vector_new(1,0);
  return;
}

