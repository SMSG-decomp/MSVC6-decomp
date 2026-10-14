void __cdecl pch_rle_begin(int *counter)

{
  g_pch_rle_counter = counter;
  *counter = 0;
  g_pch_rle_byte = -1;
  g_pch_rle_run_length = 0;
  return;
}

