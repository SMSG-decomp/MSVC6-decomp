void __cdecl pch_relocate_pragma_comment_list(void)

{
  fe_pragma_comment *slot;
  
  for (slot = g_pragma_comment_list; slot != (fe_pragma_comment *)0x0; slot = slot->next) {
    pch_relocate_slot_once(&g_pch_image,(uint)slot);
    pch_relocate_slot_once(&g_pch_image,(uint)&slot->text);
  }
  return;
}

