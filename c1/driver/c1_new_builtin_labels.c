void __cdecl c1_new_builtin_labels(void)

{
  uint *puVar1;
  void *name;
  c1_symbol *pcVar2;
  uint uVar3;
  uint uVar4;
  c1_symbol *pcVar5;
  
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
  pcVar2->detail = (void *)0x0;
  g_builtin_label_1->type = g_type_none;
  g_builtin_label_1->flags3 = g_builtin_label_1->flags3 | 0x20;
  g_builtin_label_1->flags1 = g_builtin_label_1->flags1 | 1;
  g_builtin_label_1->entity = g_builtin_label_1->entity & 0xff000001 | 1;
  g_builtin_label_1->key_ref = g_builtin_label_1->key_ref & 7 | 8;
  name = g_name_local_size;
  puVar1 = g_symbol_free_lists[g_symbol_size_class_table[9]];
  if (puVar1 != (uint *)0x0) {
    g_symbol_free_lists[g_symbol_size_class_table[9]] = (uint *)puVar1[1];
    pcVar2 = (c1_symbol *)(puVar1 + -2);
    *puVar1 = 0;
    puVar1[1] = 0;
    uVar4 = g_symbol_size_table[9];
    pcVar5 = pcVar2;
    for (uVar3 = g_symbol_size_table[9] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar5->kind = '\0';
      pcVar5->flags1 = '\0';
      pcVar5->flags2 = '\0';
      pcVar5->flags3 = '\0';
      pcVar5 = (c1_symbol *)&pcVar5->flags4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      pcVar5->kind = '\0';
      pcVar5 = (c1_symbol *)&pcVar5->flags1;
    }
    *puVar1 = (uint)name;
    pcVar2->kind = pcVar2->kind & 0xe9 | 9;
    if (pcVar2 != (c1_symbol *)0x0) goto LAB_106159c8;
  }
  pcVar2 = arena_alloc(g_arenas,g_symbol_size_table[9] + 3 & 0xfffffffc);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = sym_init_kind(pcVar2,'\t',name,0);
  }
LAB_106159c8:
  g_builtin_label_10 = pcVar2;
  pcVar2->type = g_type_none;
  g_builtin_label_10->entity = g_builtin_label_10->entity & 0xff00000a | 10;
  g_builtin_label_10->key_ref = g_builtin_label_10->key_ref & 7 | 0x50;
  g_builtin_label_10->flags3 = g_builtin_label_10->flags3 | 0x20;
  g_builtin_label_10->flags1 = g_builtin_label_10->flags1 | 1;
  g_builtin_label_10->kind = g_builtin_label_10->kind | 0x20;
  return;
}

