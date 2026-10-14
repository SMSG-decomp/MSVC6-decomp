void incr_write_compile_options(void)

{
  int iVar1;
  byte value;
  long stack_probe_size;
  
  value = g_opt_penter_hook != 0;
  if (g_opt_cpu_target == 4) {
    value = value | 2;
  }
  else if (g_opt_cpu_target == 5) {
    value = value | 4;
  }
  if (g_opt_function_level_linking != 0) {
    value = value | 8;
  }
  if (g_opt_cbstring != 0) {
    value = value | 0x10;
  }
  if (g_opt_bzalign != 0) {
    value = value | 0x20;
  }
  if (g_opt_blend != 0) {
    value = value | 0x40;
  }
  if (g_opt_line_numbers != 0) {
    value = value | 0x80;
  }
  incr_stream_put_byte(value);
  stack_probe_size = g_opt_stack_probe_size;
  if ((uint)g_incr_info_free < 4) {
    if (g_incr_stream_written == 0) {
      iVar1 = pdb_stream_replace(g_incr_info_buffer,0x2800 - g_incr_info_free);
      if (iVar1 == 0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x98f);
      }
      g_incr_stream_written = 1;
    }
    else {
      iVar1 = pdb_stream_append(g_incr_info_buffer,0x2800 - g_incr_info_free);
      if (iVar1 == 0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x98c);
      }
    }
    g_incr_info_free = 0x2800;
    g_incr_info_cursor = g_incr_info_buffer;
  }
  *(long *)g_incr_info_cursor = stack_probe_size;
  g_incr_info_cursor = (uint8_t *)((int)g_incr_info_cursor + 4);
  g_incr_info_free = g_incr_info_free + -4;
  return;
}

