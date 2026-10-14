void __cdecl free_list_mark_block_end(int *list)

{
  *(int *)(list[2] + 0x7fc) = *list;
  return;
}

