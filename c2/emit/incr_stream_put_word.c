void __fastcall incr_stream_put_word(uint16_t value)

{
  int iVar1;
  
  if ((uint)g_incr_info_free < 2) {
    if (g_incr_stream_written == 0) {
      iVar1 = pdb_stream_replace(g_incr_info_buffer,0x2800 - g_incr_info_free);
      if (iVar1 == 0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x9a6);
      }
      g_incr_stream_written = 1;
    }
    else {
      iVar1 = pdb_stream_append(g_incr_info_buffer,0x2800 - g_incr_info_free);
      if (iVar1 == 0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x9a3);
      }
    }
    g_incr_info_free = 0x2800;
    g_incr_info_cursor = g_incr_info_buffer;
  }
  *(uint16_t *)g_incr_info_cursor = value;
  g_incr_info_cursor = (uint8_t *)((int)g_incr_info_cursor + 2);
  g_incr_info_free = g_incr_info_free + -2;
  return;
}

