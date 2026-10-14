void __cdecl class_new_member_symbol(c1_type *type)

{
  char cVar1;
  uint *puVar2;
  c1_type *pcVar3;
  byte bVar4;
  c1_symbol *pcVar5;
  void *pvVar6;
  int iVar7;
  c1_symbol *pcVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  uint *member_link;
  
  (g_struct_layouts[g_class_depth].tag)->flags4 = (g_struct_layouts[g_class_depth].tag)->flags4 | 2;
  pvVar6 = g_name_alignment_member;
  pcVar5 = sym_take_free_record(3,g_name_alignment_member,0);
  if (pcVar5 == (c1_symbol *)0x0) {
    pcVar5 = arena_alloc(g_arenas,g_symbol_size_table[3] + 3 & 0xfffffffc);
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = (c1_symbol *)0x0;
    }
    else {
      pcVar5 = sym_init_kind(pcVar5,'\x03',pvVar6,0);
    }
  }
  pcVar5->flags1 = pcVar5->flags1 | 0x40;
  pcVar5->type = type;
  pcVar5->flags4 = pcVar5->flags4 | 8;
  pvVar6 = (void *)class_check_zero_sized_array_member(pcVar5);
  pcVar8 = (type->extra).sym;
  pcVar5->detail = pvVar6;
  bVar9 = (g_struct_layouts[g_class_depth].tag)->flags4;
  (g_struct_layouts[g_class_depth].tag)->flags4 = (pcVar8->flags4 ^ bVar9) & 1 ^ bVar9;
  if ((pcVar8->tag_alignment & 0x100) == 0) {
    cVar1 = (char)type->code;
    pcVar3 = type;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    if ((pcVar3->code & 0x20f) == 0x203) goto LAB_10611132;
    bVar9 = 0;
  }
  else {
LAB_10611132:
    bVar9 = 1;
  }
  (g_struct_layouts[g_class_depth].tag)->alignment =
       (ushort)bVar9 << 8 | (g_struct_layouts[g_class_depth].tag)->alignment & 0xfeff;
  class_append_member(pcVar5);
  if (pcVar8->tag_members == (void *)0x0) {
    member_link = (uint *)0x0;
  }
  else {
    member_link = *(uint **)((int)pcVar8->tag_members + 4);
  }
  for (; member_link != (uint *)0x0; member_link = (uint *)member_link[1]) {
    pcVar5 = (c1_symbol *)(member_link + -2);
    bVar9 = (byte)member_link[-2] & 0x1f;
    if ((((bVar9 != 0xf) && (bVar4 = pcVar5->kind & 0x1f, bVar4 != 0x11)) && (bVar4 != 8)) &&
       ((bVar9 != 4 && (iVar7 = class_check_member_redefinition((void *)*member_link), iVar7 == 0)))
       ) {
      pcVar8 = arena_alloc(g_arenas,g_symbol_size_table[pcVar5->kind & 0x1f] + 3 & 0xfffffffc);
      if (pcVar8 == (c1_symbol *)0x0) {
        pcVar5 = (c1_symbol *)0x0;
      }
      else {
        pcVar5 = sym_copy_unlinked(pcVar8,pcVar5,0);
      }
      class_append_member(pcVar5);
      if ((((g_struct_layouts[g_class_depth].flags & 1) != 0) &&
          (pcVar5->name != g_name_alignment_member)) && ((pcVar5->flags4 & 0x18) == 0)) {
        pcVar5->detail = (void *)((int)pcVar5->detail + (int)pvVar6);
      }
    }
    if (member_link == (uint *)0x0) break;
  }
  pvVar6 = g_name_alignment_member;
  puVar2 = g_symbol_free_lists[g_symbol_size_class_table[3]];
  if (puVar2 != (uint *)0x0) {
    pcVar5 = (c1_symbol *)(puVar2 + -2);
    g_symbol_free_lists[g_symbol_size_class_table[3]] = (uint *)puVar2[1];
    *puVar2 = 0;
    puVar2[1] = 0;
    uVar11 = g_symbol_size_table[3];
    pcVar8 = pcVar5;
    for (uVar10 = g_symbol_size_table[3] >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      pcVar8->kind = '\0';
      pcVar8->flags1 = '\0';
      pcVar8->flags2 = '\0';
      pcVar8->flags3 = '\0';
      pcVar8 = (c1_symbol *)&pcVar8->flags4;
    }
    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      pcVar8->kind = '\0';
      pcVar8 = (c1_symbol *)&pcVar8->flags1;
    }
    *puVar2 = (uint)pvVar6;
    pcVar5->kind = pcVar5->kind & 0xe3 | 3;
    if (pcVar5 != (c1_symbol *)0x0) goto LAB_106111c0;
  }
  pcVar5 = arena_alloc(g_arenas,g_symbol_size_table[3] + 3 & 0xfffffffc);
  if (pcVar5 == (c1_symbol *)0x0) {
    pcVar5 = (c1_symbol *)0x0;
  }
  else {
    pcVar5 = sym_init_kind(pcVar5,'\x03',pvVar6,0);
  }
LAB_106111c0:
  pcVar5->flags1 = pcVar5->flags1 | 0x40;
  pcVar5->type = type;
  pcVar5->flags4 = pcVar5->flags4 | 0x10;
  class_append_member(pcVar5);
  g_struct_layouts[g_class_depth].bitfield_type = 0;
  return;
}

