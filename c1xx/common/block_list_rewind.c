void __cdecl block_list_rewind(int *list)

{
  *list = 0;
  list[2] = list[3];
  list[1] = list[3];
  return;
}

