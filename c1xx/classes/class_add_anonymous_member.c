void __cdecl class_add_anonymous_member(c1_type *type)

{
  c1_u32 *sym;
  char cVar1;
  c1_class_record *pcVar2;
  uint *puVar3;
  c1_type *pcVar4;
  void *pvVar5;
  c1_u32 cVar6;
  c1_u8 *dst;
  byte bVar7;
  c1_symbol *pcVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  c1_sym_link *pcVar12;
  c1_symbol *pcVar13;
  c1_class_record *local_4;
  
  (g_class_def_stack[g_class_depth].cls)->flags5 =
       (g_class_def_stack[g_class_depth].cls)->flags5 | 2;
  pvVar5 = g_name_alignment_member;
  pcVar8 = sym_take_free_record(3,g_name_alignment_member,0);
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar8 = arena_alloc(g_arenas,g_symbol_size_table[3] + 3 & 0xfffffffc);
    if (pcVar8 == (c1_symbol *)0x0) {
      pcVar8 = (c1_symbol *)0x0;
    }
    else {
      pcVar8 = sym_init_kind(pcVar8,'\x03',pvVar5,0);
    }
  }
  pcVar8->flags3 = pcVar8->flags3 | 1;
  pcVar8->type = type;
  pcVar8->flags5 = pcVar8->flags5 | 8;
  pcVar8->flags2 = (g_class_def_stack[g_class_depth].flags ^ pcVar8->flags2) & 3 ^ pcVar8->flags2;
  iVar9 = sym_is_static_data_member(pcVar8);
  if (iVar9 == 0) {
    local_4 = (c1_class_record *)class_check_zero_sized_array_member(pcVar8);
  }
  else {
    local_4 = (c1_class_record *)0x0;
  }
  pcVar13 = (type->extra).cls;
  (pcVar8->detail).cls = local_4;
  bVar10 = (g_class_def_stack[g_class_depth].cls)->flags5;
  (g_class_def_stack[g_class_depth].cls)->flags5 = (pcVar13->flags5 ^ bVar10) & 1 ^ bVar10;
  if ((((pcVar13->detail).cls)->layout_flags3b & 1) == 0) {
    cVar1 = (char)type->code;
    pcVar4 = type;
    while (cVar1 < '\0') {
      pcVar4 = pcVar4->base;
      cVar1 = (char)pcVar4->code;
    }
    if ((pcVar4->code & 0x20f) == 0x203) goto LAB_1044ec77;
    bVar10 = 0;
  }
  else {
LAB_1044ec77:
    bVar10 = 1;
  }
  pcVar2 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
  bVar7 = pcVar2->layout_flags3b;
  pcVar2->layout_flags3b = (bVar7 ^ bVar10) & 1 ^ bVar7;
  class_append_member(pcVar8);
  if ((pcVar13->x28).members == (c1_sym_list *)0x0) {
    pcVar12 = (c1_sym_link *)0x0;
  }
  else {
    pcVar12 = ((pcVar13->x28).members)->head;
  }
  for (; pcVar12 != (c1_sym_link *)0x0; pcVar12 = pcVar12->next) {
    sym = &pcVar12[-1].position;
    bVar10 = (byte)pcVar12[-1].position & 0x1f;
    if ((((bVar10 != 0xf) && (bVar7 = (byte)*sym & 0x1f, bVar7 != 0x11)) && (bVar7 != 8)) &&
       ((bVar10 != 4 &&
        (pcVar8 = class_current_member_lookup(pcVar12->name), dst = g_arenas[0].cur,
        pcVar8 == (c1_symbol *)0x0)))) {
      if ((g_class_depth < 0) || (pcVar12->name != (g_class_def_stack[g_class_depth].cls)->name)) {
        g_arenas[0].cur =
             g_arenas[0].cur + (g_symbol_size_table[(byte)*sym & 0x1f] + 3 & 0xfffffffc);
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (dst == (c1_u8 *)0x0) {
          pcVar8 = (c1_symbol *)0x0;
        }
        else {
          pcVar8 = sym_copy_unlinked((c1_symbol *)dst,(c1_symbol *)sym,0);
        }
        class_append_member(pcVar8);
        if ((((g_class_def_stack[g_class_depth].flags & 8) != 0) &&
            (pcVar8->name != g_name_alignment_member)) && ((pcVar8->flags5 & 0x18) == 0)) {
          (pcVar8->detail).cls =
               (c1_class_record *)((int)&local_4->size + (int)&((pcVar8->detail).cls)->size);
        }
        pcVar8->flags2 =
             (g_class_def_stack[g_class_depth].flags ^ pcVar8->flags2) & 3 ^ pcVar8->flags2;
      }
      else {
        diag_error(0x1cb,sym);
      }
    }
    if (pcVar12 == (c1_sym_link *)0x0) break;
  }
  pvVar5 = g_name_alignment_member;
  puVar3 = g_symbol_free_lists[g_symbol_size_class_table[3]];
  if (puVar3 != (uint *)0x0) {
    pcVar8 = (c1_symbol *)(puVar3 + -2);
    g_symbol_free_lists[g_symbol_size_class_table[3]] = (uint *)puVar3[1];
    *puVar3 = 0;
    puVar3[1] = 0;
    cVar6 = g_symbol_size_table[3];
    pcVar13 = pcVar8;
    for (uVar11 = g_symbol_size_table[3] >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      pcVar13->kind = '\0';
      pcVar13->flags1 = '\0';
      pcVar13->flags2 = '\0';
      pcVar13->flags3 = '\0';
      pcVar13 = (c1_symbol *)&pcVar13->flags4;
    }
    for (uVar11 = cVar6 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      pcVar13->kind = '\0';
      pcVar13 = (c1_symbol *)&pcVar13->flags1;
    }
    *puVar3 = (uint)pvVar5;
    pcVar8->kind = pcVar8->kind & 0xe3 | 3;
    if (pcVar8 != (c1_symbol *)0x0) goto LAB_1044ed00;
  }
  pcVar8 = arena_alloc(g_arenas,g_symbol_size_table[3] + 3 & 0xfffffffc);
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar8 = (c1_symbol *)0x0;
  }
  else {
    pcVar8 = sym_init_kind(pcVar8,'\x03',pvVar5,0);
  }
LAB_1044ed00:
  pcVar8->flags3 = pcVar8->flags3 | 1;
  pcVar8->type = type;
  pcVar8->flags5 = pcVar8->flags5 | 0x10;
  pcVar8->flags2 = (g_class_def_stack[g_class_depth].flags ^ pcVar8->flags2) & 3 ^ pcVar8->flags2;
  class_append_member(pcVar8);
  g_class_def_stack[g_class_depth].bitfield_type = 0;
  return;
}

