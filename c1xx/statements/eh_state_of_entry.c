int __cdecl eh_state_of_entry(int index)

{
  if (g_error_count == 0) {
    return g_eh_state_table[index].kind;
  }
  return 1;
}

