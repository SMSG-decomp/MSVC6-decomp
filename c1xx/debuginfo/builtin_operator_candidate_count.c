int __cdecl builtin_operator_candidate_count(void)

{
  char *pcVar1;
  char cVar2;
  char *candidate_row;
  
  candidate_row = (char *)g_builtin_operator_candidates;
  cVar2 = (char)g_builtin_operator_candidates[0].op;
  while (cVar2 != '\0') {
    pcVar1 = candidate_row + 0x14;
    candidate_row = candidate_row + 0x14;
    cVar2 = *pcVar1;
  }
  return (int)(candidate_row + -0x104d2840) / 0x14;
}

