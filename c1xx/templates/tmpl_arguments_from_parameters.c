c1_arg_list * __cdecl tmpl_arguments_from_parameters(c1_sym_list *params)

{
  c1_arg_value cVar1;
  c1_u8 *pcVar2;
  c1_sym_link *pcVar3;
  c1_arg_item *pcVar4;
  c1_arg_list *pcVar5;
  uint param_value;
  
  pcVar5 = (c1_arg_list *)0x0;
  pcVar4 = (c1_arg_item *)g_arenas[0].cur;
  if (params == (c1_sym_list *)0x0) {
    pcVar3 = (c1_sym_link *)0x0;
  }
  else {
    pcVar3 = params->head;
  }
  do {
    if (pcVar3 == (c1_sym_link *)0x0) {
      g_arenas[0].cur = (c1_u8 *)pcVar4;
      return pcVar5;
    }
    if ((pcVar3[-1].position & 0x1f) == 0x16) {
      g_arenas[0].cur = (c1_u8 *)(pcVar4 + 1);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar4 == (c1_arg_item *)0x0) {
LAB_104b82b0:
        pcVar4 = (c1_arg_item *)0x0;
      }
      else {
        param_value = *(uint *)&pcVar3->type;
        pcVar4->next = (c1_arg_item *)0x0;
        pcVar4->prev = (c1_arg_item *)0x0;
        pcVar4->kind = pcVar4->kind & 0xf8;
        pcVar4->value = (c1_arg_value)param_value;
        pcVar4->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
      }
    }
    else {
      g_arenas[0].cur = (c1_u8 *)(pcVar4 + 1);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar4 == (c1_arg_item *)0x0) goto LAB_104b82b0;
      cVar1 = (c1_arg_value)pcVar3[2].next;
      pcVar4->next = (c1_arg_item *)0x0;
      pcVar4->prev = (c1_arg_item *)0x0;
      pcVar4->kind = pcVar4->kind & 0xf8 ^ 1;
      pcVar4->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
      pcVar4->value = cVar1;
    }
    pcVar2 = g_arenas[0].cur;
    if (pcVar5 == (c1_arg_list *)0x0) {
      g_arenas[0].cur = g_arenas[0].cur + 0xc;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar2 == (c1_u8 *)0x0) {
        pcVar5 = (c1_arg_list *)0x0;
      }
      else {
        *(c1_arg_item **)pcVar2 = pcVar4;
        *(c1_arg_item **)(pcVar2 + 4) = pcVar4;
        pcVar2[8] = (pcVar2[8] ^ pcVar4->kind >> 3 & 1) & 1 ^ pcVar2[8];
        pcVar5 = (c1_arg_list *)pcVar2;
      }
    }
    else {
      pcVar5->last->next = pcVar4;
      pcVar4->prev = pcVar5->last;
      pcVar5->last = pcVar4;
      if ((pcVar4->kind & 8) != 0) {
        pcVar5->flags = pcVar5->flags | 1;
      }
    }
    if (pcVar3 == (c1_sym_link *)0x0) {
      return pcVar5;
    }
    pcVar3 = pcVar3->next;
    pcVar4 = (c1_arg_item *)g_arenas[0].cur;
  } while( true );
}

