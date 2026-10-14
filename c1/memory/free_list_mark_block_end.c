void __cdecl free_list_mark_block_end(c1_byte_block_list *list)

{
  list->block->used = list->used;
  return;
}

