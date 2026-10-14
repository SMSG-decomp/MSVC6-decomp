char __cdecl pp_macro_is_being_expanded(fe_macro *macro)

{
  int iVar1;
  int *piVar2;
  
  if (-1 < g_macro_expansion_depth) {
    piVar2 = &g_macro_expansion_frames[g_macro_expansion_depth].active;
    iVar1 = g_macro_expansion_depth;
    do {
      if (((fe_macro *)piVar2[-2] == macro) && (*piVar2 != 0)) {
        return '\x01';
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + -6;
    } while (-1 < iVar1);
  }
  return '\0';
}

