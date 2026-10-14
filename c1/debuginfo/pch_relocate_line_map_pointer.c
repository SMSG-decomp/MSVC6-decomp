void __cdecl pch_relocate_line_map_pointer(void)

{
  pch_relocate_pointer(&g_pch_image,(uint *)&g_line_map);
  return;
}

