c1_node * __thiscall conv_apply_conversion(c1_conversion *conv,c1_node *node)

{
  c1_node *pcVar1;
  uint uVar2;
  
  if (conv->extension_note != 0) {
    uVar2 = diag_warning_is_enabled(4,0xef);
    if (uVar2 != 0) {
      diag_begin_global(g_token_position);
      diag_warning(4,0xef,(uint)conv->op,conv->source,conv->target);
      diag_note(conv->extension_note);
      diag_end_global();
    }
  }
  if ((conv->build_constant != (code *)0x0) && ((conv->expr->kind & 7) == 3)) {
    pcVar1 = (c1_node *)(*conv->build_constant)(node);
    return pcVar1;
  }
  pcVar1 = (c1_node *)(*conv->build)(node);
  return pcVar1;
}

