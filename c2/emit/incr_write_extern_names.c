void incr_write_extern_names(void)

{
  uint8_t *puVar1;
  uint8_t value;
  int iVar2;
  uint8_t value_00;
  uint8_t *puVar3;
  c2_fe_symbol **ppcVar4;
  
  value_00 = '\0';
  ppcVar4 = g_extern_name_hash;
  do {
    if (*ppcVar4 != (c2_fe_symbol *)0x0) {
      incr_stream_put_byte(value_00);
      puVar3 = (uint8_t *)(*ppcVar4)->name;
      value = *puVar3;
      while (value != '\0') {
        incr_stream_put_byte(value);
        puVar1 = puVar3 + 1;
        puVar3 = puVar3 + 1;
        value = *puVar1;
      }
      incr_stream_put_byte('\0');
      incr_stream_put_byte((*ppcVar4)->cls);
    }
    ppcVar4 = ppcVar4 + 1;
    value_00 = value_00 + '\x01';
  } while ((int)ppcVar4 < 0x1079bc18);
  if (g_incr_info_free != 0) {
    *g_incr_info_cursor = 0xff;
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
  puVar3 = g_incr_info_buffer;
  *g_incr_info_buffer = 0xff;
  g_incr_info_cursor = puVar3 + 1;
  g_incr_info_free = 0x27ff;
  return;
}

