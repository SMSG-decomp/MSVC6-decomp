void __fastcall globdf_mark_copy_parts(c2_symbol *s)

{
  c2_copy_link *pcVar1;
  c2_symbol *s_00;
  int iVar2;
  uint32_t n;
  c2_symbol *pcVar3;
  
  for (pcVar1 = (s->u34).source_links; pcVar1 != (c2_copy_link *)0x0;
      pcVar1 = pcVar1->next_of_source) {
    s_00 = pcVar1->copy;
    pcVar3 = s_00->storage;
    if (pcVar3 != (c2_symbol *)0x0) {
      iVar2 = s_00->offset;
      do {
        if ((iVar2 <= pcVar3->offset) && (pcVar3->size + pcVar3->offset <= s_00->size + iVar2)) {
          n = pcVar3->id;
          bitset_set(g_df_block_def,n);
          bitset_clear(g_df_block_use,n);
          bitset_set(g_df_block_part_def,n);
          bitset_clear(g_df_block_part_use,n);
        }
        pcVar3 = pcVar3->part_next;
      } while (pcVar3 != (c2_symbol *)0x0);
    }
    if (((s_00->u18).expr != (c2_cse_expr *)0x0) && (((s_00->u18).expr)->op == 0x14c)) {
      globdf_mark_copy_parts(s_00);
    }
  }
  return;
}

