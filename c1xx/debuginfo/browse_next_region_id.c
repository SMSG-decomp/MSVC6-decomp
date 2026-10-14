void __cdecl browse_next_region_id(void)

{
  g_browse_id_module_byte = g_browse_id_module_byte + (g_browse_id_module_byte == 0xff) + '\x01';
  return;
}

