c1_tmpl_deduction * __thiscall tmpl_deduction_copy(c1_tmpl_deduction *copy,c1_tmpl_deduction *src)

{
  c1_type *pcVar1;
  c1_arg_list *pcVar2;
  c1_u8 *pcVar3;
  c1_arg_item *item_copy;
  int iVar4;
  c1_arg_item *src_00;
  void *value;
  void *value_2;
  
  copy->tmpl = src->tmpl;
  copy->tparams = src->tparams;
  iVar4 = src->tparam_count;
  copy->flags = copy->flags & 0xe8;
  copy->tparam_count = iVar4;
  copy->args = (c1_arg_list *)0x0;
  pcVar3 = g_arenas[5].cur;
  pcVar1 = copy->tmpl->type;
  iVar4 = **(int **)(*(int *)(((uint)pcVar1 & -(uint)((pcVar1->code & 0x80) != 0)) + 8) + 0xc);
  if ((copy->tmpl->kind & 0x1f) == 8) {
    iVar4 = iVar4 + 1;
  }
  g_arenas[5].cur = g_arenas[5].cur + (iVar4 + 3U & 0xfffffffc);
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  copy->param_bytes = pcVar3;
  pcVar3 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (pcVar3 == (c1_u8 *)0x0) {
    copy->args = (c1_arg_list *)0x0;
    return copy;
  }
  pcVar2 = src->args;
  pcVar3[0] = '\0';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  pcVar3[4] = '\0';
  pcVar3[5] = '\0';
  pcVar3[6] = '\0';
  pcVar3[7] = '\0';
  src_00 = pcVar2->first;
  if ((pcVar2->flags & 1) != 0) {
    pcVar3[8] = pcVar3[8] | 1;
  }
  do {
    item_copy = (c1_arg_item *)g_arenas[0].cur;
    if ((src_00->kind & 3) == 0) {
      g_arenas[0].cur = g_arenas[0].cur + 0x14;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (item_copy == (c1_arg_item *)0x0) {
LAB_104a7dfd:
        item_copy = (c1_arg_item *)0x0;
      }
      else {
        tmpl_argument_copy_base(item_copy,src_00);
        value = (src_00->value).type;
        item_copy->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
        *(void **)((int)item_copy + 0x10) = value;
      }
    }
    else {
      g_arenas[0].cur = g_arenas[0].cur + 0x14;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (item_copy == (c1_arg_item *)0x0) goto LAB_104a7dfd;
      tmpl_argument_copy_base(item_copy,src_00);
      value_2 = (src_00->value).type;
      item_copy->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
      *(void **)((int)item_copy + 0x10) = value_2;
    }
    if (*(int *)pcVar3 == 0) {
      *(c1_arg_item **)pcVar3 = item_copy;
    }
    else {
      *(c1_arg_item **)(*(int *)(pcVar3 + 4) + 4) = item_copy;
      item_copy->prev = *(c1_arg_item **)(pcVar3 + 4);
    }
    *(c1_arg_item **)(pcVar3 + 4) = item_copy;
    src_00 = src_00->next;
    if (src_00 == (c1_arg_item *)0x0) {
      copy->args = (c1_arg_list *)pcVar3;
      return copy;
    }
  } while( true );
}

