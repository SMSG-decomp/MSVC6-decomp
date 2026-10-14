char __cdecl include_close_outer_handle(void)

{
  fe_input_file *pfVar1;
  int iVar2;
  
  iVar2 = g_include_depth;
  pfVar1 = g_input_file;
  if (g_include_depth < 3) {
    return '\0';
  }
  while ((2 < iVar2 && (pfVar1->next->handle != -1))) {
    iVar2 = iVar2 + -1;
    pfVar1 = pfVar1->next;
  }
  iVar2 = _close(pfVar1->handle);
  pfVar1->handle = -1;
  return iVar2 == 0;
}

