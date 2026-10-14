void __fastcall conv_rule_converting_constructor(c1_conversion *conv)

{
  c1_node *item;
  c1_conversion *pcVar1;
  c1_u8 *object;
  c1_symbol *pcVar2;
  c1_type *pcVar3;
  c1_node *args;
  c1_ovl_candidate *winner;
  byte bVar4;
  c1_node *local_8;
  
  if (((conv->mode == '\a') || (conv->mode == '\b')) || ((conv->flags & 0x20) != 0)) {
    conv->rank = 0x70;
    conv->note = (-(uint)((conv->flags & 0x20) != 0) & 2) + 0x1796;
  }
  else {
    pcVar2 = (conv->target->extra).cls;
    if ((pcVar2->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(pcVar2);
      if ((pcVar2->flags2 & 4) == 0) {
        conv->rank = 0x70;
        conv->note = 0x179c;
        return;
      }
    }
    pcVar2 = (c1_symbol *)class_first_constructor((int)pcVar2);
    object = g_arenas[5].cur;
    if (pcVar2 == (c1_symbol *)0x0) {
      conv->rank = 0x70;
      conv->note = 0x1795;
      return;
    }
    g_arenas[5].cur = g_arenas[5].cur + 0x18;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    object[1] = '\x02';
    pcVar3 = type_pointer_with_qualifiers(conv->target,0);
    *(c1_type **)(object + 4) = pcVar3;
    *(c1_u8 **)(object + 8) = object;
    *(c1_u8 **)(object + 0x14) = object;
    *(c1_u8 **)(object + 0x10) = object;
    args = (c1_node *)g_arenas[5].cur;
    item = conv->expr;
    local_8 = (c1_node *)0x0;
    if (item == (c1_node *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + 0x18;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      *(c1_u8 *)((int)args + 1) = '\x02';
      *(c1_type **)((int)args + 4) = conv->source;
      *(c1_node **)((int)args + 8) = args;
      *(c1_node **)((int)args + 0x14) = args;
      *(c1_node **)((int)args + 0x10) = args;
    }
    else {
      local_8 = item->link;
      args = tree_append_list_item((c1_node *)0x0,item,2);
    }
    bVar4 = conv->mode;
    if ((bVar4 == 1) || ((3 < bVar4 && (bVar4 < 7)))) {
      bVar4 = (conv->flags & 2) << 1;
    }
    else {
      bVar4 = 0x24;
    }
    winner = ovl_resolve_call(pcVar2,(c1_node *)object,args,1,(int *)0x0,bVar4);
    if (winner == (c1_ovl_candidate *)0x0) {
      conv->rank = 0x70;
      conv->note_fn = diag_note_no_copy_constructor;
      return;
    }
    conv->rank = 0x30;
    conv->via = (c1_conversion_via)winner->function;
    conv->build = conv_build_converting_constructor;
    conv->note_fn = diag_note_constructor_call;
    pcVar1 = winner->conversions;
    conv->second = (c1_conversion *)0x0;
    conv->first = pcVar1 + 1;
    if (conv->expr != (c1_node *)0x0) {
      conv->expr->link = local_8;
      return;
    }
  }
  return;
}

