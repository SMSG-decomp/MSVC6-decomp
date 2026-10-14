void __cdecl pch_relocate_pragma_comment_list(void)

{
  c1_pragma_comment *cell;
  
  for (cell = g_pragma_comment_list; cell != (c1_pragma_comment *)0x0; cell = cell->next) {
    pch_relocate_slot_once(&g_pch_image,(uint *)cell);
    pch_relocate_slot_once(&g_pch_image,(uint *)&cell->text);
  }
  return;
}

