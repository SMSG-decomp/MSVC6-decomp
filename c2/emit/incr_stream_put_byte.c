void __fastcall incr_stream_put_byte(uint8_t value)

{
  uint8_t *puVar1;
  int iVar2;
  
  if (g_incr_info_free != 0) {
    *g_incr_info_cursor = value;
    g_incr_info_cursor = g_incr_info_cursor + 1;
    g_incr_info_free = g_incr_info_free + -1;
    return;
  }
  if (g_incr_stream_written == 0) {
    iVar2 = pdb_stream_replace(g_incr_info_buffer,0x2800);
    if (iVar2 == 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x9bd);
    }
    g_incr_stream_written = 1;
  }
  else {
    iVar2 = pdb_stream_append(g_incr_info_buffer,0x2800);
    if (iVar2 == 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x9ba);
    }
  }
  puVar1 = g_incr_info_buffer;
  *g_incr_info_buffer = value;
  g_incr_info_cursor = puVar1 + 1;
  g_incr_info_free = 0x27ff;
  return;
}

