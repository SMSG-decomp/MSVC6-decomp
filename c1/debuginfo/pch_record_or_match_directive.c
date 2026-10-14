int __cdecl pch_record_or_match_directive(void)

{
  byte bVar1;
  int iVar2;
  
  if (g_pch_directive_mode != 1) {
    free_list_mark_block_end(g_pch_directive_text_blocks);
    block_list_rewind(g_pch_directive_text_blocks);
    if (*g_pch_record_cursor == 3) {
      bVar1 = block_list_equals_bytes
                        (g_pch_directive_text_blocks,(c1_u8 *)(g_pch_record_cursor + 3),
                         g_pch_record_cursor[1]);
      if (bVar1 != 0) {
        g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
        return 2;
      }
    }
    iVar2 = pch_auto_match_end();
    if (iVar2 == 3) {
      pch_directive_reopen_source();
    }
    return iVar2;
  }
  free_list_mark_block_end(g_pch_directive_text_blocks);
  block_list_rewind(g_pch_directive_text_blocks);
  if ((g_char_flags[g_pch_directive_text_blocks->cur[7]] & 3) == 0) {
    iVar2 = strncmp((char *)g_pch_directive_text_blocks->cur,"hdrstop",7);
    if (iVar2 == 0) {
      pch_directive_reopen_source();
      return 2;
    }
  }
  iVar2 = pch_write_blocks(g_pch_directive_text_blocks,(FILE *)0x0,(c1_byte_block_list *)0x0);
  init_write_reloc_record(3,0,iVar2);
  pch_write_blocks(g_pch_directive_text_blocks,(FILE *)0x0,g_pch_record_list);
  pch_directive_reopen_source();
  return 2;
}

