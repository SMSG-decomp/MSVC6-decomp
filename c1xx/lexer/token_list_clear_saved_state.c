void __fastcall token_list_clear_saved_state(int *list)

{
  uint *entry;
  
  for (entry = (uint *)*list; entry != (uint *)0x0; entry = (uint *)*entry) {
    entry[1] = 0;
    entry[2] = 0;
    entry[3] = 0;
    entry[4] = 0;
  }
  return;
}

