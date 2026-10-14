c1_arg_list * __cdecl tmpl_header_take_parameter_list(void)

{
  c1_node *pcVar1;
  c1_arg_value cVar2;
  c1_u8 *pcVar3;
  byte bVar4;
  c1_arg_item *item;
  c1_arg_item *pcVar5;
  c1_arg_list *local_4;
  
  if (g_paren_level_arg_lists[g_paren_depth + 1] == (c1_arg_list *)0x0) {
    return (c1_arg_list *)0x0;
  }
  pcVar5 = g_paren_level_arg_lists[g_paren_depth + 1]->first;
  local_4 = (c1_arg_list *)0x0;
  if (pcVar5 != (c1_arg_item *)0x0) {
    item = (c1_arg_item *)0x0;
    do {
      pcVar3 = g_arenas[0].cur;
      bVar4 = pcVar5->kind & 3;
      if (bVar4 == 1) {
        pcVar1 = (pcVar5->value).expr;
        if (pcVar1->left == (void *)0x0) {
          item = arena_alloc(g_arenas,0x10);
          if (item == (c1_arg_item *)0x0) goto LAB_104b848a;
          tmpl_list_item_construct(item,2,0);
          item->vtbl = &PTR_pch_mark_object_links_104cf060;
        }
        else {
          item = arena_alloc(g_arenas,0x14);
          if (item == (c1_arg_item *)0x0) {
LAB_104b848a:
            item = (c1_arg_item *)0x0;
          }
          else {
            cVar2 = (c1_arg_value)pcVar1->left;
            tmpl_list_item_construct(item,1,(pcVar5->kind & 4) == 4);
            item->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
            item->value = cVar2;
          }
        }
      }
      else if (bVar4 == 0) {
        g_arenas[0].cur = g_arenas[0].cur + 0x14;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (pcVar3 == (c1_u8 *)0x0) goto LAB_104b848a;
        bVar4 = pcVar5->kind;
        cVar2 = pcVar5->value;
        pcVar3[4] = '\0';
        pcVar3[5] = '\0';
        pcVar3[6] = '\0';
        pcVar3[7] = '\0';
        pcVar3[8] = '\0';
        pcVar3[9] = '\0';
        pcVar3[10] = '\0';
        pcVar3[0xb] = '\0';
        pcVar3[0xc] = ((bVar4 & 4) == 4) << 2 | pcVar3[0xc] & 0xf8;
        *(c1_arg_value *)(pcVar3 + 0x10) = cVar2;
        *(undefined ***)pcVar3 = &PTR_pch_fixup_list_object_104c4c3c;
        item = (c1_arg_item *)pcVar3;
      }
      else if (bVar4 == 2) {
        g_arenas[0].cur = g_arenas[0].cur + 0x10;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (pcVar3 == (c1_u8 *)0x0) goto LAB_104b848a;
        pcVar3[4] = '\0';
        pcVar3[5] = '\0';
        pcVar3[6] = '\0';
        pcVar3[7] = '\0';
        pcVar3[8] = '\0';
        pcVar3[9] = '\0';
        pcVar3[10] = '\0';
        pcVar3[0xb] = '\0';
        pcVar3[0xc] = pcVar3[0xc] & 0xf8 ^ 2;
        *(undefined ***)pcVar3 = &PTR_pch_mark_object_links_104cf060;
        item = (c1_arg_item *)pcVar3;
      }
      pcVar3 = g_arenas[0].cur;
      if (local_4 == (c1_arg_list *)0x0) {
        g_arenas[0].cur = g_arenas[0].cur + 0xc;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (pcVar3 == (c1_u8 *)0x0) {
          local_4 = (c1_arg_list *)0x0;
        }
        else {
          *(c1_arg_item **)pcVar3 = item;
          *(c1_arg_item **)(pcVar3 + 4) = item;
          local_4 = (c1_arg_list *)pcVar3;
          pcVar3[8] = (pcVar3[8] ^ item->kind >> 3 & 1) & 1 ^ pcVar3[8];
        }
      }
      else {
        local_4->last->next = item;
        item->prev = local_4->last;
        local_4->last = item;
        if ((item->kind & 8) != 0) {
          local_4->flags = local_4->flags | 1;
        }
      }
      pcVar5 = pcVar5->next;
    } while (pcVar5 != (c1_arg_item *)0x0);
  }
  g_paren_level_arg_lists[g_paren_depth + 1] = (c1_arg_list *)0x0;
  return local_4;
}

