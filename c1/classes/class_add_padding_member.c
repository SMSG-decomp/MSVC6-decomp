void __cdecl class_add_padding_member(uint size)

{
  uint *puVar1;
  uchar *puVar2;
  void *name;
  uint unused;
  c1_symbol *pcVar3;
  fe_arena *a;
  uint uVar4;
  uint uVar5;
  c1_symbol *pcVar6;
  
  name = g_name_alignment_member;
  unused = -(uint)(g_block_depth != '\0') & 2;
  if ((unused == 0) &&
     (puVar1 = g_symbol_free_lists[g_symbol_size_class_table[3]], puVar1 != (uint *)0x0)) {
    g_symbol_free_lists[g_symbol_size_class_table[3]] = (uint *)puVar1[1];
    pcVar3 = (c1_symbol *)(puVar1 + -2);
    *puVar1 = 0;
    puVar1[1] = 0;
    uVar5 = g_symbol_size_table[3];
    pcVar6 = pcVar3;
    for (uVar4 = g_symbol_size_table[3] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
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
    pcVar3->kind = pcVar3->kind & 0xe3 | 3;
    if (pcVar3 != (c1_symbol *)0x0) goto LAB_10610307;
  }
  a = g_arenas + unused;
  uVar5 = g_symbol_size_table[3] + 3;
  pcVar3 = (c1_symbol *)a->cur;
  puVar2 = g_arenas[unused].end;
  a->cur = &pcVar3->kind + (uVar5 & 0xfffffffc);
  if (puVar2 < &pcVar3->kind + (uVar5 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pcVar3 == (c1_symbol *)0x0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = sym_init_kind(pcVar3,'\x03',name,unused);
  }
LAB_10610307:
  pcVar3->flags1 = pcVar3->flags1 | 0x40;
  pcVar3->detail = (void *)size;
  class_append_member(pcVar3);
  g_struct_layouts[g_class_depth].offset = g_struct_layouts[g_class_depth].offset + size;
  return;
}

