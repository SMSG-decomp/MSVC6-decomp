void __cdecl diag_begin_global(int position)

{
  diag_begin(&g_diag_message_list,position);
  return;
}

