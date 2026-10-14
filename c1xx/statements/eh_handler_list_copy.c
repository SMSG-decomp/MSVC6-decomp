c1_arg_list * __thiscall eh_handler_list_copy(c1_arg_list *list,c1_arg_list *src)

{
  byte bVar1;
  c1_u8 *pcVar2;
  byte bVar3;
  c1_arg_item *pcVar4;
  c1_arg_item *pcVar5;
  
  list->first = (c1_arg_item *)0x0;
  list->last = (c1_arg_item *)0x0;
  pcVar5 = src->first;
  if ((src->flags & 1) != 0) {
    list->flags = list->flags | 1;
  }
  do {
    pcVar4 = (c1_arg_item *)g_arenas[0].cur;
    pcVar2 = g_arenas[0].cur;
    if ((pcVar5->kind & 3) == 0) {
      g_arenas[0].cur = g_arenas[0].cur + 0x14;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar4 == (c1_arg_item *)0x0) {
LAB_104b897b:
        pcVar4 = (c1_arg_item *)0x0;
      }
      else {
        pcVar2[4] = '\0';
        pcVar2[5] = '\0';
        pcVar2[6] = '\0';
        pcVar2[7] = '\0';
        pcVar2[8] = '\0';
        pcVar2[9] = '\0';
        pcVar2[10] = '\0';
        pcVar2[0xb] = '\0';
        bVar3 = (pcVar5->kind ^ *(byte *)((int)pcVar4 + 0xc)) & 3 ^ *(byte *)((int)pcVar4 + 0xc);
        *(byte *)((int)pcVar4 + 0xc) = bVar3;
        bVar1 = pcVar5->kind;
        pcVar4->vtbl = &PTR_pch_mark_object_links_104ca9b4;
        *(byte *)((int)pcVar4 + 0xc) = (bVar1 ^ bVar3) & 4 ^ bVar3;
        *(c1_arg_value *)((int)pcVar4 + 0x10) = pcVar5->value;
        pcVar4->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
      }
    }
    else {
      g_arenas[0].cur = g_arenas[0].cur + 0x14;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar4 == (c1_arg_item *)0x0) goto LAB_104b897b;
      pcVar2[4] = '\0';
      pcVar2[5] = '\0';
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
      pcVar2[8] = '\0';
      pcVar2[9] = '\0';
      pcVar2[10] = '\0';
      pcVar2[0xb] = '\0';
      bVar3 = (pcVar5->kind ^ *(byte *)((int)pcVar4 + 0xc)) & 3 ^ *(byte *)((int)pcVar4 + 0xc);
      *(byte *)((int)pcVar4 + 0xc) = bVar3;
      bVar1 = pcVar5->kind;
      pcVar4->vtbl = &PTR_pch_mark_object_links_104ca9b4;
      *(byte *)((int)pcVar4 + 0xc) = (bVar1 ^ bVar3) & 4 ^ bVar3;
      *(c1_arg_value *)((int)pcVar4 + 0x10) = pcVar5->value;
      pcVar4->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
    }
    if (list->first == (c1_arg_item *)0x0) {
      list->first = pcVar4;
    }
    else {
      list->last->next = pcVar4;
      pcVar4->prev = list->last;
    }
    list->last = pcVar4;
    pcVar5 = pcVar5->next;
    if (pcVar5 == (c1_arg_item *)0x0) {
      return list;
    }
  } while( true );
}

