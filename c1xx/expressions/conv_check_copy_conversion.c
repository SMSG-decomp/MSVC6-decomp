int __cdecl conv_check_copy_conversion(c1_node *target,c1_node *source)

{
  c1_type *pcVar1;
  byte bVar2;
  c1_conversion *conv;
  
  conv = (c1_conversion *)g_arenas[5].cur;
  if ((target != (c1_node *)0x0) && (source != (c1_node *)0x0)) {
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv == (c1_conversion *)0x0) {
      conv = (c1_conversion *)0x0;
    }
    else {
      pcVar1 = target->type;
      conv->op = 't';
      *(c1_u8 *)((int)conv + 1) = '\x01';
      *(c1_u8 *)((int)conv + 2) = '\0';
      *(c1_node **)((int)conv + 4) = source;
      *(c1_type **)((int)conv + 8) = source->type;
      *(c1_type **)((int)conv + 0xc) = pcVar1;
      conv_compute_conversion(conv);
    }
    if ((conv->flags4e & 1) != 0) {
      bVar2 = init_emit_initializer_expression(target,conv);
      return (uint)bVar2;
    }
    conv_report_cannot_convert(conv,'\x01');
  }
  return 0;
}

