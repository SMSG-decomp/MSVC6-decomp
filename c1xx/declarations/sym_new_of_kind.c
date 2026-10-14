c1_symbol * __cdecl sym_new_of_kind(c1_u8 kind,fe_name *name,int arena)

{
  fe_name **sym_link;
  c1_u32 cVar1;
  c1_u8 *pcVar2;
  c1_symbol *pcVar3;
  c1_arena *a;
  
  if (arena == 0) {
    if ((c1_sym_link *)g_symbol_free_lists[g_symbol_size_class_table[kind]] != (c1_sym_link *)0x0) {
      pcVar3 = sym_new_of_kind_free_list_fragment
                         ((uint)kind * 4,
                          (c1_sym_link *)g_symbol_free_lists[g_symbol_size_class_table[kind]],kind,
                          g_symbol_size_class_table[kind],name,0);
      return pcVar3;
    }
  }
  cVar1 = g_symbol_size_table[kind];
  a = g_arenas + arena;
  pcVar3 = (c1_symbol *)a->cur;
  pcVar2 = g_arenas[arena].end;
  a->cur = &pcVar3->kind + (cVar1 + 3 & 0xfffffffc);
  if (pcVar2 < &pcVar3->kind + (cVar1 + 3 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pcVar3 != (c1_symbol *)0x0) {
    pcVar3->kind = (pcVar3->kind ^ kind) & 0x1f ^ pcVar3->kind;
    if (kind == '\x04') {
      sym_link = &pcVar3->name;
      if (sym_link != (fe_name **)0x0) {
        *sym_link = name;
        pcVar3->next = (c1_symbol *)0x0;
        sym_tag_set_member_list(sym_link,(c1_sym_list *)0x0);
        return pcVar3;
      }
    }
    else if ((kind < 0x10) || (0x11 < kind)) {
      if (&pcVar3->name != (fe_name **)0x0) {
        pcVar3->name = name;
        pcVar3->next = (c1_symbol *)0x0;
        return pcVar3;
      }
    }
    else if (&pcVar3->name != (fe_name **)0x0) {
      pcVar3->name = name;
      pcVar3->next = (c1_symbol *)0x0;
      pcVar3->type = (c1_type *)0x0;
    }
    return pcVar3;
  }
  return (c1_symbol *)0x0;
}

