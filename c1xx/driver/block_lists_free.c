void __cdecl block_lists_free(void)

{
  free_list_destroy((c1_byte_block_list **)&g_pch_record_list);
  if (g_pch_directive_text_blocks != g_injected_text_list) {
    free_list_destroy((c1_byte_block_list **)&g_pch_directive_text_blocks);
  }
  free_list_destroy((c1_byte_block_list **)&g_injected_text_list);
  return;
}

