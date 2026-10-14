void __cdecl expr_note_destructor_lookup_failure(int sym2)

{
  if (g_eh_unresolved_dtor_class == (c1_symbol *)0x0) {
    g_eh_unresolved_dtor_class = (c1_symbol *)sym2;
  }
  return;
}

