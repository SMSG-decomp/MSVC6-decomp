c1_node * __cdecl conv_convert_cast(c1_u8 op,c1_type *target,c1_node *node)

{
  c1_u8 cVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  c1_conversion *conv;
  c1_type local_10;
  
  conv = (c1_conversion *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x50;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (conv == (c1_conversion *)0x0) {
    conv = (c1_conversion *)0x0;
  }
  else {
    conv->op = op;
    switch(op) {
    case 'd':
      cVar1 = '\x04';
      break;
    default:
      cVar1 = '\x02';
      break;
    case 't':
      cVar1 = '\x01';
      break;
    case 200:
      cVar1 = '\x06';
      break;
    case 0xd6:
      cVar1 = '\a';
      break;
    case 0xdd:
      cVar1 = '\b';
      break;
    case 0xde:
      cVar1 = '\t';
    }
    *(c1_u8 *)((int)conv + 1) = cVar1;
    *(c1_u8 *)((int)conv + 2) = '\0';
    *(c1_node **)((int)conv + 4) = node;
    if (node == (c1_node *)0x0) {
      local_10.base = (c1_type *)0x0;
      local_10.debug_index = 0;
      local_10.code = 0x80f;
      local_10.flags = 0;
      local_10.extra.cls = (c1_symbol *)0x0;
      pcVar3 = type_intern(&local_10);
    }
    else {
      pcVar3 = node->type;
    }
    *(c1_type **)((int)conv + 8) = pcVar3;
    *(c1_type **)((int)conv + 0xc) = target;
    conv_compute_conversion(conv);
  }
  if ((conv->flags4e & 1) != 0) {
    pcVar2 = conv_apply_conversion(conv,(c1_node *)0x0);
    return pcVar2;
  }
  conv_report_cannot_convert(conv,'\x01');
  return (c1_node *)0x0;
}

