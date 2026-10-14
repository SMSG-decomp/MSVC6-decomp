void __cdecl block_list_rewind(c1_byte_block_list *list)

{
  list->used = 0;
  list->block = list->first;
  list->cur = list->first->data;
  return;
}

