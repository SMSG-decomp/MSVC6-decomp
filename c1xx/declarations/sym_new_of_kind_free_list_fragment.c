c1_symbol * __cdecl
sym_new_of_kind_free_list_fragment
          (c1_u32 kind_x4,c1_sym_link *cell,c1_u8 kind,int size_class,fe_name *name,int arena)

{
  fe_name **sym_link;
  c1_u32 cVar1;
  c1_u8 *pcVar2;
  c1_arena *a;
  uint uVar3;
  uint uVar4;
  c1_symbol *pcVar5;
  uint *cursor;
  
  g_symbol_free_lists[size_class] = (uint *)cell->next;
  cell->name = (fe_name *)0x0;
  pcVar5 = (c1_symbol *)&cell[-1].position;
  cell->next = (c1_sym_link *)0x0;
  uVar4 = *(uint *)((int)g_symbol_size_table + kind_x4);
  cursor = (uint *)pcVar5;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *cursor = 0;
    cursor = (uint *)(cursor + 1);
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)cursor = 0;
    cursor = (uint *)((int)cursor + 1);
  }
  cell->name = name;
  *(byte *)pcVar5 = ((byte)*(c1_u32 *)pcVar5 ^ kind) & 0x1f ^ (byte)*(c1_u32 *)pcVar5;
  if (pcVar5 == (c1_symbol *)0x0) {
    cVar1 = g_symbol_size_table[kind];
    a = g_arenas + arena;
    pcVar5 = (c1_symbol *)a->cur;
    pcVar2 = g_arenas[arena].end;
    a->cur = &pcVar5->kind + (cVar1 + 3 & 0xfffffffc);
    if (pcVar2 < &pcVar5->kind + (cVar1 + 3 & 0xfffffffc)) {
      arena_grow(a);
    }
    if (pcVar5 == (c1_symbol *)0x0) {
      return (c1_symbol *)0x0;
    }
    pcVar5->kind = (pcVar5->kind ^ kind) & 0x1f ^ pcVar5->kind;
    if (kind == '\x04') {
      sym_link = &pcVar5->name;
      if (sym_link != (fe_name **)0x0) {
        *sym_link = name;
        pcVar5->next = (c1_symbol *)0x0;
        sym_tag_set_member_list(sym_link,(c1_sym_list *)0x0);
        return pcVar5;
      }
    }
    else if ((kind < 0x10) || (0x11 < kind)) {
      if (&pcVar5->name != (fe_name **)0x0) {
        pcVar5->name = name;
        pcVar5->next = (c1_symbol *)0x0;
        return pcVar5;
      }
    }
    else if (&pcVar5->name != (fe_name **)0x0) {
      pcVar5->name = name;
      pcVar5->next = (c1_symbol *)0x0;
      pcVar5->type = (c1_type *)0x0;
    }
  }
  return pcVar5;
}

