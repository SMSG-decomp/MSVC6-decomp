c1_tag_symbol * __cdecl decl_tag_check_kind_and_browse(c1_tag_symbol *tag,ushort kind)

{
  c1_tag_symbol *pcVar1;
  
  if (tag == (c1_tag_symbol *)0x0) {
    return (c1_tag_symbol *)0x0;
  }
  pcVar1 = class_check_tag_kind_consistency(tag,kind);
  if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->reference_symbol)(pcVar1);
  }
  return pcVar1;
}

