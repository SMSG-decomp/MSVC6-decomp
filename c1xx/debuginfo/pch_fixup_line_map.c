void __cdecl pch_fixup_line_map(void)

{
  pch_relocate_pointer(&g_pch_image,(uint *)&g_line_map);
  return;
}

