c1_builtin_operator_row * __cdecl ovl_builtin_candidates_for_operator(char op)

{
  c1_builtin_operator_row *pcVar1;
  char cVar2;
  
  pcVar1 = g_builtin_operator_candidates;
  cVar2 = (char)g_builtin_operator_candidates[0].op;
  if ((char)g_builtin_operator_candidates[0].op != op) {
    while (cVar2 != '\0') {
      cVar2 = (char)pcVar1[1].op;
      pcVar1 = pcVar1 + 1;
      if (cVar2 == op) {
        return pcVar1;
      }
    }
    pcVar1 = (c1_builtin_operator_row *)0x0;
  }
  return pcVar1;
}

